//Taufik Hafit Zakaria
//103112430093_12 - IF 06

#include <iostream>
#include "unguided3.h"
#include "unguided3.cpp"
using namespace std;

int main() {
    int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int B[3][3] = {{9,8,7},{6,5,4},{3,2,1}};
    int *p1, *p2;
    int a = 10, b = 20;

    cout << "Array A sebelum ditukar:\n";
    tampilArray(A);
    cout << "\nArray B sebelum ditukar:\n";
    tampilArray(B);

    tukarArray(A, B, 1, 1);

    cout << "\nArray A sesudah ditukar:\n";
    tampilArray(A);
    cout << "\nArray B sesudah ditukar:\n";
    tampilArray(B);

    p1 = &a;
    p2 = &b;
    cout << "\nSebelum tukar pointer: a=" << a << " b=" << b << endl;
    tukarPointer(p1, p2);
    cout << "Sesudah tukar pointer: a=" << a << " b=" << b << endl;

    return 0;
}