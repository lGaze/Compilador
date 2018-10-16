#include "..\Include\CSynStatement_BlockState.h"

CompilerCore::CSynSatement_BlockState::CSynSatement_BlockState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynSatement_BlockState::~CSynSatement_BlockState()
{
}

void CompilerCore::CSynSatement_BlockState::checkSyntax()
{
}
