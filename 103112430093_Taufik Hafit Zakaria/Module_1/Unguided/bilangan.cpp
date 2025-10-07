#include <iostream>
using namespace std;

int main() { //Taufik Hafit Zakaria || 103112430093 || 12-IF-06
    string satuan[]={"nol","satu","dua","tiga","empat","lima","enam","tujuh","delapan","sembilan"};
    int angka;
    cout<<"masukan angka (0-100): ";
    cin>>angka;
    
    cout<<angka<<" dalam kata adalah: ";
    if (angka==100) cout<<" seratus";
    else if (angka>=10 && angka<20) {
        if (angka==10) cout<<"sepuluh";
        else if (angka==11) cout<<"sebelas";
        else cout<<satuan[angka%10]<<" belas";
    } else if (angka>=20 && angka<100) {
        cout<<satuan[angka/10]<<" puluh";
        if (angka%10!=0) cout<<" "<<satuan[angka%10];
    } else if (angka>=0 && angka<10) {
        cout<<satuan[angka];
    } else {
        cout<<"angka di luar jangkauan";
    }
}