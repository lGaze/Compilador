#pragma once
#include "../Include/CSynAnalizer.h"

namespace CompilerCore {


	class CSynProgramState
	{
	public:

		CSynProgramState();
		CSynProgramState(CLexAnalyzer * lex, CSynAnalizer * syn);
		virtual ~CSynProgramState();
		virtual void checkSyntax();

	private:
		CLexAnalyzer * m_lex;
		CSynAnalizer * m_syn;
	};
}
