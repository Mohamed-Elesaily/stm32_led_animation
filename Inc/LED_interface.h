/* ************************************************************************** */
/***
 * Author   :   Mohamed Elesaily
 * Date     :   8/15/2020       
 * Version  :   01   
*/
/* ************************************************************************** */
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#define GPIOA 0
#define GPIOB 1
#define GPIOC 2

#define PIN0  0
#define PIN1  1
#define PIN2  2
#define PIN3  3
#define PIN4  4
#define PIN5  5
#define PIN6  6
#define PIN7  7
#define PIN8  8
#define PIN9 9
#define PIN10 10
#define PIN11 11
#define PIN12 12
#define PIN13 13
#define PIN14 14
#define PIN15 15



void LED_on(u8 Copy_GPIO, u8 Copy_PIN);
void LED_of(u8 Copy_GPIO, u8 Copy_PIN);




#endif