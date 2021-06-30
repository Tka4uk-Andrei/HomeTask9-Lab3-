#pragma once
#include <vector>
#include "Structs.h"

/// <summary>
/// Чтение из файла. Имя файла стандартно, а целочисленный пререфикс запрашивается через консоль
/// </summary>
/// <returns>
/// Массив считанных строк
/// </returns>
std::vector<StrIn> readFile() throw (std::string);