#pragma once

/// <summary>
/// Имя входного файла, для которого 
/// должен быть задан целочисленный префикс
/// </summary>
std::string const FILE_NAME = "RealNumValid.in";

/// <summary>
/// Ошибка считывания целочисленного префикса
/// </summary>
std::string const PREFIX_READ_ERR = "Prefix must be integer";

/// <summary>
/// Ошибка существования файла
/// </summary>
std::string const FILE_EXIST_ERR = "File with this prefix doesn't exist";

/// <summary>
/// Ошибка пустого файла
/// </summary>
std::string const FILE_IS_EMPTY_ERR = "File is empty";