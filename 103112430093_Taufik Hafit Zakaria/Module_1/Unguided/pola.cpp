#include <iostream>
using namespace std;

int main(){ //Taufik Hafit Zakaria || 103112430093 || 12-IF-06
    int angka;
    cout << "masukan angka : ";
    cin >> angka;

    for (int i = angka; i >= 1; i--)
    {
        for (int s = 0; s < angka - i; s++)
            cout << "  ";

        for (int j = i; j >= 1; j--)
            cout << j << " ";
        
        cout << "* ";

        for (int j = 1; j <= i; j++)
            cout << j << " ";
            
        cout << endl;
    }

    for (int s = 0; s < angka; s++)
        cout << "  ";
    cout << "*" << endl;

    return 0;
}