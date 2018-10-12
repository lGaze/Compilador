#include "..\Include\CSynAnalizer.h"



CompilerCore::CSynAnalizer::CSynAnalizer(CLexAnalyzer * lex)
{
	
	m_lex = lex;
	m_State			= new CSynProgramState(m_lex, this);
	var				= new CSynVarState(m_lex, this);
	func		    = new CSynFuncState(m_lex, this);
	functionBlock	= new CSynFuntion_BlockState(m_lex, this);
	param		    = new CSynParamState(m_lex, this);
	dimention		= new CSynDimentionState(m_lex, this);
}

CompilerCore::CSynAnalizer::~CSynAnalizer()
{
}

void CompilerCore::CSynAnalizer::checkSyntax()
{
	m_State->checkSyntax();
}
