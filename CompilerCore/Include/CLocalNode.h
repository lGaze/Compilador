#pragma once
#include <iostream>

namespace CompilerCore
{
	enum SCOPE
	{
		UNDEFINED = 0,
		FUNC,
		GLOBAL_VAR,
		LOCAL_VAR,
		PARAM
	};

	struct Data
	{
		std::string type;
		SCOPE scope;
		int dimen;
		void * value;
		CLocalNode * localNode;
		std::string funcName;
	};

	class CLocalNode
	{
	public:

		CLocalNode(Data data);
		~CLocalNode();

		std::string m_type;
		std::string m_funcName;
		int m_dimen;
		void * m_value;
		CLocalNode * m_localNode;

	private:

	};
}
