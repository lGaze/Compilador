#include "..\Include\CTabSym.h"

using namespace CompilerCore;
using namespace SCOPE;

CTabSym::CTabSym()
{
}

CTabSym::~CTabSym()
{
  reset();
}

string CTabSym::getSymbolType(string name, SCOPE::E scope)
{
  auto search = m_symbols.find(name);
  if (search != m_symbols.end())
  {
    switch (scope)
    {
    case FUNC:
    case GLOBAL_VAR:
    {
      if (search->second->m_data.scope == scope)
      {
        return search->second->m_data.type;
      }
      return "";
      break;
    }
    case LOCAL_VAR:
    case PARAM:
    {
      auto localNode = search->second->next;
      while (localNode != nullptr)
      {
        if (localNode->m_data.scope == scope)
        {
          return localNode->m_data.type;
        }
        else
        {
          localNode = localNode->next;
        }
      }
      return "";
      break;
    }
    case UNDEFINED: //if looking for undefined any scope is valid
    default:
    {
      if (search->second->m_data.scope != UNDEFINED)
      {
        return search->second->m_data.type;
      }
      auto localNode = search->second->next;
      if (localNode != nullptr)
      {
        return localNode->m_data.type;
      }
      return "";
      break;
    }
    }
  }
  else
  {
    return "";
  }
}

string CTabSym::getSymbolScope(string name)
{
  auto search = m_symbols.find(name);
  if (search != m_symbols.end())
  {
    SCOPE::E searchScope =
      search->second->m_data.scope;

    switch (searchScope)
    {
    case FUNC:
      return "FUNC";
      break;
    case GLOBAL_VAR:
      return "GLOBAL_VAR";
      break;
    case UNDEFINED:
    default:
    {
      auto localNode = search->second->next;
      if (localNode != nullptr)
      {
        searchScope = localNode->m_data.scope;
        if (searchScope == PARAM)
        {
          return "PARAM";
        }
        else if(searchScope == LOCAL_VAR)
        {
          return "LOCAL_VAR";
        }
      }
      return "";
      break;
    }
    }
  }
  else
  {
    return "";
  }
}

int CTabSym::getSymbolDim(string name, SCOPE::E scope)
{
  auto search = m_symbols.find(name);
  if (search != m_symbols.end())
  {
    switch (scope)
    {
    case FUNC:
    case GLOBAL_VAR:
    {
      if (search->second->m_data.scope == scope)
      {
        return search->second->m_data.dimen;
      }
      return -1;
      break;
    }
    case LOCAL_VAR:
    case PARAM:
    {
      auto localNode = search->second->next;
      while (localNode != nullptr)
      {
        if (localNode->m_data.scope == scope)
        {
          return localNode->m_data.dimen;
        }
        else
        {
          localNode = localNode->next;
        }
      }
      return -1;
      break;
    }
    case UNDEFINED: //if looking for undefined any scope is valid
    default:
    {
      if (search->second->m_data.scope != UNDEFINED)
      {
        return search->second->m_data.dimen;
      }
      auto localNode = search->second->next;
      if (localNode != nullptr)
      {
        return localNode->m_data.dimen;
      }
      return -1;
      break;
    }
    }
  }
  else
  {
    return -1;
  }
}

bool CTabSym::addSymbol(string name, Data data)
{
  auto search = m_symbols.find(name);
  if (search != m_symbols.end())
  {
    switch (search->second->m_data.scope)
    {
    case FUNC:
    case GLOBAL_VAR:
    {
      //TODO: Symbol redefinition error
      return false;
      break;
    }
    case UNDEFINED:
    default:
    {
      auto localNode = search->second->next;
      while (localNode->next != nullptr)
      {
        if (localNode->m_data.funcName == data.funcName)
        {
          //TODO: Symbol redefinition error
          return false;
        }
      }
      localNode->next = new CLocalNode(data);
      return true;
      break;
    }
    }
  }
  else
  {
    switch (data.scope)
    {
    case GLOBAL_VAR:
    case FUNC:
      m_symbols.insert({ name, new CGlobalNode(data,name) });
      break;
    default:
      Data empty;
      m_symbols.insert({ name, new CGlobalNode(empty,name) });
      m_symbols[name]->next = new CLocalNode(data);
      break;
    }
    return true;
  }
}

bool CTabSym::symbolExists(string name, SCOPE::E scope)
{
  auto search = m_symbols.find(name);
  if (search != m_symbols.end())
  {
    SCOPE::E searchScope =
      search->second->m_data.scope;

    switch (scope)
    {
    case FUNC:
    case GLOBAL_VAR:
    {
      return (scope == searchScope);
      break;
    }
    case LOCAL_VAR:
    case PARAM:
    {
      auto localNode = search->second->next;
      while (localNode != nullptr)
      {
        if (localNode->m_data.scope == scope)
        {
          return true;
        }
        else
        {
          localNode = localNode->next;
        }
      }
      return false;
      break;
    }
    case UNDEFINED: //if looking for undefined any scope is valid
    default:
    {
      return true;
      break;
    }
    }
  }
  else
  {
    return false;
  }
}

bool CTabSym::updateSymbolType(string type, string name, SCOPE::E scope)
{
  auto search = m_symbols.find(name);
  if (search != m_symbols.end())
  {
    switch (scope)
    {
    case FUNC:
    case GLOBAL_VAR:
    {
      if (search->second->m_data.scope == scope)
      {
        search->second->m_data.type = type;
        return true;
      }
      return false;
      break;
    }
    case LOCAL_VAR:
    case PARAM:
    {
      auto localNode = search->second->next;
      while (localNode != nullptr)
      {
        if (localNode->m_data.scope == scope)
        {
          localNode->m_data.type = type;
          return true;
        }
        else
        {
          localNode = localNode->next;
        }
      }
      return false;
      break;
    }
    case UNDEFINED: //if looking for undefined any scope is valid
    default:
    {
      if (search->second->m_data.scope != UNDEFINED)
      {
        search->second->m_data.type = type;
        return true;
      }
      auto localNode = search->second->next;
      if (localNode != nullptr)
      {
        localNode->m_data.type = type;
        return true;
      }
      return false;
      break;
    }
    }
  }
  else
  {
    return false;
  }
}

void CTabSym::reset()
{
  for each (auto node in m_symbols)
  {
    delete node.second;
  }
  m_symbols.clear();
}
