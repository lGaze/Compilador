#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynDimentionState : public CSynProgramState
	{
	public:
		CSynDimentionState(CLexAnalyzer * lex);
		~CSynDimentionState();
		void checkSyntax();

	private:

	};
}