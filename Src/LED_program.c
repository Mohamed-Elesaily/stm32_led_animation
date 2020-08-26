#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"RCC_interface.h"
#include"GPIO_interface.h"

void LED_on(u8 Copy_GPIO, u8 Copy_PIN){
GPIO_voidSetPinDirection(Copy_GPIO,Copy_PIN, OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinValue(Copy_GPIO,Copy_PIN, 1);
}
void LED_of(u8 Copy_GPIO, u8 Copy_PIN){

GPIO_voidSetPinValue(Copy_GPIO,Copy_PIN, 0);
}

