**Руководство по запуску программы**
=====================

 Код в репозитории тестировался и запускался на версси Python 3.7
 ***
 * Для создания тестового полигона запустите программу create_test_polygon.py и в командной строке передайте через пробел пути к файлам, не считая путь к текущей директории.
 >python3 create_test_polygon.py A.txt TestDir1/p.txt TestDir1/TestDir4/l.txt TestDir1/TestDir3/p.txt TestDir1/TestDir4/TestDir5/e.txt g.txt h.txt TestDir1/m.txt TestDir2/n.txt
 * Для поиска файлов по порядку латинкских букв в подаваемой строке запустите программу find_way_to_file_by_string.py и подайте строку, состоящую из латинских символов в качестве единственного аргумента командной строки после имени программы
  >python3 find_way_to_file_by_string.py <test_string Apple
 * Для того, чтобы запустить программу на новом наборе тестовых данных запустите программу clean_test_file_system.py, для удаления файлов формата txt и директорий за исключением корневой, которые были ранее созданы.
 >python3 clean_test_file_system.py
