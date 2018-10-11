#include "..\Include\CSynAnalizer.h"



CompilerCore::CSynAnalizer::CSynAnalizer()
{
	var				= new CSynVarState(this->m_lex);
	func		    = new CSynFuncState();
	functionBlock	= new CSynFuntion_BlockState();
	param		    = new CSynParamState();
	dimention		= new CSynDimentionState();
}

CompilerCore::CSynAnalizer::~CSynAnalizer()
{
}

void CompilerCore::CSynAnalizer::checkSyntax()
{
	CSynProgramState* p = new CSynProgramState();
	p->checkSyntax();
}
