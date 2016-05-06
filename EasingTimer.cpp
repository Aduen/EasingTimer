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
    update_freq = 1000/10; //1000ms /10Hz update frrequency
    p_time = millis();
    
    for (uint8_t i = 0; i < MAX_FUNCS; ++i) {
        delg[i].s_time = 0;
        delg[i].active = false;
    }
}

void EasingTimer::run()
{
    uint32_t c_time = millis();
    if (c_time - p_time < update_freq) return;
    p_time = c_time;
    
    for (uint8_t i = 0; i < MAX_FUNCS; ++i) {
        
        //run through active delegates, time 0 and active true means a waiting ease to be started later
        if(delg[i].s_time > 0 && delg[i].active){
            uint32_t t_diff = c_time - delg[i].s_time;
            
            float f;
            if(delg[i].begin > delg[i].end)
            {
                f = float(delg[i].begin) - delg[i].ease_func(0, delg[i].begin-delg[i].end, delg[i].dur, t_diff);
            } else {
                f = float(delg[i].begin) + delg[i].ease_func(0, delg[i].end-delg[i].begin, delg[i].dur, t_diff);
            }
            
            if(t_diff<=delg[i].dur) delg[i].cb_func(delg[i].uid, f);
            else{
                delg[i].cb_func(delg[i].uid, delg[i].end); //go to end
                delg[i].active = false; //deactivate
            }
        }
    }
}

bool EasingTimer::start(uint8_t fid)
{
    if(fid < MAX_FUNCS) delg[fid].s_time = millis();
}

int8_t EasingTimer::add(uint16_t begin,uint16_t end, uint32_t dur,void(*callback)(uint16_t, float),uint8_t easing_type)
{
    int8_t spot = get_empty_spot();
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

int8_t EasingTimer::add(uint16_t begin, uint16_t end, uint32_t dur, void (*callback)(uint16_t, float), uint8_t easing_type, uint16_t uid)
{
    int8_t spot = get_empty_spot();
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

void EasingTimer::frequency(uint16_t Hz)
{
    update_freq = 1000/Hz;
}

void EasingTimer::clear()
{
    //remove all running easing functions
    for (uint8_t i = 0; i < MAX_FUNCS; ++i) {
        delg[i].s_time = 0;
        delg[i].active = false;
    }
}

void EasingTimer::clear(uint8_t fid)
{
    if(!delg[fid].active) return;
    //remove a running easing function
    delg[fid].s_time = 0;
    delg[fid].active = false;
}

//PRIVATE

int8_t EasingTimer::get_empty_spot()
{
    for (int i = 0; i < MAX_FUNCS; i++) {
        if(!delg[i].active)return i;
    }
    return -1;
}
