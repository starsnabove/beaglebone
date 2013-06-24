// claw.cpp - class for controlling the claw

#include "claw.h"

Claw::Claw(PWM pwm_in) {

    claw_servo = Servo(pwm_in, CLAW, PWM4);
}


/* Opens the claw
 */
void Claw::open(void) {
    claw_servo.set_angle(CLAW_OPEN);
}

/* Closes the claw
 */
void Claw::close(void) {
    claw_servo.set_angle(CLAW_CLOSE);
}

