/*
 * Parser.h
 *
 *  Created on: 2015��9��4��
 *      Author: winney
 */
#include "Token.h"
#include "Scanner.h"
#include <iostream>
#include <vector>
#ifndef PARSER_H_
#define PARSER_H_

namespace Scannerlib {

class Parser {
public:
	Parser();
	virtual ~Parser();
	vector<Token*> *parseHTML(const char *code);
	void peek();
	Token *peekButOne();
	void read();
	void deleteToken();
	void readNext(bool isDelete);
	bool peek(Type type);
	bool read(Type type);
private:
	Token *_nextToken;
	Token *_nextButOneToken;
	Scanner *_scanner;
};

} /* namespace Scanner */

#endif /* PARSER_H_ */
