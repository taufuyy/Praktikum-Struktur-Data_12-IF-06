    #ifndef SERVICE_H_INCLUDED
    #define SERVICE_H_INCLUDED

    #include <iostream>
    #include <string>
    #include <algorithm>
    using namespace std;

    #define Nil NULL
    const int max_komponen = 100;

    struct infoService {
        int idService;
        string namaCustomer;
        string jenisDevice;
        string keluhan;
        string komponenRusak[max_komponen];
        int jumlahKomponen;
        int estimasiHari;
    };

    struct NodeService {
        infoService info;
        NodeService* left;
        NodeService* right;
    };

    typedef NodeService* adrService;
    struct BST { adrService root; };

    struct ElmAntrian {
        int idService;
        ElmAntrian* next;
    };
    typedef ElmAntrian* adrAntrian;

    struct infoTeknisi {
        int idTeknisi;
        string namaTeknisi;
        string spesialisasi;
    };

    struct ElmTeknisi {
        infoTeknisi info;
        adrAntrian firstAntrian;
        ElmTeknisi* next;
    };
    typedef ElmTeknisi* adrTeknisi;
    struct ListTeknisi { adrTeknisi first; };

    void create_BST(BST &T);                       // buat BST kosong
    adrService alokasi_Service(infoService data);  // alokasi node service baru

    //insert, cari, hapus service
    void insert_BST(BST &T, adrService P);         
    adrService find_Service(adrService root, int idService); 
    void delete_Service(BST &T, int idService);   

    //tampilan service
    void show_InOrder(adrService root);            
    void show_PreOrder(adrService root);          
    void show_PostOrder(adrService root);          
    void show_Jenis(adrService root, string jenis);

    //laporan total, komponen terbanyak, estimasi waktu service
    int count_TotalService(adrService root);       
    adrService find_MaxKomponen(adrService root);  
    adrService find_MinEstimasi(adrService root);  

    void create_Teknisi(ListTeknisi &L);       // buat list teknisi kosong
    adrTeknisi alokasi_Teknisi(infoTeknisi data);  // alokasi node teknisi baru
    adrAntrian alokasi_Atrian(int idService);     // alokasi node antrian baru

    //tambah, cari, hapus teknisi
    void insert_Teknisi(ListTeknisi &L, adrTeknisi P); 
    adrTeknisi find_Teknisi(ListTeknisi L, int idTeknisi); 
    void delete_Teknisi(ListTeknisi &L, int idTeknisi); 

    void insert_Atrian(adrTeknisi T, adrAntrian P);    // tambah antrian ke teknisi
    void delete_FirstAntrian(adrTeknisi T);             // layani antrian (ambil yang pertama)

    //tampilkan antrian teknisi
    void show_AllTeknisi(ListTeknisi L);           
    void show_AntrianTeknisi(adrTeknisi T);   

    //hitung, cari, cek assign
    int count_AntrianTeknisi(adrTeknisi T);        
    int count_TotalAntrian(ListTeknisi L);        
    adrTeknisi find_TeknisiPalingSedikit(ListTeknisi L); 
    bool serviceAlready_Assigned(ListTeknisi L, int idService); 

    //input dan ulang jika tidak sesuai
    bool input_IntegerWithRetry(int &num, string prompt);   
    bool input_StringWithRetry(string &str, string prompt, bool allowEmpty = false); 
    bool input_JenisDeviceWithRetry(string &jenis, string prompt); 

    //validasi input
    bool isValid_Integer(int &num, string prompt);         
    bool isValid_String(string &str, string prompt, bool allowEmpty = false); 

    //tampilan service & teknisi
    void tampilkan_Service(infoService data);             
    void tampilkan_DataTeknisi(infoTeknisi data, int jumlahAntrian); 

    //ubah ke lowercase 
    string to_Lowercase(string str);                          

    void clear_Screen();                                   // bersihkan layar terminal
    void pause();                                         // jeda program, tekan enter untuk lanjut

    #endif