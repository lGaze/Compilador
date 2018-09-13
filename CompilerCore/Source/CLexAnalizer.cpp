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

	
	while (*currChar != '/0') 
	{
		switch (m_state)
		{
		    case S_START:
		    {
		    	if (isAlpha(currChar) || *currChar == '_')
		    	{
		    		buffer.clear();
		    		buffer.append(currChar, 1);
		    		m_state = S_ID;
		    		currChar++;
		    	}
		    	else if (isDigit(currChar))
		    	{
		           
		    	}
		    }
		    
		    case S_ID:
		    {
				bool finishedToken;

				if (isAlpha(currChar) || *currChar == '_' || isDigit(currChar))
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
						//addToken(buffer.c_str(), KEYWORD, lineNumber);
					}
					else
					{
						//addToken(buffer.c_str(), ID, lineNumber);
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
bool CompilerCore::CLexAnalyzer::isAlpha(const char* currChar)
{
	return false;
}

/*
*/
bool CompilerCore::CLexAnalyzer::isDigit(const char* currChar)
{
	return false;
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
