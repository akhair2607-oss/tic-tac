#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Fungsi untuk menampilkan papan permainan
void tampilkanPapan(char papan[3][3]) {             //Menampilkan papan 3×3 dengan garis pemisah dan label "Baris" & "Kolom"
    system("cls"); // clear screen (gunakan "clear" kalau di Linux/Mac)
    cout << "=============================\n";
    cout << "       TIC TAC TOE GAME      \n";
    cout << "=============================\n\n";

    cout << "      Kolom:  1   2   3   4\n\n";
    for (int i = 0; i < 3; i++) {       //Loop pertama (i) → menampilkan tiap baris (1 sampai 3).
        cout << "Baris " << i + 1 << "   ";
        for (int j = 0; j < 3; j++) {   //Loop kedua (j) → menampilkan tiap kolom dalam baris.
            cout << " " << papan[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "          ---+---+---\n";
    }
    cout << "\n";
}

// Fungsi untuk cek pemenang
char cekPemenang(char papan[3][3]) {
    // cek baris
    for (int i = 0; i < 3; i++) {
        if (papan[i][0] == papan[i][1] && papan[i][1] == papan[i][2] && papan[i][0] != ' ')
            return papan[i][0];
    }
    // cek kolom
    for (int j = 0; j < 3; j++) {
        if (papan[0][j] == papan[1][j] && papan[1][j] == papan[2][j] && papan[0][j] != ' ')
            return papan[0][j];
    }
    // cek diagonal
    if (papan[0][0] == papan[1][1] && papan[1][1] == papan[2][2] && papan[0][0] != ' ')
        return papan[0][0];
    if (papan[0][2] == papan[1][1] && papan[1][1] == papan[2][0] && papan[0][2] != ' ')
        return papan[0][2];

    return ' '; // belum ada pemenang
}

// Fungsi cek apakah papan penuh (seri)
bool papanPenuh(char papan[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (papan[i][j] == ' ') return false;
    return true;
}

int main() {
    char papan[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    string pemain1, pemain2;
    cout << "Masukkan nama Pemain 1 (X): ";
    getline(cin, pemain1);
    cout << "Masukkan nama Pemain 2 (O): ";
    getline(cin, pemain2);

    int giliran = 0; // 0 = pemain1 (X), 1 = pemain2 (O)
    char simbol[2] = {'X', 'O'};
    string nama[2] = {pemain1, pemain2};

    while (true) {
        tampilkanPapan(papan);

        cout << "Giliran " << nama[giliran] << " (" << simbol[giliran] << ")\n";
        int baris, kolom;
        cout << "Masukkan baris (1-3): ";
        cin >> baris;
        cout << "Masukkan kolom (1-3): ";
        cin >> kolom;

        // validasi input
        if (baris < 1 || baris > 3 || kolom < 1 || kolom > 3) {
            cout << "Posisi tidak valid! Tekan enter untuk lanjut...";
            cin.ignore();
            cin.get();
            continue;
        }
        if (papan[baris-1][kolom-1] != ' ') {
            cout << "Posisi sudah terisi! Tekan enter untuk lanjut...";
            cin.ignore();
            cin.get();
            continue;
        }

        // tempatkan simbol
        papan[baris-1][kolom-1] = simbol[giliran];

        // cek pemenang
        char pemenang = cekPemenang(papan);
        if (pemenang != ' ') {
            tampilkanPapan(papan);
            if (pemenang == 'X')
                cout << "🎉 Selamat " << pemain1 << " menang!\n";
            else
                cout << "🎉 Selamat " << pemain2 << " menang!\n";
            break;
        }

        // cek seri
        if (papanPenuh(papan)) {
            tampilkanPapan(papan);
            cout << "⚖️  Permainan berakhir seri!\n";
            break;
        }

        // ganti giliran
        giliran = 1 - giliran;
    }

    cout << "\nTerima kasih sudah bermain!\n";
    return 0;
}
