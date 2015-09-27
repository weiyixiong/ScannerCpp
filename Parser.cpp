/*
 * Parser.cpp
 *
 *  Created on: 2015��9��4��
 *      Author: winney
 */

#include "Parser.h"

namespace Scannerlib {

Parser::Parser() {
	_nextToken = NULL;
}
vector<Token*> *Parser::parseHTML(const char *code) {
	_scanner = new Scanner(code);
	vector<Token*> *result = new vector<Token*>();
//	for (int i = 0; i < 100; i++) {
//		Token *t = _scanner->produce();
//		if (t->_type == COMPLETE) {
//			cout << "end" << endl;
//			break;
//		} else {
//			cout << tt->_type  << endl;
//		}
//		delete tt;
//		result->push_back(t);
//	}
	for (;;) {
		read();
		switch (_nextToken->_type) {
		case LT:
			break;
		case SL:
			read();
			break;
		case IMG:
			while (!read(SRC)) {
			}
			if (read(EQ)) {
				read();
				result->push_back(_nextToken);
			}
			break;
		case STRONG:
			while (!read(TEXT)) {
			}
			_nextToken->_type = STRONG;
			result->push_back(_nextToken);
			break;
		case A:
			while (!read(HREF)) {
			}
			if (read(EQ)) {
				read();
				_nextToken->_type = A;
				result->push_back(_nextToken);
			}
			continue;
		case TEXT:
			result->push_back(_nextToken);
			break;
		case STRING_LITERAL:
			deleteToken();
//			result->push_back(_nextToken);
			break;
		case COMPLETE:
			return result;
			break;
		default:
			deleteToken();
			break;
		}
	}
	return result;
}
void Parser::deleteToken() {
	delete _nextToken;
	_nextToken = NULL;
}
bool Parser::read(Type value) {
	bool result = false;
	read();
	if (_nextToken->_type == value) {
		result = true;
	} else {
		result = false;
	}
	return result;
}
void Parser::read() {
	_nextToken = _scanner->produce();
}
Parser::~Parser() {
	delete _scanner;
	delete _nextToken;
	delete _nextButOneToken;
}

} /* namespace Scanner */
