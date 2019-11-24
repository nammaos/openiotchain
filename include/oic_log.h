/***************************************
*		File     : oic_height.h
*		Author   : Ganesh Gudigara
*	        Desc     : hardware device definitiaon 
			  
	E-mail : ganesh@nirmitsu.com
*
************************************************************/


#ifndef _OIC_LOG_H_
#define _OIC_LOG_H_
#include <inttypes.h>
#include <stdio.h>
#define LOGFILE "oic.log"
#define LOG_INFO  	2
#define LOG_WARNING 4
#define LOG_ERR     8
#define LOG_CRIT    16
#define STDERR  32    
#define HOSTNAME_LEN 200

#ifdef CONFIG_USE_LOGFILE
int openlogfile(char *filename,int prio,int facility);
void closelogfile(void);
void log_errors(int prio,const char *s);
void create_log(int prio,char *fmt,char *file,char *func,int line,...);
#endif


#ifdef CONFIG_USE_LOGFILE
#define log_print(prio,fmt,args...) create_log(prio,fmt,__FILE__,__FUNCTION__,__LINE__,##args) 
#else
#define open_log(name, level) openlog(name, 0, 0)
#include <syslog.h>
#define log_print(prio,fmt,args...) syslog(prio,fmt,##args)
#endif
#define STDPRINT(fmt,args...) fprintf(stderr,fmt,##args)
#endif /*_NULOG_H */
 
