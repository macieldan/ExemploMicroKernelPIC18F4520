#ifndef SYSTEM_CALL_H
#define	SYSTEM_CALL_H

#include "types.h"

extern pcb_t FILA_TAREFAS[MAX_TASKS];

u_int rr_scheduler();
void config_timer();
void start_kernel();
void __interrupt() ISR_timer();


#define SAVE_CONTEXT() \
do { \
    GLOBAL_INTERRUPTS_DISABLE(); \
    if (vez != -1) { \
      FILA_TAREFAS[vez].task_stack_size = 0; \
      while (STKPTR) { \
        FILA_TAREFAS[vez].task_stack[FILA_TAREFAS[vez].task_stack_size] = TOS; \
        FILA_TAREFAS[vez].task_stack_size++; \
        asm("POP"); \
      } \
    } \
    GLOBAL_INTERRUPTS_ENABLE(); \
} while (0) \


#define RESTORE_CONTEXT() \
do { \
    GLOBAL_INTERRUPTS_DISABLE(); \
    STKPTR = 0; \
    if (FILA_TAREFAS[vez].task_stack_size) { \
      do { \
        asm("PUSH"); \
        TOS = FILA_TAREFAS[vez].task_stack[FILA_TAREFAS[vez].task_stack_size]; \
        FILA_TAREFAS[vez].task_stack_size--; \
      } while (FILA_TAREFAS[vez].task_stack_size); \
    } \
    else { \
        asm("PUSH"); \
        TOS = FILA_TAREFAS[vez].task_ptr; \
    } \
    GLOBAL_INTERRUPTS_ENABLE(); \
} while (0) \
    

#endif	/* SYSTEM_CALL_H */

