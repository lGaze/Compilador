#pragma once

#include "windows.h"
using namespace System;

#include "../Include/CErrorsModule.h"
#include "../Include/CLexAnalizer.h"

namespace CompilerCore
{
	public ref class Manager
	{
	private:
		CLexAnalyzer  * cpp_lexAnalyzer;      // LEX ANALYZER INSTANCE
		ErrorsModule ^ managed_errorsModule; // ERRORS MODULE

		void lexAnalysis(String ^ sourceCode);
		cli::array<String ^> ^ getCompilationDetails();

	public:
		Manager();
		~Manager();

		cli::array<String ^> ^ compileProgram(String ^ sourceCode);
		//...
	};
}
