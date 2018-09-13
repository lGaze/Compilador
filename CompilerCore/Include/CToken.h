#pragma once

#include <string>
using namespace std;

namespace CompilerCore
{
	enum TOKEN_TYPE
	{
		UNDEFINED = 0,
		ID,
		KEYWORD,
		INT,
		FLOAT,
		STRING,
		OPER_LOGICOS,
		OPER_LOGICO_UNARIO,
		OPER_ARITMETICOS,
		OPER_RELACIONALES,
		OPER_ASIGNACION,
		OPER_AGRUPACION,
		OPER_DIMENSIONAL,
		DELIM

	};

	class Token
	{
	private:
		std::string m_Lex;
		TOKEN_TYPE m_Type;
		int m_LineNumber;
		
	public:
		Token(std::string lex, TOKEN_TYPE type, int lineNum);
		~Token();

		std::string getLex() const { return m_Lex; }
		std::string getTypeStr();
		TOKEN_TYPE getType() const { return m_Type; }
		int getLineNumber() const { return m_LineNumber; }
	};
}

