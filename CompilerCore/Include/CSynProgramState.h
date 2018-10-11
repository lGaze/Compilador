#pragma once
#include "../Include/CSynAnalizer.h"

namespace CompilerCore {


	class CSynProgramState
	{
	public:

		CSynProgramState(CLexAnalyzer * lex);
		virtual ~CSynProgramState();
		virtual void checkSyntax();

	private:

	};
}
