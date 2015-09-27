/*
 * Scanner.h
 *
 *  Created on: 2015��9��3��
 *      Author: winney
 */

#include "Token.h"
#include "Reader.h"
#include <stdio.h>
#include <windows.h>
#include <map>
#ifndef SCANNER_H_
#define SCANNER_H_
using namespace std;
namespace Scannerlib {

class Scanner {
public:
	Scanner(const char *code);
	virtual ~Scanner();
	void ConvertUtf8ToGBK(const char *strUtf8);
	void readNextChar();
	Token* produce();
	bool isChar(char target);

public:
	char _nextChar;
	Reader *read;
	std::map<std::string, int> keywords;
};

} /* namespace Scanner */

#endif /* SCANNER_H_ */
