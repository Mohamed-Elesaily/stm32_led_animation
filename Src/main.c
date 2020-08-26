#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"RCC_interface.h"
#include"GPIO_interface.h"
#include"LED_interface.h"
#include"SYSTICK_interface.h"
void step1(void);
void step2(void);
void step3(void);
int main(void)
{

	RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_APB2, 2);
	STK_voidInit();


	while(1){
step1();
STK_voidDelay(200);
step2();
STK_voidDelay(200);
step3();
STK_voidDelay(200);

	}
}
void step1(void){
	for(int i =0;i<4;i++){
		for(int j =0;j<8;j++){
				LED_on(GPIOA, j);
				STK_voidDelay(200);
				LED_of(GPIOA, j);
				STK_voidDelay(200);
			}
				STK_voidDelay(200);
		for(int j =7;j>=0;j--){
						LED_on(GPIOA, j);
						STK_voidDelay(200);
						LED_of(GPIOA, j);
						STK_voidDelay(200);
					}
	}
}
void step2(void){
	for(int i =0;i<4;i++){
			for(int j =0;j<4;j++){
					LED_on(GPIOA, 3 + j);
					LED_on(GPIOA, 3-j);
					STK_voidDelay(200);
					LED_of(GPIOA, 3 + j);
					LED_of(GPIOA, 3-j);
					STK_voidDelay(200);
				}
					STK_voidDelay(200);
				for(int j =4;j>=0;j--){
					LED_on(GPIOA, 3 + j);
					LED_on(GPIOA, 4-j);
					STK_voidDelay(200);
					LED_on(GPIOA, 3 + j);
					LED_on(GPIOA, 4-j);
					STK_voidDelay(200);
					}
				STK_voidDelay(200);

		}
}
void step3(void){

	for(int i =0;i<4;i++){
			LED_on(GPIOA, PIN0);
			LED_on(GPIOA, PIN1);
			LED_on(GPIOA, PIN2);
			LED_on(GPIOA, PIN3);

			LED_on(GPIOA, PIN4);
			LED_on(GPIOA, PIN5);
			LED_on(GPIOA, PIN6);
			LED_on(GPIOA, PIN7);
			STK_voidDelay(200);

			LED_of(GPIOA, PIN0);
			LED_of(GPIOA, PIN1);
			LED_of(GPIOA, PIN2);
			LED_of(GPIOA, PIN3);

			LED_of(GPIOA, PIN4);
			LED_of(GPIOA, PIN5);
			LED_of(GPIOA, PIN6);
			LED_of(GPIOA, PIN7);
			STK_voidDelay(200);
		}
}

