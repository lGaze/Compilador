#include "..\Include\CToken.h"

CompilerCore::Token::Token(std::string lex, TOKEN_TYPE type, int lineNum)
{
	m_Type = type;
	m_Lex = lex;
	m_LineNumber = lineNum;
}

CompilerCore::Token::~Token()
{
}

std::string CompilerCore::Token::getTypeStr()
{
	return std::string();
}
