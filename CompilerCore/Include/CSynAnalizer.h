#pragma once
#include "../Include/CLexAnalizer.h"
#include "../Include/CErrorsModule.h"




namespace CompilerCore
{
  class CSynProgramState;
	class CSynAnalizer
	{
	public:
		CSynAnalizer(CLexAnalyzer * lex);
		~CSynAnalizer();
	 	void checkSyntax();

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

		CLexAnalyzer * m_lex;
		gcroot<ErrorsModule ^> m_errorModule;

	};
}