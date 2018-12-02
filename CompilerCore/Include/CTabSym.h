#pragma once
#include <iostream>
#include <map>
#include <string.h> 
#include "../Include/CGlobalNode.h"

using std::map;
using std::string;

namespace CompilerCore
{
  class CTabSym
  {
  public:

    CTabSym();
    ~CTabSym();

    string getSymbolType(string name, SCOPE::E scope = SCOPE::UNDEFINED);
    string getSymbolScope(string name);
    int getSymbolDim(string name, SCOPE::E scope = SCOPE::UNDEFINED);
    bool addSymbol(string name, Data data);
    bool symbolExists(string name, SCOPE::E scope = SCOPE::UNDEFINED);
    bool updateSymbolType(string type, string name, SCOPE::E scope = SCOPE::UNDEFINED);
    void reset();

  private:
    map<string, CGlobalNode*> m_symbols;
  };
}