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
