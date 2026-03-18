#include <iostream>

using namespace std;
void bagi (int array[], int n, int *bagi1, int *bagi2) {
    int *bagian1, *bagian2;//Fungsi bagi menerima array utama, ukuran n, dan pointer untuk menyimpan ukuran bagian1 & bagian2            
    *bagi1 = n/2; //bagi array jadi setengah
    *bagi2 = n - *bagi1;//n dikurangi bagian1

    bagian1 = new int [*bagi1];//mendeklarasikan array bagian1 dan bagian2
    bagian2 = new int [*bagi2]; 
}

int main () {
    int bagi1, bagi2;
    int n;
    while (true) {
        cout << ("masukkan kapasitas array : ");//masukkan kapasitas array
        cin >> n;
        if (n % 2 != 0) {
            cout << "Kapasitas array harus genap untuk dibagi 2." << endl;//kalau ganjil gabisa terinput
            continue;
        }
        break;
    }
    int array[n]; //membuat array utama dengan kapasitas n
    bagi(array, n, &bagi1, &bagi2);
    for (int i = 0; i < n; i++){
        array[i] = i;
        cout << "\nNilai array ke-" << i+1 << " adalah " << array[i];// aray utama sebelum dibagi
    }
    bagi(array, n, &bagi1, &bagi2);  
    cout << "\n\nkapasitas array setelah dibagi : " << bagi1 << " adalah " << array[bagi1];
     for (int i = 0; i < bagi1; i++){
        array [i] = i;
        cout << "\nNilai array ke-" << i+1 << " adalah " << array[i];//array bagian1
    }
    cout << "\n\nkapasitas array setelah dibagi : " << bagi2 << " adalah " << array[bagi2];
     for (int i = bagi1; i < n; i++){
        array [i] = i;
        cout << "\nNilai array ke-" << i+1 << " adalah " << array[i];//array bagian2
    }
}

