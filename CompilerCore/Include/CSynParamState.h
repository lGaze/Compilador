#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynParamState : public CSynProgramState
	{
	public:

		CSynParamState(CLexAnalyzer * lex, CSynAnalizer * syn);
		~CSynParamState();
		void checkSyntax();

	private:
		CLexAnalyzer * m_lex;
		CSynAnalizer * m_syn;
	};
}