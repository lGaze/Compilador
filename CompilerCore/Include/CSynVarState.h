#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynVarState : public CSynProgramState
	{
	public:
		CSynVarState(CLexAnalyzer * lex, CSynAnalizer * syn);
		~CSynVarState();
		void checkSyntax();

	private:
		CLexAnalyzer * m_lex;
		CSynAnalizer * m_syn;
	};
}