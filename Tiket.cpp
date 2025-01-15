#include <iostream>
using namespace std;

// Fungsi utama untuk pembelian tiket bioskop
void pembelian_tiket_bioskop() {
    int pilihan;
    int totalKursi = 50; // Jumlah kursi total di bioskop

    do {
        // Tampilan menu utama
        cout << "\t   Bioskop XXI Bandung" << endl;
        cout << "\t JL.Bhayangkara Bandung" << endl;
        cout << " =============================================" << endl;
        cout << "\t      DAFTAR MENU " << endl;
        cout << "\t---------------------------------" << endl;
        cout << "\t| 1. Pembelian Tiket            |" << endl;
        cout << "\t| 2. Cek Sisa Kursi             |" << endl;
        cout << "\t| 3. Keluar                     |" << endl;
        cout << "\t---------------------------------" << endl;
        cout << " =============================================" << endl;
        cout << endl;

        cout << " Masukan Pilihan Anda (1-3) : ";
        cin >> pilihan;
        cout << endl;

        system("cls");

        switch (pilihan) {
        case 1: {
            // Pembelian tiket
            int jenisTKT, jumlahTKT, totalTKT;
            string jenisTXT;

            cout << " =============================================" << endl;
            cout << "\t   Pembelian Tiket " << endl;
            cout << " =============================================" << endl;
            cout << " Keterangan" << endl;
            cout << " 1. Tiket Dewasa  : Rp. 35.000" << endl;
            cout << " 2. Tiket Anak-anak  : Rp. 20.000" << endl;
            cout << " =============================================" << endl;

            cout << " Jenis Tiket (1-2)  : ";
            cin >> jenisTKT;
            cout << " Jumlah Tiket   : ";
            cin >> jumlahTKT;

            if (jumlahTKT > totalKursi) {
                cout << " Jumlah tiket yang diminta melebihi sisa kursi!" << endl;
                break;
            }

            if (jenisTKT == 1) {
                totalTKT = jumlahTKT * 35000;
                jenisTXT = "Dewasa";
            } else if (jenisTKT == 2) {
                totalTKT = jumlahTKT * 20000;
                jenisTXT = "Anak-anak";
            } else {
                cout << " Jenis tiket tidak valid!" << endl;
                break;
            }

            // Mengurangi jumlah kursi
            totalKursi -= jumlahTKT;

            cout << " =============================================" << endl;
            cout << " Jenis Tiket   : " << jenisTXT << endl;
            cout << " Jumlah Tiket  : " << jumlahTKT << endl;
            cout << " ---------------------------------------------" << endl;
            cout << " Total Bayar   : Rp. " << totalTKT << endl;
            cout << " ==============================================" << endl;
            cout << endl;

            break;
        }
        case 2:
            // Cek sisa kursi
            cout << " ==============================================" << endl;
            cout << "\t   Cek Sisa Kursi " << endl;
            cout << " ==============================================" << endl;
            cout << " Sisa Kursi di Bioskop: " << totalKursi << endl;
            cout << " ==============================================" << endl;
            cout << endl;
            break;

        case 3:
            cout << " Terima kasih telah menggunakan layanan kami!" << endl;
            break;

        default:
            cout << " Pilihan tidak valid. Silakan coba lagi." << endl;
        }

    } while (pilihan != 3);
}

int main() {
    pembelian_tiket_bioskop();
    return 0;
}
