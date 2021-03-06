#pragma once

#include "windows.h"
#include "vcclr.h"
#include "../Include/CErrorsModule.h"
#include "../Include/CToken.h"
using namespace System;

#include <map>
#include <vector>
#include <stack>

using namespace std;

namespace CompilerCore
{
#define LEX_ERROR_INVALID_CHARACTER         "Invalid character"
#define LEX_ERROR_STRING_NOT_CLOSED         "String constant not closed"
#define LEX_ERROR_COMMENT_NOT_CLOSED        "Comment not closed"
#define LEX_ERROR_INVALID_FLOAT             "Invalid floating point number. Digit expected"
#define LEX_ERROR_INVALID_LOGICAL_OP_AND    "Invalid logical 'AND' operator. "
#define LEX_ERROR_INVALID_LOGICAL_OP_OR     "Invalid logical 'OR' operator."
#define LEX_ERROR_INVALID_STATE             "Internal error. Invalid state."

	enum LEX_STATE
	{
		S_START = 0,
		S_ID,
		S_KEYWORDS,
		S_OPER_LOGICO,
		S_OPER_LOGICO_UNITARIO,
		S_OPER_ARITMETICO,
		S_OPER_RELACIONAL,
		S_OPER_ASIGNACION,
		S_OPER_AGRUPACION,
		S_OPER_DIMENSIONAL,
		S_DELIM,
		S_INT,
		S_FLOAT,
		S_STRING,
		S_COMMENT,

	};

	// LEX analyzer class
	class CLexAnalyzer
	{
	private:

		msclr::gcroot<ErrorsModule ^> managedRef_errorsModule;
		std::map<std::string, std::string> m_Keywords;
		std::vector<Token *> m_Tokens;
		LEX_STATE m_state;

		int m_currentToken;
    int m_currSynToken = 0;
    Token * m_lastToken;

	public:

		CLexAnalyzer(ErrorsModule ^errorsModule);
		~CLexAnalyzer();

		const msclr::gcroot<ErrorsModule ^> getErrors() { return managedRef_errorsModule; }
		bool parseSourceCode(const char *sourceCode);
		bool addToken(std::string lex, TOKEN_TYPE type, int lineNum);
		void getTokens(std::vector<Token *> *tokensVec) const;
		bool is_Alpha(const char* currchar);
		bool is_Digit(const char* currchar);
		void reset();
		inline Token * peekToken(int i)
		{
			int tokenToPeek = m_currSynToken + i;
			if (tokenToPeek >= 0 && tokenToPeek < m_Tokens.size())
			{
				return m_Tokens[tokenToPeek];
			}
			return nullptr;
		}
		inline Token * getNextToken()
		{
			int nextToken = ++m_currSynToken;
			if (nextToken >= 0 && nextToken < m_Tokens.size())
			{
				return m_Tokens[nextToken];
			}
			return m_lastToken;
		}
	};
}

