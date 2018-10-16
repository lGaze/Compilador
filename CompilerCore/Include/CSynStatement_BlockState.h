#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynSatement_BlockState : public CSynProgramState
	{
	public:

		CSynSatement_BlockState(CLexAnalyzer * lex, CSynAnalizer * syn);
		~CSynSatement_BlockState();
		void checkSyntax();

	private:

		CLexAnalyzer * m_lex;
		CSynAnalizer * m_syn;
	};
}