//Ronuel Diaz
// This is a project that was done for my Algorithms Class
//The point of this project is to test out difference forms of sequential searchs on arrays 
//aswell as a binary search.

//read the comments to set up the different array sizes and ranges of numbers being stored.



#include <cstdlib>
#include <math.h>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*counters*/
unsigned long int keycounter = 0;
unsigned long int instruct_counter = 0;

/*prototypes*/
void generateRandomarray();
void generateSizedArray(int * random_pick);
void sequentialSearch(int * random_pick, int * uniq_array);
void sequentialSearchOrdered(int * random_pick, int * uniq_array);
void sequentialSearchFrontSwap(int * random_pick, int * uniq_array);
void sequentialSearchIndexed(int * random_pick, int * uniq_array);
void sequentialSearchFirstSwap(int * random_pick, int * uniq_array);
void BinarySearch(int * random_pick, int * uniq_array);


/*Sizes*/
int c = pow(10, 3); // size of random pick array
int b = pow(10, 8); // size of unique random array 
int a = pow(2, 31) - 1; // Range of Numbers
int index = 8; // Only used during the sequential search with indexing. 
               //must match the power of the size of the unique number array. 
/*ARRAYS*/
int * uniq_array = new int[b];
int * random_pick = new int[c];

/*Hash Table*/
std::unordered_map<int, int> intmap;

int main() {
    srand(time(NULL));

    for (int k = 99; k < 100; k++) { // Controls how many loops the program will
                                     //run through

        generateRandomarray();


    }

    cout << "   " << endl;
    cout << keycounter << "        " << instruct_counter << endl;

    return 0;

}

void generateRandomarray() {


    for (int i = 0; i < c; i++) {


        random_pick[i] = rand() % a;
    }

    generateSizedArray(random_pick);
}

void generateSizedArray(int * random_pick) {
    int Uint; // Unique Integer

    for (int i = 0; i < b; i++) {
        Uint = rand() % a;

        while (intmap.find(Uint) != intmap.end()) {// prevents non unique random numbers
            Uint = rand() % a; //tested with array size 101 and range of 100
            // result: ran forever which means it works. 
        }

        intmap.insert({Uint, i});
        uniq_array[i] = Uint;

    }
    intmap.clear();
    BinarySearch(random_pick, uniq_array); // change this function to run the different searches
}

void sequentialSearch(int * random_pick, int * uniq_array) {


    instruct_counter += 2;
    for (int j = 0; j < c; j++) {
        instruct_counter += 2;
        for (int h = 0; h < b; h++) {
            if (random_pick[j] == uniq_array[h]) {
                keycounter++;
                instruct_counter++;
                break;
            }

            instruct_counter += 3;
        }

        instruct_counter += 3;
    }

}

void sequentialSearchOrdered(int * random_pick, int * uniq_array) {


    std::sort(uniq_array, uniq_array + b);

    instruct_counter += 2;
    for (int j = 0; j < c; j++) {
        instruct_counter += 2;
        for (int h = 0; h < b; h++) {
            if (random_pick[j] == uniq_array[h]) {
                keycounter++;
                instruct_counter++;
                break;
            }

            instruct_counter += 3;
        }

        instruct_counter += 3;
    }

}

void sequentialSearchIndexed(int * random_pick, int * uniq_array) {


    std::sort(uniq_array, uniq_array + b); // quick sort 

    instruct_counter += 2;
    for (int j = 0; j < c; j++) {
        instruct_counter += 2;
        for (int h = 0; h < b; h += index) {
            if (random_pick[j] == uniq_array[h]) {
                keycounter++;
                instruct_counter++;
                break;
            }

            instruct_counter += 3;
        }

        instruct_counter += 3;
    }

}

void sequentialSearchFirstSwap(int * random_pick, int * uniq_array) {


    instruct_counter += 2;
    for (int j = 0; j < c; j++) {
        instruct_counter += 2;
        for (int h = 0; h < b; h++) {
            if (random_pick[j] == uniq_array[h]) {
                swap(uniq_array[0], uniq_array[h]);
                keycounter++;
                instruct_counter += 4;
                break;
            }

            instruct_counter += 3;
        }

        instruct_counter += 3;
    }

}

void sequentialSearchFrontSwap(int * random_pick, int * uniq_array) {


    instruct_counter += 2;
    for (int j = 0; j < c; j++) {
        instruct_counter += 2;
        for (int h = 0; h < b; h++) {
            if (random_pick[j] == uniq_array[h]) {
                swap(uniq_array[h - 1], uniq_array[h]);
                keycounter++;
                instruct_counter += 4;
                break;
            }

            instruct_counter += 3;
        }

        instruct_counter += 3;
    }

}

void BinarySearch(int * random_pick, int * uniq_array) {


    std::sort(uniq_array, uniq_array + b);

    instruct_counter += 2;
    for (int j = 0; j < c; j++) {

        if (binary_search(uniq_array, uniq_array + b, random_pick[j])) {

            keycounter++;
            instruct_counter++;

        }


        instruct_counter += 3;
    }


}