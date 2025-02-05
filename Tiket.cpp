#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Struktur untuk menyimpan informasi penerbangan
struct Flight {
    string flightNumber;
    string destination;
    int price;
    vector<vector<bool>> seatMap; // 2D vector for seat availability per schedule
    vector<string> schedule; // New attribute for flight schedule
    vector<bool> scheduleBooked; // New attribute to track if schedule is fully booked
    vector<int> availableSeats; // New attribute to track available seats for each schedule

    // Constructor untuk inisialisasi
    Flight(string fn, string dest, int pr, vector<string> sch, vector<int> seats)
        : flightNumber(fn), destination(dest), price(pr), schedule(sch), availableSeats(seats), scheduleBooked(sch.size(), false) {
        for (int i = 0; i < sch.size(); i++) {
            seatMap.push_back(vector<bool>(seats[i], false)); // Initialize seat maps for each schedule
        }
    }
};

// Fungsi untuk menampilkan daftar penerbangan
void displayFlights(const vector<Flight>& flights) {
    cout << "=============================================" << endl;
    cout << "          DAFTAR PENERBANGAN                " << endl;
    cout << "=============================================" << endl;
    for (const auto& flight : flights) {
        cout << "Penerbangan: " << flight.flightNumber << ", Tujuan: " << flight.destination 
             << ", Harga: Rp. " << flight.price 
             << ", Jadwal: ";
        for (int i = 0; i < flight.schedule.size(); i++) {
            cout << flight.schedule[i];
            if (flight.scheduleBooked[i]) {
                cout << " (Fully Booked)"; // Indicate if the schedule is fully booked
            }
            if (i < flight.schedule.size() - 1) {
                cout << ", "; // Add a comma between schedules
            }
        }
        cout << endl;
    }
    cout << "=============================================" << endl;
}

// Fungsi untuk menampilkan layout kursi
void displaySeatLayout(const Flight& flight, int scheduleIndex) {
    cout << "Layout Kursi Pesawat untuk " << flight.flightNumber << " (Tujuan: " << flight.destination << "):" << endl;
    for (int i = 0; i < flight.seatMap[scheduleIndex].size(); i++) {
        if (i % 10 == 0) cout << endl; // New row every 10 seats
        cout << "[" << setw(2) << i << (flight.seatMap[scheduleIndex][i] ? "X" : " ") << "] ";
    }
    cout << endl;
}

// Fungsi untuk memilih jadwal penerbangan
int selectSchedule(Flight& flight) {
    cout << "Pilih jadwal penerbangan:" << endl;
    for (int i = 0; i < flight.schedule.size(); i++) {
        if (!flight.scheduleBooked[i]) {
            cout << i + 1 << ". " << flight.schedule[i] << " (Kursi Tersedia: " << flight.availableSeats[i] << ")" << endl; // Display available schedules with remaining seats
        }
    }

    int choice;
    cout << "Masukkan pilihan jadwal: ";
    cin >> choice;

    if (choice < 1 || choice > flight.schedule.size() || flight.scheduleBooked[choice - 1]) {
        cout << "Jadwal tidak valid atau sudah penuh!" << endl;
        return -1; // Invalid choice
    }

    return choice - 1; // Return the index of the selected schedule
}

// Fungsi untuk memesan tiket
void bookTickets(Flight& flight, int scheduleIndex) {
    // Check if the selected schedule is fully booked
    if (flight.scheduleBooked[scheduleIndex]) {
        cout << "Jadwal penerbangan sudah penuh! Silakan pilih jadwal lain." << endl;
        return;
    }

    int jumlahTKT;
    cout << "Jumlah tiket yang ingin dipesan: ";
    cin >> jumlahTKT;

    if (jumlahTKT > flight.availableSeats[scheduleIndex]) {
        cout << "Jumlah tiket yang diminta melebihi sisa kursi!" << endl;
        return;
    }

    // Jika membeli semua tiket, lewati pemilihan kursi
    if (jumlahTKT == flight.availableSeats[scheduleIndex]) {
        for (int i = 0; i < flight.seatMap[scheduleIndex].size(); i++) {
            flight.seatMap[scheduleIndex][i] = true; // Mark all seats as booked
        }
        flight.availableSeats[scheduleIndex] = 0; // No available seats left
        flight.scheduleBooked[scheduleIndex] = true; // Mark schedule as fully booked
    } else {
        // Memilih kursi
        for (int i = 0; i < jumlahTKT; i++) {
            int seatNumber;
            cout << "Pilih nomor kursi (0-" << flight.seatMap[scheduleIndex].size() - 1 << "): ";
            cin >> seatNumber;

            if (seatNumber < 0 || seatNumber >= flight.seatMap[scheduleIndex].size() || flight.seatMap[scheduleIndex][seatNumber]) {
                cout << "Kursi tidak valid atau sudah dipesan! Silakan pilih kursi lain." << endl;
                i--; // Decrement to allow re-selection
            } else {
                flight.seatMap[scheduleIndex][seatNumber] = true; // Mark seat as booked
                flight.availableSeats[scheduleIndex]--;
            }
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
        {"Batik Air", "Jakarta", 1000000, {"08:00", "12:00", "16:00"}, {50, 50, 50}},
        {"Garuda Airlines", "Bali", 1200000, {"09:00", "13:00", "17:00"}, {30, 30, 30}},
        {"Lion Air", "Surabaya", 900000, {"10:00", "14:00", "18:00"}, {20, 20, 20}}
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

            // Mencari penerbangan yang dipilih berdasarkan tujuan dan menampilkan jadwal
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
                int scheduleIndex = selectSchedule(*selectedFlight);
                if (scheduleIndex != -1) {
                    displaySeatLayout(*selectedFlight, scheduleIndex); // Show seat layout after selecting schedule
                    bookTickets(*selectedFlight, scheduleIndex);
                }
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
