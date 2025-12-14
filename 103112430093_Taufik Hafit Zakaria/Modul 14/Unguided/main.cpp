//Taufik Hafit Zakaria
//103112430093
//main.cpp

#include "graph.h"
#include "graph.cpp"

int main() {
    Graph G;
    CreateGraph(G);
    
    // Tambah node sesuai Gambar pada soal
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');
    
    // Hubungkan node sesuai Gambar pada soal
    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');
    adrNode E = FindNode(G, 'E');
    adrNode F = FindNode(G, 'F');
    adrNode GNode = FindNode(G, 'G');
    adrNode H = FindNode(G, 'H');
    
    // Koneksi sesuai gambar
    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, GNode);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(GNode, H);
    
    // Tampilkan struktur graph
    cout << "=== Struktur Graph ===" << endl;
    PrintInfoGraph(G);
    
    // Soal 2: DFS
    cout << "\n=== DFS dari Node A ===" << endl;
    ResetVisited(G);
    PrintDFS(G, A);
    cout << endl;
    
    // Soal 3: BFS
    cout << "\n=== BFS dari Node A ===" << endl;
    ResetVisited(G);
    PrintBFS(G, A);
    cout << endl;
    
    return 0;
}