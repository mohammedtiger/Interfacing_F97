/*
 * Standard_types.h
 *
 *  Created on: 19 Apr 2019
 *      Author: root
 */

#ifndef STANDARD_TYPES_H_
#define STANDARD_TYPES_H_


#define F97_SET_BIT(reg,bit) (reg |= (1 << bit))
#define F97_CLEAR_BIT(reg,bit) (reg &= ~(1 << bit))
#define F97_CHECK_BIT(reg,bit) (reg & (1 << bit))


#endif /* STANDARD_TYPES_H_ */
