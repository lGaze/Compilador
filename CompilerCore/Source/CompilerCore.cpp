#include "../Include/CErrorsModule.h"
#include "../Include/CompilerCore.h"

/*
*/
CompilerCore::Manager::Manager()
{
	managed_errorsModule = gcnew ErrorsModule();
	cpp_lexAnalyzer = new CLexAnalyzer(managed_errorsModule);
}

/*
*/
CompilerCore::Manager::~Manager()
{
	// Free memory of LEX analyzer
	if (cpp_lexAnalyzer != nullptr)
	{
		delete cpp_lexAnalyzer;
		cpp_lexAnalyzer = nullptr;
	}

	// Memory of ERRORS MODULE is automatically collected (allocated with gcnew)
}

/*
 * Main entry point into the compiler logic
 */
cli::array<String ^> ^ CompilerCore::Manager::compileProgram(String ^ sourceCode)
{
	cli::array<String ^> ^ compilationDetails;

	// Clear state if all pointers are valid
	if (managed_errorsModule && cpp_lexAnalyzer != nullptr)
	{
		managed_errorsModule->reset();
		cpp_lexAnalyzer->reset();
	} 
	else
	{
		// invalid pointers, return error...
	}

	lexAnalysis(sourceCode);

	compilationDetails = getCompilationDetails();

	return compilationDetails;
}

/*
*/
void CompilerCore::Manager::lexAnalysis(String ^ sourceCode)
{
	if (cpp_lexAnalyzer != nullptr)
	{
		cpp_lexAnalyzer->parseSourceCode((const char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(sourceCode).ToPointer());
	}
}

cli::array<String^>^ CompilerCore::Manager::getCompilationDetails()
{
	
	return managed_errorsModule->Errors;
	// TODO: insert return statement here
}
