#include "..\Include\CSynParamState.h"


CompilerCore::CSynParamState::CSynParamState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynParamState::~CSynParamState()
{
}

void CompilerCore::CSynParamState::checkSyntax()
{
	Token *t = m_lex->peekToken(0);
	do 
	{
		t = m_lex->getNextToken();
		if (t->getType() != TOKEN_TYPE::ID)
		{
			//Error 
		}
		else
		{
		 
		}
		t = m_lex->getNextToken();
		if (!t->getLex().compare(":") == 0)
		{
			//Error
		}
		else
		{

		}
		if (!t->getLex().compare("int") || !t->getLex().compare("float") || !t->getLex().compare("bool") || !t->getLex().compare("string"))
		{
			
		}
		else
		{
			//Error
		}

	} while (t->getLex().compare(")") == 0);

	
}


