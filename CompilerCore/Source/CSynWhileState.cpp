#include "..\Include\CSynWhileState.h"

CompilerCore::CSynWhileState::CSynWhileState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynWhileState::~CSynWhileState()
{
}

void CompilerCore::CSynWhileState::checkSyntax()
{
}
