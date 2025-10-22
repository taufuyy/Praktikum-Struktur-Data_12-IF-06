//Taufik Hafit Zakaria
//103112430093_12 - IF 06
//playlist.h

#ifndef PLAYLIST_H_INCLUDED
#define PLAYLIST_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct Lagu {
    string judul;
    string penyanyi;
    float durasi;
    Lagu *next;
};

struct Playlist {
    Lagu *head;
};

void createPlaylist(Playlist &P);
Lagu* createNode(string judul, string penyanyi, float durasi);
void tambahAwal(Playlist &P, Lagu *newNode);
void tambahAkhir(Playlist &P, Lagu *newNode);
void tambahSetelahKe3(Playlist &P, Lagu *newNode);
void hapusBerdasarkanJudul(Playlist &P, string judul);
void tampilkanPlaylist(Playlist P);

#endif