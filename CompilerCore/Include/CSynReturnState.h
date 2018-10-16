#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynReturnState : public CSynProgramState
	{
	public:

		CSynReturnState(CLexAnalyzer * lex, CSynAnalizer * syn);
		~CSynReturnState();
		void checkSyntax();

	private:

		CLexAnalyzer * m_lex;
		CSynAnalizer * m_syn;
	};
}