
#include "cmsis_os.h"                                           // CMSIS RTOS header file

/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 
void Thread (void const *argument);                             // thread function
osThreadId tid_Thread;                                          // thread id
osThreadDef (Thread, osPriorityNormal, 1, 0);                   // thread object

void thread1 (void const *argument); //function prototype for thread1
osThreadId thread1_id; //thread handle
osThreadDef(thread1, osPriorityNormal, 1, 0); //thread definition structure

int Init_Threads (void) {

  tid_Thread = osThreadCreate (osThread(Thread), NULL);
  if (!tid_Thread) return(-1);
  
	uint32_t startupParameter = 0x23; // For now, as example, parameter does nothing
	thread1_id = osThreadCreate(osThread(thread1), &startupParameter); // Note: tutorial mistake fixed here.
  if (!thread1_id) return(-1);

  return(0);
}

void Thread (void const *argument) {

  while (1) {
    ; // Insert thread code here...
    osThreadYield ();                                           // suspend thread
  }
}

void thread1 (void const *argument) {

  while (1) {
    ; // Insert thread code here...
    osThreadYield ();                                           // suspend thread
  }
}