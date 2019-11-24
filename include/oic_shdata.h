/***************************************
*		File     : oic_shdata.h
*		Author   : Ganesh Gudigara
*	        Desc     : this idefines
*  the shared data across different daemons
   running in the system. This will allow
   the use to create a data of respective
   DATA_ID,
 Copyright NammaOS Team   
	E-mail : ganesh@nirmitsu.com
*
************************************************************/


#ifndef _OIC_SHDATA_H_
#define _OIC_SHDATA_H_

#include "oic_types.h"

enum {
	OIC_SHDATA_SENSOR,
eOIC_SHDATA_GPS,
	OIC_SHDATA_CAM,
	OIC_SHDATA_ME,
	OIC_SHDATA_TX_NETWORK,
	OIC_SHDATA_RX_NETWORK,
	OIC_SHDATA_COMTROLLER,
	OIC_SHDATA_SYSMON,
	OIC_SHDATA_CLI,
	MAX_SHDATA_IDS
};

struct oic_system_data
 {
	int id;
	oic_shared_segment segment[MAX_SHDATA_IDS];
	oic_system_stats stats;
	struct oic_time  uptime;      // timestamp 
	struct oic_time last_connected; // timestamp 
	struct oic_distance away_from_gs; // ground station distance
	struct oic_height last_height; // last height device is at
	struct oic_route route;  // route covered
	struct oic_obstacle ob;   // history of obstacles
	struct oic_direction last_direction; // last direction
	
  };





  struct oic_dev_s
  {
	u8 devid;
	u8 devtype;
	u8 prio;
	u8 seq;
	u8 payload[1];
   }oic_dev_t;



   struct oic_sensor_s
	{
	  u8 sensortype;
	  double high_rage;
	  double low_rage;
	  double calib_err;
	  double estimated_err;
	  double value;
	  u8  units;
}	};

	struct oic_mcontrol_s
	  {
		u8 rate;
		u8 pwm_value;


	};

	struct oic_camdev_s
	 {
		u32 camdevid;
		u32 lat;
		u32 lang;
		u8 data[1];




	};

	
	struct oic_radio_s
	{
		u8 devno;
		u16 crc;
		u8 data_direction;
		char payload[1];


	};
	
	struct oic_motioninfo_s
	{
		u32 lat;
		u32 lang;
		double estimation_value;
		

	};


	
	struct  oic_system_state
	{
		struct oic_dev_s altimeter;
		struct oic_dev_t gps;
		struct oic_dev_t magnetometer;
	 


	};

   char buf[2048[;
	struct oic_system_state *mystate;
	
;	 void init_system_state();
	 get_sensor_data(struct oic_dev_s *dev, oic_sensor_s *sensor);
	 set_ssensor_data(struct oic_sensor_t *sens);
	 set_mcotrol_data(struct oic_mcotrol_s *);
	 set_camdev_data(oic_camdev_s *camdev);
	 get_camdev_data(oic_dev_t *dev, oic_camdev_s *camdev);'


}
	
		
		









