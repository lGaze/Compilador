#include "..\Include\CSynSwitchState.h"

CompilerCore::CSynSwitchState::CSynSwitchState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynSwitchState::~CSynSwitchState()
{
}

void CompilerCore::CSynSwitchState::checkSyntax()
{
}
	