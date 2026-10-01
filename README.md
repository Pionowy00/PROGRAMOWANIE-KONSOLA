📚 System zarządzania uczniami

Prosty program konsolowy napisany w C++, umożliwiający zarządzanie listą uczniów.

Projekt został wykonany w ramach nauki programowania oraz przygotowania do egzaminu INF.04.

✨ Funkcje

Program umożliwia:

📂 wczytywanie uczniów z pliku osoby.txt,

👤 dodawanie nowych uczniów,

📋 wyświetlanie listy uczniów,

🔤 sortowanie uczniów alfabetycznie według nazwiska,

🗑️ usuwanie ucznia po numerze,

💾 zapisywanie zmian do pliku,

❌ anulowanie operacji usuwania,

🚪 zakończenie programu.

🛠️ Technologie

C++

iostream – obsługa wejścia i wyjścia,

fstream – obsługa plików,

vector – przechowywanie listy uczniów,

algorithm – sortowanie,

string – obsługa tekstu.

📁 Struktura projektu
projekt/
│
├── main.cpp
├── osoby.txt
└── README.md

main.cpp

Główny plik programu zawierający całą implementację aplikacji.

osoby.txt

Plik tekstowy przechowujący dane uczniów.

Przykładowa zawartość:

Jan Kowalski 18
Anna Nowak 17
Piotr Zielinski 19
Maria Wisniewska 18

README.md

Dokumentacja projektu.

📋 Format danych

Każdy uczeń zajmuje jeden wiersz w pliku osoby.txt.

Format:

imie nazwisko wiek


Przykład:

Jan Kowalski 18

🎮 Menu programu

Po uruchomieniu programu pojawia się menu:

===== MENU =====

0 - zakoncz program

1 - wczytaj z pliku

2 - wypisz

3 - zapisz do pliku

4 - dodaj ucznia

5 - posortuj

6 - usun ucznia o danym numerze

Wybor:

Dostępne opcje
Opcja	Działanie
0	Zakończenie programu
1	Wczytanie danych z pliku
2	Wyświetlenie listy uczniów
3	Zapisanie listy do pliku
4	Dodanie ucznia
5	Sortowanie według nazwiska
6	Usunięcie ucznia
▶️ Uruchomienie
Kompilacja

Do kompilacji można wykorzystać kompilator g++.

g++ main.cpp -o program

Uruchomienie

Windows:

program.exe


Linux:

./program


Plik osoby.txt powinien znajdować się w katalogu, z którego uruchamiany jest program.

💡 Przykład działania

Po uruchomieniu programu wybieramy opcję 1, aby wczytać dane:

Wybor: 1
Wczytano liste z pliku.


Następnie wybieramy 2:

1. Jan Kowalski, 18 lat
2. Anna Nowak, 17 lat
3. Piotr Zielinski, 19 lat


Możemy dodać kolejnego ucznia:

Wybor: 4
Podaj imie: Adam
Podaj nazwisko: Wozniak
Podaj wiek: 17
Dodano ucznia.


Po wykonaniu zmian wybieramy opcję 3, aby zapisać aktualną listę do pliku.

🧩 Zastosowane rozwiązania

Program wykorzystuje:

strukturę Uczen do przechowywania danych ucznia,

klasę Kolekcja do zarządzania listą,

vector<Uczen> jako dynamiczną kolekcję danych,

funkcję sort() do sortowania,

operacje na plikach tekstowych,

instrukcję switch do obsługi menu,

pętlę do...while do wielokrotnego wyświetlania menu.

📌 Uwagi

Zmiany wprowadzone podczas działania programu są wykonywane w pamięci. Aby zachować je po zakończeniu programu, należy użyć opcji:

3 - zapisz do pliku


Jeżeli program zostanie zamknięty bez zapisania zmian, zmiany zostaną utracone.

👨‍💻 Autor

Projekt wykonany w języku C++ w ramach przygotowania do egzaminu INF.04.
