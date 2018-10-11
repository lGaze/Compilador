#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynVarState : public CSynProgramState
	{
	public:
		CSynVarState(CLexAnalyzer * lex);
		~CSynVarState();
		void checkSyntax();

	private:

	};
}