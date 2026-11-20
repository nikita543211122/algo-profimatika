# Хэширование, множества и словари

Восемь задач с Codeforces, LeetCode и CSES. В каждой папке есть разбор, пример и реализации на C++ и Python.

| # | Задача | Идея |
|---|--------|------|
| 1 | [Distinct Values](01-distinct-values) | Уникальные элементы в отсортированном порядке |
| 2 | [Contains Duplicate](02-contains-duplicate) | Множество встреченных значений |
| 3 | [Two Sum](03-two-sum) | Словарь «число → индекс», поиск дополнения |
| 4 | [Sum of Distances](04-sum-of-distances) | Группы одинаковых чисел и суммы индексов |
| 5 | [Count Complete Subarrays](05-count-complete-subarrays) | Скользящее окно с частотами |
| 6 | [Longest Consecutive Sequence](06-longest-consecutive-sequence) | Обход цепочек от чисел без предшественника |
| 7 | [Number of Ways](07-number-of-ways) | Префиксная сумма и подсчёт первых разрезов |
| 8 | [String Matching](08-string-matching) | Префиксные полиномиальные хэши и окна длины шаблона |

## Домашнее задание

1. Написать свою хеш-функцию для строки.
2. [Codeforces — задача B](https://codeforces.com/group/MwZqR4Zf5z/contest/711077/problem/B)
3. [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/description/)
4. [Codeforces — задача E](https://codeforces.com/group/MwZqR4Zf5z/contest/711077/problem/E)
5. [Count Complete Subarrays in an Array](https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/)
6. [Number of Ways Where Square of Number Is Equal to Product of Two Numbers](https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/description/)
7. [Insert Delete GetRandom O(1)](https://leetcode.com/problems/insert-delete-getrandom-o1/description/)
8. [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)
9. [Count Unique Characters of All Substrings of a Given String](https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/description/)
10. [Codeforces 1234D — Distinct Characters Queries](https://codeforces.com/problemset/problem/1234/D)

## Контейнеры

| Что нужно | C++ | Python |
|-----------|-----|--------|
| Уникальные ключи по возрастанию | `set` | `sorted(set(values))` для разовой сортировки |
| Пары «ключ → значение» с обходом по возрастанию ключа | `map` | `dict` и явная сортировка ключей при обходе |
| Быстрая проверка принадлежности | `unordered_set` | `set` |
| Быстрый поиск значения по ключу | `unordered_map` | `dict` |

В C++ поиск, вставка и удаление по ключу в упорядоченных контейнерах занимают `O(log n)`. У хэш-таблиц эти операции в среднем занимают `O(1)` для целочисленных ключей. Коллизии могут замедлить операции. Таблица сравнивает сами ключи, поэтому проверка принадлежности остаётся точной.

## Полиномиальный хэш

`prefix[k]` — хэш первых `k` символов, `power[k]` — степень основания `base^k` по модулю `mod`.

```text
prefix[0] = 0
power[0] = 1
prefix[i + 1] = (prefix[i] * base + code(s[i])) % mod
power[i + 1] = power[i] * base % mod
```

Хэш подстроки `[l, r)` получаем за `O(1)` после линейной подготовки. Вычитаем из `prefix[r]` вклад первых `l` символов, сдвинутый на длину подстроки.

```cpp
long long removed = prefix[l] * power[r - l] % mod;
long long hash = (prefix[r] - removed + mod) % mod;
```

Равные подстроки дают одинаковые хэши. У разных подстрок из-за коллизии тоже могут совпасть хэши. В String Matching сравниваются две компоненты хэша.

## Запуск

В задачах Codeforces и CSES вход читается из stdin. Запускайте команды из папки задачи.

```bash
g++ -O2 -std=c++20 solution.cpp -o /tmp/algo-solution && /tmp/algo-solution < input.txt
python3 solution.py < input.txt
```

В задачах LeetCode отправляйте класс `Solution` из файла выбранного языка через редактор соответствующей задачи.
