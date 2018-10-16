#include "..\Include\CSynIfState.h"

CompilerCore::CSynIfState::CSynIfState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynIfState::~CSynIfState()
{
}

void CompilerCore::CSynIfState::checkSyntax()
{
}
