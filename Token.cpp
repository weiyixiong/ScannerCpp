/*
 * Token.cpp
 *
 *  Created on: 2015��9��3��
 *      Author: winney
 */

#include "Token.h"
namespace Scannerlib {

Token::Token(Type type, const char* value) {
	_type = type;
	_value = value;
}

Token::~Token() {
//	delete _value;
}

} /* namespace Scanner */
