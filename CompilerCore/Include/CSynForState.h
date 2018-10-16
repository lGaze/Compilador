#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynForState : public CSynProgramState
	{
	public:

		CSynForState(CLexAnalyzer * lex, CSynAnalizer * syn);
		~CSynForState();
		void checkSyntax();

	private:
		CLexAnalyzer * m_lex;
		CSynAnalizer * m_syn;
	};
}