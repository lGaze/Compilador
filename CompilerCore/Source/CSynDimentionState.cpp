#include "..\Include\CSynDimentionState.h"



CompilerCore::CSynDimentionState::CSynDimentionState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynDimentionState::~CSynDimentionState()
{
}

void CompilerCore::CSynDimentionState::checkSyntax()
{
}
