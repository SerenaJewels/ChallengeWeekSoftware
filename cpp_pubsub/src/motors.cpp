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

#include "MotorFunctions/MotorFunctions.cpp"

int main(void)
{
    MotorFunctions mf;

    mf.rotate(100000, 1);
    // sleep(5);
    // mf.stop();
    // sleep(5);
    // mf.rotate(0xFF);
    // sleep(5);
    // mf.stop();
	
	return 0;
};