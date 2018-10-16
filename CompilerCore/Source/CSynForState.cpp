#include "..\Include\CSynForState.h"

CompilerCore::CSynForState::CSynForState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynForState::~CSynForState()
{
}

void CompilerCore::CSynForState::checkSyntax()
{
}
