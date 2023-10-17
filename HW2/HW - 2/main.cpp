#include <iostream>
#include <vector>

using namespace std; // Menggunakan namespace std

// Fungsi untuk menambahkan dua matriks
vector<vector<int>> tambahMatriks(const vector<vector<int>>& matriks1, const vector<vector<int>>& matriks2) {
    vector<vector<int>> hasil;
    int baris = matriks1.size();
    int kolom = matriks1[0].size();

    for (int i = 0; i < baris; i++) {
        vector<int> barisHasil;
        for (int j = 0; j < kolom; j++) {
            barisHasil.push_back(matriks1[i][j] + matriks2[i][j]);
        }
        hasil.push_back(barisHasil);
    }

    return hasil;
}

// Fungsi untuk mengurangkan dua matriks
vector<vector<int>> kurangMatriks(const vector<vector<int>>& matriks1, const vector<vector<int>>& matriks2) {
    vector<vector<int>> hasil;
    int baris = matriks1.size();
    int kolom = matriks1[0].size();

    for (int i = 0; i < baris; i++) {
        vector<int> barisHasil;
        for (int j = 0; j < kolom; j++) {
            barisHasil.push_back(matriks1[i][j] - matriks2[i][j]);
        }
        hasil.push_back(barisHasil);
    }

    return hasil;
}

// Fungsi untuk menampilkan matriks
void tampilMatriks(const vector<vector<int>>& matriks) {
    for (const vector<int>& baris : matriks) {
        for (int elemen : baris) {
            cout << elemen << " ";
        }
        cout << endl;
    }
}

int main() {
    // Matriks contoh
    vector<vector<int>> matriks1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> matriks2 = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    // Operasi penambahan matriks
    vector<vector<int>> hasilTambah = tambahMatriks(matriks1, matriks2);
    cout << "Hasil Penambahan Matriks: " << endl;
    tampilMatriks(hasilTambah);

    // Operasi pengurangan matriks
    vector<vector<int>> hasilKurang = kurangMatriks(matriks1, matriks2);
    cout << "Hasil Pengurangan Matriks: " << endl;
    tampilMatriks(hasilKurang);

    return 0;
}
