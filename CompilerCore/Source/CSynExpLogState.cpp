#include "..\Include\CSynExpLogState.h"


CompilerCore::CSynExpLogState::CSynExpLogState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynExpLogState::~CSynExpLogState()
{
}

void CompilerCore::CSynExpLogState::checkSyntax()
{
	Token * t = m_lex->getNextToken();
	
}
