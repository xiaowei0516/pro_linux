#ifndef __CAR_H
#define __CAR_H


#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif


struct Car{
	void (*start)();
	void (*stop)();
};




#ifdef __cplusplus
}
#endif



#endif
