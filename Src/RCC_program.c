/*********************************/
/**
 * Author   :   Mohamed Elesaily
 * Version  :   V01
 * Date     :   8/8/2020
*/


/*********************************/
#include "STD_TYPES.h"
#include  "BIT_MATH.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void){
    #if     RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
            RCC_CR = 0X00010000;/*ENABLE HSE WITH no BYPASS*/
            RCC_CFGR = 0x00000001;
    #elif   RCC_CLOCK_TYPE == RCC_HSE_RC
            RCC_CR = 0X00050000;/*Enable HSE with bypass*/
            RCC_CFGR = 0x00000001;
    #elif   RCC_CLOCK_TYPE == RCC_HSI
            RCC_CR = 0X00000081;/*Enable HSI + trimming = 0*/
            RCC_CFGR = 0x00000000;
    #elif   RCC_CLOCK_TYPE == RCC_PLL
        #if RCC_PLL_INPUT ==  RCC_PLL_IN_HSI_DIV_2
            RCC_CFGR = 0x00000000;
            RCC_CFGR = (RCC_PLL_MUL_VAL << 18)+0x00000002;
            RCC_CR = 0x01000081;

            
        #elif RCC_PLL_INPUT ==  RCC_PLL_IN_HSE_DIV_2
            #if RCC_PLL_IN_HSE_TYPE == RCC_HSE_CRYSTAL /* HSE crystal input for PLL */
            RCC_CFGR = 0x00000000;
            RCC_CFGR = (RCC_PLL_MUL_VAL << 18)+0x00030002;
            RCC_CR = 0x01010000;
            #elif RCC_PLL_IN_HSE_TYPE == RCC_HSE_RC
            RCC_CFGR = 0x00000000;
            RCC_CFGR = (RCC_PLL_MUL_VAL << 18)+0x00030002;
            RCC_CR = 0x01050000;
            #endif

            
	#elif RCC_PLL_INPUT ==  RCC_PLL_IN_HSE
			#if RCC_PLL_IN_HSE_TYPE == RCC_HSE_CRYSTAL /* HSE crystal input for PLL */
			RCC_CFGR = 0x00000000;
			RCC_CFGR = (RCC_PLL_MUL_VAL << 18)+0x00010002;
			RCC_CR = 0x01010000;
			#elif RCC_PLL_IN_HSE_TYPE == RCC_HSE_RC
			RCC_CFGR = 0x00000000;
			RCC_CFGR = (RCC_PLL_MUL_VAL << 18)+0x00010002;
			RCC_CR = 0x01050000;
			#endif

	#endif
    #else
        // #error("wrong clock type")
#endif
   
}
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId){
    if( Copy_u8PerId <= 31)
    {
        switch (Copy_u8BusId)
        {
            case RCC_AHB    : SET_BIT(RCC_AHBENR, Copy_u8PerId);break;
            case RCC_APB1   : SET_BIT(RCC_APB1ENR, Copy_u8PerId);break;
            case RCC_APB2   : SET_BIT(RCC_APB2ENR, Copy_u8PerId);break;
            // default         :/*Return Error*/
        }
    }
    else
    {
        /* return error*/
    }
    
}
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId){
	  if( Copy_u8PerId <= 31)
	    {
	        switch (Copy_u8BusId)
	        {
	            case RCC_AHB    : CLR_BIT(RCC_AHBENR, Copy_u8PerId);break;
	            case RCC_APB1   : CLR_BIT(RCC_APB1ENR, Copy_u8PerId);break;
	            case RCC_APB2   : CLR_BIT(RCC_APB2ENR, Copy_u8PerId);break;
	            // default         :/*Return Error*/
	        }
	    }
	    else
	    {
	        /* return error*/
	    }

}
