/****************************************
 *		File   : oic_devshare.h
 *		Author : Ganesh Gudigara
 *		Desc   : device share library
 *			  interfaces
 *
 *	copyright NammaOS Team 
 *
 **********************************************/
#ifndef _OIC_DEVSHARE_H_
#define _OIC_DEVSHARE_H_


struct element_ist;

struct element_list
 {
	struct element_list *next;
	struct element_list *prev;
};

struct oic_shared_segment
{
	int shmid;
	unsigned int size;
	key_t key;
	char *ahared_buf;
	int semid;
	struct element_list list;
};
#endif
