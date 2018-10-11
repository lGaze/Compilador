#pragma once
#include "../Include/CLocalNode.h"

enum E_SCOPE
{
	UNDEFINED = 0,
	FUNC,
	GLOBAL_VAR,
	LOCAL_VAR,
	PARAM
};

class CGlobalNode
{
public:
	CGlobalNode();
	~CGlobalNode();

	string m_name;
	string m_type;
	E_SCOPE m_scope;
	int m_dimen;
	void * m_value;
	CLocalNode * m_localNode;

private:

};
