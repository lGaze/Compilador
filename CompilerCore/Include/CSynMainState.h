#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynMainState : public CSynProgramState
	{
	public:

		CSynMainState(CLexAnalyzer * lex, CSynAnalizer * syn);
		~CSynMainState();
		void checkSyntax();

	private:
		CLexAnalyzer * m_lex;
		CSynAnalizer * m_syn;
	};
}