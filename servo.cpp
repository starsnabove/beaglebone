// servo.cpp - Servo class

#include "servo.h"

#define NEUTRAL 1500000 // ns pulse width for servo neutral position
#define SIG_FREQ 350 // frequency (Hz) of the pwm signal
#define MAX 2000000 // maximum pulse width in ns
#define MIN 1000000 // minimum pulse width in ms
#define ANGLE 180.0 // the movement angle in degrees

Servo::Servo(void) {
    
}

/* Servo class constructor
 */
Servo::Servo (PWM pwm_in, int servo_number, string servo_name) {

    convert = (MAX - MIN) / ANGLE;
    
    pwm = pwm_in;
    servo_no = servo_number;
    servo_nm = servo_name;

    pwm.set_prd_frq(servo_nm, SIG_FREQ);
    pwm.set_duty_ns(servo_nm, NEUTRAL);

    pwm.run();

}

/* Sets the joint angle of the given joint
 */
void Servo::set_angle(double angle) {

    if (angle < 0 || angle > ANGLE) {
        cerr << "Invalid angle into servos.set_angle\n";
        exit(EXIT_FAILURE);
    }

    int ns = MIN + angle * convert;
    pwm.set_duty_ns(servo_nm, ns);
}


