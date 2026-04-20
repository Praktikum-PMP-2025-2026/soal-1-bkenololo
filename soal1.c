/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
*   Modul               : Data Manipulation and External Files
*   Hari dan Tanggal    : Senin, 20 April 2026
*   Nama (NIM)          : Benedictus Kenneth Setiadi (13224003)
*   Nama File           : 13224003_soal1.c
*   Deskripsi           : 
*/

#include <stdio.h>

int find_max(int n1, int n2){
    if(n1 > n2){
        return n1;
    } else {
        return n2;
    }
}

int main(){
    int n;
    
    if (scanf("%d", &n) != 1) return 0;
    // input
    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    for (int i = 0; i < n; i++){
        if(arr[i] == -1){
            float kiri = -1, kanan = -1;
            int adakiri = 0, adakanan = 0;
            // cari di kiri
            for (int j = i-1; j >= 0; j--){
                if(arr[j] != -1){
                    kiri = arr[j];
                    adakiri = 1;
                    break;
                }                
            }
            // cari di kanan
            for (int j = i+1; j < n; j++){
                if(arr[j] != -1){
                    kanan = arr[j];
                    adakanan = 1;
                    break;
                }
            }
            // set angka baru
            if(adakiri && adakanan){
                arr[i] = floor((kanan+kiri)/2);
            } else if (adakanan){
                arr[i] = kanan;
            } else if (adakiri){
                arr[i] = kiri;
            } else {
                arr[i] = 0;
            }
        }
    }
    // print
    printf("RECOVERED");
    for (int i = 0; i < n; i++) {
        printf(" %1.0f", arr[i]);
    }
    printf("\n");

    // cari maxsum

    int current_max = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        current_max = find_max(arr[i], arr[i] + current_max);
        max = current_max;
    }
    printf("MAX_SUM %d", max);
}
