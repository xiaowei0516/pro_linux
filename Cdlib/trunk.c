#include <stdlib.h>
#include <stdio.h>
#include "car.h"
 
static void start()
{
	printf("trunk, start\n");
}
 
static void stop()
{
	printf("trunk, stopped\n");
}
 
struct Car module = {
	.start = &start,
	.stop = &stop,
};
 
struct Car *get_module()
{
	return &module;
}
