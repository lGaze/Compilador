#pragma once
#include "../Include/CLexAnalizer.h"
#include "../Include/CErrorsModule.h"
#include "..\Include\CTabSym.h"
#include "../Include/CSemAnalizer.h"



namespace CompilerCore
{
  class CSynProgramState;
	class CSynAnalizer
	{
	public:
		CSynAnalizer(CLexAnalyzer * lex, CSemAnalizer * sem);
		~CSynAnalizer();
	 	void checkSyntax();
    void addError(int linenum, const char * desc, const char *line);
   /* void addSymbol(std::string name, SCOPE::E scope, int dimen, std::string type);*/

		CSynProgramState * var;
		CSynProgramState * func;
		CSynProgramState * functionBlock;
		CSynProgramState * dimention;
		CSynProgramState * param;
		CSynProgramState * m_State;
		CSynProgramState * assign;
		CSynProgramState * expLogList;
		CSynProgramState * forState;
		CSynProgramState * funcCall;
		CSynProgramState * ifState;
		CSynProgramState * print;
		CSynProgramState * read;
		CSynProgramState * returnState;
		CSynProgramState * switchState;
		CSynProgramState * whileState;
		CSynProgramState * statementBlock;
		CSynProgramState * expLog;
		CSynProgramState * main;

    string nameFunc;

	private:

    CSemAnalizer * m_sem;
		CLexAnalyzer * m_lex;
		gcroot<ErrorsModule ^> m_errorModule;

	};
}