#include <iostream>
using namespace std;

// Fungsi untuk mengisi array baru
void isiArray(int a[], int b[], int jumlah, int jumlah2) {
    for(int i = 0; i < jumlah2; i++) {
        if(i < jumlah) {
            b[i] = a[i];
        } else {
            b[i] = 0;
        }
    }
}

int main() {
    int jumlah;
    cout << "Jumlah array: ";
    cin >> jumlah;

    int a[jumlah];

    cout << "Masukkan elemen array:\n";
    for(int i = 0; i < jumlah; i++) {
        cout << "Angka ke-" << i+1 << ": ";
        cin >> a[i];
    }

    cout << "\nArray A:\n";
    for(int i = 0; i < jumlah; i++) {
        cout << a[i] << ", ";
    }

    int jumlah2 = jumlah * 2;
    int b[jumlah2];

    isiArray(a, b, jumlah, jumlah2);

    cout << "\nArray B:\n";
    for(int i = 0; i < jumlah2; i++) {
        cout << b[i] << ", ";
    }

    cout << endl;
}