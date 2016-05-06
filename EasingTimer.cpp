//
//  EasingTimer.cpp
//  Motion_lib_test
//
//  Created by Aduen Darriba on 29/12/15.
//  Copyright © 2015 Aduen Darriba. All rights reserved.
//

#include "EasingTimer.h"

EasingTimer::EasingTimer()
{
    for (uint8 i = 0; i < MAX_FUNCS; ++i) {
        delg[i].s_time = 0;
        delg[i].active = false;
    }
}

void EasingTimer::run()
{
    uint32 ctime = millis();
    for (uint8 i = 0; i < MAX_FUNCS; ++i) {
        
        //run through active delegates, time 0 and active true means a waiting ease to be started later
        if(delg[i].s_time > 0 && delg[i].active){
            uint32 t_diff = ctime - delg[i].s_time;
            
            float f;
            if(delg[i].begin > delg[i].end)
            {
                f = float(delg[i].begin) - delg[i].ease_func(0, delg[i].begin-delg[i].end, delg[i].dur, t_diff);
            } else {
                f = float(delg[i].begin) + delg[i].ease_func(0, delg[i].end-delg[i].begin, delg[i].dur, t_diff);
            }
            
            if(t_diff<=delg[i].dur) delg[i].cb_func(delg[i].uid, f);
            else delg[i].active = false; //deactivate
        }
    }
}

bool EasingTimer::start(uint8 fid)
{
    if(fid < MAX_FUNCS) delg[fid].s_time = millis();
}

int8 EasingTimer::add(uint16 begin,uint16 end, uint32 dur,void(*callback)(uint16, float),uint8 easing_type)
{
    int8 spot = get_empty_spot();
    if(spot<0) return -1; //no empty spot found
    
    ease_delg fs;
    fs.s_time = 0;
    fs.dur = dur;
    fs.end = end;
    fs.begin = begin;
    fs.cb_func = callback;
    fs.active = true;
    fs.uid = spot;
    
    if(easing_type == _QUAD_IN_) fs.ease_func = &Easing::Quad_easeIn;
    if(easing_type == _QUAD_OUT_) fs.ease_func = &Easing::Quad_easeOut;
    if(easing_type == _QUAD_INOUT_) fs.ease_func = &Easing::Quad_easeInOut;
    
    if(easing_type == _EXPO_IN_) fs.ease_func = &Easing::Expo_easeIn;
    if(easing_type == _EXPO_OUT_) fs.ease_func = &Easing::Expo_easeOut;
    if(easing_type == _EXPO_INOUT_) fs.ease_func = &Easing::Expo_easeInOut;
    
    if(easing_type == _BACK_IN_) fs.ease_func = &Easing::Back_easeIn;
    if(easing_type == _BACK_OUT_) fs.ease_func = &Easing::Back_easeOut;
    if(easing_type == _BACK_INOUT_) fs.ease_func = &Easing::Back_easeInOut;
    
    if(easing_type == _BOUNCE_IN_) fs.ease_func = &Easing::Bounce_easeIn;
    if(easing_type == _BOUNCE_OUT_) fs.ease_func = &Easing::Bounce_easeOut;
    if(easing_type == _BOUNCE_INOUT_) fs.ease_func = &Easing::Bounce_easeInOut;
    
    if(easing_type == _ELASTIC_IN_) fs.ease_func = &Easing::Elastic_easeIn;
    if(easing_type == _ELASTIC_OUT_) fs.ease_func = &Easing::Elastic_easeOut;
    if(easing_type == _ELASTIC_INOUT_) fs.ease_func = &Easing::Elastic_easeInOut;
    
    delg[spot] = fs;
    
    return spot;
}

int8 EasingTimer::add(uint16 begin, uint16 end, uint32 dur, void (*callback)(uint16, float), uint8 easing_type, uint16 uid)
{
    int8 spot = get_empty_spot();
    if(spot<0) return -1; //no empty spot found
    
    ease_delg fs;
    fs.s_time = 0;
    fs.dur = dur;
    fs.end = end;
    fs.begin = begin;
    fs.cb_func = callback;
    fs.active = true;
    fs.uid = uid;
    
    if(easing_type == _QUAD_IN_) fs.ease_func = &Easing::Quad_easeIn;
    if(easing_type == _QUAD_OUT_) fs.ease_func = &Easing::Quad_easeOut;
    if(easing_type == _QUAD_INOUT_) fs.ease_func = &Easing::Quad_easeInOut;
    
    if(easing_type == _EXPO_IN_) fs.ease_func = &Easing::Expo_easeIn;
    if(easing_type == _EXPO_OUT_) fs.ease_func = &Easing::Expo_easeOut;
    if(easing_type == _EXPO_INOUT_) fs.ease_func = &Easing::Expo_easeInOut;
    
    if(easing_type == _BACK_IN_) fs.ease_func = &Easing::Back_easeIn;
    if(easing_type == _BACK_OUT_) fs.ease_func = &Easing::Back_easeOut;
    if(easing_type == _BACK_INOUT_) fs.ease_func = &Easing::Back_easeInOut;
    
    if(easing_type == _BOUNCE_IN_) fs.ease_func = &Easing::Bounce_easeIn;
    if(easing_type == _BOUNCE_OUT_) fs.ease_func = &Easing::Bounce_easeOut;
    if(easing_type == _BOUNCE_INOUT_) fs.ease_func = &Easing::Bounce_easeInOut;
    
    if(easing_type == _ELASTIC_IN_) fs.ease_func = &Easing::Elastic_easeIn;
    if(easing_type == _ELASTIC_OUT_) fs.ease_func = &Easing::Elastic_easeOut;
    if(easing_type == _ELASTIC_INOUT_) fs.ease_func = &Easing::Elastic_easeInOut;
    
    delg[spot] = fs;
    
    return spot;
}

void EasingTimer::clear()
{
    //remove all running easing functions
    for (uint8 i = 0; i < MAX_FUNCS; ++i) {
        delg[i].s_time = 0;
        delg[i].active = false;
    }
}

void EasingTimer::clear(uint8 fid)
{
    if(!delg[fid].active) return;
    //remove a running easing function
    delg[fid].s_time = 0;
    delg[fid].active = false;
}

//PRIVATE

int8 EasingTimer::get_empty_spot()
{
    for (int i = 0; i < MAX_FUNCS; i++) {
        if(!delg[i].active)return i;
    }
    return -1;
}
