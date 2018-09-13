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
		bool isAlpha(const char * currChar);
		bool isDigit(const char * currChar);
		bool addToken(std::string lex, TOKEN_TYPE type, int lineNum);
		void reset();
		void getTokens(std::vector<Token *> *tokensVec) const;
	};
}

