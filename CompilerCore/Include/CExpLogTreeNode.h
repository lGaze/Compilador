#pragma once
#include "../Include/CToken.h"
#include "..\Include\CSemAnalizer.h"

class CSemAnalizer;
namespace CompilerCore
{
  enum NODE_RESULT
  {
    E_ARIT,
    E_LOG,
    E_REL
  };

  class CExpLogTreeNode
  {
  public:

    CExpLogTreeNode(Token * t);
    ~CExpLogTreeNode();

    CExpLogTreeNode * m_left;
    CExpLogTreeNode * m_right;
    Token * m_value;

    NODE_RESULT m_result;
    NODE_RESULT m_nodetype;
    NODE_RESULT m_expectedResultLeft;
    NODE_RESULT m_expectedResultRight;

   void inOrder();

  private:

    CSemAnalizer * sem;

  };
}
