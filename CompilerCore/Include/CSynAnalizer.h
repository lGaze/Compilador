#pragma once
#include "../Include/CLexAnalizer.h"
#include "../Include/CErrorsModule.h"
#include "../Include/CSynProgramState.h"
#include "../Include/CSynVarState.h"
#include "../Include/CSynFuncState.h"
#include "../Include/CSynFunction_BlockState.h"
#include "../Include/CSynDimentionState.h"
#include "../Include/CSynParamState.h"

namespace CompilerCore
{
	class CSynAnalizer
	{
	public:
		CSynAnalizer();
		~CSynAnalizer();
	 	void checkSyntax();

		CSynProgramState * var;
		CSynProgramState * func;
		CSynProgramState * functionBlock;
		CSynProgramState * dimention;
		CSynProgramState * param;
	
		
	private:

		CLexAnalyzer * m_lex;
		gcroot<ErrorsModule ^> m_errorModule;

	};
}