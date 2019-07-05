

#include "em_device.h"
#include <stdint.h>
#include "em_chip.h"
#include "em_cmu.h"
#include "bsp.h"

static volatile uint32_t msTick; /* counts 1ms timeTicks */

static void Delay(uint32_t dlyTicks);

/***************************************************************************//**
 * @brief SysTick_Handler
 * Interrupt Service Routine for system tick counter
 ******************************************************************************/
void SysTick_Handler(void)
{
  msTick++;       /* increment counter necessary in Delay()*/
}


/***************************************************************************//**
 * @brief  Main function
 ******************************************************************************/
int main(void)
{

  /* Chip errata */
  CHIP_Init();

  /* Setup SysTick Timer for 1 msec interrupts  */
  if (SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000)) {
    while (1) ;
  }

  /* Initialize LED driver */
  BSP_LedsInit();








}
