#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynFuntion_BlockState : public CSynProgramState
	{
	public:
		CSynFuntion_BlockState(CLexAnalyzer * lex, CSynAnalizer * syn);
		~CSynFuntion_BlockState();
		void checkSyntax();

	private:
		CLexAnalyzer * m_lex;
		CSynAnalizer * m_syn;
	};
}