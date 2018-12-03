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
    std::vector<int> tempDimen;
    std::vector<string> temp;
    std::string paramType;

    do
    {

      t = m_lex->getNextToken();
      if (t->getType() != ID)
      {
        //Error
      }
      else
      {
        temp.push_back(t->getLex());
      }

      t = m_lex->getNextToken();
      if (!t->getLex().compare("["))
      {
        m_syn->m_State = m_syn->dimention;
        m_syn->checkSyntax();
        t = m_lex->getNextToken();
        tempDimen.push_back(std::stoi(t->getLex()));
        t = m_lex->getNextToken();
      }
      else
      {
        tempDimen.push_back(0);
      }
    } while (!t->getLex().compare(","));

    if (t->getLex().compare(":"))
    {
      /* ERROR
      std::string tempError = "Se esperaba ":" ";
      m_syn->addError(t->getLineNumber(), tempError.c_str(), "");*/
    }
    t= m_lex->getNextToken();

    if (!t->getLex().compare("int")
      || !t->getLex().compare("bool")
      || !t->getLex().compare("float")
      || !t->getLex().compare("void")
      || !t->getLex().compare("string"))
    {
      /*idType = t->getLex();*/
      for (int i = 0; i < temp.size(); i++)
      {
        //add to tab
      }
    }
    t = m_lex->getNextToken();
  } while (!t->getLex().compare(";"));

  if (t->getLex().compare(")"))
  {
    /* ERROR
    std::string tempError = "Se esperaba ")" ";
    m_syn->addError(t->getLineNumber(), tempError.c_str(), "");*/
  }

}


