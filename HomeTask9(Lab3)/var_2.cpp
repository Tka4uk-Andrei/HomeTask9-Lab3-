#include <iostream>
#include "task_solution.h"
#include "file_input.h"
#include <string>

using namespace std;

///<summary>Print answer for question: is string valid?</summary>
void printAns(StrIn str)
{
	bool flag = IsRealNum( str.str )? true : false;

	cout << "------\n";
	cout << str.str << "\n";
	cout << "String is corect: " << (flag? "YES\n" : "NO\n");
	if (!flag)
		throw string( "Error occured." );

	cout << "\n";
}

int main()
{
	vector<StrIn> text;
	try
	{
		text = readFile();
		int len = text.size();
		for (int i = 0; i < len; ++i)
			try
			{
				printAns( text[i] );
			}
			catch (string errMes)
			{

			}
	}
	catch (string errMes)
	{
		cout << errMes << "\n";
		cout << "Closing programm...";
		return 0;
	}

	return 0;
}
