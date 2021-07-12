#include "system_call.h"

extern int vez;
extern int tasks_installed;

u_int rr_scheduler()
{
   vez = (vez + 1) % tasks_installed;
   return vez;
}

void __interrupt() ISR_timer()
{
   SAVE_CONTEXT();   
   vez = rr_scheduler();
   RESTORE_CONTEXT();
   TMR0L = 0;
   INTCONbits.TMR0IF = 0;   
}

void config_timer()
{
   // Configuração dos registradores responsáveis pelo timer0
   INTCONbits.PEIE      = 1;    // Habilita a interrupção por periférico
   INTCONbits.TMR0IE    = 1;  // Habilita o timer0
   INTCONbits.TMR0IF    = 0;  // Seta o flag de timer0 em 0
   T0CONbits.PSA        = 0;      // Habilita o uso do preescaler
   T0CONbits.T0PS       = 0b010; // Seta o preescaler em 1:4
   T0CONbits.T0CS       = 0;     // Seta a referência do timer (clock interno)
   TMR0L                = 0;
}

void start_kernel()
{
   GLOBAL_INTERRUPTS_ENABLE();
   T0CONbits.TMR0ON;       // Ativa o timer      
}
