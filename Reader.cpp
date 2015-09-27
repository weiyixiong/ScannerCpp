/*
 * Reader.cpp
 *
 *  Created on: 2015��9��4��
 *      Author: winney
 */

#include "Reader.h"

namespace Scannerlib {

Reader::Reader(const char *code) {
	_code=code;
}

Reader::~Reader() {
//	delete _code;
}

char Reader::read(){
	return *(_code++);
}

 
} /* namespace Scanner */
