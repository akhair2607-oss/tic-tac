#include <iostream>     // Untuk input dan output (cin, cout)
#include <iomanip>      // (tidak digunakan di sini, tapi biasanya untuk manipulasi format)
#include <string>       // Untuk penggunaan tipe data string
using namespace std;

// ==================== FUNGSI UNTUK MENAMPILKAN PAPAN PERMAINAN ==================== //
void tampilkanPapan(char papan[3][3]) {  
    // Membersihkan layar (gunakan "cls" untuk Windows, "clear" untuk Linux/Mac)
    system("cls");  

    // Tampilan judul permainan
    cout << "=============================\n";
    cout << "       TIC TAC TOE GAME      \n";
    cout << "=============================\n\n";

    // Label kolom di bagian atas papan
    cout << "      Kolom:  1   2   3\n\n";

    // Menampilkan isi papan permainan 3x3
    for (int i = 0; i < 3; i++) {  
        cout << "Baris " << i + 1 << "   "; // Menampilkan label baris di sisi kiri
        for (int j = 0; j < 3; j++) {  
            cout << " " << papan[i][j] << " "; // Menampilkan isi sel papan (X, O, atau spasi)
            if (j < 2) cout << "|"; // Garis pemisah antar kolom
        }
        cout << "\n";
        if (i < 2) cout << "          ---+---+---\n"; // Garis pemisah antar baris
    }
    cout << "\n";
}

// ==================== FUNGSI UNTUK CEK PEMENANG ==================== //
char cekPemenang(char papan[3][3]) {
    // Cek setiap baris
    for (int i = 0; i < 3; i++) {
        if (papan[i][0] == papan[i][1] && papan[i][1] == papan[i][2] && papan[i][0] != ' ')
            return papan[i][0]; // Mengembalikan simbol pemenang ('X' atau 'O')
    }

    // Cek setiap kolom
    for (int j = 0; j < 3; j++) {
        if (papan[0][j] == papan[1][j] && papan[1][j] == papan[2][j] && papan[0][j] != ' ')
            return papan[0][j];
    } 

    // Cek diagonal kiri atas ke kanan bawah
    if (papan[0][0] == papan[1][1] && papan[1][1] == papan[2][2] && papan[0][0] != ' ')
        return papan[0][0];

    // Cek diagonal kanan atas ke kiri bawah
    if (papan[0][2] == papan[1][1] && papan[1][1] == papan[2][0] && papan[0][2] != ' ')
        return papan[0][2];

    // Jika belum ada yang menang
    return ' ';
}

// ==================== FUNGSI UNTUK CEK APAKAH PAPAN SUDAH PENUH ==================== //
bool papanPenuh(char papan[3][3]) {
    // Mengecek setiap sel apakah masih ada yang kosong (' ')
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (papan[i][j] == ' ') return false; // Jika masih ada kosong, belum penuh
    return true; // Semua sel sudah terisi
}

// ==================== FUNGSI UTAMA (MAIN PROGRAM) ==================== //
int main() {
    // Inisialisasi papan kosong (3x3)
    char papan[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    // Input nama pemain
    string pemain1, pemain2;
    cout << "Masukkan nama Pemain 1 (X): ";
    getline(cin, pemain1);
    cout << "Masukkan nama Pemain 2 (O): ";
    getline(cin, pemain2);

    // Variabel giliran (0 = pemain1, 1 = pemain2)
    int giliran = 0;
    char simbol[2] = {'X', 'O'}; // Simbol untuk masing-masing pemain
    string nama[2] = {pemain1, pemain2};

    // ==================== LOOP UTAMA PERMAINAN ==================== //
    while (true) {
        tampilkanPapan(papan); // Tampilkan papan terkini

        // Tampilkan giliran pemain saat ini
        cout << "Giliran " << nama[giliran] << " (" << simbol[giliran] << ")\n";

        // Input posisi baris dan kolom
        int baris, kolom;
        cout << "Masukkan baris (1-3): ";
        cin >> baris;
        cout << "Masukkan kolom (1-3): ";
        cin >> kolom;

        

        // Validasi posisi input
        if (baris < 1 || baris > 3 || kolom < 1 || kolom > 3) {
            cout << "Posisi tidak valid! Tekan enter untuk lanjut...";
            cin.ignore();
            cin.get();
            continue; // Ulangi giliran
        }

        // Cek apakah posisi sudah terisi
        if (papan[baris-1][kolom-1] != ' ') {
            cout << "Posisi sudah terisi! Tekan enter untuk lanjut...";
            cin.ignore();
            cin.get();
            continue;
        }

        // Tempatkan simbol di papan
        papan[baris-1][kolom-1] = simbol[giliran];

        // Cek apakah ada pemenang
        char pemenang = cekPemenang(papan);
        if (pemenang != ' ') {
            tampilkanPapan(papan);
            if (pemenang == 'X')
                cout << " Selamat " << pemain1 << " menang!\n";
            else
                cout << " Selamat " << pemain2 << " menang!\n";
            break; // Keluar dari loop permainan
        }

        // Cek apakah permainan seri
        if (papanPenuh(papan)) {
            tampilkanPapan(papan);
            cout << "  Permainan berakhir seri!\n";
            break;
        }

        // Ganti giliran pemain
        giliran = 1 - giliran;
    }

    // Pesan akhir setelah permainan selesai
    cout << "\nTerima kasih sudah bermain!\n";
    return 0;
}
