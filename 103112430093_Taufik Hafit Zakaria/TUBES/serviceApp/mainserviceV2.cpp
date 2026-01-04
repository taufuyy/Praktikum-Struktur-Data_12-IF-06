#include "serviceV2.h"
#include "serviceV2.cpp"

BST dataService;
ListTeknisi dataTeknisi;

// ==================== SERVICE MENU FUNCTIONS (BST) ====================

// Fungsi: Menambah service baru ke dalam BST
void tambahService() {
    clear_Screen();  
    cout << "|----------------------------------|\n";
    cout << "|========= TAMBAH SERVICE =========|\n";
    cout << "|----------------------------------|\n";
    
    infoService data;
    // Validasi ID Service dengan retry
    input_IntegerWithRetry(data.idService, "| ID Service: ");  
    
    // Validasi Nama Customer dengan retry
    input_StringWithRetry(data.namaCustomer, "| Nama Customer: ", false);  
    
    // Validasi Jenis Device dengan retry
    input_JenisDeviceWithRetry(data.jenisDevice, "| Jenis Device (laptop/hp): ");  
    
    // Validasi Keluhan dengan retry
    input_StringWithRetry(data.keluhan, "| Keluhan: ", false);  
    
    // Validasi Estimasi Hari dengan retry
    while (true) {
        input_IntegerWithRetry(data.estimasiHari, "| Estimasi (hari): ");  
        if (data.estimasiHari > 0) {
            break;
        } else {
            cout << "| ERROR: Estimasi harus lebih dari 0 hari! Silakan coba lagi.\n";
        }
    }
    
    // Validasi Jumlah Komponen Rusak dengan retry
    while (true) {
        input_IntegerWithRetry(data.jumlahKomponen, "| Jumlah Komponen Rusak : ");  
        if (data.jumlahKomponen >= 0 && data.jumlahKomponen <= max_komponen) {  
            break;
        } else {
            cout << "| ERROR: Jumlah komponen harus antara 0 dan " << max_komponen << "! Silakan coba lagi.\n";  
        }
    }
    
    // Input setiap komponen
    for (int i = 0; i < data.jumlahKomponen; i++) {
        cout << "| Komponen " << i+1 << ": ";
        getline(cin, data.komponenRusak[i]);  
    }
    
    adrService P = alokasi_Service(data);  
    insert_BST(dataService, P);  
    cout << "|----------------------------------|\n";
    cout << "|   Service berhasil ditambahkan!  |\n";
    cout << "|----------------------------------|\n";
    pause();  
}

// Fungsi: Mencari service berdasarkan ID
void cariService() {
    clear_Screen();
    cout << "|----------------------------------|\n";
    cout << "|========== CARI SERVICE ==========|\n";
    cout << "|----------------------------------|\n";
    
    int id;
    input_IntegerWithRetry(id, "| Masukkan ID Service: ");  
    
    adrService P = find_Service(dataService.root, id);  
    
    if (P != Nil) {
        tampilkan_Service(P->info);  
    } else {
        cout << "\n Service tidak ditemukan!\n";
    }
    pause();  
}

// Fungsi: Menghapus service dari BST
void hapusService() {
    clear_Screen();  
    cout << "|----------------------------------|\n";
    cout << "|========== HAPUS SERVICE =========|\n";
    cout << "|----------------------------------|\n";
    
    int id;
    input_IntegerWithRetry(id, "| Masukkan ID Service: ");  
    
    adrService P = find_Service(dataService.root, id);  
    if (P == Nil) {
        cout << "|                                  |\n";
        cout << "|==== Service tidak ditemukan! ====|\n";
        pause();
        return;
    }
    
    tampilkan_Service(P->info);  
    cout << "\nYakin ingin menghapus? (y/n): ";
    char konfirmasi;
    cin >> konfirmasi;
    cin.ignore();
    
    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        delete_Service(dataService, id);  
    } else {
        cout << "Penghapusan dibatalkan.\n";
    }
    pause();  
}

// ==================== TEKNISI MENU FUNCTIONS (MLL) ====================

// Fungsi: Menambah teknisi baru ke dalam list
void tambahTeknisi() {
    clear_Screen();  
    cout << "|----------------------------------|\n";
    cout << "|========= TAMBAH TEKNISI =========|\n";
    cout << "|----------------------------------|\n";
    
    infoTeknisi data;
    input_IntegerWithRetry(data.idTeknisi, "| ID Teknisi: ");
    input_StringWithRetry(data.namaTeknisi, "| Nama Teknisi: ", false);  
    
    // Validasi spesialisasi tidak boleh kosong dan harus laptop/hp
    do {
        input_StringWithRetry(data.spesialisasi, "| Spesialisasi (laptop/hp): ", false);  
        if (data.spesialisasi != "laptop" && data.spesialisasi != "hp") {
            cout << "| ERROR: Spesialisasi harus 'laptop' atau 'hp'!\n";
        }
    } while (data.spesialisasi != "laptop" && data.spesialisasi != "hp");
    
    adrTeknisi P = alokasi_Teknisi(data);  
    insert_Teknisi(dataTeknisi, P);  
    cout << "|----------------------------------|\n";
    cout << "|   Teknisi berhasil ditambahkan!  |\n";
    cout << "|----------------------------------|\n";
    pause();  
}

// Fungsi: Mengassign service ke teknisi (queue antrian)
void assignServiceKeTeknisi() {
    clear_Screen();  
    cout << "|----------------------------------|\n";
    cout << "|======== ASSIGN SERVICE ==========|\n";
    cout << "|----------------------------------|\n";
    
    int idService, idTeknisi;
    
    input_IntegerWithRetry(idService, "| ID Service: ");
    
    adrService S = find_Service(dataService.root, idService);  
    if (S == Nil) {
        cout << "| Service tidak ditemukan!         |\n";
        pause();  
        return;
    }
    
    // CEK APAKAH SERVICE SUDAH DIASSIGN
    if (serviceAlready_Assigned(dataTeknisi, idService)) {  
        cout << "\nService dengan ID " << idService << " sudah diassign ke teknisi lain!\n";
        cout << "            Tidak bisa diassign lagi.\n";
        pause();  
        return;
    }
    
    input_IntegerWithRetry(idTeknisi, "| ID Teknisi: ");  
    
    adrTeknisi T = find_Teknisi(dataTeknisi, idTeknisi);  
    if (T == Nil) {
        cout << "| Teknisi tidak ditemukan!         |\n";
        pause();  
        return;
    }
    
    // Cek kesesuaian jenis device dengan spesialisasi teknisi
    if (to_Lowercase(S->info.jenisDevice) != to_Lowercase(T->info.spesialisasi)) {  
        cout << "Peringatan: Jenis device (" << S->info.jenisDevice 
             << ") tidak sesuai dengan spesialisasi teknisi (" 
             << T->info.spesialisasi << ")!\n";
        cout << "Tetap assign? (y/n): ";
        char pilihan;
        cin >> pilihan;
        cin.ignore();
        if (pilihan != 'y' && pilihan != 'Y') {
            cout << "Assign dibatalkan.\n";
            pause();  
            return;
        }
    }
    
    adrAntrian A = alokasi_Atrian(idService);  
    insert_Atrian(T, A);  
    cout << "\nService berhasil diassign ke " << T->info.namaTeknisi << "!\n";
    pause();  
}

// Fungsi: Melayani antrian pertama dari teknisi
void layaniAntrian() {
    clear_Screen();  
    cout << "|-------------------------------------|\n";
    cout << "|========== LAYANI ANTRIAN ===========|\n";
    cout << "|-------------------------------------|\n";
    
    int idTeknisi;
    input_IntegerWithRetry(idTeknisi, "| ID Teknisi: ");
    
    adrTeknisi T = find_Teknisi(dataTeknisi, idTeknisi);  
    if (T == Nil) {
        cout << "| Teknisi tidak ditemukan!         |\n";
        pause();  
        return;
    }
    
    if (T->firstAntrian == Nil) {
        cout << "|                                     |\n";
        cout << "| Teknisi ini tidak memiliki antrian. |\n";
    } else {
        cout << "\n| Antrian yang akan dilayani:\n";
        cout << "| Service ID: " << T->firstAntrian->idService << endl;
        
        cout << "\nLayani antrian ini? (y/n): ";
        char konfirmasi;
        cin >> konfirmasi;
        cin.ignore();
        
        if (konfirmasi == 'y' || konfirmasi == 'Y') {
            delete_FirstAntrian(T);  
        } else {
            cout << "Pelayanan dibatalkan.\n";
        }
    }
    pause();  
}

// ==================== LAPORAN & STATISTIK ====================

// Fungsi: Menampilkan laporan statistik sistem
void laporanStatistik() {
    clear_Screen();  
    
    cout << "|========================================|\n";
    cout << "|           LAPORAN STATISTIK            |\n";
    cout << "|========================================|\n";
    
    int totalService = count_TotalService(dataService.root);  
    cout << "| 1. Total Service: " << totalService <<"                    |"<< endl;
    
    int totalAntrian = count_TotalAntrian(dataTeknisi);  
    cout << "| 2. Total Antrian Aktif: " << totalAntrian <<"              |"<< endl;
    
    adrService maxNode = find_MaxKomponen(dataService.root);  
    if (maxNode != Nil) {
        cout << "| 3. Service Komponen Terbanyak:         |\n";
        cout << "|    ID: " << maxNode->info.idService 
             << " | Komponen: " << maxNode->info.jumlahKomponen <<"               |"<< endl;
    }
    
    adrService minNode = find_MinEstimasi(dataService.root);  
    if (minNode != Nil) {
        cout << "| 4. Service Estimasi Tercepat:          |\n";
        cout << "|    ID: " << minNode->info.idService 
             << " | Estimasi: " << minNode->info.estimasiHari << " hari          |\n";
    }
    
    adrTeknisi T = find_TeknisiPalingSedikit(dataTeknisi);  
    if (T != Nil) {
        cout << "| 5. Teknisi dengan Antrian Tersedikit:  |\n";
        cout << "|    Nama: " << T->info.namaTeknisi 
             << " | Antrian: " << count_AntrianTeknisi(T) <<"             |"<< endl;
    }
    
    cout << "|========================================|\n";
    pause();  
}

// ==================== MENU UTAMA SERVICE (BST) ====================

// Fungsi: Menu utama untuk operasi BST (Service)
void menuService() {
    int pilihan;
    do {
        clear_Screen(); 
        cout << "|--------------------------------|\n";
        cout << "|====== MENU SERVICE (BST) ======|\n";
        cout << "|--------------------------------|\n";
        cout << "| 1. Tambah Service Baru         |\n";
        cout << "| 2. Cari Service                |\n";
        cout << "| 3. Hapus Service               |\n";
        cout << "| 4. Tampilkan Semua (InOrder)   |\n";
        cout << "| 5. Tampilkan       (PreOrder)  |\n";
        cout << "| 6. Tampilkan       (PostOrder) |\n";
        cout << "| 7. Tampilkan by Jenis Device   |\n";
        cout << "| 0. Kembali                     |\n";
        cout << "|--------------------------------|\n";
        cout << "\n=> Pilihan: ";
        
        // Validasi input menu
        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "ERROR: Input harus berupa angka! Silakan coba lagi.\n";
            pause();  
            continue;
        }
        cin.ignore();
        
        switch(pilihan) {
            case 1: tambahService(); break;
            case 2: cariService(); break;
            case 3: hapusService(); break;
            case 4: 
                clear_Screen();  
                cout << "|----------------------------------|\n";
                cout << "|==== DAFTAR SERVICE (INORDER) ====|\n";
                cout << "|                                  |\n";
                show_InOrder(dataService.root);  
                pause();  
                break;
            case 5:
                clear_Screen();  
                cout << "|----------------------------------|\n";
                cout << "|=== DAFTAR SERVICE (PREORDER) ====|\n";
                cout << "|                                  |\n";
                show_PreOrder(dataService.root);  
                pause();  
                break;
            case 6:
                clear_Screen();  
                cout << "|----------------------------------|\n";
                cout << "|=== DAFTAR SERVICE (POSTORDER) ===|\n";
                cout << "|                                  |\n";
                show_PostOrder(dataService.root);  
                pause();  
                break;
            case 7: {
                clear_Screen();  
                cout << "|----------------------------------|\n";
                cout << "|======== SERVICE BY JENIS ========|\n";
                cout << "|----------------------------------|\n";

                string jenis;
                input_JenisDeviceWithRetry(jenis, "| Jenis Device (laptop/hp): "); 
                cout << "|                                  |\n";
                show_Jenis(dataService.root, jenis);  
                pause();  
                break;
            }
            case 0: break;
            default:
                cout << "Pilihan tidak valid! Silakan coba lagi.\n";
                pause();  
        }
    } while(pilihan != 0);
}

// ==================== MENU UTAMA TEKNISI (MLL) ====================

// Fungsi: Menu utama untuk operasi MLL (Teknisi & Antrian)
void menuTeknisi() {
    int pilihan;
    do {
        clear_Screen();  
        cout << "|--------------------------------|\n";
        cout << "|====== MENU TEKNISI (MLL) ======|\n";
        cout << "|--------------------------------|\n";
        cout << "| 1. Tambah Teknisi              |\n";
        cout << "| 2. Lihat Semua Teknisi         |\n";
        cout << "| 3. Hapus Teknisi               |\n";
        cout << "| 4. Assign Service ke Teknisi   |\n";
        cout << "| 5. Lihat Antrian Teknisi       |\n";
        cout << "| 6. Layani Antrian              |\n";
        cout << "| 0. Kembali                     |\n";
        cout << "|--------------------------------|\n";
        cout << "\n=> Pilihan: ";
        
        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "ERROR: Input harus berupa angka! Silakan coba lagi.\n";
            pause();  
            continue;
        }
        cin.ignore();
        
        switch(pilihan) {
            case 1: tambahTeknisi(); break;
            case 2: 
                clear_Screen();  
                show_AllTeknisi(dataTeknisi);  
                pause();  
                break;
            case 3: {
                clear_Screen();  
                cout << "|--------------------------------|\n";
                cout << "|======== HAPUS TEKNISI =========|\n";
                cout << "|--------------------------------|\n";
                int id;
                input_IntegerWithRetry(id, "| ID Teknisi: ");  
                adrTeknisi T = find_Teknisi(dataTeknisi, id);  
                if (T != Nil) {
                    tampilkan_DataTeknisi(T->info, count_AntrianTeknisi(T));  
                    
                    cout << "\nYakin ingin menghapus? (y/n): ";
                    char konfirmasi;
                    cin >> konfirmasi;
                    cin.ignore();
                    
                    if (konfirmasi == 'y' || konfirmasi == 'Y') {
                        delete_Teknisi(dataTeknisi, id);  
                    } else {
                        cout << "Penghapusan dibatalkan.\n";
                    }
                } else {
                    cout << "| Teknisi dengan ID tersebut tidak ditemukan!\n";
                }
                pause();  
                break;
            }
            case 4: assignServiceKeTeknisi(); break;
            case 5: {
                clear_Screen();  
                cout << "|--------------------------------|\n";
                cout << "|======== Lihat Antrian =========|\n";
                cout << "|--------------------------------|\n";
                int idTek;
                input_IntegerWithRetry(idTek, "| ID Teknisi: ");  
                adrTeknisi teknisi = find_Teknisi(dataTeknisi, idTek);  
                if (teknisi != Nil) {
                    show_AntrianTeknisi(teknisi);  
                } else {
                    cout << "| Teknisi dengan ID tersebut tidak ditemukan!\n";
                }
                pause();  
                break;
            }
            case 6: layaniAntrian(); break;
            case 0: break;
            default:
                cout << "| Pilihan tidak valid! Silakan coba lagi.\n";
                pause();  
        }
    } while(pilihan != 0);
}

// ==================== FUNGSI MAIN ====================

int main() {
    // Inisialisasi struktur data
    create_BST(dataService);  
    create_ListTeknisi(dataTeknisi);  
    
    // Data contoh untuk demo
    infoService contoh1 = {101, "Andi", "laptop", "Layar rusak", {"LCD", "Kabel"}, 2, 3};  
    infoService contoh2 = {102, "Budi", "hp", "Baterai boros", {"Baterai"}, 1, 2};
    insert_BST(dataService, alokasi_Service(contoh1));
    insert_BST(dataService, alokasi_Service(contoh2));
    
    infoTeknisi tek1 = {1, "Joko", "laptop"};
    infoTeknisi tek2 = {2, "Sari", "hp"};
    insert_Teknisi(dataTeknisi, alokasi_Teknisi(tek1));
    insert_Teknisi(dataTeknisi, alokasi_Teknisi(tek2));
    
    // Menu utama program
    int pilihan;
    do {
        clear_Screen();
        cout << "|----------------------------------------|\n";
        cout << "|=== SISTEM ANTRIAN SERVICE LAPTOP/HP ===|\n";
        cout << "|----------------------------------------|\n";
        cout << "| 1. Menu Service (BST)                  |\n";
        cout << "| 2. Menu Teknisi & Antrian (MLL)        |\n";
        cout << "| 3. Laporan & Statistik                 |\n";
        cout << "| 0. Keluar                              |\n";
        cout << "|----------------------------------------|\n";
        cout << "\n=> Pilihan: ";
        
        
        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "ERROR: Input harus berupa angka! Silakan coba lagi.\n";
            pause();  
            continue;
        }
        cin.ignore();
        
        switch(pilihan) {
            case 1: menuService(); break;
            case 2: menuTeknisi(); break;
            case 3: laporanStatistik(); break;
            case 0: 
                clear_Screen();  
                cout << "\n======== Terima kasih telah menggunakan sistem ini! ========\n\n";
                break;
            default:
                cout << "\nPilihan tidak valid! Silakan coba lagi.\n";
                pause();  
        }
    } while(pilihan != 0);
    
    return 0;
}