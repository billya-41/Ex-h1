#include <stdio.h>
#include <stdbool.h>

int bparkir(int jenis [], int lama [], int jumkendaraan, int biaya []);
int tparkir (int biaya [], int jumkendaraan); 
void sparkir (char nama [], int jenis[], int lama[], int jumkendaraan, int biaya[], int total); 

int i;

int main () {
    char nama [100]; 
    int jumkendaraan = 0;
    int jenis [3] = {0};
    int lama [3] = {0}; 
    int biaya [3] = {0};
;    printf("Masukkan nama anda :");    
    scanf(" %[^\n]", nama);
    do {
    printf("Masukkan jumlah kendaraan :");
    scanf("%d", &jumkendaraan);
    if(jumkendaraan < 1 || jumkendaraan > 3) {
            printf("Jumlah kendaraan tidak valid. Silakan coba lagi.\n");
        }
    else break;
    } while(true);
    for(i = 0; i < jumkendaraan; i++){
    while(true){
     printf ("Masukkan jenis kendaraan ke-%d\n 1. Mobil\n 2. Motor\n 3. Truk\n", i+1);
     scanf("%d", &jenis[i]);
      if (jenis[i] < 1 || jenis[i] > 3) {printf("Kendaraan diluar opsi silahkan coba lagi\n"); continue;}
      else break;
    }
     printf("Masukkan lama parkir (jam) :");
     scanf("%d", &lama[i]);
    }
    int total_sementara = bparkir(jenis, lama, jumkendaraan, biaya);
    int total = tparkir(biaya, jumkendaraan);
    sparkir(nama, jenis, lama, jumkendaraan, biaya, total);  
}
    


int bparkir (int jenis[], int lama[], int jumkendaraan, int biaya[]) {
    for(i = 0; i < jumkendaraan; i++){
    int diskon;
    if (jenis[i] == 1) {biaya [i] = 5000 * lama[i];}
    else if (jenis[i] == 2) {biaya [i] = (0.50 * 5000) * lama[i];}
    else {biaya [i] = (2 * 5000) * lama[i];}
    if (lama[i] > 5) {diskon = 0.1 * biaya [i] ;}
    else {diskon = 0;}
    biaya[i] = biaya[i] - diskon;
    }
    return biaya[i];
}

int tparkir (int biaya[], int jumkendaraan) {
    int total = 0;
    for (int i = 0; i < jumkendaraan; i++) {
        total += biaya[i];
    }
    return total;
}

void sparkir (char nama [], int jenis[], int lama[], int jumkendaraan, int biaya[], int total) {
        printf("------------------------------STRUK PARKIR------------------------------\n");
    printf("Nama : %s\n", nama);
    for(i = 0; i < jumkendaraan; i++){
        switch (jenis[i])
        {
        case 1:
            printf("Jenis kendaraan : mobil kendaraan jenis ke-%d\n", jenis[i]);
            printf("Lama parkir : %d jam\n", lama[i]);
            printf("Biaya parkir : %d\n", biaya[i]);
            break;
        case 2:
            printf("Jenis kendaraan : motor kendaraan jenis  ke-%d\n", jenis[i]);
            printf("Lama parkir : %d jam\n", lama[i]);
            printf("Biaya parkir : %d\n", biaya[i]);
            break;
        case 3:
            printf("Jenis kendaraan :  truk kendaraan jenis ke-%d\n", jenis[i]);
            printf("Lama parkir : %d jam\n", lama[i]);
            printf("Biaya parkir : %d\n", biaya[i]);
            break;
        default:
            printf("Jenis kendaraan tidak diketahui\n");
            break;
        }
}
    printf("------------------------------------------------------------------------\n");
    printf("Total biaya parkir : %d\n", total);
    printf("------------------------------STRUK PARKIR------------------------------");

    FILE *file = fopen("struk_parkir.txt", "a");
    if (file == NULL) {
        printf("struk_parkir.txt", "w");
        return;
    }
    
    fprintf(file, "------------------------------STRUK PARKIR------------------------------\n");
    fprintf(file, "Nama : %s\n", nama);
    for(i = 0; i < jumkendaraan; i++){
        switch (jenis[i])
        {
        case 1:
            fprintf(file, "Jenis kendaraan : mobil kendaraan jenis ke-%d\n", jenis[i]);
            fprintf(file, "Lama parkir : %d jam\n", lama[i]);
            fprintf(file, "Biaya parkir : %d\n", biaya[i]);
            break;
        case 2:
            fprintf(file, "Jenis kendaraan : motor kendaraan jenis ke-%d\n", jenis[i]);
            fprintf(file, "Lama parkir : %d jam\n", lama[i]);
            fprintf(file, "Biaya parkir : %d\n", biaya[i]);
            break;
        case 3:
            fprintf(file, "Jenis kendaraan :  truk kendaraan jenis ke-%d\n", jenis[i]);
            fprintf(file, "Lama parkir : %d jam\n", lama[i]);
            fprintf(file, "Biaya parkir : %d\n", biaya[i]);
            break;
        default:
            fprintf(file, "Jenis kendaraan tidak diketahui\n");
            break;
        }
}
    fprintf(file, "------------------------------------------------------------------------\n");
    fprintf(file, "Total biaya parkir : %d\n", total);
    fprintf(file, "------------------------------STRUK PARKIR------------------------------\n");
    fclose(file);
}