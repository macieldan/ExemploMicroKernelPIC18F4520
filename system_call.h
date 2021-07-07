#ifndef SYSTEM_CALL_H
#define SYSTEM_CALL_H

#include "types.h"

u_int rr_scheduler();


#define SAVE_CONTEXT() \
do { \
    GLOBAL_INTERRUPTS_DISABLE(); \
    


    GLOBAL_INTERRUPTS_ENABLE(); \
 
} while (0)\
    
#define RESTORE_CONTEXT() \
do { \
    GLOBAL_INTERRUPTS_ENABLE(); \
} while (0)\