#ifndef TYPES_H
#define TYPES_H

#define MAX_STACK 32;
#define GLOBAL_INTERRUPTS_ENABLE() INTCONbits.GIE = 1 
#define GLOBAL_INTERRUPTS_DISABLE() INTCONbits.GIE = 0

typedef unsigned u_int;
typedef void (*f_ptr)(void);

typedef struct pcb{
   u_int task_id;
   f_ptr task_ptr;
   int task_stack[MAX_STACK];
   int task_
}pcb_t;

#endif 
