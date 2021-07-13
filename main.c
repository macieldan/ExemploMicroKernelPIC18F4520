/**
 * Exemplo do dia 05/07.
 * Manipulação da pilha do microcontrolador
 */

#include <xc.h>
#include "types.h"
#include "user_tasks.h"
#include "system_call.h"

#pragma config WDT = OFF 

pcb_t FILA_TAREFAS[MAX_TASKS];
int vez = -1;
int tasks_installed = 0;


int main()
{
   
   config_user_tasks();
   
   // Instalar as tarefas de usuário
   FILA_TAREFAS[tasks_installed].task_id           = 1;
   FILA_TAREFAS[tasks_installed].task_ptr          = t1;
   FILA_TAREFAS[tasks_installed].task_stack_size   = 0;
   tasks_installed++;

   FILA_TAREFAS[tasks_installed].task_id           = 2;
   FILA_TAREFAS[tasks_installed].task_ptr          = t2;
   FILA_TAREFAS[tasks_installed].task_stack_size   = 0;
   tasks_installed++;
   
   FILA_TAREFAS[tasks_installed].task_id           = 3;
   FILA_TAREFAS[tasks_installed].task_ptr          = t3;
   FILA_TAREFAS[tasks_installed].task_stack_size   = 0;
   tasks_installed++;
   
   config_timer();
   start_kernel();
   
   while (1) {
      
   }
   
   return 0;
}
