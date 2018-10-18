#include "..\Include\CSynReadState.h"

CompilerCore::CSynReadState::CSynReadState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynReadState::~CSynReadState()
{
}

void CompilerCore::CSynReadState::checkSyntax()
{
	Token * t = m_lex->getNextToken();

	if (!t->getLex().compare("("))
	{
		t = m_lex->getNextToken();
		if (t->getType() == ID)
		{
			t = m_lex->getNextToken();
			if (!t->getLex().compare("["))
			{
				//m_syn->m_State = m_syn->dimention
				//m_syn->m_State->checkSyntax();
				t = m_lex->getNextToken();
			}

		}
		else
		{
			//Error
		}
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
