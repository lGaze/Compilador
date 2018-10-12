#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynDimentionState : public CSynProgramState
	{
	public:

		CSynDimentionState(CLexAnalyzer * lex, CSynAnalizer * syn);
		~CSynDimentionState();
		void checkSyntax();

	private:
		CLexAnalyzer * m_lex;
		CSynAnalizer * m_syn;
	};
}