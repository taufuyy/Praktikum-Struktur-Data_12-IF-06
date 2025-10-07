//Taufik Hafit Zakaria
//103112430093_12 - IF 03

#include <iostream>
using namespace std;
int main(){
    int x, y;
    int *px;
    x = 87;
    px = &x;
    y = *px;

    cout << "Alamat x    = " << &x << endl;
    cout << "Isi px      = " << px << endl;
    cout << "Isi x       = " << x << endl;
    cout << "Nilai *px   = " << *px << endl;
    cout << "Nilai y     = " << y << endl;
    
    return 0;
}