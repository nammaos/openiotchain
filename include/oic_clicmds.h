/****************************************
 *		File   : oic_devshare.h
 *		Author : Ganesh Gudigara
 *			  interfaces
 *
 *	copyright Nammaos Team 
 *
 **********************************************/
#ifndef _OPENIOTCHAIN_CND_H_
#define _OPENIOTCHAIN_CND_H_

#define MAX_CHAN_CLIENTS   8


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


enum cmds{
	OIC_CMD_PUBLISHED,
	OIC_CMD_GETDATA,
	OIC_CMD_EMERGENCY,
	OIC_CMD_NOTIFY,
	OIC_CMD_ANALYSE,
	OIC_CMD_SENDDATA,
	MAX_CHAN_CMDS
};

enum {
	OPENIOTCHAIN_CLIENT_MODE,
	OPENIOTCHAIN_SERVER_MODE,
   };


#define MAX_SOCKCHAN_NAME   40

typedef struct oic_sockdata_s
{
	int fd;
	char *tx_buf;
	int tx_len;
	char *rx_buf;
	int rx_len;
	int multicast;
        char channel_name[MAX_SOCKCHAN_NAME];
	int port; // if use inet socket otherwise useless
        unsigned long timeout; // timeout for polling
	int mode;
	int *clients;
	int max_clients;
	int chan_id;
}oic_sockdata;





typedef struct oic_poll
  {
	struct pollfd *fdlist;
	int max_fds;
	int fd_count;
	unsigned long timeout;
        oic_sockdata *socks[MAX_CHAN_CLIENTS];
 }oic_poll_t;
	





struct oic_channel_data
	{
           u8 chan_id;
	   u8 chan_cmd;
	   u16  length;
	   u8  payload[1];
	};

int oic_process_cmd(void *buf, int len);
int oic_verify_packet(void *buf, int len);

int oic_create_channel(oic_sockdata *sockdata);
int oic_destroy_channel(oic_sockdata *sockdata);
int oic_add_listener(oic_poll_t *plist, oic_sockdata *sockdata);
int oic_handle_data(oic_poll_t *plist);

int oic_write_socket_channel(oic_sockdata *sockdata);
int oic_write_client_channel(oic_sockdata *sockdata, int fd);
int oic_read_socket_channel(oic_sockdata *sockdata);
int oic_read_multi_channel(oic_poll_t *plist);


//just for test
struct altimeter_data
  {
	int height;
	int te;
	int temp;
 };


#endif // OPENIOTCHAIN_CMD




