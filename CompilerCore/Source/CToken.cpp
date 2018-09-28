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
	if (m_Type == 0) return "UNDEFINED";
	if (m_Type == 1) return "ID";
	if (m_Type == 2) return "KEYWORD";
	if (m_Type == 3) return "INT";
	if (m_Type == 4) return "FLOAT";
	if (m_Type == 5) return "STRING";
	if (m_Type == 6) return "OPER_LOGICOS";
	if (m_Type == 7) return "OPER_LOGICO_UNARIO";
	if (m_Type == 8) return "OPER_ARITMETICOS";
	if (m_Type == 9) return "OPER_RELACIONALES";
	if (m_Type == 10) return "OPER_ASIGNACION";
	if (m_Type == 12) return "OPER_AGRUPACION";
	if (m_Type == 13) return "OPER_DIMENSIONAL";
	if (m_Type == 14) return "DELIM";
	return "";
}
