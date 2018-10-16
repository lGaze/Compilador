#include "..\Include\CSynPrintState.h"

CompilerCore::CSynPrintState::CSynPrintState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynPrintState::~CSynPrintState()
{
}

void CompilerCore::CSynPrintState::checkSyntax()
{
}
