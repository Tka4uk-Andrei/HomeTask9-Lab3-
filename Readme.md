# Основы С++. Лабораторная работа 3 (Рекурсивные функции)

## Содержение
1. [Описание задания](#Описание-лабораторной)
2. [Спецификация](#Спецификация)

## Описание лабораторной

Понятие вещественное число определено с помощью БНФ следующим образом:

`<вещественное число>` **::=**  `<мантисса>` `<порядок>` **|** `<знак>` `<мантисса>` `<порядок>`\
`<мантисса>` **::=**  `<целое без знака>` **.** `<целое без знака>`\
`<порядок>` **::=**  **E** `<целое без знака>`  | **E** `<знак>` `<целое без знака>`\
`<целое без знака>` **::=**  `<цифра>` **|** `<цифра>` `<целое без знака>`\
`<цифра>` **::=** _0_ **|** _1_ **|** _2_ **|** _3_ **|** _4_ **|** _5_ **|** _6_ **|** _7_ **|** _8_ **|** _9_ \
`<знак>` **::=**  _+_ **|** _-_ 

Требуется вывести сообщение о соответствии строки, описанному выше формату.

## Спецификация

**Примечание.** Первая цифра спецификации позывает номер задания

| № | Входные данные (формальное описание) | Результат |
|---|---|---|
1.1 | Файла с заданным префиксом не существует | ```File <_file_name_> doesn't exist. Program is closing...```
1.2 | Префикс файла задан не целым числом | ```File prefix must be integer. Program is closing...```
1.3 | Файл пуст | ```File is empty. Program is closing...```
2.1 | Число записано правильно | ```false. Read error occurred on string```
2.2 | Число записано не правильно | ```true```
