#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

int n; 

// Функція для введення кількості елементів масиву
int control() {
    while (true) {
        cout << "Enter the number of elements of the array: ";
        cin >> n;
        if (cin.get() == '\n' && n > 0) break;
        else {
            cout << "An integer is expected!";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return n;
}

// Функція для сортування масиву вставками
void insertionSort(int* arr) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


void genRandom(int* arr) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 2001 - 1000;
    }
}


void genSpad(int* arr) {
    for (int i = 0; i < n; i++) {
        arr[i] = 1000 - i;
    }
}


void duplicate_value(int* arr, int value) {
    for (int i = 0; i < n; i++) {
        arr[i] = value;
    }
}


void genTheSameValue(int* arr) {
    int value1, value2;
    do {
        value1 = rand() % 2001 - 1000;
        value2 = rand() % 2001 - 1000;
    } while (value1 == value2);

    duplicate_value(arr, value1);
    int index1 = rand() % n;
    int index2;
    do {
        index2 = rand() % n;
    } while (index2 == index1);

    arr[index2] = value2;
}

int main() {
    n = control();

    int* randomArr = new int[n];
    genRandom(randomArr);

    int* descendArr = new int[n];
    genSpad(descendArr);


    

 
    int uniformValue = rand() % 2001 - 1000;
    int* uniformArr = new int[n];
    duplicate_value(uniformArr, uniformValue);

    int* duplicateArr = new int[n + 2];
    genTheSameValue(duplicateArr);

    
    high_resolution_clock::time_point start_time1 = high_resolution_clock::now();
    insertionSort(randomArr);
    high_resolution_clock::time_point end_time1 = high_resolution_clock::now();

   
    high_resolution_clock::time_point start_time2 = high_resolution_clock::now();
    insertionSort(descendArr);
    high_resolution_clock::time_point end_time2 = high_resolution_clock::now();

   
    high_resolution_clock::time_point start_time3 = high_resolution_clock::now();
    insertionSort(uniformArr);
    high_resolution_clock::time_point end_time3 = high_resolution_clock::now();

 
    high_resolution_clock::time_point start_time4 = high_resolution_clock::now();
    insertionSort(duplicateArr);
    high_resolution_clock::time_point end_time4 = high_resolution_clock::now();

   
    auto duration1 = duration_cast<microseconds>(end_time1 - start_time1);
    auto duration2 = duration_cast<microseconds>(end_time2 - start_time2);
    auto duration3 = duration_cast<microseconds>(end_time3 - start_time3);
    auto duration4 = duration_cast<microseconds>(end_time4 - start_time4);

    cout << "Insertion sort for random array: " << duration1.count() << "ms" << endl;
    cout << "Insertion sort for descending array: " << duration2.count() << "ms" << endl;
    cout << "Insertion sort for uniform array: " << duration3.count() << "ms" << endl;
    cout << "Insertion sort for duplicate values array: " << duration4.count() << "ms" << endl;

    delete[] randomArr;
    delete[] descendArr;
    delete[] uniformArr;
    delete[] duplicateArr;

    return 0;
}
