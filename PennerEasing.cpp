//
//  PennerEasing.cpp
//  Motions_lib_test
//
//  Based on the work of Robert Penner
//
//  Created by Aduen Darriba on 31/12/15.
//  Copyright © 2015 Aduen Darriba. All rights reserved.
//

#include "PennerEasing.h"

float Easing::Quad_easeIn(uint16 start, uint16 end, uint32 dur, uint32 t_diff)
{
    float c = end;
    float t = t_diff;
    float b = start;
    float d = dur;
    
    return c*(t/=d)*t + b;
}

float Easing::Quad_easeOut (uint16 start, uint16 end, uint32 dur, uint32 t_diff) {
    float c = end;
    float t = t_diff;
    float b = start;
    float d = dur;
    
    return -c *(t/=d)*(t-2) + b;
}

float Easing::Quad_easeInOut (uint16 start, uint16 end, uint32 dur, uint32 t_diff) {
    float c = end;
    float t = t_diff;
    float b = start;
    float d = dur;
    
    if ((t/=d/2) < 1) return ((c/2)*(t*t)) + b;
    return -c/2 * (((t-2)*(--t)) - 1) + b;
}

float Easing::Back_easeIn (uint16 start, uint16 end, uint32 dur, uint32 t_diff) {
    float c = end;
    float t = t_diff;
    float b = start;
    float d = dur;
    
    float s = 1.70158f;
    float postFix = t/=d;
    return c*(postFix)*t*((s+1)*t - s) + b;
}
float Easing::Back_easeOut(uint16 start, uint16 end, uint32 dur, uint32 t_diff) {
    float c = end;
    float t = t_diff;
    float b = start;
    float d = dur;
    
    float s = 1.70158f;
    return c*((t=t/d-1)*t*((s+1)*t + s) + 1) + b;
}

float Easing::Back_easeInOut(uint16 start, uint16 end, uint32 dur, uint32 t_diff) {
    float c = end;
    float t = t_diff;
    float b = start;
    float d = dur;
    
    float s = 1.70158f;
    if ((t/=d/2) < 1) return c/2*(t*t*(((s*=(1.525f))+1)*t - s)) + b;
    float postFix = t-=2;
    return c/2*((postFix)*t*(((s*=(1.525f))+1)*t + s) + 2) + b;
}

float Easing::Bounce_easeIn (uint16 start, uint16 end, uint32 dur, uint32 t_diff) {
    float c = end;
    float t = t_diff;
    float b = start;
    float d = dur;
    
    return c - Bounce_easeOut (d-t, 0, c, d) + b;
}
float Easing::Bounce_easeOut(uint16 start, uint16 end, uint32 dur, uint32 t_diff) {
    float c = end;
    float t = t_diff;
    float b = start;
    float d = dur;
    
    if ((t/=d) < (1/2.75f)) {
        return c*(7.5625f*t*t) + b;
    } else if (t < (2/2.75f)) {
        float postFix = t-=(1.5f/2.75f);
        return c*(7.5625f*(postFix)*t + .75f) + b;
    } else if (t < (2.5/2.75)) {
        float postFix = t-=(2.25f/2.75f);
        return c*(7.5625f*(postFix)*t + .9375f) + b;
    } else {
        float postFix = t-=(2.625f/2.75f);
        return c*(7.5625f*(postFix)*t + .984375f) + b;
    }
}

float Easing::Bounce_easeInOut(uint16 start, uint16 end, uint32 dur, uint32 t_diff) {
    float c = end;
    float t = t_diff;
    float b = start;
    float d = dur;
    
    if (t < d/2) return Bounce_easeIn (t*2, 0, c, d) * .5f + b;
    else return Bounce_easeOut (t*2-d, 0, c, d) * .5f + c*.5f + b;
}

float Easing::Expo_easeIn (uint16 start, uint16 end, uint32 dur, uint32 t_diff) {
    float c = end;
    float t = t_diff;
    float b = start;
    float d = dur;
    
    return (t==0) ? b : c * pow(2, 10 * (t/d - 1)) + b;
}
float Easing::Expo_easeOut(uint16 start, uint16 end, uint32 dur, uint32 t_diff) {
    float c = end;
    float t = t_diff;
    float b = start;
    float d = dur;
    
    return (t==d) ? b+c : c * (-pow(2, -10 * t/d) + 1) + b;
}

float Easing::Expo_easeInOut(uint16 start, uint16 end, uint32 dur, uint32 t_diff) {
    float c = end;
    float t = t_diff;
    float b = start;
    float d = dur;
    
    if (t==0) return b;
    if (t==d) return b+c;
    if ((t/=d/2) < 1) return c/2 * pow(2, 10 * (t - 1)) + b;
    return c/2 * (-pow(2, -10 * --t) + 2) + b;
}

float Easing::Elastic_easeIn (uint16 start, uint16 end, uint32 dur, uint32 t_diff) {
    float c = end;
    float t = t_diff;
    float b = start;
    float d = dur;
    
    if (t==0) return b;  if ((t/=d)==1) return b+c;
    float p=d*.3f;
    float a=c;
    float s=p/4;
    float postFix =a*pow(2,10*(t-=1));
    return -(postFix * sin((t*d-s)*(2*PI)/p )) + b;
}

float Easing::Elastic_easeOut(uint16 start, uint16 end, uint32 dur, uint32 t_diff) {
    float c = end;
    float t = t_diff;
    float b = start;
    float d = dur;
    
    if (t==0) return b;  if ((t/=d)==1) return b+c;
    float p=d*.3f;
    float a=c;
    float s=p/4;
    return (a*pow(2,-10*t) * sin( (t*d-s)*(2*PI)/p ) + c + b);
}

float Easing::Elastic_easeInOut(uint16 start, uint16 end, uint32 dur, uint32 t_diff) {
    float c = end;
    float t = t_diff;
    float b = start;
    float d = dur;
    
    if (t==0) return b;  if ((t/=d/2)==2) return b+c;
    float p=d*(.3f*1.5f);
    float a=c;
    float s=p/4;
    
    if (t < 1) {
        float postFix =a*pow(2,10*(t-=1));
        return -.5f*(postFix* sin( (t*d-s)*(2*PI)/p )) + b;
    }
    float postFix =  a*pow(2,-10*(t-=1));
    return postFix * sin( (t*d-s)*(2*PI)/p )*.5f + c + b;
}