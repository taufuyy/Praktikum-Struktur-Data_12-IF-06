//Taufik Hafit Zakaria
//103112430093_12 - IF 06
//playlist-main.cpp

#include <iostream>
#include "Playlist.h"
#include "Playlist.cpp"
using namespace std;

int main() {
    Playlist myPlaylist;
    createPlaylist(myPlaylist);

    int pilihan;
    string judul, penyanyi;
    float durasi;

    do {
        cout << "\n===== MENU PLAYLIST LAGU =====" << endl;
        cout << "1. Tambah lagu di awal playlist" << endl;
        cout << "2. Tambah lagu di akhir playlist" << endl;
        cout << "3. Tambah lagu setelah lagu ke-3" << endl;
        cout << "4. Hapus lagu berdasarkan judul" << endl;
        cout << "5. Tampilkan semua lagu" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore(); 

        switch (pilihan) {
        case 1:
            cout << "\nMasukkan judul lagu   : ";
            getline(cin, judul);
            cout << "Masukkan nama penyanyi: ";
            getline(cin, penyanyi);
            cout << "Masukkan durasi (menit): ";
            cin >> durasi;
            tambahAwal(myPlaylist, createNode(judul, penyanyi, durasi));
            cout << "Lagu berhasil ditambahkan di awal!\n";
            break;

        case 2:
            cout << "\nMasukkan judul lagu   : ";
            getline(cin, judul);
            cout << "Masukkan nama penyanyi: ";
            getline(cin, penyanyi);
            cout << "Masukkan durasi (menit): ";
            cin >> durasi;
            tambahAkhir(myPlaylist, createNode(judul, penyanyi, durasi));
            cout << "Lagu berhasil ditambahkan di akhir!\n";
            break;

        case 3:
            cout << "\nMasukkan judul lagu   : ";
            getline(cin, judul);
            cout << "Masukkan nama penyanyi: ";
            getline(cin, penyanyi);
            cout << "Masukkan durasi (menit): ";
            cin >> durasi;
            tambahSetelahKe3(myPlaylist, createNode(judul, penyanyi, durasi));
            break;

        case 4:
            cout << "\nMasukkan judul lagu yang ingin dihapus: ";
            getline(cin, judul);
            hapusBerdasarkanJudul(myPlaylist, judul);
            break;

        case 5:
            tampilkanPlaylist(myPlaylist);
            break;

        case 0:
            cout << "\nKeluar dari program. Terima kasih!\n";
            break;

        default:
            cout << "Pilihan tidak valid! Coba lagi.\n";
        }
    } while (pilihan != 0);

    return 0;
}