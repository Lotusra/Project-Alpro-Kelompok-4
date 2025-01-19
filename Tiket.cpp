#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Struktur untuk menyimpan informasi penerbangan
struct Flight {
    string flightNumber;
    string destination;
    int availableSeats;
    int price;
    vector<bool> seatMap; // true = booked, false = available
};

// Fungsi untuk menampilkan daftar penerbangan
void displayFlights(const vector<Flight>& flights) {
    cout << "=============================================" << endl;
    cout << "          DAFTAR PENERBANGAN                " << endl;
    cout << "=============================================" << endl;
    for (const auto& flight : flights) {
        cout << "Penerbangan: " << flight.flightNumber << ", Tujuan: " << flight.destination 
             << ", Kursi Tersedia: " << flight.availableSeats << ", Harga: Rp. " << flight.price << endl;
    }
    cout << "=============================================" << endl;
}

// Fungsi untuk menampilkan layout kursi
void displaySeatLayout(const Flight& flight) {
    cout << "Layout Kursi Pesawat untuk " << flight.flightNumber << " (Tujuan: " << flight.destination << "):" << endl;
    for (int i = 0; i < flight.seatMap.size(); i++) {
        if (i % 10 == 0) cout << endl; // New row every 10 seats
        cout << "[" << setw(2) << i << (flight.seatMap[i] ? "X" : " ") << "] ";
    }
    cout << endl;
}

// Fungsi untuk memesan tiket
void bookTickets(Flight& flight) {
    int jumlahTKT;
    cout << "Jumlah tiket yang ingin dipesan: ";
    cin >> jumlahTKT;

    if (jumlahTKT > flight.availableSeats) {
        cout << "Jumlah tiket yang diminta melebihi sisa kursi!" << endl;
        return;
    }

    // Memilih kursi
    for (int i = 0; i < jumlahTKT; i++) {
        int seatNumber;
        cout << "Pilih nomor kursi (0-" << flight.seatMap.size() - 1 << "): ";
        cin >> seatNumber;

        if (seatNumber < 0 || seatNumber >= flight.seatMap.size() || flight.seatMap[seatNumber]) {
            cout << "Kursi tidak valid atau sudah dipesan! Silakan pilih kursi lain." << endl;
            i--; // Decrement to allow re-selection
        } else {
            flight.seatMap[seatNumber] = true; // Mark seat as booked
            flight.availableSeats--;
        }
    }

    // Input identitas pengguna
    string name, email, phone;
    cout << "Masukkan Nama Anda: ";
    cin.ignore();
    getline(cin, name);
    cout << "Masukkan Email Anda: ";
    getline(cin, email);
    cout << "Masukkan Nomor Telepon Anda: ";
    getline(cin, phone);

    cout << "=============================================" << endl;
    cout << "Pemesanan Tiket Berhasil!" << endl;
    cout << "Nomor Penerbangan: " << flight.flightNumber << endl;
    cout << "Jumlah Tiket: " << jumlahTKT << endl;
    cout << "Total Bayar: Rp. " << (jumlahTKT * flight.price) << endl;
    cout << "Nama: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Telepon: " << phone << endl;
    cout << "=============================================" << endl;
}

// Fungsi utama untuk pemesanan tiket pesawat
void pemesanan_tiket_pesawat() {
    int pilihan;
    vector<Flight> flights = {
        {"GA123", "Jakarta", 50, 1000000, vector<bool>(50, false)},
        {"JT456", "Bali", 30, 1200000, vector<bool>(30, false)},
        {"Lion Air 789", "Surabaya", 20, 900000, vector<bool>(20, false)}
    };

    // Tampilan menu utama
    do {
        cout << "\t   SISTEM PEMESANAN TIKET PESAWAT" << endl;
        cout << " =============================================" << endl;
        cout << "\t      DAFTAR MENU " << endl;
        cout << "\t---------------------------------" << endl;
        cout << "\t| 1. Tampilkan dan Pesan Tiket |" << endl;
        cout << "\t| 2. Keluar                    |" << endl;
        cout << "\t---------------------------------" << endl;
        cout << " =============================================" << endl;
        cout << endl;

        cout << " Masukan Pilihan Anda (1-2) : ";
        cin >> pilihan;
        cout << endl;

        system("cls");

        switch (pilihan) {
        case 1: {
            string destination;
            displayFlights(flights);
            cout << "Pilih kota tujuan: ";
            cin >> destination;

            // Mencari penerbangan yang dipilih berdasarkan tujuan
            vector<Flight*> selectedFlights;
            for (auto& flight : flights) {
                if (flight.destination == destination) {
                    selectedFlights.push_back(&flight);
                }
            }

            if (selectedFlights.empty()) {
                cout << "Tidak ada penerbangan tersedia untuk tujuan tersebut!" << endl;
                break;
            }

            // Tampilkan penerbangan dan layout kursi
            for (auto& selectedFlight : selectedFlights) {
                displaySeatLayout(*selectedFlight);
                bookTickets(*selectedFlight);
            }
            break;
        }

        case 2:
            cout << "Terima kasih telah menggunakan layanan kami!" << endl;
            break;

        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }

    } while (pilihan != 2);
}

int main() {
    pemesanan_tiket_pesawat();
    return 0;
}
