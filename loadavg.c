/* Simple C program to check load average and sleep 
 * for random interval between 5 and 15 minutes
 * 
 * comple: gcc loadavg.c -o loadavg
 * run like so: loadavg && something_else
 */

#define _BSD_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>


main() 
{

   double load[3];  
   if (getloadavg(load, 3) == -1){
     exit(1);
   }

  if (load[0] > 10){
    int p;
    p = getpid();
    srand(time(NULL)+p);
    int y;
    y = 60 + (int) (1000.0 * (rand() / (RAND_MAX + 1.0)));

    sleep(y);

    if (getloadavg(load, 3) == -1){
      exit(1);
    }
  } 

  if (load[0] > 10){
    exit(1);
  }

  exit(0);

}

