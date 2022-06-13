# ОПИ Рубежный контроль 2

## Студент: Авдейкина Валерия ИУ7-23Б

### Задание

Отсортировать слова в строках в файле в алфавитном порядке.

### Модуль A22

#### Спецификация

| Имя модуля | sort\_words |
|----|---------|
| Функция | Сортировка массива слов в алфавитном порядке |
| Список параметров | Массив слов, количество слов в массиве |
| Входные данные        | Массив слов, длина |
| Выходные данные       | нет |
| Внешние эффекты       | Изменение слов в массиве |
| Допущение модуля      | длина массива не равна 0 |

#### Тестовые данные

| Количество слов, массив слов | Итоговый массив/Ошибка |
|---|---|
| 3 / a b c | a b c |
| 3 / c b a | a b c |
| 3 / a a a | a a a |
| 4 / b c c a | a b c c |
| 0 / пуст | Ошибка (assert) |