#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynFuncState : public CSynProgramState
	{
	public:
		CSynFuncState(CLexAnalyzer * lex, CSynAnalizer * syn);
		~CSynFuncState();
		void checkSyntax();

	private:
		CLexAnalyzer * m_lex;
		CSynAnalizer * m_syn;
	};
}
