#include <iostream>
using namespace std;



//Fungsi iteratif untuk mencari nilai maksimum dalam array
int maxA (int n, int arr[]) {
    int max = arr[0];//set nilai max sebagai elemen pertama dalam array
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];//ubah elemen max jika array mempunyai nilai lebih besar dari max
        }
    }
    return max;//kembalikan nilai max
}

//fungsi rekursif untuk mencari nilai maksimum dalam array
int maxAR (int n, int arr[]) {
    if (n == 1) {
        return arr[0];//jika n sama dengan 1, kembalikan elemen pertama dalam array
    }
    int max = maxAR(n - 1, arr);//set nilai max dengan memanggil fungsi maxAR dengan parameter n-1
    if (arr[n - 1] > max) {
        return arr[n - 1];//kembalikan elemen terakhir dalam array jika lebih besar dari max
    } else {
        return max;//kembalikan nilai max jika elemen terakhir dalam array tidak lebih besar dari max
    }
}

void cetak_n (int n, int arr[]) {
    cout << "Jumlah elemen dalam array adalah: " << n << endl;
    //mencetak jumlah elemen array berdasarkan parameter n yang diberikan saat pemanggilan fungsi
}

//Fungsi iteratif untuk menghitung rata-rata dari elemen array
float rata (int n, int arr[]) {
    float sum = 0.0f;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

//Fungsi rekursif untuk menghitung rata-rata dari elemen array
float rataR (int n, int arr[]) {
    if (n == 0) {
        return 0.0f;//jika n sama dengan 0, kembalikan 0
    }
    return (arr[n - 1] + rataR(n - 1, arr) * (n - 1)) / n;//kembalikan hasil penjumlahan elemen terakhir dalam array dengan hasil pemanggilan fungsi rataR dengan parameter n-1 dikalikan dengan n-1, lalu dibagi dengan n
}

int main () {
    int n;
    cout << "Masukkan kapasitas array :" << endl;//masukkan kapasitas array
    cin >> n;
    int arr[n];//set ukuran array sesuai dengan input kapasitas array
    cout << "Masukkan elemen array: " << endl;//masukkab elemen array sesuai kapasitas array
    for (int i  = 0; i < n; i++){
        cin >> arr[i];
    }
    int max = maxA(n, arr);//set nilai max dengan memanggil fungsi maxA
    int maxR = maxAR(n, arr);//set nilai maxR dengan memanggil fungsi maxAR
    cout << "Nilai maksimum dalam array yang diinput adalah: " << max << endl;
    cout << "Nilai maksimum dalam array yang diinput (rekursif) adalah: " << maxR << endl;
    cetak_n(n, arr);//fungsi untuk mencetak jumlah elemen array
    float rata1 = rata(n, arr);
    float rataR1 = rataR(n, arr);
    cout << "Rata-rata dari elemen array yang diinput adalah: " << rata1 << endl;
    cout << "Rata-rata dari elemen array yang diinput (rekursif) adalah: " << rataR1 << endl;
}