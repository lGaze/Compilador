#include "..\Include\CSynAssignState.h"

CompilerCore::CSynAssingnState::CSynAssingnState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynAssingnState::~CSynAssingnState()
{
}

void CompilerCore::CSynAssingnState::checkSyntax()
{
}
