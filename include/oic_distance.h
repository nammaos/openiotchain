/***************************************
*		File     : oic_distance.h
*		Author   : Ganesh Gudigara
*	        Desc     : hardware device definitiaon 
			  
	E-mail : ganesh@nirmitsu.com
*
************************************************************/


#ifndef _OIC_DISTANCE_H_
#define _OIC_DISTANCE_H_


typedef struct oic_distance
{
	float d_in_mm;
	float d_in_meters;
	float d_in_km;
	double lat;
	double lang;
		
} oic_distance_t;

#endif

