#pragma once
#include "../Include/CLexAnalizer.h"
#include "../Include/CErrorsModule.h"
#include "../Include/CSynProgramState.h"
#include "../Include/CSynVarState.h"
#include "../Include/CSynFuncState.h"
#include "../Include/CSynFunction_BlockState.h"
#include "../Include/CSynDimentionState.h"
#include "../Include/CSynParamState.h"
#include "../Include/CSynAssignState.h"
#include "../Include/CSynExp_Log_ListState.h"
#include "../Include/CSynForState.h"
#include "../Include/CSynFuncState.h"
#include "../Include/CSynIfState.h"
#include "../Include/CSynPrintState.h"
#include "../Include/CSynReadState.h"
#include "../Include/CSynReturnState.h"
#include "../Include/CSynSwitchState.h"
#include "../Include/CSynWhileState.h"
#include "../Include/CSynStatement_BlockState.h"
#include "../Include/CSynFunc_CallState.h"
#include "../Include/CSynExpLogState.h"



namespace CompilerCore
{
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
		
	private:

		CLexAnalyzer * m_lex;
		gcroot<ErrorsModule ^> m_errorModule;

	};
}