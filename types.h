#ifndef TYPES_H
#define	TYPES_H

#include <xc.h>

#define MAX_STACK 32
#define MAX_TASKS 4
#define GLOBAL_INTERRUPTS_ENABLE() INTCONbits.GIE = 1
#define GLOBAL_INTERRUPTS_DISABLE() INTCONbits.GIE = 0
#define TASK void

typedef unsigned u_int;
typedef void (*f_ptr)(void);


// Armazena os dados das tarefas
typedef struct pcb {
    u_int task_id;
    f_ptr task_ptr;
    u_int task_stack[MAX_STACK];
    int task_stack_size;
} pcb_t;


#endif	/* TYPES_H */

