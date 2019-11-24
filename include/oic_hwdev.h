/***************************************
*		File     : oic_hwdev.h
*		Author   : Ganesh Gudigara
*	        Desc     : hardware device definitiaon 
			  
	E-mail : ganesh@nirmitsu.com
*
************************************************************/


#ifndef _OIC_HWDEV_H_
#define _OIC_HWDEV_H_



#define MAX_DEV_NAME   40
#define MAX_RX_BUF     256
#define MAX_TX_BUF     256


enum {
	OIC_DEVICE_SENSOR_ALTIMETER,
	OIC_DEVICE_SENSOR_IMU,
	OIC_DEVICE_GPS,
	OIC_DEVICE_WIRELESS,
	OIC_DEVICE_SERVO1,
	OIC_DEVICE_SERVO2,
	OIC_DEVICE_SERVO3,
	OIC_DEVICE_MOTOR,
	OIC_DEVICE_CAM1,
	OIC_DEVICE_CAM2,
	OIC_DEVICE_AP_BATMOaN,
	OIC_DEVICE_MOTOR_BATMOaN,
	OIC_DEVICE_LED,
	MAX_OIC_HWDEVICES
   };



struct oic_hwdev;
typedef struct oic_hwdev
  {
	int devid;
	 char name[MAX_DEV_NAME];
	int fd;
	int flags;
	int min_len;
	char rxbuf[MAX_RX_BUF];
	char txbuf[MAX_TX_BUF];
	int (*init)(struct oic_hwdev *hw_dev);
	int (*close)(struct oic_hwdev *hw_dev);
	int (*configure)(struct oic_hwdev *hw_dev, void *userdata, int  len);
	int (*process_data)(struct oic_hwdev *hw_dev, char *buf, int   len);
	int (*send_data)(struct oic_hwdev *hwdev, char *buf, int len);

	int (*get_result)(struct oic_hwdev *hwdev, void *data, int len);
	int (*verify_read)(struct oic_hwdev *hwdev, char *buf, int len, int status);
	int (*verify_write)(struct oic_hwdev *hwdev, char *buf, int len, int status);

  }oic_hwdev_t;


int oic_open_hwdev(struct oic_hwdev *hwdev);
int oic_read_hwdev(struct oic_hwdev *hwdev, unsigned char *buf, int len);

int oic_write_hwdev(struct oic_hwdev *hwdev, unsigned char *buf, int len);

void oic_close_hwdev(struct oic_hwdev *hwdev);

int oic_poll_dev(struct oic_hwdev *hwdev);

int oic_ioctl_hwdev(struct oic_hwdev *hwdev, unsigned int cmd, void      *data);

#endif
