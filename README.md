# Porównanie wydajności struktur danych

Program służy do porównania czasu wykonywania wybranych operacji na trzech różnych strukturach danych w C++:

- tablicy wbudowanej,
- `vector`,
- `list`.

W ramach testu tworzonych jest 100 000 losowych wartości typu `short int`. Następnie dla każdej struktury wykonywane są operacje dodania elementu w środku, sortowania oraz usunięcia elementu. Całość jest mierzona za pomocą biblioteki `<chrono>`.

## Przebieg testu

Dla każdej z badanych struktur wykonywane są kolejno następujące czynności:

1. Wygenerowanie i zapisanie 100 000 losowych liczb.
2. Wylosowanie kolejnej wartości.
3. Umieszczenie nowego elementu w połowie struktury.
4. Posortowanie wszystkich elementów.
5. Usunięcie elementu znajdującego się w środku.
6. Zmierzenie całkowitego czasu wykonania powyższych operacji.

## Wykorzystane struktury danych

### Tablica wbudowana

Do przechowywania danych wykorzystywana jest tablica o rozmiarze 100001 elementów:

short int builtin[100001];


Standardowa tablica C++ nie posiada funkcji umożliwiających bezpośrednie wstawianie i usuwanie elementów. Z tego powodu operacje te trzeba wykonać ręcznie.

Przy dodawaniu elementu w środku wszystkie wartości znajdujące się za wskazanym miejscem są przesuwane o jedną pozycję:

for (int i = 100000; i > 50000; --i) { builtin[i] = builtin[i - 1]; }


Po przesunięciu danych nowa wartość zostaje zapisana pod indeksem `50000`.

Usuwanie elementu działa podobnie, jednak tym razem wartości znajdujące się za usuwanym elementem są przesuwane o jedną pozycję w lewo.

Do sortowania tablicy wykorzystano funkcję:

sort(builtin, builtin + 100001);


### Vector

W przypadku wektora używany jest kontener:

vector<short int> vec;


W przeciwieństwie do zwykłej tablicy `vector` udostępnia gotowe funkcje do dodawania oraz usuwania elementów.

Element w środku wektora jest dodawany za pomocą:

vec.insert(vec.begin() + 50000, random_int);


Natomiast jego usunięcie wykonuje:

vec.erase(vec.begin() + 50000);


Sortowanie odbywa się przy użyciu:

sort(vec.begin(), vec.end());


Elementy wektora są przechowywane w ciągłym obszarze pamięci. W związku z tym dodanie lub usunięcie wartości ze środka powoduje konieczność przesunięcia części pozostałych elementów.

### Lista

Trzecią badaną strukturą jest lista:

list<short int> included;


Lista nie umożliwia bezpośredniego dostępu do elementu za pomocą indeksu. Aby dotrzeć do jej środka, iterator przesuwany jest odpowiednią liczbę pozycji:

auto it = included.begin(); advance(it, included.size() / 2);


Po znalezieniu odpowiedniego miejsca nowa wartość jest dodawana funkcją:

included.insert(it, random_int);


Do sortowania listy wykorzystywana jest metoda dostępna bezpośrednio w kontenerze:

included.sort();


Po ponownym znalezieniu środkowego elementu można go usunąć:

included.erase(it);


## Pomiar czasu

Do sprawdzenia czasu wykonywania operacji wykorzystano bibliotekę `<chrono>`. Początek pomiaru jest zapisywany przed wykonaniem testowanych operacji:

auto start = highresolutionclock::now();


Po zakończeniu wszystkich operacji pobierany jest czas końcowy:

auto stop = highresolutionclock::now();


Różnica pomiędzy tymi wartościami jest następnie przeliczana na mikrosekundy:

auto duration = duration_cast<microseconds>(stop - start);


Uzyskany wynik jest wyświetlany w konsoli.

## Generowanie liczb losowych

Do tworzenia danych testowych wykorzystano mechanizmy znajdujące się w bibliotece `<random>`.

Generatorem liczb jest algorytm Mersenne Twister:

mt19937 rng(rd());


Zakres generowanych wartości został dopasowany do typu `short int`:

uniformintdistribution<int> uni(-32768, 32767);


W efekcie program może wygenerować liczby całkowite od `-32768` do `32767`.

## Przykładowy wynik

Uzyskane czasy zależą między innymi od komputera, użytego kompilatora oraz aktualnego obciążenia systemu. Przykładowy rezultat może wyglądać następująco:

Operations on builtin table took 12345 microseconds Operations on vector took 11234 microseconds Operations on list took 23456 microseconds


Podane wartości są jedynie przykładem i podczas kolejnych uruchomień mogą być inne.

## Na co zwrócić uwagę?

Wynik pomiaru obejmuje **wstawianie elementu, sortowanie oraz jego późniejsze usunięcie**. Oznacza to, że otrzymane czasy nie pokazują wyłącznie różnic pomiędzy operacjami dodawania i usuwania.

Szczególnie istotny wpływ na końcowy rezultat może mieć sortowanie danych.

Na uzyskane wyniki mogą również wpływać:

- wydajność procesora,
- ustawienia optymalizacji kompilatora,
- obciążenie systemu operacyjnego,
- sposób zarządzania pamięcią,
- wygenerowane dane losowe,
- implementacja biblioteki standardowej C++.

Aby uzyskać bardziej wiarygodne rezultaty, warto wykonać test kilkukrotnie, a następnie obliczyć średni czas dla każdej ze struktur.
