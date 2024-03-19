#include <stdio.h>

int min(int a, int b) { //berfungsi untuk mencari minimal dua bilangan bulat
    return a < b ? a : b;
}

void swap(int *a, int *b) { //berfungsi untuk menukar dua elemen di dalam sebuah array
    int temp = *a;
    *a = *b;
    *b = temp;
}

int min_swaps_to_sort(int n, int cards[]) { //berfungsi untuk mencari swap minimum untuk mengurutkan kartu
    int swaps = 0; //digunakan untuk menghitung jumlah pertukaran yang dilakukan
    for (int i = 0; i < n; i++) { //untuk iterasi melalui semua kartu dalam array
        int min_index = i;
        for (int j = i+1; j < n; j++) {
            if (cards[j] < cards[min_index]) { //berfungsi untuk setiap kartu dibandingkan dengan kartu terkecil yang telah ditemukan sebelumnya. Jika kartu yang sedang dipertimbangkan lebih kecil dari kartu terkecil yang ditemukan sebelumnya, maka min_index diubah menjadi indeks kartu yang lebih kecil tersebut
                min_index = j;
            }
        }
        if (i != min_index) {
            swap(&cards[i], &cards[min_index]); //untuk menukar posisi sekarang dengan kartu terkecil yang ditemukan
            swaps++;
        }
    }
    return swaps;
}

int main() {
    int n;
    scanf("%d", &n); //untuk menginput jumlah kartu
    int cards[n];
    for (int i = 0; i < n; i++) {
        char card[3];
        scanf("%s", card); //untuk menginput nilai kartu
        if (card[0] >= '1' && card[0] <= '9') {
            cards[i] = card[0] - '0';
        } else {
            switch(card[0]) { //mengonversi J, Q, K menjadi nilai numerik
                case 'J':
                    cards[i] = 11;
                    break;
                case 'Q':
                    cards[i] = 12;
                    break;
                case 'K':
                    cards[i] = 13;
                    break;
            }
        }
    }
    printf("%d\n", min_swaps_to_sort(n, cards)); //output jumlah minimal langkah pertukaran
    return 0;
}
