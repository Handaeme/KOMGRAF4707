#include <iostream>
#include <cmath>

using namespace std;

// Fungsi untuk melakukan scaling
void scaling(float points[][3], int n, float sx, float sy) {
    // Matriks scaling
    float scalingMatrix[3][3] = {
        {sx, 0, 0},
        {0, sy, 0},
        {0, 0, 1}
    };

    // Menampilkan matriks scaling
    cout << "Matriks Scaling:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << scalingMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    // Melakukan scaling untuk setiap titik
    for (int i = 0; i < n; i++) {
        // Menambahkan kolom matriks satu untuk homogen
        float point[3] = {points[i][0], points[i][1], 1};

        // Mengalikan matriks scaling dengan titik
        float result[3] = {0, 0, 0};
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                result[j] += scalingMatrix[j][k] * point[k];
            }
        }

        // Menyimpan hasil scaling kembali ke array titik
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

    // Menampilkan titik sebelum scaling
    cout << "\nTitik sebelum scaling:\n";
    for (int i = 0; i < n; i++) {
        cout << "Titik " << i + 1 << ": (" << points[i][0] << ", " << points[i][1] << ")\n";
    }

    // Memasukkan faktor scaling
    float sx, sy;
    cout << "\nMasukkan faktor scaling sx sy: ";
    cin >> sx >> sy;

    // Melakukan scaling
    scaling(points, n, sx, sy);

    // Menampilkan titik setelah scaling
    cout << "\nTitik setelah scaling:\n";
    for (int i = 0; i < n; i++) {
        cout << "Titik " << i + 1 << ": (" << points[i][0] << ", " << points[i][1] << ")\n";
    }

    return 0;
}
