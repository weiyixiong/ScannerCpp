/*
 * Token.h
 *
 *  Created on: 2015��9��3��
 *      Author: winney
 */

#include "Tag.h"
#include <string>
#ifndef TOKEN_H_
#define TOKEN_H_
namespace Scannerlib {

class Token {
public:
	Token(Type type, const char* value);
	virtual ~Token();
public:
	Type _type;
	const char* _value;
};

}
/* namespace Scanner */

#endif /* TOKEN_H_ */
