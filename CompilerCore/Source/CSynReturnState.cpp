#include "..\Include\CSynReturnState.h"

CompilerCore::CSynReturnState::CSynReturnState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynReturnState::~CSynReturnState()
{
}

void CompilerCore::CSynReturnState::checkSyntax()
{
}
