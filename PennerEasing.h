//
//  PennerEasing.hpp
//  Motions_lib_test
//
//  Created by Aduen Darriba on 31/12/15.
//  Copyright © 2015 Aduen Darriba. All rights reserved.
//

#ifndef PennerEasing_hpp
#define PennerEasing_hpp

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

class Easing {
public:
    float static Quad_easeIn (uint16 start, uint16 end, uint32 dur, uint32 t_diff);
    float static Quad_easeOut (uint16 start, uint16 end, uint32 dur, uint32 t_diff);
    float static Quad_easeInOut (uint16 start, uint16 end, uint32 dur, uint32 t_diff);
    
    float static Back_easeIn (uint16 start, uint16 end, uint32 dur, uint32 t_diff);
    float static Back_easeOut(uint16 start, uint16 end, uint32 dur, uint32 t_diff);
    float static Back_easeInOut(uint16 start, uint16 end, uint32 dur, uint32 t_diff);
    
    float static Bounce_easeIn (uint16 start, uint16 end, uint32 dur, uint32 t_diff);
    float static Bounce_easeOut (uint16 start, uint16 end, uint32 dur, uint32 t_diff);
    float static Bounce_easeInOut (uint16 start, uint16 end, uint32 dur, uint32 t_diff);
    
    float static Expo_easeIn (uint16 start, uint16 end, uint32 dur, uint32 t_diff);
    float static Expo_easeOut (uint16 start, uint16 end, uint32 dur, uint32 t_diff);
    float static Expo_easeInOut (uint16 start, uint16 end, uint32 dur, uint32 t_diff);
    
    float static Elastic_easeIn (uint16 start, uint16 end, uint32 dur, uint32 t_diff);
    float static Elastic_easeOut (uint16 start, uint16 end, uint32 dur, uint32 t_diff);
    float static Elastic_easeInOut (uint16 start, uint16 end, uint32 dur, uint32 t_diff);
};

#endif /* PennerEasing_hpp */
