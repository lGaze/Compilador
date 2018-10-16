#include "..\Include\CSynReadState.h"

CompilerCore::CSynReadState::CSynReadState(CLexAnalyzer * lex, CSynAnalizer * syn)
{
	m_lex = lex;
	m_syn = syn;
}

CompilerCore::CSynReadState::~CSynReadState()
{
}

void CompilerCore::CSynReadState::checkSyntax()
{
}
