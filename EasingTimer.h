//
//  EasingTimer.hpp
//  Motion_lib_test
//
//  Created by Aduen Darriba on 29/12/15.
//  Copyright © 2015 Aduen Darriba. All rights reserved.
//

#ifndef EasingTimer_hpp
#define EasingTimer_hpp

#define MAX_FUNCS 36

#define _QUAD_IN_ 11
#define _QUAD_OUT_ 12
#define _QUAD_INOUT_ 13

#define _BACK_IN_ 14
#define _BACK_OUT_ 15
#define _BACK_INOUT_ 16

#define _BOUNCE_IN_ 17
#define _BOUNCE_OUT_ 18
#define _BOUNCE_INOUT_ 19

#define _EXPO_IN_ 20
#define _EXPO_OUT_ 21
#define _EXPO_INOUT_ 22

#define _ELASTIC_IN_ 23
#define _ELASTIC_OUT_ 24
#define _ELASTIC_INOUT_ 25


// Arduino versioning.
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#define uint8 uint8_t
#define uint16 uint16_t
#define uint32 uint32_t
#define uint64 uint64_t
#define int8 int8_t
#define int16 int16_t
#define int32 int32_t
#define int64 int64_t
#define boolean bool
#else
//#include "WProgram.h" //arduino case
#include "pandora.h" // OpenCM case
#endif
#include "PennerEasing.h"

typedef struct {
    float (*ease_func)(uint16,uint16,uint32,uint32);
    void (*cb_func)(uint16,float);
    uint32 s_time;
    uint16 begin;
    uint16 end;
    uint16 dur;
    uint16 uid;
    bool active;
} ease_delg; //32,32,32,16,16,16, 8 = 152bytes

class EasingTimer {
public:
    explicit EasingTimer();

    const static uint8 MAX_TIMER = MAX_FUNCS;
    
    int8 add(uint16 begin,uint16 end, uint32 dur,void(*callback)(uint16, float),uint8 easing_type);
    int8 add(uint16 begin,uint16 end, uint32 dur,void(*callback)(uint16, float),uint8 easing_type, uint16 uid);
    bool start(uint8 fid);
    void clear();
    void clear(uint8 fid);
    
    void run();
    
    //more to come
    static const uint8 QUAD_IN = _QUAD_IN_;
    static const uint8 QUAD_OUT = _QUAD_OUT_;
    static const uint8 QUAD_INOUT = _QUAD_INOUT_;
    
    static const uint8 BACK_IN = _BACK_IN_;
    static const uint8 BACK_OUT = _BACK_OUT_;
    static const uint8 BACK_INOUT = _BACK_INOUT_;
    
    static const uint8 BOUNCE_IN = _BOUNCE_IN_;
    static const uint8 BOUNCE_OUT = _BOUNCE_OUT_;
    static const uint8 BOUNCE_INOUT = _BOUNCE_INOUT_;
    
    static const uint8 EXPO_IN = _EXPO_IN_;
    static const uint8 EXPO_OUT = _EXPO_OUT_;
    static const uint8 EXPO_INOUT = _EXPO_INOUT_;
    
    static const uint8 ELASTIC_IN = _ELASTIC_IN_;
    static const uint8 ELASTIC_OUT = _ELASTIC_OUT_;
    static const uint8 ELASTIC_INOUT = _ELASTIC_INOUT_;
    
private:
    ease_delg delg[MAX_FUNCS];
    
    int8 get_empty_spot();
};

#endif /* EasingTimer_hpp */
