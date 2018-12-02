#pragma once
#include "../Include/CLocalNode.h"

namespace CompilerCore
{
  class CGlobalNode
  {
  public:
  
  	CGlobalNode(Data data, std::string name);
  	~CGlobalNode();
  
  	std::string m_name;
    Data m_data;
    CLocalNode* next = nullptr;
  };
}