#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "file_input_mes.h"
#include "Structs.h"

using namespace std;

/// <summary>
/// ��������� �������������� ��������
/// </summary>
/// <returns>�������� ��������</returns>
int getFilePrefix() throw (string)
{
	int filePrefix;
	cout << "Enter integer - file prefix\n";
	
	if (!(cin >> filePrefix))
		throw PREFIX_READ_ERR;

	return filePrefix;
}

/// <summary>
/// ������ �� �����. ��� ����� ����������, � ������������� ��������� ������������� ����� �������
/// </summary>
/// <returns>
/// ������ ��������� �����
/// </returns>
vector<StrIn> readFile() throw (string)
{
	auto filePrefix = to_string(getFilePrefix());
	fstream input(filePrefix + FILE_NAME);

	if (!input.is_open())
		throw FILE_EXIST_ERR + "\nFile name: \"" + filePrefix + FILE_NAME + "\"";

	vector<StrIn> strs;
	StrIn str;
	while (input.getline(str.str, STR_LEN))
		strs.push_back(str);

	if (strs.size() == 0)
		throw FILE_IS_EMPTY_ERR;

	return strs;
}