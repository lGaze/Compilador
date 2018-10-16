#include "..\Include\CSynExp_Log_ListState.h"

CompilerCore::CSynExp_Log_ListState::CSynExp_Log_ListState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynExp_Log_ListState::~CSynExp_Log_ListState()
{
}

void CompilerCore::CSynExp_Log_ListState::checkSyntax()
{
}
