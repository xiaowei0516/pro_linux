#include "car.h"
#include <stdlib.h>

static void start(){
	printf("trunk start\n");
}

static void stop(){
	printf("trunk stop\n");
}

struct Car trunk={
	.start = &start,
	.stop =  &stop,
};


