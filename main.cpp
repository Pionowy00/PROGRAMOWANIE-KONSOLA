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
    // Variable used to store each randomly generated number.
    // short int can store values from -32768 to 32767.
    short int random_int;

    // Create a random number generator.
    // random_device is used to create a seed for the generator.
    random_device rd;
    mt19937 rng(rd());

    // Set the range of random numbers that can be generated.
    uniform_int_distribution<int> uni(-32768, 32767);

    // Create a built-in array capable of holding 100001 short integers.
    short int builtin[100001];

    // Create a vector and a linked list.
    vector<short int> vec;
    list<short int> included;

    // Fill all three data structures with 100000 random numbers.
    for (int i = 0; i < 100000; i++)
    {
        // Generate a random number.
        random_int = uni(rng);

        // Add the number to the built-in array.
        builtin[i] = random_int;

        // Add the number to the vector.
        vec.push_back(random_int);

        // Add the number to the linked list.
        included.push_back(random_int);
    }

    // Generate another random number.
    // This number will be inserted into each data structure.
    random_int = uni(rng);


    // ============================================================
    // BUILT-IN ARRAY
    // ============================================================

    // Record the starting time before performing the operations.
    auto start = high_resolution_clock::now();

    // Move all elements from position 50000 onwards one position
    // to the right. This creates an empty position at index 50000.
    //
    // The loop starts at 100000 because the array has an extra
    // element available at that position.
    for (int i = 100000; i > 50000; --i)
    {
        builtin[i] = builtin[i - 1];
    }

    // Insert the new random number at the middle of the array.
    builtin[50000] = random_int;

    // Sort the entire array into ascending order.
    sort(builtin, builtin + 100001);

    // Remove the element at position 50000 by shifting all
    // following elements one position to the left.
    for (int i = 50000; i < 100000; i++)
    {
        builtin[i] = builtin[i + 1];
    }

    // Record the finishing time.
    auto stop = high_resolution_clock::now();

    // Calculate how much time the operations took.
    auto duration = duration_cast<microseconds>(stop - start);

    // Display the time taken.
    cout << "Operations on builtin table took "
         << duration.count() << " ns" << endl;


    // ============================================================
    // VECTOR
    // ============================================================

    // Start the timer before performing the vector operations.
    start = high_resolution_clock::now();

    // Insert the random number at the middle of the vector.
    // Elements after this position have to be shifted to make room.
    vec.insert(vec.begin() + 50000, random_int);

    // Sort all elements in the vector into ascending order.
    sort(vec.begin(), vec.end());

    // Remove the element at position 50000.
    // Elements after it are shifted to fill the empty space.
    vec.erase(vec.begin() + 50000);

    // Stop the timer.
    stop = high_resolution_clock::now();

    // Calculate the elapsed time.
    duration = duration_cast<microseconds>(stop - start);

    // Display the time taken.
    cout << "Operations on vector took "
         << duration.count() << " ns" << endl;


    // ============================================================
    // LINKED LIST
    // ============================================================

    // Start the timer before performing the list operations.
    start = high_resolution_clock::now();

    // Create an iterator pointing to the beginning of the list.
    auto it = included.begin();

    // Move the iterator to the middle of the list.
    // Unlike a vector, a list cannot directly access an element
    // using an index, so advance() must be used.
    advance(it, included.size() / 2);

    // Insert the random number at the iterator's position.
    // Inserting into a linked list does not require shifting
    // all the following elements.
    included.insert(it, random_int);

    // Sort the linked list.
    // list has its own sort() function because std::sort()
    // requires random-access iterators, which a list does not have.
    included.sort();

    // Reset the iterator to the beginning of the list.
    it = included.begin();

    // Move the iterator to the middle of the list again.
    advance(it, included.size() / 2);

    // Remove the element at the middle position.
    included.erase(it);

    // Stop the timer.
    stop = high_resolution_clock::now();

    // Calculate the elapsed time.
    duration = duration_cast<microseconds>(stop - start);

    // Display the time taken.
    cout << "Operations on list took "
         << duration.count() << " ns" << endl;

    return 0;
}
