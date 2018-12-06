#pragma once
#include <vector>
#include "../Include/CLexAnalizer.h"
#include "../Include/CExplog.h"
#include "../Include/CErrorsModule.h"
#include "../Include/CToken.h"

namespace CompilerCore
{
  class CSemAnalizer
  {
  public:
    CSemAnalizer(ErrorsModule ^errorsModule);
    ~CSemAnalizer();
  
    std::vector<CExplog*> mexpressions;
    void addExpLog(std::vector<Token*> m_exp, string m_funcName, int linenum);
    void checkExpressions();

    void addError(int linenum, const char * desc, const char *line);
  
  private:
  
    gcroot<ErrorsModule ^> m_errorModule;
    CLexAnalyzer * m_lex;
  
  };
}