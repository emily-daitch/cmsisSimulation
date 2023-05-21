/*----------------------------------------------------------------------------
 * CMSIS-RTOS 'main' function template
 *---------------------------------------------------------------------------*/

#define osObjectsPublic                     // define objects in main module
#include "osObjects.h"                      // RTOS object definitions


/*
 * main: initialize and start the system
 */
extern int Init_Threads (void);
osThreadId main_id;

int main (void) {
	
	main_id = osThreadGetId ();
	
  osKernelInitialize ();                    // initialize CMSIS-RTOS

  // initialize peripherals here
	Init_Threads ();
  // create 'thread' functions that start executing,
  // example: tid_name = osThreadCreate (osThread(name), NULL);

  osKernelStart ();                         // start thread execution 
	
	// We have the option to continue to use the main thread
	//while (1) {
		
	//}
	// Otherwise, execution will end as normal.
	// Tutorial suggests using osTerminate, but it does not appear to be standard for CMSIS RTOSv1. Will investigate further.
	// osTerminate(main_id);
}
