#include "..\Include\CSynFunction_BlockState.h"

CompilerCore::CSynFuntion_BlockState::CSynFuntion_BlockState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynFuntion_BlockState::~CSynFuntion_BlockState()
{
}

void CompilerCore::CSynFuntion_BlockState::checkSyntax()
{
}
