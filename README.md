# Data Structure Performance Comparison



This program compares the time required to perform the same operations on three different C++ data structures:



- Built-in array

- `vector`

- `list`



The program generates 100,000 random numbers, inserts an additional number into the middle of each data structure, sorts the data, removes an element from the middle, and measures how long these operations take.



## Operations Performed



For each data structure, the program performs the following operations:



1. Generate and store 100,000 random `short int` values.

2. Generate one additional random value.

3. Insert the new value into the middle of the data structure.

4. Sort the entire data structure.

5. Remove the element from the middle.

6. Measure the total time taken for these operations.



## Data Structures



### Built-in Array



The program uses:



short int builtin[100001];





Since a built-in array has a fixed size and does not provide insertion or deletion operations, these operations are performed manually.



To insert an element, existing elements are shifted one position to the right:



for (int i = 100000; i > 50000; --i) { builtin[i] = builtin[i - 1]; }





The new element is then placed at index `50000`.



To remove the element, the elements after it are shifted one position to the left.



The array is sorted using:



sort(builtin, builtin + 100001);





### Vector



The program uses:



vector<short int> vec;





The vector provides built-in insertion and deletion operations:



vec.insert(vec.begin() + 50000, random\_int);





and:



vec.erase(vec.begin() + 50000);





The vector is sorted using:



sort(vec.begin(), vec.end());





Because a vector stores its elements contiguously in memory, inserting or removing an element from the middle requires the elements after that position to be moved.



### Linked List



The program uses:



list<short int> included;





A linked list does not provide direct random access using an index. Therefore, an iterator is moved to the middle of the list using:



auto it = included.begin(); advance(it, included.size() / 2);





The element can then be inserted using:



included.insert(it, random\_int);





The list provides its own sorting function:



included.sort();





The middle element is found again and removed using:



included.erase(it);





## Timing



The program uses the C++ `<chrono>` library to measure execution time:



auto start = highresolutionclock::now();



// Operations being measured



auto stop = highresolutionclock::now();





The elapsed time is converted to microseconds:



auto duration = duration_cast<microseconds>(stop - start);





The result is then printed to the console.



## Random Number Generation



The program generates random values using the `<random>` library.



A Mersenne Twister random number generator is created:



mt19937 rng(rd());





The values are generated within the range of a `short int`:



uniformintdistribution<int> uni(-32768, 32767);





This produces random numbers between `-32768` and `32767`.








## Example Output



The exact values will vary depending on the computer and compiler.



Operations on builtin table took 12345 microseconds Operations on vector took 11234 microseconds Operations on list took 23456 microseconds





## Important Note



The measured time includes **insertion, sorting, and removal** for each data structure.



The sorting operation can have a significant effect on the total execution time, so the results do not represent only the performance of insertion and deletion.



The results can also vary between runs because of:



- CPU speed

- Compiler optimizations

- Operating system activity

- Memory usage

- Randomly generated input data

- C++ standard library implementation



For more reliable benchmarking, the program should ideally be run multiple times and the results averaged.

