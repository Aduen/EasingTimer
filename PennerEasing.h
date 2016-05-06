//
//  PennerEasing.hpp
//  Motions_lib_test
//
//  Created by Aduen Darriba on 31/12/15.
//  Copyright © 2015 Aduen Darriba. All rights reserved.
//

#ifndef PennerEasing_hpp
#define PennerEasing_hpp

#include "stdint.h"

class Easing {
public:
    float static Quad_easeIn (uint16_t start, uint16_t end, uint32_t dur, uint32_t t_diff);
    float static Quad_easeOut (uint16_t start, uint16_t end, uint32_t dur, uint32_t t_diff);
    float static Quad_easeInOut (uint16_t start, uint16_t end, uint32_t dur, uint32_t t_diff);
    
    float static Back_easeIn (uint16_t start, uint16_t end, uint32_t dur, uint32_t t_diff);
    float static Back_easeOut(uint16_t start, uint16_t end, uint32_t dur, uint32_t t_diff);
    float static Back_easeInOut(uint16_t start, uint16_t end, uint32_t dur, uint32_t t_diff);
    
    float static Bounce_easeIn (uint16_t start, uint16_t end, uint32_t dur, uint32_t t_diff);
    float static Bounce_easeOut (uint16_t start, uint16_t end, uint32_t dur, uint32_t t_diff);
    float static Bounce_easeInOut (uint16_t start, uint16_t end, uint32_t dur, uint32_t t_diff);
    
    float static Expo_easeIn (uint16_t start, uint16_t end, uint32_t dur, uint32_t t_diff);
    float static Expo_easeOut (uint16_t start, uint16_t end, uint32_t dur, uint32_t t_diff);
    float static Expo_easeInOut (uint16_t start, uint16_t end, uint32_t dur, uint32_t t_diff);
    
    float static Elastic_easeIn (uint16_t start, uint16_t end, uint32_t dur, uint32_t t_diff);
    float static Elastic_easeOut (uint16_t start, uint16_t end, uint32_t dur, uint32_t t_diff);
    float static Elastic_easeInOut (uint16_t start, uint16_t end, uint32_t dur, uint32_t t_diff);
};

#endif /* PennerEasing_hpp */
