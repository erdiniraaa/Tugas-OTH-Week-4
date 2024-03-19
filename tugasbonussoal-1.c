#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getCardValue(char card) { //berfungsi untuk mendapatkan nilai angka dari kartu
    if (card == 'J') return 11; //jika karakter kartu 'J' maka fungsi mengembalikan nilai 11 karena dalam aturan permainan 'j' mempunyai nilai 11
    else if (card == 'Q') return 12;
    else if (card == 'K') return 13;
    else if (card == '1') return 10;
    else return (int)(card - '0'); //untuk mengembalikan nilai numerik dari karakter
}

void printCards(char *cards, int length) { //berfungsi untuk menampilkan urutan kartu
    for (int a = 0; a < length; a++) { //untuk iterasi melalui setiap elemen dalam array 'cards' dan variabel loop 'a' diinisialisasi dengan nilai 0 dan ditingkatkan seiring dengan setiap iterasi hingga mencapai panjang array 'cards'
        printf("%c ", cards[a]); //untuk mencetak karakter yang ada di indeks ke 'a' dari array 'cards' untuk mencetak nilai kartu di posisi tersebut
    }
    printf("\n");
}

int sortCards(char *cards, int length) { //berfungsi untuk mengurutkan kartu
    int swaps = 0; //untuk menghitung jumlah pertukaran yang dilakukan untuk mengurutkan kartu
    for (int a = 0; a < length - 1; a++) { //loop ini akan berhenti sebelum elemen terakhir karena tidak perlu memeriksa elemen terakhir saat iterasi terakhir
        int min_idx = a; //'a' adalah indeks kartu terkecil yang ditemukan dalam iterasi saat ini
        for (int b = a; b < length; b++) {
            if (getCardValue(cards[b]) < getCardValue(cards[min_idx])) { //mengkonversi kartu ke nilai angka untuk membandingkan
                min_idx = b;
            }
        }
        if (min_idx != a) //berfungsi untuk pengecekan apakah kartu terkecil ditemukan pada indeks yang berbeda pada saat ini, jika sama ada kartu yang lebih kecil dari kartu saat ini, maka pertukaran dilakukan
        {
            char temp = cards[a]; //digunakan untuk menyimpan nilai sementara dari kartu pada posisi saat ini
            cards[a] = cards[min_idx]; //nilai kartu pada posisi 'min_idx' dipindahkan ke posisi saat ini 'a'
            cards[min_idx] = temp; //Nilai kartu yang disimpan dalam 'temp' dipindahkan ke posisi yang sebelumnya diisi oleh nilai kartu 'cards[min_idx]', di kode ini menyelesaikan proses pertukaran
            swaps++; //jumlah pertukaran ditambah satu setiap kali pertukaran dilakukan

            printf("Pertukaran %d : ", swaps); //untuk mengeluarkan output pertukaran
            printCards(cards, length); //setelah pertukaran dilakukan, urutan kartu baru dicetak ke layar menggunakan fungsi 'printCards'
        }
        
    }
    return swaps; //mengembalikan jumlah total pertukaran yang dilakukan
}

int main() {
    int n; //mendeklarasikan untuk menyimpan jumlah kartu yang dimasukkan
    scanf("%d", &n); //untuk menginputkan jumlah kartu dan disimpan dalam variabel 'n'

    char cards[n]; //mendeklarasikan untuk menyimpan nilai-nilai kartu dan ukuran array ini ditentukan oleh jumlah kartu yang dimasukkan

    for (int a = 0; a < n; a++) { //digunakan untuk mengisi array 'cards' dengan nilai-nilai kartu yang dimasukkan
        scanf(" %c", &cards[a]); //setiap kartu yang dimasukkan akan disimpan di dalam array 'cards'
    }

    int swaps = sortCards(cards, n); //berfungsi untuk mengurutkan kartu dalam array

    printf("%d\n", swaps); //mengoutputkan jumlah pertukaran kartu

    free(cards);
    return 0;
}
