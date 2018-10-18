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
	Token * t = m_lex->getNextToken();

	if (!t->getLex().compare("("))
	{
		m_syn->m_State = m_syn->expLogList;
		m_syn->m_State->checkSyntax();
		t = m_lex->getNextToken();
	}
	else
	{
		//error
	}

	if (t->getLex().compare(";"))
	{
		//Error
	}
}
