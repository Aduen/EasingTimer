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


#include "Arduino.h"
#include "PennerEasing.h"

typedef struct {
    float (*ease_func)(uint16_t,uint16_t,uint32_t,uint32_t);
    void (*cb_func)(uint16_t,float);
    uint32_t s_time;
    uint16_t begin;
    uint16_t end;
    uint16_t dur;
    uint16_t uid;
    bool active;
} ease_delg; //32,32,32,16,16,16, 8 = 152bytes

class EasingTimer {
public:
    explicit EasingTimer();
    
    const static uint8_t MAX_TIMER = MAX_FUNCS;
    
    int8_t add(uint16_t begin,uint16_t end, uint32_t dur,void(*callback)(uint16_t, float),uint8_t easing_type);
    int8_t add(uint16_t begin,uint16_t end, uint32_t dur,void(*callback)(uint16_t, float),uint8_t easing_type, uint16_t uid);
    bool start(uint8_t fid);
    void clear();
    void clear(uint8_t fid);
    void frequency(uint16_t Hz);
    
    void run();
    
    //more to come
    static const uint8_t QUAD_IN = _QUAD_IN_;
    static const uint8_t QUAD_OUT = _QUAD_OUT_;
    static const uint8_t QUAD_INOUT = _QUAD_INOUT_;
    
    static const uint8_t BACK_IN = _BACK_IN_;
    static const uint8_t BACK_OUT = _BACK_OUT_;
    static const uint8_t BACK_INOUT = _BACK_INOUT_;
    
    static const uint8_t BOUNCE_IN = _BOUNCE_IN_;
    static const uint8_t BOUNCE_OUT = _BOUNCE_OUT_;
    static const uint8_t BOUNCE_INOUT = _BOUNCE_INOUT_;
    
    static const uint8_t EXPO_IN = _EXPO_IN_;
    static const uint8_t EXPO_OUT = _EXPO_OUT_;
    static const uint8_t EXPO_INOUT = _EXPO_INOUT_;
    
    static const uint8_t ELASTIC_IN = _ELASTIC_IN_;
    static const uint8_t ELASTIC_OUT = _ELASTIC_OUT_;
    static const uint8_t ELASTIC_INOUT = _ELASTIC_INOUT_;
    
private:
    ease_delg delg[MAX_FUNCS];
    
    uint16_t update_freq;
    uint32_t p_time;
    
    int8_t get_empty_spot();
};

#endif /* EasingTimer_hpp */
