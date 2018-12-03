#include "..\Include\CSynDimentionState.h"



CompilerCore::CSynDimentionState::CSynDimentionState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynDimentionState::~CSynDimentionState()
{
}

void CompilerCore::CSynDimentionState::checkSyntax()
{
  Token * t = m_lex->peekToken(0);
  if (t->getType() == INT)
  {
    t = m_lex->getNextToken();
    if (!t->getLex().compare("]"))
    {
      t = m_lex->peekToken(-1);
    }
    else
    {
      /* ERRORs
      std::string tempError = "Se esperaba "]" ";
      m_syn->addError(t->getLineNumber(), tempError.c_str(), "");*/
    }
  }
  else
  {
    /* ERROR
    std::string tempError = "Se esperaba un tipo INT ";
    m_syn->addError(t->getLineNumber(), tempError.c_str(), "");*/
  }
}
