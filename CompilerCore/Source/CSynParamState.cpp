#include "..\Include\CSynParamState.h"


CompilerCore::CSynParamState::CSynParamState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynParamState::~CSynParamState()
{
}

void CompilerCore::CSynParamState::checkSyntax()
{
}


