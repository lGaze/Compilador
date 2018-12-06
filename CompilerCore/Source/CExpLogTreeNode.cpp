#include "..\Include\CExpLogTreeNode.h"

CompilerCore::CExpLogTreeNode::CExpLogTreeNode(Token* t)
{
  m_left = nullptr;
  m_right = nullptr;
  m_value = t;
  TOKEN_TYPE tokenToCheck;

  tokenToCheck = m_value->getType();

  switch (tokenToCheck)
  {
  case CompilerCore::ID:
  {
    m_nodetype = NODE_RESULT::E_ARIT;
    m_expectedResultLeft = NODE_RESULT::E_ARIT;
    m_expectedResultRight = NODE_RESULT::E_ARIT;
    break;
  }
  case CompilerCore::INT:
  case CompilerCore::FLOAT:
  case CompilerCore::OPER_ARITMETICOS:
  {
    m_nodetype = NODE_RESULT::E_ARIT;
    m_expectedResultLeft = NODE_RESULT::E_ARIT;
    m_expectedResultRight = NODE_RESULT::E_ARIT;
    break;
  }

  case CompilerCore::OPER_LOGICO_UNARIO:
  case CompilerCore::OPER_LOGICOS:
  {
    m_nodetype = NODE_RESULT::E_LOG;
    m_expectedResultLeft = NODE_RESULT::E_LOG;
    m_expectedResultRight = NODE_RESULT::E_LOG;
    break;
  }

  case CompilerCore::STRING:
  case CompilerCore::OPER_RELACIONALES:
  {
    m_nodetype = NODE_RESULT::E_REL;
    m_expectedResultLeft = NODE_RESULT::E_REL;
    m_expectedResultRight = NODE_RESULT::E_REL;
    break;
  }
  default:
  {
    break;
  }
  }

}

CompilerCore::CExpLogTreeNode::~CExpLogTreeNode()
{
}

void CompilerCore::CExpLogTreeNode::inOrder()
{
  if (m_right != nullptr)
  {
    m_right->inOrder();
  }
  
   //Valida los tokens y manda errores
   //sem->addError()
  
  if (m_left != nullptr)
  {
    m_left->inOrder();
  }
}

