#include <iostream>
#include <random>
#include <assert.h>
#include <string.h>

using namespace std;

#define MIN 100
#define MAX 500

mt19937 rng;

int generateRandomInt(int min, int max);
void printArray(int *array, size_t size);
void heapsort(int* array, size_t size);
void buildheap(int* array, size_t size);
void maxheapify(int* array, size_t, int pos);
void swap(int& a, int& b){
	a^=b;b^=a;a^=b;
}
bool validate(int* array, size_t size);

int main(int argc, char *argv[]) {
    rng.seed(random_device()());
    cout << "===========================================================" << endl;
    cout << "\tHeapsort Practice" << endl;
    cout << "===========================================================" << endl << endl;

    const int numberOfElements = generateRandomInt(MIN, MAX);
    int *numbers = new int[numberOfElements];
    for (int i = 0; i < numberOfElements; i++) {
        numbers[i] = generateRandomInt(0, 100);
    }

    printArray(numbers, numberOfElements);
    heapsort(numbers, numberOfElements);
    printArray(numbers, numberOfElements);
    assert(validate(numbers, numberOfElements) && "The sort is not ordering all the elements");

    system("read");
    return EXIT_SUCCESS;
}

int generateRandomInt(int min, int max) {
    uniform_int_distribution<mt19937::result_type> distribution(min, max); 
    return distribution(rng);
}

void printArray(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void maxheapify(int* array, size_t size, int pos){
	int right = (pos+1)<<1,
		left = right-1;
	int maxlocal;
	if(right < size && array[right] > array[pos] ){
		maxlocal = right;
	}else{
		maxlocal = pos;
	}
	if( left < size && array[left] > array[maxlocal] ){
		maxlocal = left;
	}
	if( maxlocal != pos){
		swap(array[pos], array[maxlocal]);
		maxheapify(array, size, maxlocal);
	}
	
}

void buildheap(int* array, size_t size){
	for(int i=(size>>1); i>=0 ; i--){
		maxheapify(array, size, i);
	}
}
void heapsort(int* array, size_t size) {
	buildheap(array, size);
	for(int i = size-1; i>0 ; i--){
		swap(array[0], array[i]);
		size--;
		maxheapify(array, size, 0);
	}
}

bool validate(int* array, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}
