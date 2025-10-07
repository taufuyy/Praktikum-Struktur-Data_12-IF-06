//Taufik Hafit Zakaria
//103112430093_12 - IF 06

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan panjang segitiga: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}