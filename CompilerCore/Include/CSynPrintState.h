#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynPrintState : public CSynProgramState
	{
	public:

		CSynPrintState(CLexAnalyzer * lex, CSynAnalizer * syn);
		~CSynPrintState();
		void checkSyntax();

	private:

		CLexAnalyzer * m_lex;
		CSynAnalizer * m_syn;
	};
}