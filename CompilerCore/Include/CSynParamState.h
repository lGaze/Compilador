#pragma once
#include "../Include/CSynProgramState.h"

namespace CompilerCore {

	class CSynParamState : public CSynProgramState
	{
	public:

		CSynParamState(CLexAnalyzer * lex);
		~CSynParamState();
		void checkSyntax();

	private:

	};
}