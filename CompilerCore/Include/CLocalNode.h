#pragma once

class CLocalNode
{
public:
	CLocalNode();
	~CLocalNode();

	string m_type;
	string m_funcName;
	int m_dimen;
	void * m_value;
	CLocalNode * m_localNode;
private:

};
