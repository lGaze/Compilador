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
	Token * t = m_lex->getNextToken();

	if (!t->getLex().compare("if"))
	{
		m_syn->m_State = m_syn->ifState;
		m_syn->m_State->checkSyntax();
		t = m_lex->getNextToken();
	}

	if (!t->getLex().compare("while"))
	{
		m_syn->m_State = m_syn->whileState;
		m_syn->m_State->checkSyntax();
		t = m_lex->getNextToken();
	}

	if (!t->getLex().compare("for"))
	{
		m_syn->m_State = m_syn->forState;
		m_syn->m_State->checkSyntax();
		t = m_lex->getNextToken();
	}

	if (!t->getLex().compare("read"))
	{
		m_syn->m_State = m_syn->read;
		m_syn->m_State->checkSyntax();
		t = m_lex->getNextToken();
	}

	if (!t->getLex().compare("print"))
	{
		m_syn->m_State = m_syn->read;
		m_syn->m_State->checkSyntax();
		t = m_lex->getNextToken();
	}

	if (!t->getLex().compare("return"))
	{
		m_syn->m_State = m_syn->returnState;
		m_syn->m_State->checkSyntax();
		t = m_lex->getNextToken();
	}

}
