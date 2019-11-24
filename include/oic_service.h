/***************************************
*		File     : oic_height.h
*		Author   : Ganesh Gudigara
*	        Desc     : hardware device definitiaon 
			  
	E-mail : ganesh@nirmitsu.com
*
************************************************************/


#ifndef _OIC_SERVICE_H_
#define _OIC_SERVICE_H_
#include <oic_types.h>
enum {
	OIC_READ_MODE = 0x4,
	OIC_SENSOR1_READ = 0x8,
	OIC_SENSOR2_READ = 0x10
     };


int
oic_check_sensor_data (int fd1, int fd2, unsigned long miliseconds);
#endif
