#include "..\Include\CSynFunction_BlockState.h"

CompilerCore::CSynFuntion_BlockState::CSynFuntion_BlockState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynFuntion_BlockState::~CSynFuntion_BlockState()
{
}

void CompilerCore::CSynFuntion_BlockState::checkSyntax()
{
  Token *t = m_lex->getNextToken();

  while (t->getLex().compare("var") == 0)
  {
    m_syn->m_State = m_syn->var;
    m_syn->m_State->checkSyntax();
    t = m_lex->getNextToken();
  }

  if (!t->getLex().compare("if"))
  {
    m_syn->m_State = m_syn->ifState;
    m_syn->checkSyntax();
    t = m_lex->getNextToken();
  }

  if (!t->getLex().compare("for"))
  {
    m_syn->m_State = m_syn->forState;
    m_syn->checkSyntax();
    t = m_lex->getNextToken();
  }

  if (!t->getLex().compare("while"))
  {
    m_syn->m_State = m_syn->whileState;
    m_syn->checkSyntax();
    t = m_lex->getNextToken();
  }

  if (!t->getLex().compare("switch"))
  {
    m_syn->m_State = m_syn->switchState;
    m_syn->checkSyntax();
    t = m_lex->getNextToken();
  }

  if (!t->getLex().compare("read"))
  {
    m_syn->m_State = m_syn->read;
    m_syn->checkSyntax();
    t = m_lex->getNextToken();
  }

  if (!t->getLex().compare("print"))
  {
    m_syn->m_State = m_syn->print;
    m_syn->checkSyntax();
    t = m_lex->getNextToken();
  }

  if (t->getLex().compare("return"))
  {
    /* ERROR
    std::string tempError = "No se encontro "return" ";
    m_syn->addError(t->getLineNumber(), tempError.c_str(), "");*/
  }
  else
  {
    m_syn->m_State = m_syn->returnState;
    m_syn->checkSyntax();
  }
  if (t->getLex().compare(";"))
  {
    /* ERROR
    std::string tempError = "Se esperaba ";" ";
    m_syn->addError(t->getLineNumber(), tempError.c_str(), "");*/

  }


}
