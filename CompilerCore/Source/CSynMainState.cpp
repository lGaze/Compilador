#include "..\Include\CSynMainState.h"

CompilerCore::CSynMainState::CSynMainState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynMainState::~CSynMainState()
{
}

void CompilerCore::CSynMainState::checkSyntax()
{
	Token * t = m_lex->getNextToken();
	if (!t->getLex().compare("(") || !t->getLex().compare(""))
	{
    //Error
	}

	t = m_lex->getNextToken();

	if (!t->getLex().compare(")") || !t->getLex().compare(" "))
	{
		//Error
	}

	t = m_lex->getNextToken();
	
	if (!t->getLex().compare("{"))
	{
		m_syn->m_State = m_syn->functionBlock;
		m_syn->m_State->checkSyntax();
		t = m_lex->getNextToken();
	}
  else
  {
    //Error
  }

}
