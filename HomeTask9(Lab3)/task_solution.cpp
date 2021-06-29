/// <summary>
/// �������� �� ������ ������ ����� ��� ������
/// </summary>
/// <param name="arr">������ �� ����������� �������</param>
/// <returns>
/// ������, ���� ������ ���� ��� �����, ���� � ��������� ������
/// </returns>
bool IsSign(char* arr)
{
	return *arr == '-' || *arr == '+';
}

/// <summary>
/// �������� �� ������ ������
/// </summary>
/// <param name="arr">������ �� ����������� �������</param>
/// <returns>
/// ������, ���� ������ �����, ���� � ��������� ������
/// </returns>
bool IsNumber(char* arr)
{
	return '0' <= *arr && *arr <= '9';
}

/// <summary>
/// ����� �������, �� ������� ���������� ����� ��� �����
/// </summary>
/// <param name="arr">������ �� �������, � �������� ���������� ��������</param>
/// <returns>������ �� �������, � �������� ������������������ �� ������������� �������</returns>
char* IntWithoutSignLastPos(char* arr)
{
	if (!IsNumber(arr))
		return arr;

	return IntWithoutSignLastPos(arr + 1);
}

/// <summary>
/// ����� �������, �� ������� ���������� �������
/// </summary>
/// <param name="arr">������ �� �������, � �������� ���������� ��������</param>
/// <returns>������ �� �������, � �������� ������������������ �� ������������� �������</returns>
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
/// ����� �������, �� ������� ���������� �������
/// </summary>
/// <param name="arr">������ �� �������, � �������� ���������� ��������</param>
/// <returns>������ �� �������, � �������� ������������������ �� ������������� �������</returns>
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
/// �������� �� ������ �������������� ������.
/// ������ +/- NUM . NUM e/E +/- NUM
/// </summary>
/// <param name="arr">������ �� �������, � �������� ���������� ��������</param>
/// <returns>
/// ������, ���� ����� ������������� �������, ����� ����
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