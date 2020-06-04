#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <cstdlib>

// Define the function to be called when ctrl-c (SIGINT) signal is sent to process

static bool keepRunning = true;

static void signal_callback_handler(int signum)
{
   (void)signum;
   printf("Caught signal %d\n",signum);
   keepRunning = false;
   exit(1);
}

int main()
{
   signal(SIGINT, signal_callback_handler);
   int count = 0; 
    
   while(keepRunning)
   {
    count ++;
    printf("Program processing stuff here.  %d\n", count);     
   }
   return EXIT_SUCCESS;
}
