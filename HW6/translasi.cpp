#include <iostream>
#include <cmath>

using namespace std;

// Fungsi untuk melakukan translasi
void translasi(float points[][3], int n, float tx, float ty) {
    // Matriks translasi
    float translationMatrix[3][3] = {
        {1, 0, tx},
        {0, 1, ty},
        {0, 0, 1}
    };

    // Menampilkan matriks translasi
    cout << "Matriks Translasi:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << translationMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    // Melakukan translasi untuk setiap titik
    for (int i = 0; i < n; i++) {
        // Menambahkan kolom matriks satu untuk homogen
        float point[3] = {points[i][0], points[i][1], 1};

        // Mengalikan matriks translasi dengan titik
        float result[3] = {0, 0, 0};
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                result[j] += translationMatrix[j][k] * point[k];
            }
        }

        // Menyimpan hasil translasi kembali ke array titik
        points[i][0] = result[0];
        points[i][1] = result[1];
    }
}

int main() {
    // Jumlah titik
    int n;
    cout << "Masukkan jumlah titik: ";
    cin >> n;

    // Membuat array untuk menyimpan titik-titik
    float points[n][3];

    // Memasukkan koordinat titik
    for (int i = 0; i < n; i++) {
        cout << "Masukkan koordinat titik " << i + 1 << " (x y): ";
        cin >> points[i][0] >> points[i][1];
    }

    // Menampilkan titik sebelum translasi
    cout << "\nTitik sebelum translasi:\n";
    for (int i = 0; i < n; i++) {
        cout << "Titik " << i + 1 << ": (" << points[i][0] << ", " << points[i][1] << ")\n";
    }

    // Memasukkan nilai translasi
    float tx, ty;
    cout << "\nMasukkan nilai translasi tx ty: ";
    cin >> tx >> ty;

    // Melakukan translasi
    translasi(points, n, tx, ty);

    // Menampilkan titik setelah translasi
    cout << "\nTitik setelah translasi:\n";
    for (int i = 0; i < n; i++) {
        cout << "Titik " << i + 1 << ": (" << points[i][0] << ", " << points[i][1] << ")\n";
    }

    return 0;
}
