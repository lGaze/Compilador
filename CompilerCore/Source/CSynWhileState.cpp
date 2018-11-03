#include "..\Include\CSynWhileState.h"

CompilerCore::CSynWhileState::CSynWhileState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynWhileState::~CSynWhileState()
{
}

void CompilerCore::CSynWhileState::checkSyntax()
{
	Token * t = m_lex->getNextToken();

	if (t->getLex().compare("("))
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
