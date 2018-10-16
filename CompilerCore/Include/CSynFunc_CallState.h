#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynFunc_CallState : public CSynProgramState
	{
	public:

		CSynFunc_CallState(CLexAnalyzer * lex, CSynAnalizer * syn);
		~CSynFunc_CallState();
		void checkSyntax();

	private:
		CLexAnalyzer * m_lex;
		CSynAnalizer * m_syn;
	};
}