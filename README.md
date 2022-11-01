# LLP_base
За основу взята идея регистра Windows
### Файл данных
+ Данные в файле представлены последовательно
+ Фаайл состоит из 2 частей - заголовок и основные блоки
  + Заголовок содержит служебную информацию - размер файла, размер заголовка и тд
+ Основными блоками данных являются ведра, каждое ведро - отдельное дерево или схема дерева
+ Каждое ведро состоит из заголовка и ячеек
  + Заголовок содержит служебную информацию - размер ведра, смещение относительно начала файла и тд.

Схема основного файла:
![Alt-text](https://drive.google.com/file/d/1qO_QwgrS2EGpEBTBd7f87ZDGLBLBm2KC/view?usp=share_link)

### Элементы данных
Элементы представлены ячейками в файле данных. Каждая ячейка может быть либо вершиной, либо атрибутом вершины
Вершины представлены в виде структур *key_node*; вершина содержит следующие поля:
####key_node
| Attribute | Discription |
|:----|:--------|
| cell_header | Ссылка на структуру cell_header - заголовок ячейки |
| node_name | Имя вершины |
| parrent_offset | Сдвиг относительно заголовка ведра до вершины-родителя |
| subkeys_offset | Сдвиг относительно заголовка ведра до вершин-потомков |
| key_values_offset | Сдвиг относительно заголовка ведра до списка значений атрибутов вершины |

Атрибуты вершины представлены в виде структур *key_value*;
####key_value
| Attribute | Discription |
|:----|:--------|
| cell_header | Ссылка на структуру cell_header - заголовок ячейки|
| value_name | Имя атрибута |
| data_size | Размер ячейки относительно заголовка |
| data_type | Тип данных в ячейке |
| data_offset | Сами данные (если их размер относительно небольшой) либо сдвиг относительно текущей ячейки до данных |