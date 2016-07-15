#include "car.h"
#include <dlfcn.h>
#include <stdlib.h>
 
struct Car *car;
 
struct Car *register_module(char *module_name)
{
	struct Car *(*get_module)();
	void *handle;
 
	handle = dlopen(module_name, RTLD_LAZY);
	if (!handle) {
		return NULL;
	}
 
	get_module = dlsym(handle, "get_module");
	if (dlerror() != NULL) {
		dlclose(handle);
		return NULL;
	}

 
	//dlclose(handle);
	return get_module(); 
}
 
int main(int argc, char *argv[])
{
	struct Car *car;
 
	if ((car = register_module("./libcar.so")) == NULL) {
    	printf("abbbb\n");
		return -1;
	}
 
    printf("aabb\n");
	car->start();
	car->stop();
 
	return 0;
}
