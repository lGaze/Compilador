#pragma once
#include <iostream>
#include <map>
#include "../Include/CGlobalNode.h"
#include <string.h> 

using std::map;
using std::string;

class CTabSym
{
public:
	CTabSym();
	~CTabSym();
	map<string, CGlobalNode*> m_symbols;

	string getSymbolType();
	string getSymbolScope();
	int getSymbolDim();
	bool addSymbol();
	bool symbolExist();
	bool updateSymbolType();
	void reset();

private:

};