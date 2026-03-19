#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main () {
    int M, N;
    cout << "Masukkan jumlah baris dan kolom: ";
    cin >> M >> N;  

    int A[100][100];

    cout << M << " " << N << endl;
    for (int i = 0; i < M; i++){
        cout << "Masukkan elemen baris ke-" << i + 1 << ": ";
        for (int j = 0; j < N; j++){
            cin >> A[i][j]; 
        }    
    }

    //90 derajat
    cout << "\n" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Elemen baris ke-" << i + 1 << ": ";
        for (int j = M - 1; j >= 0; j--) {
            cout << A[j][i];
            if (j > 0) cout << " ";
        }
        cout << "\n";
        cout << endl;
    }
}
