# Отчет по лабораторной работе №1 (ОПИ)

## Студент: Авдейкина Валерия Павловна
## Группа: ИУ7-23Б

## 4.2. Поиск ошибки и ее описание

В код основной программы был добавлен тест 2 в виде функции Test2().

Контрольная сумма фиксации: ```bfc3175```
Комментарий: ```main.py: Test2() was added.```

```
commit bfc3175eb256fb6ae0df0800c5167976694312d6 (HEAD -> master)
Author: Valeriya Avdeykina <avp21u792@student.bmstu.ru>
Date:   Tue Mar 8 17:35:10 2022 +0300

    main.py: Test2() was added.
```

## 4.3. Исправление ошибки

Ошибка была исправлена:

```
sheglar@SHEGLAR-VB:~/se$ git status
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   iarray.py

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        .avp_otchet.md.swp
        avp_otchet.md

no changes added to commit (use "git add" and/or "git commit -a")
```
```
sheglar@SHEGLAR-VB:~/se$ git diff
diff --git a/iarray.py b/iarray.py
index bfe46b8..06312d3 100644
--- a/iarray.py
+++ b/iarray.py
@@ -6,9 +6,10 @@ def GetMaxCount(Arr, N):
   while (I < N):
     if (Arr[I] > Max):
       Max = Arr[I]
+      Count = 1^M
     else:
       if (Max == Arr[I]):
-        Count += 1;
+        Count += 1^M
     
     I += 1
```

Контрольная сумма фиксации: 5ec3869
```
commit 5ec3869d0d659959154a8b39a46f576acb4500c7 (HEAD -> master)
Author: Valeriya Avdeykina <avp21u792@student.bmstu.ru>
Date:   Tue Mar 8 18:00:52 2022 +0300

    iarray.py: Count resetting was added.
```

## 4.4. Анализ истории

- В выдаче команды git log с добавлением --name-status изменится вывод коммитов: под комментарием коммита добавятся изменяемые файлы и их статус.

В примере ниже по сравнению со стандартным выводом добавились две последние строки, где A означает, что файлы добавлены (M - изменены и т.д.)
```
commit 75773888151dca179308f6ec79ca8ee78ed746f8
Author: Valeriya Avdeykina <avp21u792@student.bmstu.ru>
Date:   Tue Mar 8 16:06:17 2022 +0300

    Initial version of program was added.

A       iarray.py
A       main.py
```
- Чтобы посмотреть некоторый диапазон коммитов, нужно написать команду в следующей форме:
```
git log ^r1 r2

или

git log r1..r2
```
Это покажет коммиты начиная с r2 (более новый) до r1 (более старый) (r1 и его предки не включаются).

Следующая команда покажет коммиты, доступные либо от r1, либо от r2, но не от них обоих:
```
git log r1...r2
```

- Разница версий одного и того же файла разных ревизий:
```
git diff com_hash1 com_hash2 file_name
```

## 4.5. Работа с Wiki

- Картинки вставляются следующим образом:
```
![Alt text](image-link "Image title")
```
- Оглавление составляется следующим образом (с помощью HTML-тегов):
```
1. [Пункт 1](#point1)

## Пункт 1 <a name="point1"></a>
```
- Чтобы указать ссылку на другую страницу Wiki из того же проекта, можно использовать Page Slug, то есть:
```
[Other page](Project-Name/Page-Name-With-Dashes)
```
- Комментарии пишутся следующим образом (как в HTML):
```
<!---
Комментарий
Вуху!
-->
```
- Таблицы (+ можно вставлять HTML таблицы):
```
h1 | h2
---|---
c1 | c2
---|---
c3 | c4

| h1 | h2 | h3 |
|:---|:--:|---:|
|left|cent|rigt|
```
