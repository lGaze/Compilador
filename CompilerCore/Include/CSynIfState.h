#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynIfState : public CSynProgramState
	{
	public:
		CSynIfState(CLexAnalyzer * lex, CSynAnalizer * syn);
		~CSynIfState();
		void checkSyntax();

	private:
		CLexAnalyzer * m_lex;
		CSynAnalizer * m_syn;
	};
}