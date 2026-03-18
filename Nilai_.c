#include <stdio.h>

// deklarasi fungsi
void nilai_akhir1 (char mahasiswa[][10], int TUGAS[], int UTS[], int UAS[], float nilai_akhir[]);
void grade (char mahasiswa[][10], float nilai_akhir[]);
int NTE_NTA (float nilai_akhir[]);

int main () {
    // deklarasi array untuk 10 mahasiswa
    char mahasiswa [10][10] = {0};   // nama mahasiswa (maks 9 karakter + null)
    int TUGAS [10] = {0};            // nilai tugas
    int UTS [10] = {0};              // nilai UTS
    int UAS [10] = {0};              // nilai UAS
    float nilai_akhir [10] = {0};    // nilai akhir

    // panggil fungsi
    nilai_akhir1 (mahasiswa, TUGAS, UTS, UAS, nilai_akhir);
    grade(mahasiswa, nilai_akhir);
    NTE_NTA(nilai_akhir);

    return 0;
}

// fungsi untuk input dan hitung nilai akhir
void nilai_akhir1(char mahasiswa[][10], int TUGAS[], int UTS[], int UAS[], float nilai_akhir[]){
    float sum = 0.0; // untuk menghitung rata-rata kelas

    printf("-------------------------------INPUT NILAI MAHASISWA------------------------------\n");

    // loop untuk 10 mahasiswa
    for (int i = 0; i < 10; i++){

        // input nama mahasiswa
        printf("Nama Mahasiswa ke-%d: ", i+1);
        scanf(" %9[^\n]", mahasiswa[i]);// baca string dengan spasi, maksimal 9 karakter

        // input nilai tugas dengan validasi
        do {
            printf("Nilai TUGAS: ");
            scanf ("%d", &TUGAS[i]);
            if (TUGAS[i] < 0 || TUGAS[i] > 100) {
                printf("Input salah. Nilai TUGAS ga valid untuk mahasiswa ke-%d.\n", i+1);  // jika nilai TUGAS kurang dari 0 atau lebih dari 100, tampilkan pesan error
            }
        } while (TUGAS[i] < 0 || TUGAS[i] > 100); // ulangi input sampai valid tidak boleh kurang dari 0 atau lebih dari 1

        // input nilai UTS dengan validasi
        do {
            printf("Nilai UTS: ");
            scanf ("%d", &UTS[i]);
            if (UTS[i] < 0 || UTS[i] > 100) {
                printf("Input salah. Nilai UTS ga valid untuk mahasiswa ke-%d.\n", i+1); // jika nilai UTS kurang dari 0 atau lebih dari 100, tampilkan pesan error
            }
        } while (UTS[i] < 0 || UTS[i] > 100); // ulangi input sampai valid tidak boleh kurang dari 0 atau lebih dari 1

        // input nilai UAS dengan validasi
        do {
            printf("Nilai UAS: ");
            scanf ("%d", &UAS[i]);
            if (UAS[i] < 0 || UAS[i] > 100) {
                printf("Input salah. Nilai UAS ga valid untuk mahasiswa ke-%d.\n", i+1); // jika nilai UAS kurang dari 0 atau lebih dari 100, tampilkan pesan error
            }
        } while (UAS[i] < 0 || UAS[i] > 100); // ulangi input sampai valid tidak boleh kurang dari 0 atau lebih dari 1

        // hitung nilai akhir (30% tugas, 30% UTS, 40% UAS)
        nilai_akhir[i] = (TUGAS[i] * 0.3) + (UTS[i] * 0.3) + (UAS[i] * 0.4);

        printf("\nNilai akhir %s : %.2f\n", mahasiswa[i], nilai_akhir[i]);

        // jika nilai < 60, wajib remedial
        if (nilai_akhir[i] < 60) {
            printf("Nilai akhir %s kurang dari 60 dan harus remedial\n", mahasiswa[i]);

            int nilai_remedial = 0;
            printf("Nilai remedial %s : ", mahasiswa[i]);
            scanf("%d", &nilai_remedial);

            // jika nilai remedial lebih tinggi, gantikan
            if (nilai_remedial >= nilai_akhir[i]) {
                nilai_akhir[i] = nilai_remedial;
            }

            printf("\nNilai akhir setelah remedial %s : %.2f\n", mahasiswa[i], nilai_akhir[i]);
        }

        // akumulasi untuk rata-rata
        sum += nilai_akhir[i];

        printf("\n");
    }

    // hitung rata-rata kelas
    float nilai_kelas = sum / 10.0;
    printf("\nRata-rata nilai akhir kelas: %.2f\n", nilai_kelas);
}

// fungsi untuk menentukan grade
void grade (char mahasiswa[][10], float nilai_akhir[]){
    int A = 0, B = 0, C = 0, D = 0;

    for (int i = 0; i < 10; i++){
        //jika nilai akhir >= 80, grade A; >= 70, grade B; >= 60, grade C; < 60, grade D
        if (nilai_akhir[i] >= 80) {
            printf("Grade %s : A\n", mahasiswa[i]);
            A++;
        } 
        else if (nilai_akhir[i] >= 70) {
            printf("Grade %s : B\n", mahasiswa[i]);
            B++;
        } 
        else if (nilai_akhir[i] >= 60) {
            printf("Grade %s : C\n", mahasiswa[i]);
            C++;
        }
        else {
            printf("Grade %s : D\n", mahasiswa[i]);
            D++;
        }
    }

    // tampilkan jumlah tiap grade
    printf("\nJumlah Mahasiswa dengan Grade A: %d\n", A);
    printf("Jumlah Mahasiswa dengan Grade B: %d\n", B);
    printf("Jumlah Mahasiswa dengan Grade C: %d\n", C);
    printf("Jumlah Mahasiswa dengan Grade D: %d\n", D);
}

// fungsi mencari nilai tertinggi dan terendah
int NTE_NTA (float nilai_akhir[]){
    float NTE = nilai_akhir[0]; // nilai tertinggi
    float NTA = nilai_akhir[0]; // nilai terendah

    for (int i = 0; i < 10; i++){
        if (nilai_akhir[i] > NTE) {
            NTE = nilai_akhir[i];// jika array nilai akhir tertinggi lebih besar dari NTE, maka NTE diupdate dengan nilai tersebut
        }
        if (nilai_akhir[i] < NTA) {
            NTA = nilai_akhir[i]; // jika array nilai akhir terendah lebih kecil dari NTA, maka NTA diupdate dengan nilai tersebut
        }
    }

    printf("\nNilai tertinggi kelas : %.2f\n", NTE);
    printf("Nilai terendah kelas : %.2f\n", NTA);
}