#include "sys_cfg_stm32f407.h"
#include "stm32f4xx.h"

extern volatile uint32_t SYS_TickCounter;

void SysTick_Handler(void) {
  SYS_TickCounter ++;
}




void NMI_Handler(void)
{

}


void HardFault_Handler(void)
{

  while (1)
  {
  }

}


void MemManage_Handler(void)
{

  while (1)
  {
  }

}


void BusFault_Handler(void)
{

  while (1)
  {
  }

}


void UsageFault_Handler(void)
{

  while (1)
  {
  }

}

void SVC_Handler(void)
{

}

void DebugMon_Handler(void)
{

}

void PendSV_Handler(void)
{

}
