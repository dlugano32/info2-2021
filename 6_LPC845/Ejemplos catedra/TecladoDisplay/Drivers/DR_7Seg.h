/*
 * DR_7Seg.h
 *
 *  Created on: 27 sep. 2021
 *      Author: chor
 */

#ifndef DR_7SEG_H_
#define DR_7SEG_H_

#include <DR_GPIO.h>
#include "LPC845.h"

#define	_7SEG_RST	0,18
#define	_7SEG_CLK	0,19
#define	_7SEG_BCDA	0,20
#define	_7SEG_BCDB	0,23
#define	_7SEG_BCDC	0,22
#define	_7SEG_BCDD	0,21

#define IOCON_INDEX_7SEG_RST	IOCON_INDEX_PIO0_18
#define IOCON_INDEX_7SEG_CLK	IOCON_INDEX_PIO0_19
#define IOCON_INDEX_7SEG_BCDA	IOCON_INDEX_PIO0_20
#define IOCON_INDEX_7SEG_BCDB	IOCON_INDEX_PIO0_21
#define IOCON_INDEX_7SEG_BCDC	IOCON_INDEX_PIO0_22
#define IOCON_INDEX_7SEG_BCDD	IOCON_INDEX_PIO0_23

#define	CANT_DIGITOS	6

extern uint8_t display[CANT_DIGITOS];

void Init7Segs(void);
void BarridoDisplay(void);

#endif /* DR_7SEG_H_ */
