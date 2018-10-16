#include "..\Include\CSynFunc_CallState.h"

CompilerCore::CSynFunc_CallState::CSynFunc_CallState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynFunc_CallState::~CSynFunc_CallState()
{
}

void CompilerCore::CSynFunc_CallState::checkSyntax()
{
}
