
#ifndef BitOperator_H_
#define	BitOperator_H_

/*This is used to get bit value in register as true or false*/
#define GET_BIT(REG , BIT)     REG & (1 << BIT)

/*This is used to set bit value in register to 1 */
#define SET_BIT(REG , BIT)     REG |= (1 << BIT)

/*This is used to toggle bit value in register (0 become 1 and 1 become 0) */
#define TOGGLE_BIT(REG , BIT)  REG ^= (1 << BIT)

/*This is used to clear bit value in register to 0*/
#define CLEAR_BIT(REG , BIT)   REG &= ~(1 << BIT)



#endif	/* BitOperator_H_ */

