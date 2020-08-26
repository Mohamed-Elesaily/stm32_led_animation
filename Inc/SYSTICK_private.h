#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

#define SYSTICK_ADDRESS 0xE000E010

#define SYSTICK_STK_CTRL *((volatile u32 *)(SYSTICK_ADDRESS + 0X00))
#define SYSTICK_STK_LOAD *((volatile u32 *)(SYSTICK_ADDRESS + 0X04))
#define SYSTICK_STK_VAL *((volatile u32 *)(SYSTICK_ADDRESS + 0X08))
#define SYSTICK_CALIB *((volatile u32 *)(SYSTICK_ADDRESS + 0X0C))


#define STK_AHB_DIV_8 0
#define STK_AHB 1

#define STK_DISABLE 0
#define STK_ENABLE 1
#endif