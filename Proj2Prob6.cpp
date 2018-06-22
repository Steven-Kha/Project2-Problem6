//Alex Chau, Steven Kha, Arshdeep Singh
//CPSC 323, Project 2 Problem #6

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findRowValue (string s);

int findColValue (string s);

int main() {

	string pTable[5][8] = {
	  {"TQ", "", "", "", "", "TQ", "", ""},
	  {"", "+TQ", "-TQ", "", "", "TQ", "~", "~" },
	  {"FR", "", "", "", "", "FR", "", "" },
	  { "", "~", "~", "*FR", "/FR", "", "~", "~" },
	  { "a", "", "", "", "", "(E)", "", "" },
	 };

	string tokenCol[8] = { "a", "+", "-", "*", "/", "(", ")", "$" };

	//const int stateROW = 5;	

	/*char tokenCol[8] = { "a", "+", "-", "*", "/", "(", ")", "$" };

	char stateRow[5] = { "E", "Q", "T", "R", "F"};
	*/

	string hi =  " ";

	//vector<char> stack;

	vector<string> stack;

	string sInput = " ";

	//(a+a)*a$
	cout << "Enter a string : ";
	cin >> sInput;

	int colValue = 0;

	int rowValue = 0;

	stack.push_back("E");
	string token = " ";

	bool lexer = false;

	for (int i = 0; i < sInput.length(); i++)
	{
		token = sInput[i];
		lexer = false;
			
		while (lexer == false)
		{
			if ( stack[stack.size()-1] == token )
			{		
				
				cout << "[ '" << token << "' found ]\n";
				
				stack.pop_back();	
				lexer = true;
			}
			else if (stack[stack.size()-1] == "~")
			{
				cout << "[ ~" << " = epsilon found]\n";
				stack.pop_back();
			}
			else if (token == "$")
			{
				if( pTable[findRowValue(stack[stack.size()-1])][findColValue(token)] == "~" ) 
				{
					cout << "[ " << "'$' found ] \n";
					cout << "[" << sInput << " is accepted ]\n";
					system("pause");
					exit(1);
				}
				else
				{
					cout << "String not accepted \n";
					system("pause");
					exit(1);
				}
			}
			else if ( stack[stack.size()-1] != token)
			{
				//cout << stack[stack.size()-1] << ": " << token << endl;
				
				string terminal = pTable[findRowValue(stack[stack.size()-1])][findColValue(token)];
				cout << stack[stack.size()-1] << ": " << terminal << endl;
				stack.pop_back();

				if (terminal == "")
				{
					cout << "string not accepeted \n";
					system("pause");
					exit(1);
				}
				
				for (int j = terminal.length()-1; j >= 0; j--)
				{
					
					string strs (1,terminal[j]);
					stack.push_back(strs);
				}

			}				

		}

	}

	system("pause");
	return 0;
}
int findRowValue (string s) {
	string stateRow[5] = { "E", "Q", "T", "R", "F"};
	for (int i = 0; i < sizeof(stateRow); i++)
	{
		if (s == stateRow[i])
		{
			return i;
		}		
	}	
	return 100;
}

int findColValue (string s) {
	
	string tokenCol[8] = { "a", "+", "-", "*", "/", "(", ")", "$" };
	for (int i = 0; i < sizeof(tokenCol); i++)
	{
		if (s == tokenCol[i])
		{
			return i;
		}
	}
	return 100;
}