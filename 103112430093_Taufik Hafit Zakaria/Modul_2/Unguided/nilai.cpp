//Taufik Hafit Zakaria
//103112430093_12 - IF 06

#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Masukkan jumlah bilangan: ";
    cin >> N;

    int *ptr = new int[N];
    for (int i = 0; i < N; i++) {
        cout << "Masukkan bilangan ke-" << (i+1) << ": ";
        cin >> ptr[i];
    }

    int jumlah = 0;
    int maksimum = ptr[0];
    int minimum = ptr[0];

    for (int i = 1; i < N; i++) {
        jumlah += ptr[i];
        if (ptr[i] > maksimum) {
            maksimum = ptr[i];
        }
        if (ptr[i] < minimum) {
            minimum = ptr[i];
        }
    }

    cout << "\nHasil:" << endl;
    cout << "Jumlah: " << jumlah << endl;
    cout << "Nilai Maksimum: " << maksimum << endl;
    cout << "Nilai Minimum: " << minimum << endl;

    delete[] ptr;
    return 0;
}