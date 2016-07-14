#include "car.h"
#include <stdlib.h>

static void start(){
	printf("bicycle start\n");
}

static void stop(){
	printf("bicycle stop\n");
}

struct Car bicycle={
	.start = &start,
	.stop =  &stop,
};


