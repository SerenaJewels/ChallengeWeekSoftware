#ifndef MOTOR_FUNCTIONS
#define MOTOR_FUNCTIONS

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <linux/can.h>
#include <linux/can/raw.h>

class MotorFunctions {
    public:
        struct can_frame frame;
        int s;

        // initialization
        MotorFunctions();

        // functions
        void stop();

        void rotate(int dir);
};

#endif