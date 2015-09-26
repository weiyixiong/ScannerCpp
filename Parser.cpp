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
	for (int i = 0; i < 100; i++) {
		Token *t = _scanner->produce();
		if (t->_type == COMPLETE) {
			cout << "end" << endl;
			break;
		} else {
//			cout << tt->_type  << endl;
		}
//		delete tt;
		result->push_back(t);
	}
//	for (;;) {
//		read();
////		cout << _nextToken->_type << endl;
//		result->push_back(_nextToken);
//		if (_nextToken->_type == COMPLETE) {
//			return result;
//		}
//	}
//		switch (_nextToken->_type) {
//		case TEXT:
////			result->push_back(_nextToken);
//			continue;
//			break;
//		case STRING_LITERAL:
//			break;
//		case COMPLETE:
//			cout << "asdf" << endl;
//			return result;
//			break;
//		default:
//			break;
//		}
//	}
//	for (;;) {
//		read();
//		switch (_nextToken->_type) {
//		case LT: {
//			if (peek(SL)) {
//				continue;
//			}
//			read();
//			switch (_nextToken->_type) {
//			case IMG: {
//				while (!read(SRC)) {
//					//cout << "peek" << peek()->_value.c_str() << endl;
//				}
//				if (read(EQ)) {
//					read();
//					result->push_back(_nextToken);
//				}
//			}
//				continue;
//				break;
//			case STRONG:
//				for (;;) {
//					if (peek(TEXT)) {
//						peek();
//						_nextToken->_type = STRONG;
//						result->push_back(_nextToken);
////						cout << "Strong:" << peek()->_value << endl;
////						delete tmp;
//						break;
//					}
//					readNext(true);
//				}
//				readNext(false);
//				continue;
//				break;
//			case A:
//				while (read(HREF)) {
//					//cout << peek()->_value.c_str() << endl;
//				}
//				if (peek(EQ)) {
//					readNext(true);
//					read();
//					_nextToken->_type = A;
//					result->push_back(_nextToken);
////					delete tmp;
//				}
//				continue;
//				break;
//			case SPAN:
//			case EM:
//			case UNKNOW:
////				deleteToken();
//				break;
//			default:
//
//				break;
//			}
//		}
//			continue;
//			break;
//		case TEXT:
//			result->push_back(_nextToken);
//			continue;
//			break;
//		case STRING_LITERAL:
////			deleteToken();
//			break;
//		case COMPLETE:
//			return result;
//			break;
//		default:
//			break;
//		}
//	}

	return result;
}
Token *Parser::peekButOne() {
	if (!_nextToken)
		_nextToken = _scanner->produce();
	if (!_nextButOneToken)
		_nextButOneToken = _scanner->produce();
	return _nextButOneToken;
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
void Parser::readNext(bool isDelete) {
	read();
//	if (isDelete) {
//		delete _nextToken;
//		_nextToken = NULL;
//	}
}
bool Parser::peek(Type value) {
	peek();
	return _nextToken->_type == value;
}
void Parser::read() {
	_nextToken = _scanner->produce();
//	if (!_nextToken) {
//		_nextToken = _scanner->produce();
//		return;
//	}
//	_nextToken = _nextButOneToken;
//	if (_nextButOneToken) {
//		delete _nextButOneToken;
//	}
//	_nextButOneToken = NULL;
}
void Parser::peek() {
	if (!_nextToken)
		_nextToken = _scanner->produce();
}
Parser::~Parser() {
	delete _scanner;
	delete _nextToken;
	delete _nextButOneToken;
}

} /* namespace Scanner */
