#include <LossyDataProtocol.h>
#include <SimpleTimer.h>

#include <EasingTimer.h>

SimpleTimer t;
EasingTimer m;

uint8 _fid[3];

void motioncb(uint8 fid, float pos)
{
    uint16 p = pos;
    
    SerialUSB.print("id ");
    SerialUSB.print(fid);
    
    
    SerialUSB.print(" - ");
    SerialUSB.println(pos);
    
    if (fid == _fid[0]) analogWrite(3, p);
    if (fid == _fid[1]) analogWrite(4, p);
    if (fid == _fid[2]) analogWrite(5, p);
    
}

//20hz update rate... maybe a better solutions is adding this to the EasingTimer lib
void update_easing(uint8 pid)
{
    m.run();
}

void start_easing(uint8 tmr_id)
{
    m.start(tmr_id);
}

void setup()
{
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    
    delay(1000);
    SerialUSB.println("Easing timer test 001...");
    
    t.setTimer(50, update_easing, SimpleTimer::RUN_FOREVER);
    
                    //start, end, duration, callback, easing type
    _fid[0] = m.add(0, 255, 10000, motioncb, EasingTimer::QUAD_IN);
    _fid[1] = m.add(0, 255, 8000, motioncb, EasingTimer::EXPO_INOUT);
    _fid[2] = m.add(0, 255, 6000, motioncb, EasingTimer::ELASTIC_OUT);
    
    t.setTimer(500, start_easing, SimpleTimer::RUN_ONCE, _fid[0]);
    t.setTimer(10500, start_easing, SimpleTimer::RUN_ONCE, _fid[1]);
    t.setTimer(18500, start_easing, SimpleTimer::RUN_ONCE, _fid[2]);
}

void loop()
{
    t.run();
    //m.run();
}

