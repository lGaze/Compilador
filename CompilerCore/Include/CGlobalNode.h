#pragma once
#include "../Include/CLocalNode.h"

class CGlobalNode
{
public:
	CGlobalNode();
	~CGlobalNode();
	string m_name;
	string m_type;
	int m_dimen;
	void * m_value;
	CLocalNode * m_localNode;

private:

};
