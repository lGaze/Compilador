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

			if (t->getType() != ID)
			{
          /* ERROR
          std::string tempError = "Se esperaba un ID";
           m_syn->addError(t->getLineNumber(), tempError.c_str(), "");*/
			}
			else
			{
				tempIDs.push_back(t->getLex());
			}


			t = m_lex->getNextToken();

			if (!t->getLex().compare("["))
			{
        t = m_lex->getNextToken();
				tempDimen.push_back(stoi(t->getLex()));
				m_syn->m_State = m_syn->dimention;
				m_syn->checkSyntax();
			  t = m_lex->getNextToken();
			}
			else
			{
					tempDimen.push_back(0);
			}


		} while (!t->getLex().compare(","));

			if (!t->getLex().compare(":"))
			{
        /* ERROR
        std::string tempError = "Se esperaba ":" ";
        m_syn->addError(t->getLineNumber(), tempError.c_str(), "");*/
			}

			t = m_lex->getNextToken();

			if (!t->getLex().compare("int") || !t->getLex().compare("float") || !t->getLex().compare("bool") || !t->getLex().compare("string"))
			{
				IDtype.push_back(t->getLex());
        CTabSym tabsym;
        
        for (int i = 0; i < tempIDs.size(); i++)
        {
          Data data;
          data.dimen = tempDimen[i];
          data.funcName = m_syn->nameFunc;
     /*     tabsym.addSymbol(tempIDs[i], )*/
        }
			}
			else
			{
        /* ERROR
        std::string tempError = "No se encontro tipo";
        m_syn->addError(t->getLineNumber(), tempError.c_str(), "");*/
			}

      t = m_lex->getNextToken();

			if (t->getLex().compare(";"))
			{
				
			}
	}
}


