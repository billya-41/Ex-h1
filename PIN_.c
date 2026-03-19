#include <stdio.h>

int main(){
    int pin = 0;
    int pilihan = 0;
    int jawab = 0;
    int nyawa = 3;

    while (pilihan != 1){
        printf("Masukkan PIN yang Anda inginkan =");
        scanf("%d", &pin);
        if (pin <= 1000 || pin >= 9999) continue;
        printf("Anda yakin untuk menyimpan? (1 = simpan, 0 = mengulang) =");
        scanf("%d", &pilihan);
    } 

    while(nyawa >= 1 && jawab != pin){
        printf("Masukkan pin yang baru Anda masukkan =");
        scanf("%d", &jawab);
        nyawa--;
        if (nyawa == 0){
            printf("Kartu Anda terblokir!!!");
        }
    }
    return 0;
}