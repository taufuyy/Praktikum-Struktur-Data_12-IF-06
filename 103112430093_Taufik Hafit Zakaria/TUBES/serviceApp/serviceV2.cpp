#include "serviceV2.h"

// ==================== VALIDASI INPUT ====================

// Fungsi: Memvalidasi input angka
bool isValid_Integer(int &num, string pertanyaan) {
    cout << pertanyaan;
    if (!(cin >> num)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "| ERROR: Input harus berupa angka! Silakan coba lagi.\n";
        return false;
    }
    cin.ignore();
    return true;
}

// Fungsi: Input angka dengan perulangan jika salah
bool input_IntegerWithRetry(int &num, string pertanyaan) {
    while (true) {
        cout << pertanyaan;
        if (!(cin >> num)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "| ERROR: Input harus berupa angka! Silakan coba lagi.\n";
        } else {
            cin.ignore();
            return true;
        }
    }
}

// Fungsi: Memvalidasi input string
bool isValid_String(string &str, string pertanyaan, bool allowEmpty) {
    cout << pertanyaan;
    getline(cin, str);
    if (!allowEmpty && str.empty()) {
        cout << "| ERROR: Input tidak boleh kosong!\n";
        return false;
    }
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return true;
}

// Fungsi: Input string dengan perulangan jika salah
bool input_StringWithRetry(string &str, string pertanyaan, bool allowEmpty) {
    while (true) {
        cout << pertanyaan;
        getline(cin, str);
        
        if (!allowEmpty && str.empty()) {
            cout << "| ERROR: Input tidak boleh kosong! Silakan coba lagi.\n";
        } else {
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            return true;
        }
    }
}

// Fungsi: Input jenis device (laptop/hp) dengan validasi
bool input_JenisDeviceWithRetry(string &jenis, string pertanyaan) {
    while (true) {
        cout << pertanyaan;
        getline(cin, jenis);
        // Konversi ke huruf kecil
        transform(jenis.begin(), jenis.end(), jenis.begin(), ::tolower);
        // Validasi: hanya menerima "laptop" atau "hp"
        if (jenis == "laptop" || jenis == "hp") {
            return true;
        } else {
            cout << "| ERROR: Jenis device harus 'laptop' atau 'hp'! Silakan coba lagi.\n";
        }
    }
}

// Fungsi: Konversi string ke huruf kecil
string to_Lowercase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// ==================== TAMPILAN DATA ====================

// Fungsi: Menampilkan detail lengkap service
void tampilkan_Service(infoService data) {
    cout << "|----------------------------------|\n";
    cout << "|========= DETAIL SERVICE =========|\n";
    cout << "|----------------------------------|\n";
    cout << "| ID Service     : " << data.idService << endl;
    cout << "| Nama Customer  : " << data.namaCustomer << endl;
    cout << "| Jenis Device   : " << data.jenisDevice << endl;
    cout << "| Keluhan        : " << data.keluhan << endl;
    cout << "| Estimasi       : " << data.estimasiHari << " hari" << endl;
    cout << "| Komponen Rusak : ";
    if (data.jumlahKomponen == 0) {
        cout << "Tidak ada";
    } else {
        for (int i = 0; i < data.jumlahKomponen; i++) {
            cout << "\n|  - " << data.komponenRusak[i];
        }
    }
    cout << "\n|==================================|\n";
}

// Fungsi: Menampilkan detail teknisi beserta jumlah antrian
void tampilkan_DataTeknisi(infoTeknisi data, int jumlahAntrian) {
    cout << "\n|--------------------------------|\n";
    cout << "|========= DATA TEKNISI =========|\n";
    cout << "|--------------------------------|\n";
    cout << "| ID Teknisi    : " << data.idTeknisi << endl;
    cout << "| Nama Teknisi  : " << data.namaTeknisi << endl;
    cout << "| Spesialisasi  : " << data.spesialisasi << endl;
    cout << "| Jumlah Antrian: " << jumlahAntrian << endl;
    cout << "|================================|\n";
}

// ==================== BST OPERATIONS ====================

// Fungsi: Membuat BST kosong
void create_BST(BST &T) { 
    T.root = Nil; 
}

// Fungsi: Mengalokasikan memory untuk node service baru
adrService alokasi_Service(infoService data) {  // NAMA DIPERBAIKI: alokasi_Service
    adrService P = new NodeService;
    P->info = data;
    P->left = Nil;
    P->right = Nil;
    return P;
}

// Fungsi: Menyisipkan service ke dalam BST (terurut berdasarkan ID)
void insert_BST(BST &T, adrService P) {
    // Kasus 1: BST masih kosong
    if (T.root == Nil) {
        T.root = P;
        return;
    }   
    
    // Cari posisi yang tepat untuk insert
    adrService current = T.root;
    adrService parent = Nil;
    
    while (current != Nil) {
        parent = current;       
        // Jika ID lebih kecil, ke kiri
        if (P->info.idService < current->info.idService) {
            current = current->left;
        }
        // Jika ID lebih besar, ke kanan
        else if (P->info.idService > current->info.idService) {
            current = current->right;
        }
        // Jika ID sudah ada (duplikat)
        else {
            cout << "| ERROR: Service dengan ID tersebut sudah ada!\n";
            delete P;
            return;
        }
    }  
    
    // Sisipkan di posisi yang tepat
    if (P->info.idService < parent->info.idService) {
        parent->left = P;
    } else {
        parent->right = P;
    }
}

// Fungsi: Mencari service berdasarkan ID (rekursif)
adrService find_Service(adrService root, int idService) {
    // Basis: tree kosong atau ketemu
    if (root == Nil) return Nil;
    if (root->info.idService == idService)
        return root;
    
    // Rekursif: cari di subtree kiri atau kanan
    if (idService < root->info.idService)
        return find_Service(root->left, idService);
    else
        return find_Service(root->right, idService);
}

// Fungsi: Mencari node dengan nilai terkecil di subtree (UNTUK DELETE)
adrService find_MinNode(adrService root) {
    while (root != Nil && root->left != Nil)
        root = root->left;
    return root;
}

// Fungsi: Menghapus service dari BST
void delete_Service(BST &T, int idService) {
    adrService parent = Nil;
    adrService current = T.root;
    
    // Cari node yang akan dihapus
    while (current != Nil && current->info.idService != idService) {
        parent = current;
        if (idService < current->info.idService)
            current = current->left;
        else
            current = current->right;
    }
    
    // Jika service tidak ditemukan
    if (current == Nil) {
        cout << "Service tidak ditemukan!\n";
        return;
    }
    
    // KASUS 1: Node tidak punya anak (leaf node)
    if (current->left == Nil && current->right == Nil) {
        if (parent == Nil) {
            T.root = Nil;  // Hapus root
        } else if (parent->left == current) {
            parent->left = Nil;
        } else {
            parent->right = Nil;
        }
        delete current;
    }
    // KASUS 2: Node punya 1 anak
    else if (current->left == Nil || current->right == Nil) {
        adrService child = (current->left != Nil) ? current->left : current->right;
        
        if (parent == Nil) {
            T.root = child;  // Ganti root dengan child
        } else if (parent->left == current) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        delete current;
    }
    // KASUS 3: Node punya 2 anak
    else {
        adrService successor = find_MinNode(current->right); // Cari successor (node terkecil di subtree kanan)
        infoService tempInfo = successor->info;
        delete_Service(T, successor->info.idService);        // Hapus successor
        current->info = tempInfo;                            // Ganti data node dengan successor
    }
    cout << "Service berhasil dihapus!\n";
}

// Fungsi: Menampilkan BST secara InOrder (kiri-root-kanan)
void show_InOrder(adrService root) {
    if (root != Nil) {
        show_InOrder(root->left);
        tampilkan_Service(root->info);
        show_InOrder(root->right);
    }
}

// Fungsi: Menampilkan BST secara PreOrder (root-kiri-kanan)
void show_PreOrder(adrService root) {
    if (root != Nil) {
        tampilkan_Service(root->info);
        show_PreOrder(root->left);
        show_PreOrder(root->right);
    }
}

// Fungsi: Menampilkan BST secara PostOrder (kiri-kanan-root)
void show_PostOrder(adrService root) {
    if (root != Nil) {
        show_PostOrder(root->left);
        show_PostOrder(root->right);
        tampilkan_Service(root->info);
    }
}

// Fungsi: Menampilkan service berdasarkan jenis device
void show_Jenis(adrService root, string jenis) {
    if (root != Nil) {
        show_Jenis(root->left, jenis);
        if (to_Lowercase(root->info.jenisDevice) == to_Lowercase(jenis))
            tampilkan_Service(root->info);
        show_Jenis(root->right, jenis);
    }
}

// Fungsi: Menghitung total service di BST
int count_TotalService(adrService root) {
    if (root == Nil) return 0;
    return 1 + count_TotalService(root->left) + count_TotalService(root->right);
}

// Fungsi: Mencari service dengan komponen rusak terbanyak
adrService find_MaxKomponen(adrService root) {
    if (root == Nil) return Nil;
    
    adrService maxNode = root;
    adrService leftMax = find_MaxKomponen(root->left);
    adrService rightMax = find_MaxKomponen(root->right);
    
    if (leftMax != Nil && leftMax->info.jumlahKomponen > maxNode->info.jumlahKomponen)
        maxNode = leftMax;
    if (rightMax != Nil && rightMax->info.jumlahKomponen > maxNode->info.jumlahKomponen)
        maxNode = rightMax; 
    
    return maxNode;
}

// Fungsi: Mencari service dengan estimasi tercepat
adrService find_MinEstimasi(adrService root) {
    if (root == Nil) return Nil;
    
    adrService minNode = root;
    adrService leftMin = find_MinEstimasi(root->left);
    adrService rightMin = find_MinEstimasi(root->right);
    
    if (leftMin != Nil && leftMin->info.estimasiHari < minNode->info.estimasiHari)
        minNode = leftMin;
    if (rightMin != Nil && rightMin->info.estimasiHari < minNode->info.estimasiHari)
        minNode = rightMin; 
    
    return minNode;
}

// ==================== MULTI LINKED LIST OPERATIONS ====================

// Fungsi: Membuat list teknisi kosong
void create_ListTeknisi(ListTeknisi &L) { 
    L.first = Nil; 
}

// Fungsi: Mengalokasikan memory untuk node teknisi baru
adrTeknisi alokasi_Teknisi(infoTeknisi data) {
    adrTeknisi P = new ElmTeknisi;
    P->info = data;
    P->firstAntrian = Nil;
    P->next = Nil;
    return P;
}

// Fungsi: Mengalokasikan memory untuk node antrian baru
adrAntrian alokasi_Atrian(int idService) {
    adrAntrian P = new ElmAntrian;
    P->idService = idService;
    P->next = Nil;
    return P;
}

// Fungsi: Menambahkan teknisi ke dalam list (insert last)
void insert_Teknisi(ListTeknisi &L, adrTeknisi P) {
    if (L.first == Nil) {
        L.first = P;
    } else {
        adrTeknisi Q = L.first;
        while (Q->next != Nil) Q = Q->next;
        Q->next = P;
    }
}

// Fungsi: Mencari teknisi berdasarkan ID
adrTeknisi find_Teknisi(ListTeknisi L, int idTeknisi) {
    adrTeknisi P = L.first;
    while (P != Nil) {
        if (P->info.idTeknisi == idTeknisi) 
            return P;
        P = P->next;
    }
    return Nil;
}

// Fungsi: Menghapus teknisi dari list
void delete_Teknisi(ListTeknisi &L, int idTeknisi) {
    adrTeknisi P = L.first;
    adrTeknisi prec = Nil;
    
    // Cari teknisi yang akan dihapus
    while (P != Nil && P->info.idTeknisi != idTeknisi) {
        prec = P;
        P = P->next;
    }
    
    // Jika teknisi tidak ditemukan
    if (P == Nil) {
        cout << "Teknisi tidak ditemukan!\n";
        return;
    }
    
    // Hapus semua antrian (child nodes) terlebih dahulu
    while (P->firstAntrian != Nil) {
        adrAntrian temp = P->firstAntrian;
        P->firstAntrian = temp->next;
        delete temp;
    }
    
    // Hapus teknisi dari list
    if (prec == Nil) {
        L.first = P->next;  // Hapus di awal list
    } else {
        prec->next = P->next;
    }
    
    delete P;
    cout << "Teknisi berhasil dihapus!\n";
}

// Fungsi: Menambahkan antrian ke teknisi (insert last di queue)
void insert_Atrian(adrTeknisi T, adrAntrian P) {
    if (T->firstAntrian == Nil) {
        T->firstAntrian = P;  // Antrian pertama
    } else {
        // Cari posisi terakhir
        adrAntrian Q = T->firstAntrian;
        while (Q->next != Nil) Q = Q->next;
        Q->next = P;  // Tambah di akhir
    }
}

// Fungsi: Melayani antrian pertama (FIFO - First In First Out)
void delete_FirstAntrian(adrTeknisi T) {
    // Cek apakah ada antrian
    if (T->firstAntrian == Nil) {
        cout << "ERROR: Tidak ada antrian untuk teknisi ini!\n";
        return;
    }
    
    // Ambil antrian pertama
    adrAntrian P = T->firstAntrian;
    T->firstAntrian = P->next;  // Geser ke antrian berikutnya
    cout << "Service ID " << P->idService << " telah dilayani.\n";
    delete P;
}

// Fungsi: Menampilkan semua teknisi beserta antriannya
void show_AllTeknisi(ListTeknisi L) {
    if (L.first == Nil) {
        cout << "Belum ada teknisi terdaftar!\n";
        return;
    }
    
    adrTeknisi P = L.first;
    int no = 1;
    cout << "\n|===================== DAFTAR TEKNISI =====================|\n";
    cout << "|                                                          |\n";
    while (P != Nil) {
        cout << "| " << no << ". ID: " << P->info.idTeknisi 
             << " | Nama: " << P->info.namaTeknisi 
             << " | Spesialis: " << P->info.spesialisasi 
             << " | Antrian: " << count_AntrianTeknisi(P) << endl;
        P = P->next;
        no++;
    }
    cout << "|==========================================================|\n";
}

// Fungsi: Menampilkan antrian dari seorang teknisi
void show_AntrianTeknisi(adrTeknisi T) {
    if (T->firstAntrian == Nil) {
        cout << "|                                |\n";
        cout << "|       Tidak ada antrian.       |\n";
        return;
    }
    
    adrAntrian P = T->firstAntrian;
    int no = 1;
    cout << "\n| Antrian Service: \n";
    while (P != Nil) {
        cout << "| " << no << ". ID Service: " << P->idService << endl;
        P = P->next;
        no++;
    }
}

// Fungsi: Menghitung jumlah antrian per teknisi
int count_AntrianTeknisi(adrTeknisi T) {
    int count = 0;
    adrAntrian P = T->firstAntrian;
    while (P != Nil) { 
        count++; 
        P = P->next; 
    }
    return count;
}

// Fungsi: Menghitung total semua antrian
int count_TotalAntrian(ListTeknisi L) {
    int total = 0;
    adrTeknisi P = L.first;
    while (P != Nil) { 
        total += count_AntrianTeknisi(P); 
        P = P->next; 
    }
    return total;
}

// Fungsi: Mencari teknisi dengan antrian paling sedikit
adrTeknisi find_TeknisiPalingSedikit(ListTeknisi L) {
    if (L.first == Nil) return Nil;
    
    adrTeknisi minTeknisi = L.first;
    int minAntrian = count_AntrianTeknisi(minTeknisi);
    adrTeknisi P = L.first->next;
    
    while (P != Nil) {
        int jumlah = count_AntrianTeknisi(P);
        if (jumlah < minAntrian) {
            minAntrian = jumlah;
            minTeknisi = P;
        }
        P = P->next;
    }
    return minTeknisi;
}

// Fungsi: Mengecek apakah service sudah diassign ke teknisi manapun
bool serviceAlready_Assigned(ListTeknisi L, int idService) {
    adrTeknisi P = L.first;
    
    // Cek di semua teknisi
    while (P != Nil) {
        adrAntrian A = P->firstAntrian;
        // Cek di semua antrian teknisi ini
        while (A != Nil) {
            if (A->idService == idService) {
                return true;  // Service sudah diassign
            }
            A = A->next;
        }
        P = P->next;
    }
    return false;  // Service belum diassign
}

// ==================== UTILITY FUNCTIONS ====================

// Fungsi: Membersihkan layar terminal
void clear_Screen() {
    #ifdef _WIN32
    system("cls");      // Untuk Windows
    #else
    system("clear");    // Untuk Linux/Mac
    #endif
}

// Fungsi: Menjeda program, menunggu input enter
void pause() {
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.get();
}