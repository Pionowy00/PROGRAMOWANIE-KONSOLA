#include <iostream>

using namespace std;


///////////////////////////////////////////////////////////////////
// nazwa struktury: drzewo
// pola struktury: int liczba - liczba, ktora bedzie przechowywana w drzewie.
// struct drzewo *lewy - wskaznik do lewej odnogi obecnego miejsca w naszym drzewie
//struct drzewo *prawy - wskaznik do prawej odnogi obecnego miejsca w naszym drzewie
// opis: struktura wspomagajaca tworzenie, modyfikowanie, analizowanie i usuwanie wartosci z drzewa
///////////////////////////////////////////////////////////////////
struct drzewo
{
    int liczba;
    struct drzewo *lewy, *prawy;
};


///////////////////////////////////////////////////////////////////
// nazwa funkcji: dodaj()
// paramety funkcji: drzewo *&d - nasze drzewo binarne, int liczba - liczba, ktora chcemy dodac
// zwracana wartosc: brak
// opis: dodaje liczbe do naszego drzewa binarnego. Jesli drzewo jest puste, tworzy nowe drzewo
///////////////////////////////////////////////////////////////////
void dodaj(drzewo *&d, int liczba)
{
    if (d == NULL)
    {
        d = new drzewo;
        d->liczba = liczba;
        d->lewy = NULL;
        d->prawy = NULL;
        return;
    }

    if (liczba > d->liczba)
    {
        dodaj(d->prawy, liczba);
    }
    else
    {
        dodaj(d->lewy, liczba);
    }

}

///////////////////////////////////////////////////////////////////
// nazwa funkcji: wpisz()
// paramety funkcji: drzewo *&d - nasze drzewo binarne, int poziom - poziom rozgalezienia. Sluzy do estetycznego wyswietlania drzewa w konsoli
// zwracana wartosc: brak
// opis: wypisuje drzewo binarne ze spacjami pozwalajacymi latwe i przejrzyste czytanie drzewa
///////////////////////////////////////////////////////////////////
void wypisz(drzewo *d, int poziom = 0)
{
    if (d == NULL)
    {
        return;
    }
    else
    {
        poziom++;
        wypisz(d->prawy, poziom);
        for (int i = 0; i < poziom; i++)
        {
            cout << "    ";
        }
        cout << d->liczba << endl;
        wypisz(d->lewy, poziom);
    }

}

///////////////////////////////////////////////////////////////////
// nazwa funkcji: usun()
// paramety funkcji: drzewo *&d - nasze drzewo binarne
// zwracana wartosc: brak
// opis: uzywane na koniec programu, zapobiega przepelnieniu sie stosu, usuwa wszystkie dane o drzewie ze stosu pamieci
///////////////////////////////////////////////////////////////////
void usun(drzewo *d)
{
    if (d == NULL)
    {
        return;

    }
    else
    {
        usun(d->lewy);
        usun(d->prawy);
        delete d;
    }

}

int main()
{
    struct drzewo *d = NULL; //tworzymy nowe drzewo binarne
    //dodajemy wartosci do drzewa binarnego
    dodaj(d, 3);
    dodaj(d, 5);
    dodaj(d, 1);
    dodaj(d, 7);
    dodaj(d, 2);
    dodaj(d, 3);
    dodaj(d, 4);

    wypisz(d); //wypisujemy wartosci z drzewa binarnego

    usun(d); //usuwamy drzewo binarne z pamieci przed zakonczeniem programu
}
