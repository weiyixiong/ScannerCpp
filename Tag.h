/*
 * Tag.h
 *
 *  Created on: 2015Äê9ÔÂ3ÈÕ
 *      Author: winney
 */

#ifndef TAG_H_
#define TAG_H_

enum Type {
	P = 256,
	IMG = P + 1,
	SPAN = P + 2,
	BR = P + 3,
	STRONG = P + 4,
	EM = P + 5,
	LT = P + 6,
	GT = P + 7,
	SL = P + 8,
	END = P + 9,
	EQ = P + 10,
	STYLE = P + 11,
	STRING_LITERAL = P + 12,
	SPACE = P + 13,
	TEXT = P + 14,
	SRC = P + 15,
	A = P + 16,
	HREF = P + 17,
	COMPLETE = P + 99,
	UNKNOW = P + 100
};

#endif /* TAG_H_ */
