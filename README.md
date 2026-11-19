# Drzewo binarne w C++

## Opis projektu
Program przedstawia implementację zwykłego drzewa binarnego wyszukiwania (BST) w języku C++. Umożliwia dodawanie liczb do drzewa, wyświetlanie jego struktury w konsoli oraz usuwanie całego drzewa z pamięci.

## Zasady działania
- Korzeń jest pierwszym dodanym elementem.
- Liczby mniejsze lub równe wartości węzła trafiają do lewego poddrzewa.
- Liczby większe od wartości węzła trafiają do prawego poddrzewa.

## Funkcje

### `dodaj(drzewo *&d, int liczba)`
Dodaje nową liczbę do drzewa zgodnie z zasadami BST. Jeśli napotka wolne miejsce (`NULL`), tworzy nowy węzeł.

### `wypisz(drzewo *d, int poziom = 0)`
Wyświetla drzewo w konsoli z zachowaniem jego struktury. Wykorzystuje wcięcia zależne od poziomu drzewa. Najpierw wypisywane jest prawe poddrzewo, następnie korzeń, a na końcu lewe poddrzewo.

### `usun(drzewo *d)`
Usuwa wszystkie elementy drzewa z pamięci. Najpierw usuwa poddrzewa, a następnie aktualny węzeł.

## Struktura węzła
Każdy element drzewa przechowuje:
- `liczba` – wartość węzła.
- `lewy` – wskaźnik na lewe poddrzewo.
- `prawy` – wskaźnik na prawe poddrzewo.

## Przykład użycia

```cpp
drzewo *d = NULL;

dodaj(d, 3);
dodaj(d, 5);
dodaj(d, 1);
dodaj(d, 7);
dodaj(d, 2);

wypisz(d);

usun(d);
```

## Technologie
- C++
- Biblioteka `iostream`
- Dynamiczna alokacja pamięci (`new` i `delete`)
