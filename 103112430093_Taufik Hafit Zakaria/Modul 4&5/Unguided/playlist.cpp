//Taufik Hafit Zakaria
//103112430093_12 - IF 06
//playlist.cpp

#include "Playlist.h"

void createPlaylist(Playlist &P) {
    P.head = NULL;
}

Lagu* createNode(string judul, string penyanyi, float durasi) {
    Lagu *newNode = new Lagu;
    newNode->judul = judul;
    newNode->penyanyi = penyanyi;
    newNode->durasi = durasi;
    newNode->next = NULL;
    return newNode;
}

void tambahAwal(Playlist &P, Lagu *newNode) {
    newNode->next = P.head;
    P.head = newNode;
}

void tambahAkhir(Playlist &P, Lagu *newNode) {
    if (P.head == NULL) {
        P.head = newNode;
    } else {
        Lagu *temp = P.head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void tambahSetelahKe3(Playlist &P, Lagu *newNode) {
    if (P.head == NULL) {
        cout << "Playlist masih kosong!" << endl;
        return;
    }

    Lagu *temp = P.head;
    int count = 1;
    while (temp != NULL && count < 3) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Playlist kurang dari 3 lagu!" << endl;
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Lagu berhasil ditambahkan setelah lagu ke-3!" << endl;
    }
}

void hapusBerdasarkanJudul(Playlist &P, string judul) {
    if (P.head == NULL) {
        cout << "Playlist kosong!" << endl;
        return;
    }

    Lagu *temp = P.head;
    Lagu *prev = NULL;

    if (temp != NULL && temp->judul == judul) {
        P.head = temp->next;
        delete temp;
        cout << "Lagu \"" << judul << "\" berhasil dihapus!" << endl;
        return;
    }

    while (temp != NULL && temp->judul != judul) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Lagu dengan judul \"" << judul << "\" tidak ditemukan!" << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Lagu \"" << judul << "\" berhasil dihapus!" << endl;
}

void tampilkanPlaylist(Playlist P) {
    if (P.head == NULL) {
        cout << "\nPlaylist kosong!\n";
        return;
    }

    Lagu *temp = P.head;
    int i = 1;
    cout << "\n=== Daftar Playlist Lagu ===\n";
    while (temp != NULL) {
        cout << i << ". Judul   : " << temp->judul << endl;
        cout << "   Penyanyi: " << temp->penyanyi << endl;
        cout << "   Durasi  : " << temp->durasi << " menit" << endl << endl;
        temp = temp->next;
        i++;
    }
}