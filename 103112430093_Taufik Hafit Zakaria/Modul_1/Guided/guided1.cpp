#include <iostream>
using namespace std;

int main() { //Taufik Hafit Zakaria || 103112430093 || 12-IF-06
    int hari;
    cout << "Hari 1-7: ";
    cin >> hari;
    if (hari == 7)
    {
        cout << "Hari minggu\n";
    }
    else
    {
        cout << "Hari kerja\n";
    }
    
    switch (hari)
    {
    case 7:
        cout << "Hari minggu\n";
        break;
    
    default:
        cout << "Hari kerja\n";
        break;
    }

}
