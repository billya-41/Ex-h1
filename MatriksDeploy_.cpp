#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main () {
    int M = 4;
    int N = 3;
    int A [100][100] = {{34, 87, 15},
                        {66, 71, 52},
                        {47, 47, 48},
                        {45, 75, 35}};

    
    cout << M << " " << N << endl;
    for (int i = 0; i < M; i++) {
        cout << "Elemen baris ke-" << i + 1 << ": ";
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    } 

    //90 derajat
    cout << "\n" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Elemen baris ke-" << i + 1 << ": ";
        for (int j = M - 1; j >= 0; j--) {
            cout << A[j][i] << " ";
        }
        cout << endl;
    }
}
