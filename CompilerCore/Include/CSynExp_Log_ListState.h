#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynExp_Log_ListState : public CSynProgramState
	{
	public:

		CSynExp_Log_ListState(CLexAnalyzer * lex, CSynAnalizer * syn);
		~CSynExp_Log_ListState();
		void checkSyntax();

	private:
		CLexAnalyzer * m_lex;
		CSynAnalizer * m_syn;
	};
}