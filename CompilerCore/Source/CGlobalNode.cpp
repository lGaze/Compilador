#include "..\Include\CGlobalNode.h"

using namespace CompilerCore;

CGlobalNode::CGlobalNode(Data data, std::string name)
{
    m_data = data;
    m_name = name;
}

CGlobalNode::~CGlobalNode()
{
  if (next)
  {
    delete next;
  }
}
