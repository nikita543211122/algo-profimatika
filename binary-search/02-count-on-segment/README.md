# Шаг 1 · Количество чисел на отрезке [l, r]

## Идея

- Сортируем массив.
- Ответ на запрос: (число элементов ≤ r) − (число элементов < l) = upperBound(r) − lowerBound(l).
- lowerBound(x) — первый индекс с a[i] ≥ x, upperBound(x) — первый индекс с a[i] > x (массив отсортирован).
- Сложность O((n + k) log n).

## Запуск

```bash
g++ -O2 -std=c++20 solution.cpp -o solution && ./solution < input.txt
python3 solution.py < input.txt
```

## Пример

Вход:
```
5
10 1 10 3 4
4
1 10
2 9
3 4
2 2
```

Выход:
```
5 2 2 0
```
