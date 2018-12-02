#include "..\Include\CSynAnalizer.h"
#include "../Include/CSynVarState.h"
#include "../Include/CSynFuncState.h"
#include "../Include/CSynFunction_BlockState.h"
#include "../Include/CSynDimentionState.h"
#include "../Include/CSynParamState.h"
#include "../Include/CSynAssignState.h"
#include "../Include/CSynExp_Log_ListState.h"
#include "../Include/CSynForState.h"
#include "../Include/CSynFuncState.h"
#include "../Include/CSynIfState.h"
#include "../Include/CSynPrintState.h"
#include "../Include/CSynReadState.h"
#include "../Include/CSynReturnState.h"
#include "../Include/CSynSwitchState.h"
#include "../Include/CSynWhileState.h"
#include "../Include/CSynStatement_BlockState.h"
#include "../Include/CSynFunc_CallState.h"
#include "../Include/CSynExpLogState.h"
#include "../Include/CSynMainState.h"
#include "../Include/CSynProgramState.h"


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
	expLog			= new CSynExpLogState(m_lex, this);
	main			= new CSynMainState(m_lex, this);

}

CompilerCore::CSynAnalizer::~CSynAnalizer()
{
}

void CompilerCore::CSynAnalizer::checkSyntax()
{
	m_State->checkSyntax();
}
