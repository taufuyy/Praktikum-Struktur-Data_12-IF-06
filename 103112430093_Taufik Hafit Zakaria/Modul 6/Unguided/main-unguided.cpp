//Taufik Hafit Zakaria
//103112430093_12 - IF 06
//main-unguided.cpp
#include "Doublylist.h"
#include "Doublylist.cpp"

void tampilkanMenu() {
    cout << "1. Tambah Data" << endl;
    cout << "2. Cari Data" << endl;
    cout << "3. Hapus Data" << endl;
    cout << "4. Keluar Program" << endl;
    cout << "Pilih menu (0-1): ";
}

void tambahData(List &L) {
    infotype x;
    address P;
    string jawaban;
    
    cout << "\n=== TAMBAH DATA KENDARAAN ===" << endl;
    
    do {
        cout << endl;
        cout << "Masukkan nomor polisi: ";
        getline(cin, x.nopol);
        
        cout << "Masukkan warna kendaraan: ";
        getline(cin, x.warna);
        
        cout << "Masukkan tahun kendaraan: ";
        cin >> x.thnBuat;
        cin.ignore();
        
        if (findElm(L, x.nopol) != Nil) {
            cout << "\nError: Nomor polisi sudah terdaftar!" << endl;
            cout << endl;
            continue;
        }
        
        P = alokasi(x);
        insertLast(L, P);
        cout << endl;
        
        cout << "Apakah ingin menambahkan data kendaraan lagi? (ya/tidak): ";
        getline(cin, jawaban);
        
    } while (jawaban == "ya" || jawaban == "Ya" || jawaban == "YA" || jawaban == "Y" || jawaban == "y");
    
    cout << "\n=== DATA KENDARAAN ===" << endl;
    if (L.first == Nil) {
        cout << "Tidak ada data kendaraan." << endl;
    } else {
        printInfo(L);
    }
    cout << endl;
}

void cariData(List L) {
    if (L.first == Nil) {
        cout << "\nTidak ada data kendaraan untuk dicari." << endl;
        cout << endl;
        return;
    }
    
    string nopolCari;
    string lanjut;
    
    cout << "\n=== CARI DATA KENDARAAN ===" << endl;
    
    do {
        cout << endl;
        cout << "Masukkan nomor polisi yang dicari: ";
        getline(cin, nopolCari);
        
        address hasil = findElm(L, nopolCari);
        if (hasil != Nil) {
            cout << "\nData kendaraan ditemukan:" << endl;
            cout << "No polisi  : " << hasil->info.nopol << endl;
            cout << "Warna      : " << hasil->info.warna << endl;
            cout << "Tahun      : " << hasil->info.thnBuat << endl;
        } else {
            cout << "\nData tidak tersedia." << endl;
        }
        
        cout << endl;
        cout << "Apakah ingin melanjutkan pencarian? (ya/tidak): ";
        getline(cin, lanjut);
        
    } while (lanjut == "ya" || lanjut == "Ya" || lanjut == "YA" || lanjut == "Y" || lanjut == "y");
    
    cout << endl;
}

void hapusData(List &L) {
    if (L.first == Nil) {
        cout << "\nTidak ada data kendaraan untuk dihapus." << endl;
        cout << endl;
        return;
    }
    
    string nopolHapus;
    string lanjut;
    
    cout << "\n=== HAPUS DATA KENDARAAN ===" << endl;
    
    do {
        if (L.first == Nil) {
            cout << "\nTidak ada data kendaraan tersisa." << endl;
            break;
        }
        
        cout << endl;
        cout << "Masukkan nomor polisi yang ingin dihapus: ";
        getline(cin, nopolHapus);
        
        address hapus = findElm(L, nopolHapus);
        if (hapus != Nil) {
            address temp;
            
            if (hapus == L.first) {
                deleteFirst(L, temp);
            } else if (hapus == L.last) {
                deleteLast(L, temp);
            } else {
                address prec = hapus->prev;
                deleteAfter(prec, temp);
            }
            
            cout << "\nData dengan nomor polisi " << nopolHapus << " berhasil dihapus." << endl;
            dealokasi(temp);
            
            cout << endl;
            cout << "=== DATA KENDARAAN TERUPDATE ===" << endl;
            if (L.first == Nil) {
                cout << "Tidak ada data kendaraan." << endl;
            } else {
                printInfo(L);
            }
        } else {
            cout << "\nData dengan nomor polisi " << nopolHapus << " tidak ditemukan." << endl;
        }
        
        cout << endl;
        cout << "Apakah ingin melanjutkan penghapusan? (ya/tidak): ";
        getline(cin, lanjut);
        
    } while (lanjut == "ya" || lanjut == "Ya" || lanjut == "YA" || lanjut == "Y" || lanjut == "y");
    
    cout << endl;
}

int main() {
    List L;
    createList(L);
    
    int pilihan;
    
    cout << "=== PROGRAM DATA KENDARAAN ===" << endl;
    cout << endl;
    
    do {
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore();
        
        switch(pilihan) {
            case 1:
                tambahData(L);
                break;
            case 2:
                cariData(L);
                break;
            case 3:
                hapusData(L);
                break;
            case 4:
                cout << "\nTerima kasih telah menggunakan program ini!" << endl;
                break;
            default:
                cout << "\nPilihan tidak valid! Silakan pilih menu 0-1." << endl;
                cout << endl;
        }
        
    } while (pilihan != 4);
    
    // Dealokasi semua elemen
    address temp;
    while (L.first != Nil) {
        deleteFirst(L, temp);
        dealokasi(temp);
    }
    
    return 0;
}