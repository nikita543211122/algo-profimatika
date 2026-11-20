# 217. Contains Duplicate

Верните `true`, если хотя бы одно число встречается дважды. [Условие LeetCode](https://leetcode.com/problems/contains-duplicate/description/)

## Идея

- Храним уже пройденные числа в множестве. При первом повторе возвращаем `true`.
- В C++ `insert(value).second` показывает, был ли добавлен новый ключ. В Python используем `value in seen` и затем `seen.add(value)`.
- В среднем `O(n)` времени и `O(u)` дополнительной памяти, где `u` — число различных значений.

## Отправка

[Класс Solution на C++](solution.cpp) · [Класс Solution на Python](solution.py)

## Пример

`nums = [1, 2, 3, 1]` → `true`. Последняя единица уже есть в множестве.
