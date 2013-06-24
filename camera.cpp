//camera.cpp - library for interacting with the camera

#include "camera.h"


#define READ_SIZE 32

const char GET_SIZE[5] = {0x56, 0x00, 0x34, 0x01, 0x00};
const char RESET_CAMERA[4] = {0x56, 0x00, 0x26, 0x00};
const char TAKE_PICTURE[5] = {0x56, 0x00, 0x36, 0x01, 0x00};
const char STOP_TAKING_PICTURES[5] = {0x56, 0x00, 0x36, 0x01, 0x03};
const char READ_DATA[8] = {0x56, 0x00, 0x32, 0x0C, 0x00, 0x0A, 0x00, 0x00};


Camera::Camera(void) {

    serial = Uart(1);
}

void Camera::reset(void) {

    while (!serial.transmit(RESET_CAMERA, 4));

    char ret[4];

    while(!serial.receive(ret, 4));

    if ((ret[0] != '0x76') && (ret[1] != '0x00') && (re[2] != '0x26') &&
            (ret[3] != '0x00')) {
        cerr << "Error resetting camera\n";
        exit(1);
    }
}



