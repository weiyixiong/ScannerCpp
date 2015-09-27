/*
 * Scanner.cpp
 *
 *  Created on: 2015��9��3��
 *      Author: winney
 */

#include "Scanner.h"
#include <iostream>
namespace Scannerlib {

Scanner::Scanner(const char *code) {
	keywords.insert(make_pair("p", P));
	keywords.insert(make_pair("img", IMG));
	keywords.insert(make_pair("span", SPAN));
	keywords.insert(make_pair("br", BR));
	keywords.insert(make_pair("strong", STRONG));
	keywords.insert(make_pair("em", EM));
	keywords.insert(make_pair("src", SRC));
	keywords.insert(make_pair("a", A));
	keywords.insert(make_pair("href", HREF));
	read = new Reader(code);
	_nextChar = read->read();
}

Scanner::~Scanner() {
	delete read;
}
void Scanner::readNextChar() {
	_nextChar = read->read();
}
bool Scanner::isChar(char target) {
	return (_nextChar >= 'A' && _nextChar <= 'Z')
			|| (_nextChar >= 'a' && _nextChar <= 'z');
}
Token* Scanner::produce() {
	if (!_nextChar) {
		return new Token(COMPLETE, NULL);
	}
	switch (_nextChar) {
	case ' ':
		readNextChar();
		return new Token(SPACE, NULL);
		break;
	case '=':
		readNextChar();
		return new Token(EQ, NULL);
		break;
	case '<':
		readNextChar();
		return new Token(LT, NULL);
		break;
	case '/':
		readNextChar();
		return new Token(SL, NULL);
		break;
	case '>':
		readNextChar();
		return new Token(GT, NULL);
		break;
	case '"': {
		std::string *sb = new string();
		readNextChar();
		while (_nextChar != '"') {
			sb->push_back(_nextChar);
			readNextChar();
		}
		readNextChar();
		return new Token(STRING_LITERAL, sb->c_str());
	}
		break;
//	default:
//		readNextChar();
//		return new Token(SPACE, NULL);
//		break;
	}
	std::string *sb = new string();
	if (isChar(_nextChar)) {
		while (isChar(_nextChar)) {
			sb->push_back(_nextChar);
			readNextChar();
		}
		if (keywords[sb->c_str()]) {
			return new Token((Type) keywords[sb->c_str()], NULL);
		} else {
			return new Token(UNKNOW, NULL);
		}
	} else {
		while (_nextChar && (_nextChar) != '<') {
			sb->push_back(_nextChar);
			readNextChar();
		}
		//	ConvertUtf8ToGBK(sb->c_str());
		return new Token(TEXT, sb->c_str());
	}

}
} /* namespace Scanner */
