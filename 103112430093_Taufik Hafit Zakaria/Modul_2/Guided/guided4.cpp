//Taufik Hafit Zakaria
//103112430093_12 - IF 03

#include <iostream>
using namespace std;
/*prototype fungsi */
void tulis(int x);
int main()
{
    int jum;
    cout << "jumlah baris kata = ";
    cin >> jum;
    tulis(jum);
    return 0;
}
/*badan prosedur*/
    void tulis(int x){
    for (int i=0;i<x;i++)
    cout<<"baris ke-"<<i+1<<endl;
}