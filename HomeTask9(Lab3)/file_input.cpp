#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "file_input_mes.h"
#include "Structs.h"

using namespace std;

/// <summary>
/// Получение целочисленного префикса
/// </summary>
/// <returns>Значение префикса</returns>
int getFilePrefix() throw (string)
{
	int filePrefix;
	cout << "Enter integer - file prefix\n";
	
	if (!(cin >> filePrefix))
		throw PREFIX_READ_ERR;

	return filePrefix;
}

/// <summary>
/// Чтение из файла. Имя файла стандартно, а целочисленный пререфикс запрашивается через консоль
/// </summary>
/// <returns>
/// Массив считанных строк
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