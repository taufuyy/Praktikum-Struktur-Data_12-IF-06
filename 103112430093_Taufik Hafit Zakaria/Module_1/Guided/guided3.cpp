#include <iostream>
using namespace std;

struct Mahasiswa
{
    string nama;
    string NIM;
};

int main() { //Taufik Hafit Zakaria || 103112430093 || 12-IF-06
    Mahasiswa mhs;
    mhs.nama = "Taufik";
    mhs.NIM = "1103112430093";

    cout << "Nama : " << mhs.nama << endl
         << "NIM : " << mhs.NIM;
}