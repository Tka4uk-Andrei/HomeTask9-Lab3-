/// <summary>
/// Является ли символ знаком плюса или минуса
/// </summary>
/// <param name="arr">Ссылка на проверяемый элемент</param>
/// <returns>
/// истину, если символ плюс или минус, ложь в противном случае
/// </returns>
bool IsSign(char* arr)
{
	return *arr == '-' || *arr == '+';
}

/// <summary>
/// Является ли символ цифрой
/// </summary>
/// <param name="arr">Ссылка на проверяемый элемент</param>
/// <returns>
/// истину, если символ цифра, ложь в противном случае
/// </returns>
bool IsNumber(char* arr)
{
	return '0' <= *arr && *arr <= '9';
}

/// <summary>
/// Поиск позиции, на которой обрывается число без знака
/// </summary>
/// <param name="arr">Ссылка на элемент, с которого начинается проверка</param>
/// <returns>Ссылка на элемент, с которого последовательность не соответствует формату</returns>
char* IntWithoutSignLastPos(char* arr)
{
	if (!IsNumber(arr))
		return arr;

	return IntWithoutSignLastPos(arr + 1);
}

/// <summary>
/// Поиск позиции, на которой обрывается порядок
/// </summary>
/// <param name="arr">Ссылка на элемент, с которого начинается проверка</param>
/// <returns>Ссылка на элемент, с которого последовательность не соответствует формату</returns>
char* OrderLastPos(char* arr)
{
	if (*arr != 'E' && *arr != 'e')
		return arr;

	char* hypNumStartPoint = IsSign(arr + 1) ? arr + 2 : arr + 1;
	char* hypNumEndPointI = IntWithoutSignLastPos(hypNumStartPoint);

	if (hypNumEndPointI == hypNumStartPoint)
		return arr;

	return hypNumEndPointI;
}

/// <summary>
/// Поиск позиции, на которой обрывается мантиса
/// </summary>
/// <param name="arr">Ссылка на элемент, с которого начинается проверка</param>
/// <returns>Ссылка на элемент, с которого последовательность не соответствует формату</returns>
char* MantisLastPos(char* arr)
{
	char* notNumCharPos = IntWithoutSignLastPos(arr);

	if (*notNumCharPos != '.')
		return arr;
	
	char* endOfMantis = IntWithoutSignLastPos(notNumCharPos + 1);
	
	if (endOfMantis == notNumCharPos + 1)
		return arr;

	return  endOfMantis;
}

/// <summary>
/// Является ли строка действительным числом.
/// Формат +/- NUM . NUM e/E +/- NUM
/// </summary>
/// <param name="arr">Ссылка на элемент, с которого начинается проверка</param>
/// <returns>
/// истину, если число соответствует формату, иначе ложь
/// </returns>
bool IsRealNum(char *arr)
{
	char* mantStart = &arr[0];
	if (IsSign(mantStart))
		mantStart++;

	char* mantisLastPos = MantisLastPos(mantStart);
	if (mantisLastPos == mantStart)
		return false;

	char* orderLastPos = OrderLastPos(mantisLastPos);
	if (orderLastPos == mantisLastPos)
		return false;

	return *orderLastPos == '\0';
}