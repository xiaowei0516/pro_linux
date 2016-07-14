#include "car.h"
extern struct Car  trunk;
extern struct Car  bicycle;

struct Car *car;

struct Car  *register_module(struct Car *module){
	car = module;
}
int main(){
	car = register_module(&bicycle);
	car->start();
    car->stop();
/*	
	car = register_module(&bicycle);
	car->start();
    car->stop();*/
	return 0;
}
