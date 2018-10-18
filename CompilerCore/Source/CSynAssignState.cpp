#include "..\Include\CSynAssignState.h"

CompilerCore::CSynAssingnState::CSynAssingnState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynAssingnState::~CSynAssingnState()
{
}

void CompilerCore::CSynAssingnState::checkSyntax()
{
	Token * t = m_lex->getNextToken();

	if (!t->getLex().compare("="))
	{
		//m_syn->m_State = m_syn->expLog;
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
