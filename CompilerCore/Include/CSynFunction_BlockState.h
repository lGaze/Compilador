#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynFuntion_BlockState : public CSynProgramState
	{
	public:
		CSynFuntion_BlockState(CLexAnalyzer * lex);
		~CSynFuntion_BlockState();
		void checkSyntax();

	private:

	};
}