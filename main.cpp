#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Struktura przechowuj¹ca dane jednego ucznia.
struct Uczen
{
    string imie, nazwisko;
    int wiek;
};

// Klasa przechowuj¹ca i obs³uguj¹ca kolekcjê uczniów.
class Kolekcja
{
private:
    // Wektor przechowuj¹cy wszystkich uczniów.
    vector<Uczen> lista_uczniow;

public:
    // Konstruktor klasy Kolekcja.
    Kolekcja()
    {
    }

    // Destruktor klasy Kolekcja.
    ~Kolekcja()
    {
    }

    // Dodaje podanego ucznia na koniec wektora.
    void dodaj_ucznia(Uczen u)
    {
        lista_uczniow.push_back(u);
    }

    // Wczytuje dane uczniów z pliku tekstowego.
    void wczytaj(string nazwa_pliku)
    {
        // Otwarcie pliku do odczytu.
        ifstream plik(nazwa_pliku);

        // Sprawdzenie, czy plik zosta³ poprawnie otwarty.
        if (!plik)
        {
            cout << "Nie udalo sie otworzyc pliku!" << endl;
            return;
        }

        Uczen uczen;

        // Odczytywanie kolejnych danych uczniów do momentu
        // wyst¹pienia koñca pliku lub b³êdu odczytu.
        while (plik >> uczen.imie >> uczen.nazwisko >> uczen.wiek)
        {
            lista_uczniow.push_back(uczen);
        }

        // Zamkniêcie pliku.
        plik.close();
    }

    // Zapisuje wszystkich uczniów do pliku tekstowego.
    void zapisz(string nazwa_pliku)
    {
        // Otwarcie pliku do zapisu.
        ofstream plik(nazwa_pliku);

        // Sprawdzenie, czy plik zosta³ poprawnie otwarty.
        if (!plik)
        {
            cout << "Nie udalo sie otworzyc pliku!" << endl;
            return;
        }

        // Zapisanie wszystkich elementów wektora do pliku.
        for (int i = 0; i < lista_uczniow.size(); i++)
        {
            plik << lista_uczniow[i].imie << " "
                 << lista_uczniow[i].nazwisko << " "
                 << lista_uczniow[i].wiek << endl;
        }

        // Zamkniêcie pliku.
        plik.close();
    }

    // Wyœwietla wszystkich uczniów znajduj¹cych siê w kolekcji.
    void wyswietl()
    {
        // Przejœcie przez wszystkie elementy wektora.
        for (int i = 0; i < lista_uczniow.size(); i++)
        {
            cout << i + 1 << ". "
                 << lista_uczniow[i].imie << " "
                 << lista_uczniow[i].nazwisko << ", "
                 << lista_uczniow[i].wiek << " lat" << endl;
        }
    }

    // Sortuje uczniów alfabetycznie wed³ug nazwiska.
    void sortuj()
    {
        sort(lista_uczniow.begin(), lista_uczniow.end(),
             [](const Uczen& a, const Uczen& b)
             {
                 return a.nazwisko < b.nazwisko;
             });
    }

    // Usuwa ucznia o podanym numerze z kolekcji.
    void usun_ucznia(int numer)
    {
        // Wartoœæ 0 oznacza anulowanie operacji usuwania.
        if(numer == 0)
        {
            cout << "anulowano usuwanie ucznia" << endl;
            return;
        }

        // Sprawdzenie, czy podany numer ucznia jest poprawny.
        if (numer < 1 || numer > lista_uczniow.size())
        {
            cout << "Nieprawidlowy numer ucznia!" << endl;
            return;
        }

        // Usuniêcie ucznia z wektora na podstawie jego numeru.
        lista_uczniow.erase(lista_uczniow.begin() + numer - 1);

        cout << "Uczen zostal usuniety." << endl;
    }
};

// Funkcja odpowiedzialna za obs³ugê menu programu.
void menu(Kolekcja& kolekcja)
{
    // Zmienna okreœlaj¹ca, czy u¿ytkownik chce zakoñczyæ program.
    bool koniec = false;

    // Domyœlna nazwa pliku przechowuj¹cego dane uczniów.
    string nazwa_pliku = "osoby.txt";

    // Pêtla menu wykonywana do momentu wybrania opcji 0.
    do
    {
        int wybor;

        // Wyœwietlenie dostêpnych opcji programu.
        cout << endl;
        cout << "===== MENU =====" << endl;
        cout << "0 - zakoncz program" << endl;
        cout << "1 - wczytaj z pliku" << endl;
        cout << "2 - wypisz" << endl;
        cout << "3 - zapisz do pliku" << endl;
        cout << "4 - dodaj ucznia" << endl;
        cout << "5 - posortuj" << endl;
        cout << "6 - usun ucznia o danym numerze" << endl;
        cout << "Wybor: ";

        // Pobranie wyboru u¿ytkownika.
        cin >> wybor;

        // Wykonanie odpowiedniej operacji na podstawie wyboru u¿ytkownika.
        switch (wybor)
        {
        // Zakoñczenie dzia³ania programu.
        case 0:
            koniec = true;
            break;

        // Wczytanie danych uczniów z pliku.
        case 1:
            kolekcja.wczytaj(nazwa_pliku);
            cout << "Wczytano liste z pliku. Wszystkie zmiany w liscie sa w wersji roboczej. By je zapisac, po edycji listy wybierz opcje 3." << endl;
            break;

        // Wyœwietlenie zawartoœci kolekcji.
        case 2:
            kolekcja.wyswietl();
            break;

        // Zapisanie aktualnej zawartoœci kolekcji do pliku.
        case 3:
            kolekcja.zapisz(nazwa_pliku);
            cout << "Zapisano liste do pliku " << nazwa_pliku << endl;
            break;

        // Dodanie nowego ucznia.
        case 4:
        {
            Uczen uczen;

            // Pobranie danych nowego ucznia od u¿ytkownika.
            cout << "Podaj imie: ";
            cin >> uczen.imie;

            cout << "Podaj nazwisko: ";
            cin >> uczen.nazwisko;

            cout << "Podaj wiek: ";
            cin >> uczen.wiek;

            // Dodanie utworzonego ucznia do kolekcji.
            kolekcja.dodaj_ucznia(uczen);

            cout << "Dodano ucznia. By zapisac liste, wybierz opcje 3." << endl;
            break;
        }

        // Posortowanie uczniów wed³ug nazwiska.
        case 5:
            kolekcja.sortuj();
            cout << "Lista zostala posortowana. By zapisac posortowana liste, wybierz opcje 3." << endl;
            break;

        // Usuniêcie ucznia o podanym numerze.
        case 6:
        {
            int numer;

            // U¿ytkownik mo¿e anulowaæ operacjê, podaj¹c 0.
            cout << "Jesli chcesz anulowac usuniecie ucznia, wybierz liczbe 0." << endl;
            cout << "Podaj numer ucznia do usuniecia: ";
            cin >> numer;

            // Wywo³anie funkcji usuwaj¹cej ucznia.
            kolekcja.usun_ucznia(numer);
            break;
        }

        // Obs³uga nieprawid³owego wyboru z menu.
        default:
            cout << "Nieprawidlowa opcja!" << endl;
            break;
        }

    // Ponowne wyœwietlanie menu, dopóki u¿ytkownik nie wybierze 0.
    } while (!koniec);
}

// Funkcja g³ówna programu.
int main()
{
    // Utworzenie obiektu klasy Kolekcja.
    Kolekcja kolekcja;

    // Uruchomienie g³ównego menu programu.
    menu(kolekcja);

    // Zakoñczenie programu.
    return 0;
}
