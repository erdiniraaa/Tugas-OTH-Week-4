#include <stdio.h>
#include <stdlib.h>

void koboImaginaryChess(int i, int j, int size, int *chessBoard) { //berfungsi untuk mensimulasikan gerakan seorang kuda di papan catur
    if (i < 0 || i >= size || j < 0 || j >= size) { //berfungsi untuk mengecek apakah koordinat berada di dalam papan catur
        return;
    }

    int moves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}}; ////untuk menentukan perpindahan yang mungkin dilakukan oleh bidak kuda

    //untuk menandai posisi yang dapat dicapai oleh bidak kuda
    for (int k = 0; k < 8; k++) { //untuk mengiterasi melalui semua kemungkinan perpindahan yang mungkin dilakukan oleh kuda
        int new_i = i + moves[k][0]; //menghitung koordinat baris baru dan untuk posisi yang mungkin dimana kuda bergerak serta untuk perubahan baris yang ditentukan
        int new_j = j + moves[k][1]; //sama dengan baris sebelumnya, namun kode ini menghitung koordinat kolom baru berdasarkan perubahan kolom yang ditentukan
        if (new_i >= 0 && new_i < size && new_j >= 0 && new_j < size) {
            chessBoard[new_i * size + new_j] = 1;
        }
    }

    printf("Papan catur setelah simulasi:\n"); //untuk menampilkan papan catur setelah diberi nilai
    for (int row = 0; row < size; row++) { //untuk mengontrol iterasi melalui baris papan catur
        for (int col = 0; col < size; col++) { //untuk mengontrol iterasi melalui kolom papan catur
            printf("%d ", chessBoard[row * size + col]); //kode ini untuk mencetak nilai dari setiap elemen papan catur
        }
        printf("\n");
    }
}

int main() {
    //inisialisasi papan catur
    int size = 8; //ukuran papan catur yang digunakan 8*8
    int *chessBoard = (int *)malloc(size * size * sizeof(int)); 
    for (int i = 0; i < size * size; i++) {
        chessBoard[i] = 0; // Semua elemen diisi dengan 0
    }

    int i, j;
    printf("Masukkan posisi bidak kuda: \n");
    scanf("%d %d", &i, &j); //berfungsi menginput posisi bidak kuda

    koboImaginaryChess(i, j, size, chessBoard); //untuk memanggil fungsi koboImaginaryChess

    free(chessBoard);  //free memory yang dialokasikan untuk papan catur

    return 0;
}
