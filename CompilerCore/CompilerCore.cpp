#include "stdafx.h"

#include "CompilerCore.h"

/*
*/
CompilerCore::Manager::Manager()
{

}

/*
*/
CompilerCore::Manager::~Manager()
{

}

/*
*/
cli::array<String^> ^CompilerCore::Manager::compileProgram(String^ sourceCode)
{
	cli::array<String^> ^compilationDetails = gcnew cli::array<String ^>(1);
	compilationDetails[0] = gcnew String("Hola mundo");
	return compilationDetails;
}




