#include "..\Include\CExplog.h"
#include <stack>

CompilerCore::CExplog::CExplog(std::vector<Token*> exp, string funcName, int linenum)
{
  m_funcName = funcName;
  m_exp = exp;
  m_lineNum = linenum;
}

CompilerCore::CExplog::~CExplog()
{
}

void CompilerCore::CExplog::createPostfix()
{
#define TOKEN1 (*iterator1)
#define TOKEN2 (*iterator2)

  auto iterator1 = m_exp.begin();
  auto iterator2 = iterator1 + 1;
  TOKEN_TYPE tokenToCheck;

  std::stack<Token*> tempTokens;
  Token * tempTokenToSave;
  int open = 0;
  int i = 0;

//exp:     (a+b)*(c-d)+((e/f)*(a+b))
//        ^^
//open = 0
//tmpTokens: <>
//postfix:   <ab+cd-*ef/ab+*+>

  while (i < m_exp.size())
  {
    tokenToCheck = TOKEN1->getType();

    switch (tokenToCheck)
    {
      case CompilerCore::ID:
      {
        if (TOKEN2->getType() == OPER_ASIGNACION)
        {
          m_SymbolToUpdate = TOKEN1->getLex();
          iterator1++;
          iterator2++;
        }
        if(TOKEN2->getType() == OPER_ARITMETICOS)
        {
          m_postfixExp.push_back(TOKEN1);
        }
        break;
      }
      case CompilerCore::KEYWORD:
      {
        break;
      }
      case CompilerCore::OPER_LOGICOS:
      {
        break;
      }
      case CompilerCore::OPER_LOGICO_UNARIO:
      {
        break;
      }
      case CompilerCore::OPER_ARITMETICOS:
      case CompilerCore::OPER_RELACIONALES:
      {

        if (TOKEN2->getType() == ID)
        {
          m_postfixExp.push_back(TOKEN2);
          m_postfixExp.push_back(TOKEN1);
          iterator1++;
          iterator2++;
        }

        if (TOKEN2->getType() == OPER_AGRUPACION)
        {
          tempTokens.push(TOKEN1);
        }

        break;
      }
      case CompilerCore::OPER_AGRUPACION:
      {
        if (!TOKEN1->getLex().compare("("))
        {
          open++;
        }

        if (!TOKEN1->getLex().compare(")"))
        {
          if (open == tempTokens.size())
          {
            m_postfixExp.push_back(tempTokens.top());
            tempTokens.pop();
          }
          open--;
        }
        break;
      }
      case CompilerCore::OPER_DIMENSIONAL:
      {
        break;
      }
      default:
      {
        break;
      }
    }

    i++;
    iterator1++;
    iterator2++;

  }
}

// ab+c*
// ^
// <"a + b * c" >
void CompilerCore::CExplog::buildTree()
{

  std::stack<CExpLogTreeNode*> tree;
  TOKEN_TYPE tokenToCheck;

  int i = 0;
  while (i < m_postfixExp.size())
  {
    //Creo que se rompe :S
    CExpLogTreeNode * root = new CExpLogTreeNode(m_postfixExp[i]);
    tokenToCheck = m_postfixExp[i]->getType();

    switch (tokenToCheck)
    {
      case CompilerCore::OPER_LOGICO_UNARIO:
      case CompilerCore::OPER_RELACIONALES:
      case CompilerCore::OPER_ASIGNACION:
      case CompilerCore::OPER_AGRUPACION:
      case CompilerCore::OPER_DIMENSIONAL:
      case CompilerCore::OPER_LOGICOS:
      case CompilerCore::OPER_ARITMETICOS:
      {
        root->m_right = tree.top();
        tree.pop();
        root->m_left = tree.top();
        tree.pop();
        tree.push(root);
      }

      case CompilerCore::INT:
      case CompilerCore::FLOAT:
      case CompilerCore::STRING:
      case CompilerCore::ID:
      {
        tree.push(root);
        break;
      }

      default:
      {
        break;
      }
    }
    i++;
  }
  m_tree = tree.top();
  tree.top();
}

bool CompilerCore::CExplog::validateTree()
{
  return false;
}
