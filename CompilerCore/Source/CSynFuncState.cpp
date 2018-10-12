#include "..\Include\CSynFuncState.h"


CompilerCore::CSynFuncState::CSynFuncState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynFuncState::~CSynFuncState()
{
}

void CompilerCore::CSynFuncState::checkSyntax()
{
	Token * t = m_lex->getNextToken();
	if (t->getType() != TOKEN_TYPE::ID)
	{
		//Error 
	}

	t = m_lex->getNextToken();

	if (!t->getLex().compare("(") == 0)
	{
		//Error 
	}
	else
	{
		m_syn->m_State = m_syn->param;
		m_syn->m_State->checkSyntax();
	}
	t = m_lex->getNextToken();

	if (!t->getLex().compare(":"))
	{
		//Error
	}
	t = m_lex->getNextToken();

	if (!t->getLex().compare("int") || !t->getLex().compare("float") || !t->getLex().compare("bool") || !t->getLex().compare("string") || !t->getLex().compare("void"))
	{
		
	}
	else
	{
		//Error 
	}

	t = m_lex->getNextToken();

	
}

