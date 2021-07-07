/*
 * File:   types.c
 * Author: uniti
 *
 * Created on 5 de Julho de 2021, 14:54
 */
#ifndef TYPES_H
#define TYPES_H

#define MAX_STACK 32;

typedef unsigned u_int;
typedef void (*f_ptr)(void);

typedef struct pcb{
   u_int task_id;
   f_ptr task_ptr;
   int task_stack[MAX_STACK];
   int task_
}pcb_t;

#endif 




int main(void) {
   /* Replace with your application code */
   while (1) {
   }
}
