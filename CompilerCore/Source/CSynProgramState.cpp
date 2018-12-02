#include "..\Include\CSynProgramState.h"

CompilerCore::CSynProgramState::CSynProgramState()
{
}

CompilerCore::CSynProgramState::CSynProgramState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynProgramState::~CSynProgramState()
{
}

void CompilerCore::CSynProgramState::checkSyntax()
{
	Token * t = m_lex->peekToken(0);
  Token * nt = t;
	while (t->getLex().compare("var") == 0)
	{
    m_syn->nameFunc = " global";
		m_syn->m_State = m_syn->var;
		m_syn->m_State->checkSyntax();
		t = m_lex->getNextToken();
	}

	while (t->getLex().compare("function") == 0)
	{
    nt = m_lex->getNextToken();
    m_syn->nameFunc = nt->getLex();
		m_syn->m_State = m_syn->func;
		m_syn->m_State->checkSyntax();
		t = m_lex->getNextToken();
	}
	
	if (t->getLex().compare("main") != 0)
	{
		//Error
	}
	else
	{
		m_syn->m_State = m_syn->main;
		m_syn->m_State->checkSyntax();
		t = m_lex->getNextToken();
	}

}
