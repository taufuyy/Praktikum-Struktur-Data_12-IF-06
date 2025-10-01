#include <iostream>
using namespace std;

int main() { //Taufik Hafit Zakaria || 103112430093 || 12-IF-06
    float angka1, angka2, tambah, kurang, kali, bagi;
    cout << "\nMasukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;
    tambah = angka1 + angka2;
    kurang = angka1 - angka2;
    kali = angka1 * angka2;
    cout << "=====================================\n";
    cout << "Hasil tambah: " << tambah << endl;
    cout << "Hasil kurang: " << kurang << endl;
    cout << "Hasil kali: " << kali << endl;
    if (angka2 != 0) {
        bagi = angka1 / angka2;
        cout << "Hasil bagi: " << bagi << endl;
    } else {
        cout << "Pembagi tidak boleh 0" << endl;
    }
    return 0;
}