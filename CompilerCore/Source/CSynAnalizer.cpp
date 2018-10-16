#include "..\Include\CSynAnalizer.h"



CompilerCore::CSynAnalizer::CSynAnalizer(CLexAnalyzer * lex)
{
	
	m_lex = lex;

	m_State			= new CSynProgramState(m_lex, this);
	var				= new CSynVarState(m_lex, this);
	func		    = new CSynFuncState(m_lex, this);
	functionBlock	= new CSynFuntion_BlockState(m_lex, this);
	param		    = new CSynParamState(m_lex, this);
	dimention		= new CSynDimentionState(m_lex, this);
	assign	        = new CSynAssingnState(m_lex, this);
	expLogList      = new CSynExp_Log_ListState(m_lex, this);
	forState        = new CSynForState(m_lex, this);
	funcCall        = new CSynFunc_CallState(m_lex, this);
	ifState         = new CSynIfState(m_lex, this);
	print	        = new CSynPrintState(m_lex, this);
	read            = new CSynReadState(m_lex, this);
	returnState     = new CSynReturnState(m_lex, this);
	switchState     = new CSynSwitchState(m_lex, this);
	whileState      = new CSynWhileState(m_lex, this);
	statementBlock  = new CSynSatement_BlockState(m_lex, this);

}

CompilerCore::CSynAnalizer::~CSynAnalizer()
{
}

void CompilerCore::CSynAnalizer::checkSyntax()
{
	m_State->checkSyntax();
}
