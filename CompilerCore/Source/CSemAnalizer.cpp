#include "..\Include\CSemAnalizer.h"

CompilerCore::CSemAnalizer::CSemAnalizer(ErrorsModule ^errorsModule)
{
  m_errorModule = errorsModule;
}

CompilerCore::CSemAnalizer::~CSemAnalizer()
{
}

void CompilerCore::CSemAnalizer::addExpLog(std::vector<Token*> exp, string funcName, int linenum)
{
  CExplog * explog = new CExplog(exp,funcName,linenum);
  explog->createPostfix();
  explog->buildTree();
  mexpressions.push_back(explog);

}

void CompilerCore::CSemAnalizer::checkExpressions()
{
  int i = 0;
  while (i < mexpressions.size())
  {
    mexpressions[i]->validateTree();
  }

}

void CompilerCore::CSemAnalizer::addError(int linenum, const char * desc, const char * line)
{
  m_errorModule->addErrorSem(linenum, desc, line);
}
