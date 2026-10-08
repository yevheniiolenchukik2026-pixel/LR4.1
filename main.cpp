// Оленчук Є. В., ІК-12. ЛР 4.1, варіант 10. Чотири види циклів.
// Обчислення добутку P = prod(i*N / (i^2 + N^2)), i = N..16.
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cout << "N: ";
    // N не може бути нулем (0/0), а верхня межа добутку дорівнює 16.
    if (!(cin >> N) || N == 0 || N > 16) {
        cerr << "Invalid N (N != 0 and N <= 16)\n";
        return 1;
    }
    double p1 = 1, p2 = 1, p3 = 1, p4 = 1;
    int i;

    // 1) while
    i = N;
    while (i <= 16) {
        p1 *= double(i) * N / (double(i) * i + double(N) * N);
        ++i;
    }

    // 2) do...while
    i = N;
    do {
        p2 *= double(i) * N / (double(i) * i + double(N) * N);
        ++i;
    } while (i <= 16);

    // 3) for зі зростанням лічильника
    for (i = N; i <= 16; ++i)
        p3 *= double(i) * N / (double(i) * i + double(N) * N);

    // 4) for зі спаданням лічильника
    for (i = 16; i >= N; --i)
        p4 *= double(i) * N / (double(i) * i + double(N) * N);

    cout << scientific << setprecision(12);
    cout << "while:   " << p1 << '\n';
    cout << "do:      " << p2 << '\n';
    cout << "for ++:  " << p3 << '\n';
    cout << "for --:  " << p4 << '\n';
    // Різний порядок множення дає лише похибку округлення, тому порівнюємо з допуском.
    const double tol = 1e-12 * fabs(p1);
    cout << "Agreement: "
         << (fabs(p1 - p2) <= tol && fabs(p1 - p3) <= tol
             && fabs(p1 - p4) <= tol ? "yes" : "no") << '\n';
    return 0;
}
