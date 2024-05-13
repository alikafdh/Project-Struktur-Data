#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Maksimal jumlah buku
const int MAX_BUKU = 50;

// Struktur untuk menyimpan informasi buku
struct Buku {
    string judul;
    int harga;
    int stok;
};

// Fungsi untuk menampilkan daftar buku
void tampilkanBuku(Buku buku[], int jumlahBuku) {
    cout << left << setw(20) << "Judul Buku" << setw(10) << "Harga" << setw(5) << "Stok" << endl;
    for (int i = 0; i < jumlahBuku; i++) {
        cout << left << setw(20) << buku[i].judul << setw(10) << buku[i].harga << setw(5) << buku[i].stok << endl;
    }
}

// Fungsi utama
int main() {
    Buku daftarBuku[MAX_BUKU] = {
        {"Buku C++", 50000, 10},
        {"Buku Java", 40000, 5},
        {"Buku Python", 60000, 8}
    };
    int jumlahBuku = 3; // Jumlah buku yang tersedia

    int pilihan, jumlah;
    char lanjut;
    float total = 0;

    do {
        system("cls");
        tampilkanBuku(daftarBuku, jumlahBuku);

        cout << "\nMasukkan nomor buku yang ingin dibeli (1-" << jumlahBuku << "): ";
        cin >> pilihan;
        cout << "Masukkan jumlah buku yang ingin dibeli: ";
        cin >> jumlah;

        // Periksa stok dan hitung total
        if (pilihan >= 1 && pilihan <= jumlahBuku && jumlah <= daftarBuku[pilihan - 1].stok) {
            daftarBuku[pilihan - 1].stok -= jumlah;
            total += daftarBuku[pilihan - 1].harga * jumlah;
            cout << "Buku berhasil dibeli!\n";
        } else {
            cout << "Pilihan tidak valid atau stok buku tidak cukup.\n";
        }

        cout << "Apakah Anda ingin membeli buku lain? (y/n): ";
        cin >> lanjut;
    } while (lanjut == 'y' || lanjut == 'Y');

    cout << fixed << setprecision(2);
    cout << "Total pembayaran: Rp" << total << endl;

    return 0;
}

