#include "main.h"
#define DELAY_COUNT 1000000

void delay (unsigned int ii) {
    unsigned int jj;
    for(jj = ii; jj > 0; jj--)
        asm("nop");
}

int main(void)
{
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();
  // I/O port C and A clock enable
  RCC->APB2ENR = RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPAEN;

  // Set PC_13 to output
  GPIOC->CRH &= ~(GPIO_CRH_MODE13 | GPIO_CRH_CNF13);
  GPIOC->CRH |= GPIO_CRH_MODE13;

  while (1)
  {
    /* USER CODE END WHILE */
    GPIOC->BRR |= 1<<13;
    delay(DELAY_COUNT);
    GPIOC->BSRR |= 1<<13;
    delay(DELAY_COUNT);
  }
}

void Error_Handler(void)
{
}
