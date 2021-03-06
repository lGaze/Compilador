#include "..\Include\CLexAnalizer.h"

CompilerCore::CLexAnalyzer::CLexAnalyzer(ErrorsModule ^ errorsModule) :
  managedRef_errorsModule(errorsModule),
  m_currentToken(0),
  m_lastToken(new Token("", UNDEFINED, 0))
{
	m_Keywords["var"		] = "";
	m_Keywords["main"		] = "";
	m_Keywords["int"		] = "";
	m_Keywords["float"		] = "";
	m_Keywords["string"		] = "";
	m_Keywords["bool"		] = "";
	m_Keywords["void"		] = "";
	m_Keywords["function"	] = "";
	m_Keywords["if"			] = "";
	m_Keywords["else"		] = "";
	m_Keywords["while"		] = "";
	m_Keywords["for"		] = "";
	m_Keywords["inc"		] = "";
	m_Keywords["dec"		] = "";
	m_Keywords["switch"		] = "";
	m_Keywords["case"		] = "";
	m_Keywords["default"	] = "";
	m_Keywords["print"		] = "";
	m_Keywords["read"		] = "";
	m_Keywords["return"		] = "";
	m_Keywords["true"		] = "";
	m_Keywords["false"		] = "";



}

/*
*/
CompilerCore::CLexAnalyzer::~CLexAnalyzer()
{
	managedRef_errorsModule->reset();
	m_Tokens.clear();
}

/*
*/
bool CompilerCore::CLexAnalyzer::parseSourceCode(const char * sourceCode)
{

	int lineNumber = 1;
	const char * currChar = sourceCode;
	const char * offset;
	std::string buffer;
	std::string lineBuffer;
	m_state = S_START;

	/**
	 * Parser
	 */
	while (*currChar != '\0') 
	{
		switch (m_state)
		{
		    case S_START:
		    {
				//Nex line '\n'
				if (*currChar == '\n')
				{
					lineNumber++;
					currChar++;
				}
				//Tab and Space
				else if (*currChar == '\t' || *currChar == ' ')
				{
					currChar++;
				}
				//ID, KEYWORD
		    	else if (is_Alpha(currChar) || *currChar == '_')
		    	{
		    		buffer.clear();
		    		m_state = S_ID;
					break;
		    	}
				//INT
		    	else if (is_Digit(currChar))
		    	{
					buffer.clear();
					m_state = S_INT;
					break;
		    	}
				//FLOAT
				else if (*currChar == '.')
				{
					buffer.clear();
					buffer.append(currChar, 1);
					m_state = S_FLOAT;
					break;
				}
				// STRING
				else if (*currChar == '"')
				{
					buffer.clear();
					m_state = S_STRING;
					break;
				}
				//DELIM
				else if (*currChar == ','|| *currChar == ';'|| *currChar == ':')
				{
					buffer.clear();
					buffer.append(currChar, 1);
					m_state = S_DELIM;
					break;
				}
				//OPER ASIG
				else if (*currChar == '=')
				{
					offset = currChar;
					buffer.clear();
					buffer.append(currChar, 1);
					m_state = S_OPER_ASIGNACION;
					offset++;
					break;
				}
				//OPER REL
				else if (*currChar == '<'||*currChar == '>')
				{
					offset = currChar;
					buffer.clear();
					buffer.append(currChar, 1);
					m_state = S_OPER_RELACIONAL;
					offset++;
					break;
				}
				//OPER ARIT
				else if (*currChar == '+' || *currChar == '-' || *currChar == '/' || *currChar == '%' || *currChar == '*' || *currChar == '^')
				{
					if (*currChar == '/')
					{
						offset = currChar;
						offset++;
					}
					buffer.clear();
					buffer.append(currChar, 1);
					m_state = S_OPER_ARITMETICO;
					break;
				}
				//OPER LOGI
				else if (*currChar == '&' || *currChar == '|')
				{
					offset = currChar;
					buffer.clear();
					buffer.append(currChar, 1);
					m_state = S_OPER_LOGICO;
					offset++;
					break;
				}
				//OPER UN
				else if (*currChar == '!')
				{
					offset = currChar;
					buffer.clear();
					buffer.append(currChar, 1);
					m_state = S_OPER_LOGICO_UNITARIO;
					offset++;
					break;
				}
				//OPER AGRU
				else if (*currChar == '(' || *currChar == ')' || *currChar == '{' || *currChar == '}' )
				{
					buffer.clear();
					buffer.append(currChar, 1);
					m_state = S_OPER_AGRUPACION;
					break;
				}
				//OPER DIMEN
				else if (*currChar == '[' || *currChar == ']')
				{
					buffer.clear();
					buffer.append(currChar, 1);
					m_state = S_OPER_DIMENSIONAL;
					break;
				}
				//NINGUN CASO
				else
				{
					const char * desc = "Simbolo invalido";
					lineBuffer.append(currChar, 1);
					managedRef_errorsModule->addErrorLex(lineNumber, desc, lineBuffer.c_str());
					//lineBuffer.clear();
					currChar++;
					break;
				}
				break;
		    }
		    
		    case S_ID:
		    {
				buffer.append(currChar, 1);
				currChar++;
				bool finishedToken = false;

				if (  is_Alpha(currChar) || *currChar == '_' || is_Digit(currChar))
				{
					buffer.append(currChar, 1);
					currChar++;
					if (*currChar == '\0' || *currChar == ' ' || !is_Alpha(currChar) && !is_Digit(currChar) && *currChar != '_')
					{
						finishedToken = true;
					}
				
				}
				else
				{
					finishedToken = true;
				}

				if (finishedToken)
				{
					if (m_Keywords.find(buffer) != m_Keywords.end())
					{
						addToken(buffer.c_str(), KEYWORD, lineNumber);
					}
					else
					{
						addToken(buffer.c_str(), ID, lineNumber);
					}
					m_state = S_START;
					finishedToken = false;
					break;
				}
				break;
		    }

			case S_OPER_LOGICO:
			{
				if (*offset != *currChar)
				{
					const char * desc = "Operador logico incompleto";
					lineBuffer.append(currChar, 1);
					managedRef_errorsModule->addErrorLex(lineNumber, desc, lineBuffer.c_str());
					lineBuffer.clear();
					currChar++;
					m_state = S_START;
					break;
				}
				else
				{
					currChar++;
					buffer.append(currChar, 1);
					addToken(buffer.c_str(), OPER_LOGICOS, lineNumber);
					m_state = S_START;
					currChar++;
					break;
				}
				break;
			}

			case S_OPER_LOGICO_UNITARIO:
			{
				bool finishedToken = false;
				if (*offset == '=')
				{
					currChar++;
					m_state = S_OPER_RELACIONAL;
					break;
				}
				else
				{
					finishedToken = true;
				}
				if (finishedToken)
				{
					addToken(buffer.c_str(), OPER_LOGICO_UNARIO, lineNumber);
					m_state = S_START;
					currChar++;
					finishedToken = false;
					break;
				}
			}

			case S_OPER_ARITMETICO:
			{
				if (*offset == '*')
				{
					currChar++;
					buffer.append(currChar,1);
					m_state = S_COMMENT;
					break;
				}
				addToken(buffer.c_str(), OPER_ARITMETICOS, lineNumber);
				currChar++;
				m_state = S_START;
				break;
			}

			case S_OPER_RELACIONAL:
			{
				bool finishedToken = false;
				if (*offset != '=')
				{
					finishedToken = true;
				}
				else
				{
					buffer.append(currChar, 1);
					currChar++;
					finishedToken = true;
				}
				if (finishedToken)
				{
				    addToken(buffer.c_str(), OPER_RELACIONALES, lineNumber);
					m_state = S_START;
					finishedToken = false;
					break;
				}
				break;
			}

			case S_OPER_ASIGNACION:
			{
				if (*offset == '=')
				{
					currChar++;
					m_state = S_OPER_RELACIONAL;
					break;
				}
				else
				{
					addToken(buffer.c_str(), OPER_ASIGNACION, lineNumber);
					currChar++;
					m_state = S_START;
					break;
				}
				break;
			}

			case S_DELIM:
			{
				addToken(buffer.c_str(), DELIM, lineNumber);
				currChar++;
				m_state = S_START;
				break;
			}

			case S_INT:
			{
				bool finishedToken = false;
				buffer.append(currChar, 1);
				currChar++;
			
				if (is_Digit(currChar))
				{
					buffer.append(currChar, 1);
					currChar++;
					if (*currChar == '\0')
					{
						finishedToken = true;
					}
				
				}
				
				else if (*currChar == '.')
				{
					buffer.append(currChar, 1);
					m_state = S_FLOAT;
					break;
				}
			
				else
				{
					finishedToken = true;
				}

				if (finishedToken)
				{
					addToken(buffer.c_str(), INT, lineNumber);
					m_state = S_START;
					finishedToken = false;
					break;
				}
				break;
			}

			case S_FLOAT:
			{
				offset = currChar;
				bool finishedToken = false;
				currChar++;

				if (*offset == '.' && !is_Digit(currChar))
				{
					buffer.append(currChar, 1);
					const char * desc = "Numero Flotante invalido";
					lineBuffer.append(buffer);
					managedRef_errorsModule->addErrorLex(lineNumber, desc, lineBuffer.c_str());
					lineBuffer.clear();
					currChar++;
					m_state = S_START;
					break;
				}

				if (is_Digit(currChar))
				{
					buffer.append(currChar, 1);
					currChar++;
					if (*currChar == '\0' || !is_Digit(currChar))
					{
						finishedToken = true;
					}					
				}
				else
				{
					finishedToken = true;
				}

				if (finishedToken)
				{
					addToken(buffer.c_str(), FLOAT, lineNumber);
					m_state = S_START;
					finishedToken = false;
					break;
				}
				break;
			}

			case S_STRING:
			{
				bool finishedToken = false;
				buffer.append(currChar, 1);
				currChar++;

				if (*currChar != '"')
				{
					buffer.append(currChar, 1);
					currChar++;
					if (*currChar == '\0' || *currChar == '\n')
					{
						const char * desc = "String sin cerrar";
						lineBuffer.append(buffer);
						managedRef_errorsModule->addErrorLex(lineNumber, desc, lineBuffer.c_str());
						lineBuffer.clear();
						m_state = S_START;
						break;
					}
					break;
				}
				else
				{
					finishedToken = true;
				}
				if (finishedToken)
				{
					addToken(buffer.c_str(), STRING, lineNumber);
					currChar++;
					m_state = S_START;
					finishedToken = false;
					break;
				}
			}

			case S_OPER_AGRUPACION:
			{
				addToken(buffer.c_str(), OPER_AGRUPACION, lineNumber);
				currChar++;
				m_state = S_START;
				break;
			}

			case S_OPER_DIMENSIONAL:
			{
				addToken(buffer.c_str(), OPER_DIMENSIONAL, lineNumber);
				currChar++;
				m_state = S_START;
				break;
			}

			case S_COMMENT:
			{
				bool finishedComment = false;
				currChar++;
				offset = currChar;
				offset++;
				while (*currChar != '*' || *currChar != '\0')
				{
					
					buffer.append(currChar, 1);
					currChar++;
					offset++;
					if (*currChar == '*' && *offset == '/')
					{
						finishedComment = true;
					}
 					if(*offset == '\0')
					{
						bool a = true;		
						const char * desc = "Comentario sin cerrar";
						lineBuffer.append(buffer);
						managedRef_errorsModule->addErrorLex(lineNumber, desc, lineBuffer.c_str());
						lineBuffer.clear();
						currChar = offset;
						m_state = S_START;
						break;
					}
					if (finishedComment)
					{			
						m_state = S_START;
						currChar++;
						currChar++;
						finishedComment = false;
						break;
					}
				}	
			}
		}
	}

	return true;
}


/*
*/
bool CompilerCore::CLexAnalyzer::addToken(std::string lex, TOKEN_TYPE type, int lineNum)
{
	Token * token = new Token(lex, type, lineNum);
	m_Tokens.push_back(token);
	m_currentToken++;
	return true;
}

/*
*/
void CompilerCore::CLexAnalyzer::reset()
{
	managedRef_errorsModule->reset();
	m_Tokens.clear();
}

/*
*/
void CompilerCore::CLexAnalyzer::getTokens(std::vector<Token*>* tokensVec) const
{
	*tokensVec = m_Tokens;
}

/*
*/
bool CompilerCore::CLexAnalyzer::is_Alpha(const char * currchar)
{
	if ((int)*currchar > 64 && (int)*currchar < 91 || (int)*currchar > 96 && (int)*currchar < 123)
	{
		return true;
	}
	return false;
}

/*
*/
bool CompilerCore::CLexAnalyzer::is_Digit(const char * currchar)
{
	if ((int)*currchar > 47 && (int)*currchar < 58)
	{
		return true;
	}
	return false;
}