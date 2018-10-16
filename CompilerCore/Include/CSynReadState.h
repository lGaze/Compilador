#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynReadState : public CSynProgramState
	{
	public:

		CSynReadState(CLexAnalyzer * lex, CSynAnalizer * syn);
		~CSynReadState();
		void checkSyntax();

	private:

		CLexAnalyzer * m_lex;
		CSynAnalizer * m_syn;
	};
}