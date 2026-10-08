#include <iostream>
#include <chrono>
#include <random>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int main()
{
    // Zmienna przechowujaca aktualnie wygenerowana liczbe.
    // Typ short int pozwala przechowywac wartosci od -32768 do 32767.
    short int random_int;

    // Uruchomienie generatora liczb losowych.
    // random_device dostarcza wartosc poczatkowa dla generatora mt19937.
    random_device rd;
    mt19937 rng(rd());

    // Ustalenie zakresu losowanych wartosci.
    uniform_int_distribution<int> uni(-32768, 32767);

    // Utworzenie tablicy pozwalajacej przechowac 100001 elementow.
    short int builtin[100001];

    // Utworzenie wektora oraz listy, ktore beda wykorzystane w tescie.
    vector<short int> vec;
    list<short int> included;

    // Wypelnienie wszystkich trzech struktur 100000 losowymi liczbami.
    for (int i = 0; i < 100000; i++)
    {
        // Wylosowanie kolejnej liczby.
        random_int = uni(rng);

        // Zapisanie liczby w tablicy.
        builtin[i] = random_int;

        // Dodanie liczby na koncu wektora.
        vec.push_back(random_int);

        // Dodanie liczby na koncu listy.
        included.push_back(random_int);
    }

    // Wylosowanie dodatkowej wartosci, ktora zostanie
    // pozniej dodana w srodkowym miejscu kazdej struktury.
    random_int = uni(rng);


    // ============================================================
    // TABLICA WBUDOWANA
    // ============================================================

    // Rozpoczecie pomiaru czasu dla operacji wykonywanych na tablicy.
    auto start = high_resolution_clock::now();

    // Przesuniecie elementow znajdujacych sie od pozycji 50000
    // o jedno miejsce w prawo, aby przygotowac miejsce na nowa wartosc.
    for (int i = 100000; i > 50000; --i)
    {
        builtin[i] = builtin[i - 1];
    }

    // Wstawienie nowej liczby w srodkowej pozycji tablicy.
    builtin[50000] = random_int;

    // Posortowanie wszystkich elementow tablicy rosnaco.
    sort(builtin, builtin + 100001);

    // Przesuniecie pozostalych elementow o jedno miejsce w lewo.
    // W ten sposob element ze srodka zostaje usuniety.
    for (int i = 50000; i < 100000; i++)
    {
        builtin[i] = builtin[i + 1];
    }

    // Zakonczenie pomiaru czasu.
    auto stop = high_resolution_clock::now();

    // Przeliczenie zmierzonego czasu na mikrosekundy.
    auto duration = duration_cast<microseconds>(stop - start);

    // Wyswietlenie wyniku dla tablicy.
    cout << "Operations on builtin table took "
         << duration.count() << " microseconds" << endl;


    // ============================================================
    // VECTOR
    // ============================================================

    // Rozpoczecie pomiaru czasu dla operacji na wektorze.
    start = high_resolution_clock::now();

    // Dodanie nowej wartosci w polowie wektora.
    // Elementy znajdujace sie dalej musza zostac przesuniete.
    vec.insert(vec.begin() + 50000, random_int);

    // Posortowanie wszystkich elementow wektora.
    sort(vec.begin(), vec.end());

    // Usuniecie elementu znajdujacego sie na pozycji 50000.
    vec.erase(vec.begin() + 50000);

    // Zakonczenie pomiaru czasu dla wektora.
    stop = high_resolution_clock::now();

    // Obliczenie czasu potrzebnego na wykonanie operacji.
    duration = duration_cast<microseconds>(stop - start);

    // Wyswietlenie uzyskanego wyniku.
    cout << "Operations on vector took "
         << duration.count() << " microseconds" << endl;


    // ============================================================
    // LISTA LACZONA
    // ============================================================

    // Rozpoczecie pomiaru czasu dla operacji wykonywanych na liscie.
    start = high_resolution_clock::now();

    // Utworzenie iteratora wskazujacego na poczatek listy.
    auto it = included.begin();

    // Przesuniecie iteratora do srodka listy.
    // Lista nie pozwala na bezposredni dostep za pomoca indeksu,
    // dlatego konieczne jest przejscie przez kolejne elementy.
    advance(it, included.size() / 2);

    // Wstawienie nowej wartosci w miejscu wskazywanym przez iterator.
    // W przypadku listy nie trzeba przesuwac wszystkich kolejnych elementow.
    included.insert(it, random_int);

    // Posortowanie elementow listy przy pomocy jej wlasnej metody.
    included.sort();

    // Ustawienie iteratora ponownie na poczatku listy.
    it = included.begin();

    // Ponowne przejscie do srodkowego elementu.
    advance(it, included.size() / 2);

    // Usuniecie elementu wskazywanego przez iterator.
    included.erase(it);

    // Zakonczenie pomiaru czasu dla listy.
    stop = high_resolution_clock::now();

    // Przeliczenie wyniku na mikrosekundy.
    duration = duration_cast<microseconds>(stop - start);

    // Wyswietlenie czasu wykonania operacji na liscie.
    cout << "Operations on list took "
         << duration.count() << " microseconds" << endl;

    return 0;
}
