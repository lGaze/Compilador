#include "..\Include\CSynReturnState.h"

CompilerCore::CSynReturnState::CSynReturnState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynReturnState::~CSynReturnState()
{
}

void CompilerCore::CSynReturnState::checkSyntax()
{
	Token * t = m_lex->getNextToken();

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

	if (t->getLex().compare(";"))
	{
		//Error
	}
}
