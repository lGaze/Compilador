#include "..\Include\CSynForState.h"

CompilerCore::CSynForState::CSynForState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynForState::~CSynForState()
{
}

void CompilerCore::CSynForState::checkSyntax()
{
	Token * t = m_lex->getNextToken();
	
	if (t->getLex().compare("("))
	{
		//Error
	}

	t = m_lex->getNextToken();

	if (!t->getType() == ID)
	{
		m_syn->m_State = m_syn->assign;
		m_syn->m_State->checkSyntax();
		t = m_lex->getNextToken();
	}
	else
	{
		//Error
	}

	if (t->getLex().compare(";"))
	{
		//Error
	}

	t = m_lex->getNextToken();

	if (!t->getType() == ID || !t->getType() == OPER_LOGICO_UNARIO)
	{
		m_syn->m_State = m_syn->expLog;
		m_syn->checkSyntax();
		t = m_lex->getNextToken();
	}
	else
	{
		//Error
	}

	if (t->getLex().compare(";"))
	{
		//Error
	}

	if (!t->getLex().compare("inc") || !t->getLex().compare("dec"))
	{
		//m_syn->m_State = m_syn.>inc_Dec;
		//m_syn->m_state->checkSyntax();
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
		m_syn->m_State->checkSyntax();
		t = m_lex->getNextToken();
	}
}
