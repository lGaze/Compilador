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
	Token *t = m_lex->peekToken(0);
	do 
	{
		t = m_lex->getNextToken();

	} while (t->getLex().compare(")") == 0);
}


