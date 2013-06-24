//camera.h - library for dealing with camera


#ifndef __CAMERA_H_INCLUDED__
#define __CAMERA_h_INCLUDED__

#include "uart.h"

class Camera {

    public:
       
        Camera(void);
        void reset(void);

    private:

        Uart serial;

};


#endif
