#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynWhileState : public CSynProgramState
	{
	public:
		CSynWhileState(CLexAnalyzer * lex, CSynAnalizer * syn);
		~CSynWhileState();
		void checkSyntax();

	private:
		CLexAnalyzer * m_lex;
		CSynAnalizer * m_syn;
	};
}