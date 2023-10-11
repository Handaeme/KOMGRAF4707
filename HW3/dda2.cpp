#include <iostream>
#include <cmath>

// Fungsi untuk membulatkan nilai float ke integer
int round(float n) {
    return static_cast<int>(n + 0.5); // Pembulatan ke integer terdekat
}

// Fungsi untuk menggambar garis menggunakan algoritma DDA
void DDALine(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int step;

    // Tentukan langkah yang akan digunakan berdasarkan apakah dx atau dy yang lebih besar
    if (abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);

    // Hitung peningkatan x dan y untuk setiap langkah
    float x_incr = static_cast<float>(dx) / step;
    float y_incr = static_cast<float>(dy) / step;

    // Gunakan titik awal sebagai x dan y
    float x = x0;
    float y = y0;

    for (int i = 0; i < step; i++) {
        // Cetak koordinat piksel
        std::cout << round(x) << " " << round(y) << "\n";
        x += x_incr;
        y += y_incr;
    }
}

int main() {
    int x0 = 10, y0 = 1, x1 = 2, y1 = 10;

    // Panggil fungsi DDALine untuk menggambar garis
    DDALine(x0, y0, x1, y1);

    return 0;
}
