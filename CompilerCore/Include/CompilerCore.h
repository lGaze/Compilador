#pragma once

#include "windows.h"
using namespace System;

#include "../Include/CErrorsModule.h"
#include "../Include/CLexAnalizer.h"
#include "../Include/CSynAnalizer.h"
#include "../Include/CSemAnalizer.h"

namespace CompilerCore
{
  public ref class Manager
  {

  private:
    CLexAnalyzer * cpp_lexAnalyzer;      // LEX ANALYZER INSTANCE
    ErrorsModule ^ managed_errorsModule; // ERRORS MODULE
    CSynAnalizer * cpp_sinAnalyzer;      //SYN ANALYZER INSTANCE
    CSemAnalizer * cpp_semAnalizer;       //SEM ANALYZER INSTANCE

    void lexAnalysis(String ^ sourceCode);
    void synAnalysis();
    void semAnalysis();

		cli::array<String ^> ^ getCompilationDetails();
		std::vector<Token*> *tok;

	public:
		Manager();
		~Manager();

		cli::array<String ^> ^ compileProgram(String ^ sourceCode);

		//...
	};
}
