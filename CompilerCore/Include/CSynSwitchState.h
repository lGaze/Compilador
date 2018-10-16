#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynSwitchState : public CSynProgramState
	{
	public:

		CSynSwitchState(CLexAnalyzer * lex, CSynAnalizer * syn);
		~CSynSwitchState();
		void checkSyntax();

	private:

		CLexAnalyzer * m_lex;
		CSynAnalizer * m_syn;
	};
}