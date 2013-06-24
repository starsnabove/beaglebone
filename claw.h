//claw.h

#ifndef __CLAW_H_included__
#define __CLAW_H_included__

#include "servo.h"

#define CLAW_OPEN 90
#define CLAW_CLOSE 0

class Claw {

    private:

        Servo claw_servo;

    public:

        Claw(PWM);
        void open(void);
        void close(void);
};




#endif
