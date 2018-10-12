#include "..\Include\CSynVarState.h"

CompilerCore::CSynVarState::CSynVarState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynVarState::~CSynVarState()
{
}

void CompilerCore::CSynVarState::checkSyntax()
{
	std::vector<int> tempDimen;
	std::vector<string> tempIDs;
	std::vector<string> IDtype;

	Token *t = m_lex->peekToken(0);
	while (!t->getLex().compare("var"))
	{
		do
		{
			t = m_lex->getNextToken();
			if (t->getType != ID)
			{
				//Error
			}
			else
			{
				tempIDs.push_back(t->getLex());
			}

			t = m_lex->getNextToken();

			if (t->getLex().compare("["))
			{
				
				tempDimen.push_back(stoi(t->getLex()));
				m_syn->m_State = m_syn->dimention;
				m_syn->checkSyntax();
				t = m_lex->getNextToken();
			}
			else
			{
					tempDimen.push_back(0);
			}

			t = m_lex->getNextToken();

		} while (!t->getLex().compare(","));

			if (t->getLex().compare(":"))
			{
				//Error
			}

			t = m_lex->getNextToken();

			if (!t->getLex().compare("int") || !t->getLex().compare("float") || !t->getLex().compare("bool") || !t->getLex().compare("string"))
			{
				IDtype.push_back(t->getLex());
			}
			else
			{
				//Error
			}
			if (t->getLex().compare(";"))
			{
				
			}
	}
}


