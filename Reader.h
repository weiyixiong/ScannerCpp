/*
 * Reader.h
 *
 *  Created on: 2015��9��4��
 *      Author: winney
 */
#include <string>
#ifndef READER_H_
#define READER_H_
namespace Scannerlib {

class Reader {
public:
	Reader(const char *code);
	char read();
	virtual ~Reader(); 
public:
	const char *_code;
};

} /* namespace Scanner */

#endif /* READER_H_ */
