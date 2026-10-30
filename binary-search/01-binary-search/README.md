# Шаг 1 · A. Двоичный поиск

## Идея

- Для каждого запроса ищем первый индекс с a[i] ≥ x (lower bound).
- Инвариант: a[left] < x, a[right] ≥ x; фиктивные границы left = −1, right = n.
- Ответ YES, если right < n и a[right] == x.

## Запуск

```bash
g++ -O2 -std=c++20 solution.cpp -o solution && ./solution < input.txt
python3 solution.py < input.txt
```

## Пример

Вход:
```
5 3
1 3 3 7 9
3 4 9
```

Выход:
```
YES
NO
YES
```
