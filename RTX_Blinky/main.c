/*----------------------------------------------------------------------------
 * CMSIS-RTOS 'main' function template
 *---------------------------------------------------------------------------*/

#define osObjectsPublic                     // define objects in main module
#include "osObjects.h"                      // RTOS object definitions


/*
 * main: initialize and start the system
 */
extern int Init_Thread (void);
osThreadId main_id;

int main (void) {
  osKernelInitialize ();                    // initialize CMSIS-RTOS

  // initialize peripherals here

  // create 'thread' functions that start executing,
  // example: tid_name = osThreadCreate (osThread(name), NULL);
	Init_Thread (); //Add this line

  osKernelStart ();                         // start thread execution 
	
	main_id = osThreadGetId ();

	while(1)
	{
		//Could use main thread as a thread also
	}
}
