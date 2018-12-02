#include "..\Include\CLocalNode.h"

using namespace CompilerCore;

CLocalNode::CLocalNode(Data data)
{
  m_data = data;
}

CLocalNode::~CLocalNode()
{
  if (next)
  {
    delete next;
  }
}
