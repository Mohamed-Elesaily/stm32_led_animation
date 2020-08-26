#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR, PIN) (VAR |= 1 << PIN)
#define CLR_BIT(VAR, PIN) (VAR &= ~(1 << PIN))
#define GET_BIT(VAR, PIN) (1 & (VAR >> PIN))
#define TOG_BIT(VAR, PIN) (VAR ^= (1<<PIN) )

#define SET_VALUE(VAR,START,VALUE) (VAR |= (VALUE<<START))
#define CLR_REG(VAR) (VAR = 0x00000000)
#endif