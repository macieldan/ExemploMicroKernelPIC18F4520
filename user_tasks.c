#include "user_tasks.h"
#include <xc.h>

void config_user_tasks()
{
   TRISDbits.RD0 = 0;
   TRISDbits.RD1 = 0;
   TRISDbits.RD2 = 0;
}

TASK t1()
{
   while (1) {
      LATDbits.LATD0 = ~PORTDbits.RD0;
   }
}

TASK t2()
{
   while (1) {
      LATDbits.LATD1 = ~PORTDbits.RD1;
   }   
}

TASK t3()
{
   while (1) {
      LATDbits.LATD2 = ~PORTDbits.RD2;
   }   
}
