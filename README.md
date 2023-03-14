# LLP_base

### Лабораторная работа №1 по низкоуровневому программированию

Вариант - документное дерево

---

### Сборка проекта

`make clean build`                           - linux

`make -f Makefile-win clean build`           - windows

---

### Запуск программы

`./main <flag> <filename> [data-filename]`   - linux

`main.exe <flag> <filename> [data-filename]` - windows

---

#### Доступные флаги

`-p` - заполнение файла хранилища `filename` данными из файла `data-filename`

Формат: `./main -p storage.txt dg/storageData.txt`

`-o` - открыть существующий файл хранилища

Формат: `./main -o storage.txt`

`-n` - создать новый файл хранилища, создать в нём шаблон для вершин

Формат: `./main -n storage.txt`

---

### Генератор данных

В папке `dg` находится файл для генерации файла с данными

Формат: `py generator.py <count> <fieldname>=<fieldtype> ... <output>`

Получить справку по формату ввода: `py generator.py help`

