/***************************************
*		File     : oic_time.h
*		Author   : Ganesh Gudigara
*	        Desc     : hardware device definitiaon 
			  
	E-mail : ganesh@nirmitsu.com
*
************************************************************/


#ifndef _OIC_TIME_H_
#define _OIC_TIME_H_


  #ifdef _LINUX_
   typedef oic_time_t struct timeval;
#else
	typedef struct oic_time
	{
		uint64_t us;
		uint8_t seconds;
		uint8_t  minutes;
		uint8_t  hours;
		uint8_t  days;
		
	} oic_time_t;
#endif

#endif

