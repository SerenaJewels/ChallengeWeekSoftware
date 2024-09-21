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

#include <errno.h>

#include "MotorFunctions.h"
struct can_frame frame;
int s;
int nbytes=0;
struct ifreq ifr;
struct sockaddr_can addr;
const char *ifname = "vcan0";

inline MotorFunctions::MotorFunctions() {
    if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) == -1) {
        perror("Error while opening socket");
        printf("socket failed opening");
    }

    strcpy(ifr.ifr_name, ifname);
	ioctl(s, SIOCGIFINDEX, &ifr);
	
	addr.can_family  = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	printf("%s at index %d\n", ifname, ifr.ifr_ifindex);

	if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
		perror("Error in socket bind");
        printf("socket failed binding");
	}

    frame.can_id  = 0x141;
    frame.can_dlc = 8;
    frame.data[0] = 0x00;
    frame.data[1] = 0x00;
    frame.data[2] = 0x00;
    frame.data[3] = 0x00;
    frame.data[4] = 0x00;
    frame.data[5] = 0x00;
    frame.data[6] = 0x00;
    frame.data[7] = 0x00;
};

inline void MotorFunctions::stop() {
    frame.can_id  = 0x141;
    frame.can_dlc = 8;
    frame.data[0] = 0x81;
    frame.data[1] = 0x00;
    frame.data[2] = 0x00;
    frame.data[3] = 0x00;
    frame.data[4] = 0x00;
    frame.data[5] = 0x00;
    frame.data[6] = 0x00;
    frame.data[7] = 0x00;
    nbytes = write(s, &frame, sizeof(struct can_frame));
    printf("Wrote %d bytes\n", nbytes);
};

inline void MotorFunctions::rotate(int speed, int dir) {
    frame.can_id  = 0x141;
    frame.can_dlc = 8;
    frame.data[0] = 0xA2;
    frame.data[1] = 0x00;
    frame.data[2] = 0x00;
    frame.data[3] = 0x00;
    // frame.data[4] = 0x10;
    // frame.data[5] = 0x27;
    // frame.data[6] = 0x00;
    // frame.data[7] = 0x00;
    

    // speed data
    speed = dir ? -speed : speed;

    if (speed > 16777216) {
        frame.data[7] = speed % 16777216;
        speed = speed - frame.data[7];
    } else {
        frame.data[7] = 0x00;
    }

    if (speed > 65536) {
        frame.data[6] = speed % 65536;
        speed = speed - frame.data[6];
    } else {
        frame.data[6] = 0x00;
    }

    if (speed > 256) {
        frame.data[5] = speed % 256;
        speed = speed - frame.data[6];
    } else {
        frame.data[5] = 0x00;
    }

    frame.data[4] = speed;

    printf("\n%d %d %d %d %d %d %d %d\n", frame.data[0], frame.data[1], frame.data[2], frame.data[3], frame.data[4], frame.data[5], frame.data[6], frame.data[7]);

    // frame.data[0] = 0xA2;
    // frame.data[1] = 0x00;
    // frame.data[2] = 0x00;
    // frame.data[3] = 0x00;
    // frame.data[4] = 0x10;
    // frame.data[5] = 0x27;
    // frame.data[6] = 0x00;
    // frame.data[7] = 0x00;

    nbytes = write(s, &frame, sizeof(struct can_frame));
    printf("Wrote %d bytes\n", nbytes);
}