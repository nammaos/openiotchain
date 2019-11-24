/*****************************************************************************
 *
 ******************************************************************************/

#ifndef OPENIOTCHAINTHREAD_H
#define OPENIOTCHAINTHREAD_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define MIN_SLEEPTIME 10



  typedef struct oic_thread_s
  {
    unsigned long timeout;
    int run;	
    int scan;
    pthread_t thr_id;
    void *(*func) (void *);
    void *data;
    int thr_type;
    void (*notifyblock) (int event, void *obj);
  } oic_thread_t;


#ifdef __cplusplus
}
#endif

int oic_create_thread (oic_thread_t *);
int oic_manage_thread (oic_thread_t *);
void oic_stop_thread (oic_thread_t *);


#endif /*OPENIOTCHAINTHREAD_H */
