#include "..\Include\CSynFuncState.h"


CompilerCore::CSynFuncState::CSynFuncState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynFuncState::~CSynFuncState()
{
}

void CompilerCore::CSynFuncState::checkSyntax()
{
}

