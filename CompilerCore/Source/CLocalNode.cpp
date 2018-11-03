#include "..\Include\CLocalNode.h"

CompilerCore::CLocalNode::CLocalNode(Data data)
{
	m_type = data.type;
	m_scope = data.scope;
	m_dimen = data.dimen;
	m_value = data.value;
	m_localNode = data.localNode;
	m_funcName = data.funcName;
}

CompilerCore::CLocalNode::~CLocalNode()
{
}
