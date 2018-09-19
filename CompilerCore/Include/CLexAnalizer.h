#pragma once

#include "windows.h"
#include "vcclr.h"
#include "../Include/CErrorsModule.h"
#include "../Include/CToken.h"

using namespace System;

#include <map>
#include <vector>
#include <stack>
#include "ctype.h"
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
		S_OPER_LOGICOS,
		S_OPER_LOGICO_UNITARIO,
		S_OPER_ARITMETICOS,
		S_OPER_RELACIONALES,
		S_OPER_ASIGNACION,
		S_DELIM,
		S_INT,
		S_FLOAT,
		S_STRING

	};

	// LEX analyzer class
	class CLexAnalyzer
	{
	private:
		msclr::gcroot<ErrorsModule ^> managedRef_errorsModule;

		std::map<std::string, std::string> m_Keywords;
		std::vector<Token *> m_Tokens;

		LEX_STATE m_state;

		// ...
		// ...

	public:

		CLexAnalyzer(ErrorsModule ^errorsModule);
		~CLexAnalyzer();
		
		bool parseSourceCode(const char *sourceCode);
		bool addToken(std::string lex, TOKEN_TYPE type, int lineNum);
		void reset();
		void getTokens(std::vector<Token *> *tokensVec) const;
	};
}

