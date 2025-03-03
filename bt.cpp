#include <iostream>

using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findMin(int arr[], int size) {
    if (size == 0) return -1;
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void insertElement(int arr[], int &size, int element, int position) {
    if (position < 0 || position > size || size >= 20) {
        cout << "Vi tri khong hop le " << endl;
        return;
    }
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
}

void removeElement(int arr[], int &size, int position) {
    if (position < 0 || position >= size) return;
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

int main() {
    int arr[20] = {8, 3, 7, 4, 2, 9, 5, 1, 6};
    int size = 9;

    cout << "Mang ban dau: ";
    printArray(arr, size);

    cout << "Gia tri nho nhat: " << findMin(arr, size) << endl;

    selectionSort(arr, size);

    cout << "Mang sau khi sap xep: ";
    printArray(arr, size);

    insertElement(arr, size, 10, 3);

    cout << "Mang sau khi chen: ";
    printArray(arr, size);

    reverseArray(arr, size);
    cout << "Mang sau khi dao nguoc: ";
    printArray(arr, size);

    removeElement(arr, size, 4);
    cout << "Mang sau khi xoa phan tu thu 4: ";
    printArray(arr, size);
}