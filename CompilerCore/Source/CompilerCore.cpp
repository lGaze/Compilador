#include "../Include/CErrorsModule.h"
#include "../Include/CompilerCore.h"

/*
*/
CompilerCore::Manager::Manager()
{
	managed_errorsModule = gcnew ErrorsModule();
	cpp_lexAnalyzer = new CLexAnalyzer(managed_errorsModule);
	tok = new std::vector<Token *>;
  cpp_semAnalizer = new CSemAnalizer(managed_errorsModule);
  cpp_sinAnalyzer = new CSynAnalizer(cpp_lexAnalyzer, cpp_semAnalizer);
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
	//cli::array<String ^> ^ compilationDetails;

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
  synAnalysis();
  semAnalysis();
	return getCompilationDetails();
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

void CompilerCore::Manager::synAnalysis()
{
  cpp_sinAnalyzer->checkSyntax();
}

void CompilerCore::Manager::semAnalysis()
{
  cpp_semAnalizer->checkExpressions();
}

cli::array<String^>^ CompilerCore::Manager::getCompilationDetails()
{
	managed_errorsModule = cpp_lexAnalyzer->getErrors();
	cli::array<String^> ^error = managed_errorsModule->Errors;
	int longitudErrores = error->Length;
	cpp_lexAnalyzer->getTokens(tok);
	int posArroba = longitudErrores;
	cli::array<String^>^ compDetails = gcnew cli::array<String ^> (posArroba + tok->size()+1);
	
	for (int i = 0; i < longitudErrores; i++)
	{
		compDetails[i] = error[i];
	}

	compDetails[posArroba] = "@";
	int a = posArroba + 1;

	for (vector<Token*>::iterator it = tok->begin(); it != tok->end(); it++)
	{
		String^ lex = gcnew String((*it)->getLex().c_str());
		String^ type = gcnew String((*it)->getTypeStr().c_str());
		String^ line = gcnew String(std::to_string((*it)->getLineNumber()).c_str());
		compDetails[a++] = String::Format("{2}\t{0}\t{1}", lex, type, line);
		
	}

	return compDetails;
	
}
