#include <Stdio.h>
#include <math.h>

float perhitungan(int x, int y){
    float hasil = 0;
    hasil = (pow(x, 2) - pow(y, 2)) / (pow(x, 2) + pow(y, 2));
    return hasil;
}

int main (){
    int x;
    int y;
    float hasil;

    printf("Masukkan x: ");
    scanf("%d", &x);
    printf("Masukkan y: ");
    scanf("%d", &y);
    hasil = perhitungan(x,y);
    printf("Hasil perhitungan: %f", hasil);
}