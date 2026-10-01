Program do zarządzania uczniami

Opis programu



Program służy do zarządzania listą uczniów. Dane każdego ucznia składają się z:



imienia,



nazwiska,



wieku.



Program umożliwia dodawanie, wyświetlanie, sortowanie i usuwanie uczniów oraz wczytywanie i zapisywanie danych w pliku tekstowym.



Program został napisany w języku C++ z wykorzystaniem programowania obiektowego.



Funkcje programu



Program posiada następujące opcje:



Opcja	Funkcja

0	Zakończenie programu

1	Wczytanie listy uczniów z pliku

2	Wyświetlenie listy uczniów

3	Zapisanie listy uczniów do pliku

4	Dodanie nowego ucznia

5	Posortowanie uczniów według nazwiska

6	Usunięcie ucznia o podanym numerze

Wykorzystane biblioteki



Program wykorzystuje następujące biblioteki:



\#include <iostream>

\#include <string>

\#include <fstream>

\#include <vector>

\#include <algorithm>



iostream



Służy do obsługi wejścia i wyjścia, między innymi:



cin

cout



string



Umożliwia przechowywanie tekstu, np. imienia i nazwiska ucznia.



fstream



Służy do obsługi plików tekstowych. W programie wykorzystano:



ifstream





do odczytu danych z pliku oraz:



ofstream





do zapisywania danych do pliku.



vector



Służy do przechowywania dynamicznej listy uczniów.



algorithm



Biblioteka zawiera funkcję:



sort()





wykorzystywaną do sortowania uczniów według nazwiska.



Struktura danych



Informacje o jednym uczniu są przechowywane w strukturze Uczen:



struct Uczen

{

&#x20;   string imie, nazwisko;

&#x20;   int wiek;

};





Struktura zawiera trzy pola:



imie – imię ucznia,



nazwisko – nazwisko ucznia,



wiek – wiek ucznia.



Klasa Kolekcja



Klasa Kolekcja przechowuje listę uczniów:



vector<Uczen> lista\_uczniow;





Klasa posiada metody odpowiedzialne za wykonywanie operacji na liście:



dodaj\_ucznia()

wczytaj()

zapisz()

wyswietl()

sortuj()

usun\_ucznia()



Dodawanie ucznia



Metoda:



dodaj\_ucznia(Uczen u)





dodaje nowego ucznia na koniec wektora za pomocą:



lista\_uczniow.push\_back(u);



Wczytywanie danych



Metoda:



wczytaj(string nazwa\_pliku)





otwiera plik tekstowy i odczytuje z niego dane kolejnych uczniów.



Każdy wiersz pliku powinien zawierać:



imie nazwisko wiek





Przykład:



Jan Kowalski 18

Anna Nowak 17

Piotr Zielinski 19



Zapisywanie danych



Metoda:



zapisz(string nazwa\_pliku)





zapisuje wszystkich uczniów znajdujących się aktualnie w kolekcji do pliku.



Program korzysta domyślnie z pliku:



osoby.txt



Wyświetlanie danych



Metoda:



wyswietl()





wyświetla wszystkich uczniów wraz z ich numerami.



Przykładowy wynik:



1\. Jan Kowalski, 18 lat

2\. Anna Nowak, 17 lat

3\. Piotr Zielinski, 19 lat



Sortowanie



Metoda:



sortuj()





sortuje uczniów alfabetycznie według nazwiska.



Do sortowania wykorzystano funkcję:



sort()





z biblioteki <algorithm>.



Usuwanie ucznia



Metoda:



usun\_ucznia(int numer)





usuwa ucznia o podanym numerze.



Jeżeli użytkownik poda:



0





operacja zostaje anulowana.



Jeżeli poda numer spoza zakresu listy, program wyświetli komunikat:



Nieprawidlowy numer ucznia!



Menu programu



Po uruchomieniu programu wyświetlane jest menu:



===== MENU =====

0 - zakoncz program

1 - wczytaj z pliku

2 - wypisz

3 - zapisz do pliku

4 - dodaj ucznia

5 - posortuj

6 - usun ucznia o danym numerze

Wybor:





Użytkownik wybiera numer odpowiadający operacji, którą chce wykonać.



Menu jest realizowane za pomocą instrukcji:



switch





oraz pętli:



do ... while





Program działa do momentu wybrania opcji 0.



Format pliku



Program korzysta z pliku:



osoby.txt





Każdy uczeń powinien znajdować się w osobnym wierszu.



Przykładowa zawartość:



Jan Kowalski 18

Anna Nowak 17

Piotr Zielinski 19

Maria Wisniewska 18





Kolejność danych w każdym wierszu:



imie nazwisko wiek



Przykład działania



Po uruchomieniu programu użytkownik może wybrać opcję 1, aby wczytać dane:



Wybor: 1

Wczytano liste z pliku.





Następnie opcja 2 wyświetla listę:



1\. Jan Kowalski, 18 lat

2\. Anna Nowak, 17 lat

3\. Piotr Zielinski, 19 lat





Po wybraniu 4 można dodać nowego ucznia:



Podaj imie: Adam

Podaj nazwisko: Wozniak

Podaj wiek: 17

Dodano ucznia.





Opcja 5 sortuje listę według nazwiska.



Opcja 6 umożliwia usunięcie ucznia:



Podaj numer ucznia do usuniecia: 2

Uczen zostal usuniety.





Po zakończeniu edycji opcja 3 zapisuje aktualną listę do pliku.



Uruchomienie programu



Do skompilowania programu wymagany jest kompilator C++, np. g++.



Przykładowe polecenie:



g++ main.cpp -o program





Uruchomienie programu:



Windows

program.exe



Linux

./program





Plik osoby.txt powinien znajdować się w katalogu, z którego uruchamiany jest program.



Autor



Projekt wykonany w języku C++ w ramach nauki programowania i przygotowania do egzaminu INF.04.

