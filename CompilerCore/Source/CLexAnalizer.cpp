#include "..\Include\CLexAnalizer.h"

CompilerCore::CLexAnalyzer::CLexAnalyzer(ErrorsModule ^ errorsModule)
{
}

/*
*/
CompilerCore::CLexAnalyzer::~CLexAnalyzer()
{
}

/*
*/
bool CompilerCore::CLexAnalyzer::parseSourceCode(const char * sourceCode)
{

	int lineNumber = 1;
	const char * currChar = sourceCode;
	std::string buffer;
	std::string lineBuffer;
	m_state = S_START;

	/**
	 * Parser
	 */
	while (*currChar != '/0') 
	{
		switch (m_state)
		{
		    case S_START:
		    {
				// ID, KEYWORD
		    	if (isalpha((int)*currChar) || *currChar == '_')
		    	{
		    		buffer.clear();
		    		buffer.append(currChar, 1);
		    		m_state = S_ID;
		    		currChar++;
		    	}
				// INT
		    	else if (isdigit((int)*currChar))
		    	{
					buffer.clear();
					buffer.append(currChar, 1);
					m_state = S_INT;
					currChar++;
		    	}
				// Float
				else if (*currChar == '.')
				{
					buffer.clear();
					buffer.append(currChar, 1);
					m_state = S_FLOAT;
					currChar++;
				}
				else if (*currChar == '"')
				{
					buffer.clear();
					buffer.append(currChar, 1);
					m_state = S_STRING;
					currChar++;
				}
		    }
		    
		    case S_ID:
		    {
				bool finishedToken;

				if (  isalpha((int)*currChar) || *currChar == '_' || isdigit((int)*currChar))
				{
					buffer.append(currChar, 1);
					currChar++;
					if (*currChar == '/0')
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
				}
		    }

			case S_KEYWORDS:
			{

			}

			case S_OPER_LOGICOS:
			{

			}

			case S_OPER_LOGICO_UNITARIO:
			{

			}

			case S_OPER_ARITMETICOS:
			{

			}

			case S_OPER_RELACIONALES:
			{

			}

			case S_OPER_ASIGNACION:
			{

			}

			case S_DELIM:
			{

			}

			case S_INT:
			{
				bool finishedToken;

			
				if (isdigit((int)*currChar))
				{
					buffer.append(currChar, 1);
					currChar++;
					if (*currChar == '/0')
					{
						finishedToken = true;
					}
				}
				
				else if (*currChar == '.')
				{
					buffer.append(currChar, 1);
					m_state = S_FLOAT;
					currChar++;
				}
			
				else
				{
					finishedToken = true;
				}

				if (finishedToken == true)
				{
					if (m_Keywords.find(buffer) != m_Keywords.end())
					{
						addToken(buffer.c_str(), INT, lineNumber);
					}
					m_state = S_START;
				}

			}

			case S_FLOAT:
			{
				bool finishedToken;


				if (isdigit((int)*currChar))
				{
					buffer.append(currChar, 1);
					currChar++;
					if (*currChar == '/0')
					{
						finishedToken = true;
					}
				}
				else
				{
					finishedToken = true;
				}

				if (finishedToken == true)
				{
					if (m_Keywords.find(buffer) != m_Keywords.end())
					{
						addToken(buffer.c_str(), FLOAT, lineNumber);
					}
					m_state = S_START;
				}
			}

			case S_STRING:
			{
				bool finishedToken;

				if (*currChar != '"')
				{
					buffer.append(currChar, 1);
					currChar++;
				}
				if (*currChar == '"' || *currChar == '/0')
				{
					finishedToken = true;
				}
				if (finishedToken == true);
				{
					if (m_Keywords.find(buffer) != m_Keywords.end())
					{
						addToken(buffer.c_str(), STRING, lineNumber);
					}
					m_state = S_START;
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
	return true;
}

/*
*/
void CompilerCore::CLexAnalyzer::reset()
{
}

/*
*/
void CompilerCore::CLexAnalyzer::getTokens(std::vector<Token*>* tokensVec) const
{
}
