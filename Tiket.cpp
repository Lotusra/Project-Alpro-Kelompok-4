#include <stdio.h>

#define MAX_PENERBANGAN 3
#define MAX_JADWAL 3

int main() {
    // Array untuk menyimpan nama maskapai
    char *maskapai[MAX_PENERBANGAN] = {"Batik Air", "Garuda", "Lion Air"};
    // Array untuk menyimpan tujuan
    char *tujuan[MAX_PENERBANGAN] = {"Jakarta", "Bali", "Surabaya"};
    // Array untuk menyimpan harga tiket
    int harga[MAX_PENERBANGAN] = {1000000, 1200000, 900000};
    // Array untuk menyimpan jadwal penerbangan
    char *jadwal[MAX_PENERBANGAN][MAX_JADWAL] = {
        {"08:00", "12:00", "16:00"},
        {"09:00", "13:00", "17:00"},
        {"10:00", "14:00", "18:00"}
    };

    int pilihanPenerbangan, pilihanJadwal, jumlahTiket;
    int ulangi;

    do {
        // Menampilkan daftar penerbangan
        printf("Daftar Penerbangan:\n");
        for (int i = 0; i < MAX_PENERBANGAN; i++) {
            printf("%d. %s ke %s, Harga: %d\n", i + 1, maskapai[i], tujuan[i], harga[i]);
            for (int j = 0; j < MAX_JADWAL; j++) {
                printf("   Jadwal %d: %s\n", j + 1, jadwal[i][j]);
            }
        }

        // Memilih penerbangan
        printf("Pilih penerbangan (1-%d): ", MAX_PENERBANGAN);
        scanf("%d", &pilihanPenerbangan);
        if (pilihanPenerbangan < 1 || pilihanPenerbangan > MAX_PENERBANGAN) {
            printf("Pilihan penerbangan tidak valid.\n");
            continue; // Kembali ke awal loop
        }

        // Memilih jadwal
        printf("Pilih jadwal (1-%d): ", MAX_JADWAL);
        scanf("%d", &pilihanJadwal);
        if (pilihanJadwal < 1 || pilihanJadwal > MAX_JADWAL) {
            printf("Pilihan jadwal tidak valid.\n");
            continue; // Kembali ke awal loop
        }

        // Memasukkan jumlah tiket
        printf("Masukkan jumlah tiket: ");
        scanf("%d", &jumlahTiket);
        if (jumlahTiket < 1) {
            printf("Jumlah tiket tidak valid.\n");
            continue; // Kembali ke awal loop
        }

        // Menampilkan ringkasan pemesanan
        printf("Anda memesan %d tiket untuk penerbangan %s ke %s pada jadwal %s.\n", jumlahTiket, maskapai[pilihanPenerbangan - 1], tujuan[pilihanPenerbangan - 1], jadwal[pilihanPenerbangan - 1][pilihanJadwal - 1]);
        printf("Total harga: %d\n", jumlahTiket * harga[pilihanPenerbangan - 1]);

        // Menanyakan apakah ingin memesan lagi
        printf("Apakah Anda ingin memesan tiket lagi? (1: Ya, 2: Tidak): ");
        scanf("%d", &ulangi);
    } while (ulangi == 1);

    printf("Terima kasih telah menggunakan layanan kami.\n");

    return 0;
}
