#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynExpLogState : public CSynProgramState
	{
	public:

		CSynExpLogState(CLexAnalyzer * lex, CSynAnalizer * syn);
		~CSynExpLogState();
		void checkSyntax();

	private:
		CLexAnalyzer * m_lex;
		CSynAnalizer * m_syn;
	};
}