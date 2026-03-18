#include <iostream>
using namespace std;
int rekursif_fak(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * rekursif_fak(n - 1);
}

void cetak_faktorial(int n) {
    cout << "Faktorial dari " << n << " adalah " << rekursif_fak(n) << endl;
}

int main () {
    int n;
    cout << "Masukkan angka:" << endl;
    cin >> n;
    cetak_faktorial(n);
}