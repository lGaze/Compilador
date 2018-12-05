#pragma once

#include "../Include/CToken.h"
#include "../Include/CExpLogTreeNode.h"
#include <vector>

namespace CompilerCore
{
  class CExplog
  {
  public:

    CExplog(std::vector<Token*> exp, string funcName, int linenum);
    ~CExplog();



  private:

    int m_lineNum;
    string m_funcName;
    std::vector<Token*> m_exp;

    std::vector<Token*> m_postfixExp;
    string m_SymbolToUpdate;

    CExpLogTreeNode * m_tree;
    NODE_RESULT m_expectedResult;

  public:

    void createPostfix();
    void buildTree();
    bool validateTree();
   
  };
}