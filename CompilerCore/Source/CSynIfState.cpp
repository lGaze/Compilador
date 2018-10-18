#include "..\Include\CSynIfState.h"

CompilerCore::CSynIfState::CSynIfState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynIfState::~CSynIfState()
{
}

void CompilerCore::CSynIfState::checkSyntax()
{
	Token * t = m_lex->getNextToken();

	if (t->getLex().compare("("))
	{
		//Error
	}

	t = m_lex->getNextToken();

	if (!t->getType() == ID || !t->getType() == OPER_LOGICO_UNARIO)
	{
		//m_syn->m_State = m_syn->expLog;
		//m_syn->checkSyntax();
		t = m_lex->getNextToken();
	}
	else
	{
		//Error
	}

	if (t->getLex().compare(")"))
	{
		//Error
	}

	t = m_lex->getNextToken();
	if (!t->getLex().compare("{"))
	{
		m_syn->m_State = m_syn->statementBlock;
		m_syn->checkSyntax();
		t = m_lex->getNextToken();
		if (t->getLex().compare("else"))
		{
			m_syn->m_State = m_syn->statementBlock;
			m_syn->checkSyntax();
			t = m_lex->getNextToken();
		}
	}

}
