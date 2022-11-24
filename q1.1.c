#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

unsigned long jesse;
struct timespec walter1;
struct timespec walter2;
struct timespec walter3;
struct timespec walter4;
struct timespec walter5;
struct timespec walter6;

void countmeth(){
  unsigned long meth=1;
  for(int i=1;i<=32;i++){
    meth=meth*2;
  }
  jesse=meth;
}

void *countA(void *j){
  unsigned long hank=0;
  clock_gettime(CLOCK_MONOTONIC,&walter1);
  while(hank<jesse){
    hank++;
  }
  clock_gettime(CLOCK_MONOTONIC,&walter2);
  printf("%lf seconds \n", (double)(walter2.tv_sec-walter1.tv_sec) + ((double)(walter2.tv_nsec-walter1.tv_nsec)/1000000000L));
}
void *countB(void *j){
  unsigned long hank=0;
  clock_gettime(CLOCK_MONOTONIC,&walter3);
  while(hank<jesse){
    hank++;
  }
  clock_gettime(CLOCK_MONOTONIC,&walter4);
  printf("%lf seconds \n", (double)(walter4.tv_sec-walter3.tv_sec) + ((double)(walter4.tv_nsec-walter3.tv_nsec)/1000000000L));
}
void *countC(void *j){
  unsigned long hank=0;
  clock_gettime(CLOCK_MONOTONIC,&walter5);
  while(hank<jesse){
    hank++;
  }
  clock_gettime(CLOCK_MONOTONIC,&walter6);
  printf("%lf seconds \n", (double)(walter6.tv_sec-walter5.tv_sec) + ((double)(walter6.tv_nsec-walter5.tv_nsec)/1000000000L));
}
int main (){
  countmeth();
  pthread_t realone;
  pthread_t realtwo;
  pthread_t realthree;
  pthread_attr_t talkone;
  pthread_attr_t talktwo;
  pthread_attr_t talkthree;

  struct sched_param schedparam1;
  struct sched_param schedparam2;

  
  schedparam1.sched_priority = 0;
  
  pthread_attr_init(&talkone);
  pthread_attr_setinheritsched(&talkone, PTHREAD_EXPLICIT_SCHED);
  pthread_attr_setschedpolicy(&talkone, SCHED_OTHER);
  pthread_attr_setschedparam(&talkone, &schedparam1);
  pthread_create(&realone,&talkone,&countA,NULL); 
  
  schedparam2.sched_priority = 69;
  pthread_attr_init(&talktwo);
  pthread_attr_setinheritsched(&talktwo, PTHREAD_EXPLICIT_SCHED);
  pthread_attr_setschedpolicy(&talktwo, SCHED_FIFO);
  pthread_attr_setschedparam(&talktwo, &schedparam2);
  pthread_create(&realtwo,&talktwo,&countB,NULL);

  pthread_attr_init(&talkthree);
  pthread_attr_setinheritsched(&talkthree, PTHREAD_EXPLICIT_SCHED);
  pthread_attr_setschedpolicy(&talkthree, SCHED_RR);
  pthread_attr_setschedparam(&talkthree, &schedparam2);
  pthread_create(&realthree,&talkthree,&countC,NULL);
  
  pthread_join(realone,NULL);
  pthread_join(realtwo,NULL);
  pthread_join(realthree,NULL);
}


