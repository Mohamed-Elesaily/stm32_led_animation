#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"SYSTICK_private.h"
#include"SYSTICK_config.h"
#include"SYSTICK_interface.h"
void STK_voidInit(void){
    #if SYSTICK_CLOCK_SOURCE == STK_AHB_DIV_8
        CLR_BIT( SYSTICK_STK_CTRL,2);
    #elif  SYSTICK_CLOCK_SOURCE == STK_AHB
        SET_BIT( SYSTICK_STK_CTRL,2);
    #endif 

    #if SYSTICK_ENABLE_INT == STK_DISABLE
        CLR_BIT( SYSTICK_STK_CTRL,1);
    #elif  SYSTICK_ENABLE_INT == STK_ENABLE
        SET_BIT( SYSTICK_STK_CTRL,1);
    #endif      
}
void STK_voidDelay(u32 Copy_Delay_ms){
    #if SYSTICK_CLOCK_SOURCE == STK_AHB_DIV_8
        SYSTICK_STK_LOAD = 1000 * Copy_Delay_ms;
    #elif  SYSTICK_CLOCK_SOURCE == STK_AHB
        SYSTICK_STK_LOAD = (1000 * Copy_Delay_ms) * 8;
    #endif 
    SET_BIT(SYSTICK_STK_CTRL,0);
    while(GET_BIT(SYSTICK_STK_CTRL,16) == 0);
}
