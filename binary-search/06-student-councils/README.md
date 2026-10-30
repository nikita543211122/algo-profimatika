# Шаг 2 · G. Студенческие советы

## Идея

- Бинпоиск по числу советов c.
- Из группы в c советов идёт не больше min(a[i], c) человек.
- good(c): Σ min(a[i], c) ≥ k·c (достаточность — заполнение таблицы k × c по столбцам).
- Монотонность: T…T F…F. left = 0, right = Σa / k + 1. Всё в long long. Ответ left.

## Запуск

```bash
g++ -O2 -std=c++20 solution.cpp -o solution && ./solution < input.txt
python3 solution.py < input.txt
```

## Пример

Вход:
```
4
6
1
2
3
4
5
6
```

Выход:
```
5
```
