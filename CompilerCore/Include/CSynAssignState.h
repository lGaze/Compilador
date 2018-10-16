#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynAssingnState : public CSynProgramState
	{
	public:

		CSynAssingnState(CLexAnalyzer * lex, CSynAnalizer * syn);
		~CSynAssingnState();
		void checkSyntax();

	private:
		CLexAnalyzer * m_lex;
		CSynAnalizer * m_syn;
	};
}