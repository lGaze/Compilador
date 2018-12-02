#pragma once
#include <iostream>

namespace CompilerCore
{
  namespace SCOPE
  {
    enum E
    {
      UNDEFINED = 0,
      FUNC,
      GLOBAL_VAR,
      LOCAL_VAR,
      PARAM
    };
  }

	struct Data
	{
		int dimen = 0;
		SCOPE::E scope = SCOPE::UNDEFINED;
		void* value = nullptr;
		std::string type = "";
		std::string funcName = "";
	};

	class CLocalNode
	{
	public:
		CLocalNode(Data data);
		~CLocalNode();
    Data m_data;
    CLocalNode* next = nullptr;
	};
}
