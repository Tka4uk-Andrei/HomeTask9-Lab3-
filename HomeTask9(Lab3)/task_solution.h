#pragma once

/// <summary>
/// Является ли строка действительным числом.
/// Формат +/- NUM . NUM e/E +/- NUM
/// </summary>
/// <param name="arr">Ссылка на элемент, с которого начинается проверка</param>
/// <returns>
/// истину, если число соответствует формату, иначе ложь
/// </returns>
bool IsRealNum(char* arr);