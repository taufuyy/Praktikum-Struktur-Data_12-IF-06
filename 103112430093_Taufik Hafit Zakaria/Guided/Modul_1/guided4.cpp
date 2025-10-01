#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa
{
    string nama;
    string NIM;
};

int main() { //Taufik Hafit Zakaria || 103112430093 || 12-IF-06
    Mahasiswa mhs;

    cout << "Nama : ";
    getline(cin, mhs.nama);
    cout << "NIM : ";
    cin >> mhs.NIM;

    
    cout << "====================\nNama : " << mhs.nama << endl
         << "NIM : " << mhs.NIM;
}