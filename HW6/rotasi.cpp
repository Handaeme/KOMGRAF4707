#include <iostream>
#include <cmath>

using namespace std;

// Fungsi untuk melakukan rotasi
void rotasi(float points[][3], int n, float theta) {
    // Menghitung nilai cos dan sin dari sudut rotasi
    float cosTheta = cos(theta);
    float sinTheta = sin(theta);

    // Matriks rotasi
    float rotationMatrix[3][3] = {
        {cosTheta, -sinTheta, 0},
        {sinTheta, cosTheta, 0},
        {0, 0, 1}
    };

    // Menampilkan matriks rotasi
    cout << "Matriks Rotasi:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << rotationMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    // Melakukan rotasi untuk setiap titik
    for (int i = 0; i < n; i++) {
        // Menambahkan kolom matriks satu untuk homogen
        float point[3] = {points[i][0], points[i][1], 1};

        // Mengalikan matriks rotasi dengan titik
        float result[3] = {0, 0, 0};
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                result[j] += rotationMatrix[j][k] * point[k];
            }
        }

        // Menyimpan hasil rotasi kembali ke array titik
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

    // Menampilkan titik sebelum rotasi
    cout << "\nTitik sebelum rotasi:\n";
    for (int i = 0; i < n; i++) {
        cout << "Titik " << i + 1 << ": (" << points[i][0] << ", " << points[i][1] << ")\n";
    }

    // Memasukkan nilai sudut rotasi
    float theta;
    cout << "\nMasukkan nilai sudut rotasi (derajat): ";
    cin >> theta;

    // Mengonversi sudut rotasi ke radian
    theta = theta * M_PI / 180.0;

    // Melakukan rotasi
    rotasi(points, n, theta);

    // Menampilkan titik setelah rotasi
    cout << "\nTitik setelah rotasi:\n";
    for (int i = 0; i < n; i++) {
        cout << "Titik " << i + 1 << ": (" << points[i][0] << ", " << points[i][1] << ")\n";
    }

    return 0;
}
