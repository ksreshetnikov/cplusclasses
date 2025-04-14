#include <iostream>
using namespace std;

class SortArray {
private:
    int* arr;
    int size;
    
public:
    SortArray(int array[], int n) : size(n) {
        arr = new int[size];
        for(int i=0; i<size; i++) {
            arr[i] = array[i];
        }
    }
    
    ~SortArray() {
        delete[] arr;
    }
    
    void sort() {
        for(int i=0; i<size-1; i++) {
            for(int j=0; j<size-i-1; j++) {
                if(*(arr+j) > *(arr+j+1)) {
                    swap(arr+j, arr+j+1);
                }
            }
        }
    }
    
    void display() {
        for(int i=0; i<size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
private:
    void swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};

int main() {
    int initialArray[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(initialArray)/sizeof(initialArray[0]);
    
    SortArray sorter(initialArray, n);
    cout << "Original array: ";
    sorter.display();
    
    sorter.sort();
    cout << "Sorted array: ";
    sorter.display();
    
    return 0;
}
