#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynFuncState : public CSynProgramState
	{
	public:
		CSynFuncState(CLexAnalyzer * lex);
		~CSynFuncState();
		void checkSyntax();

	private:

	};
}
