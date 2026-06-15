#include <iostream>
#include <cmath>

using namespace std;

// ==========================================================
// Завдання 1.11: Обробка масиву (множення половин на 2 і 3)
// ==========================================================
void task1() {
    cout << "\n--- Task 1.11: Array Halves Processing ---" << endl;
    int N;
    cout << "Enter array size N: ";
    cin >> N;

    if (N <= 0) {
        cout << "Error: array size must be positive!" << endl;
        return;
    }

    // Динамічне виділення пам'яті для масиву
    int* A = new int[N];

    cout << "Enter " << N << " array elements:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Обробка масиву: першу половину множимо на 2, другу на 3
    int half = N / 2;
    for (int i = 0; i < N; ++i) {
        if (i < half) {
            A[i] *= 2;
        } else {
            A[i] *= 3;
        }
    }

    cout << "Array processing result: ";
    for (int i = 0; i < N; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    // Очищення пам'яті
    delete[] A;
}

// ==========================================================
// Завдання 2.11: Пошук індексу останнього мінімального 
// серед парних додатних після першого від'ємного
// ==========================================================
void task2() {
    cout << "\n--- Task 2.11: Find Specific Minimum Element ---" << endl;
    int N;
    cout << "Enter array size N: ";
    cin >> N;

    if (N <= 0) {
        cout << "Error: array size must be positive!" << endl;
        return;
    }

    int* A = new int[N];
    cout << "Enter " << N << " array elements:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // 1. Шукаємо перший від'ємний елемент
    int firstNegIdx = -1;
    for (int i = 0; i < N; ++i) {
        if (A[i] < 0) {
            firstNegIdx = i;
            break;
        }
    }

    if (firstNegIdx == -1 || firstNegIdx == N - 1) {
        cout << "No negative elements found or it is the last element. Search impossible." << endl;
        delete[] A;
        return;
    }

    // 2. Шукаємо останній мінімальний серед парних додатних
    int minVal = -1; // Ініціалізуємо маркером
    int lastMinIdx = -1;
    bool foundAny = false;

    for (int i = firstNegIdx + 1; i < N; ++i) {
        if (A[i] > 0 && A[i] % 2 == 0) { // Перевірка на додатне і парне число
            if (!foundAny || A[i] <= minVal) { // <= дозволяє знайти ОСТАННІЙ мінімум
                minVal = A[i];
                lastMinIdx = i;
                foundAny = true;
            }
        }
    }

    if (foundAny) {
        cout << "Last minimum positive even element: " << minVal 
             << " (Index: " << lastMinIdx << ")" << endl;
    } else {
        cout << "No positive even elements found after the first negative element." << endl;
    }

    delete[] A;
}

// ==========================================================
// Завдання 3.11: Точки в трикутнику
// ==========================================================
// Допоміжна функція для обчислення площі трикутника за координатами
double calculateArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

// Структура для збереження координат точки
struct Point {
    double x, y;
};

void task3() {
    cout << "\n--- Task 3.11: Points Inside a Triangle ---" << endl;
    int n;
    cout << "Enter the number of points n (<= 200): ";
    cin >> n;

    if (n <= 0 || n > 200) {
        cout << "Invalid number of points!" << endl;
        return;
    }

    // Динамічний масив структур для збереження точок
    Point* points = new Point[n];

    cout << "Enter coordinates for " << n << " points (x y format):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    Point A, B, C;
    cout << "Enter coordinates of vertex A (x y): "; cin >> A.x >> A.y;
    cout << "Enter coordinates of vertex B (x y): "; cin >> B.x >> B.y;
    cout << "Enter coordinates of vertex C (x y): "; cin >> C.x >> C.y;

    double areaABC = calculateArea(A.x, A.y, B.x, B.y, C.x, C.y);
    int countInside = 0;

    // Перевірка кожної точки (сума площ підтрикутників == площі основного трикутника)
    for (int i = 0; i < n; ++i) {
        double Px = points[i].x;
        double Py = points[i].y;

        double areaPAB = calculateArea(Px, Py, A.x, A.y, B.x, B.y);
        double areaPBC = calculateArea(Px, Py, B.x, B.y, C.x, C.y);
        double areaPCA = calculateArea(Px, Py, C.x, C.y, A.x, A.y);

        // Використовуємо epsilon (1e-6) для уникнення похибок порівняння чисел типу double
        if (abs(areaABC - (areaPAB + areaPBC + areaPCA)) < 1e-6) {
            countInside++;
        }
    }

    cout << "Number of points strictly inside or on the border of the triangle: " << countInside << endl;

    delete[] points;
}

// ==========================================================
// ГОЛОВНЕ МЕНЮ ПРОГРАМИ
// ==========================================================
int main() {
    int choice;
    do {
        cout << "\n=======================================" << endl;
        cout << "          LABORATORY WORK 1            " << endl;
        cout << "=======================================" << endl;
        cout << "1. Run Task 1.11 (Array Halves)" << endl;
        cout << "2. Run Task 2.11 (Find Minimum)" << endl;
        cout << "3. Run Task 3.11 (Points & Triangle)" << endl;
        cout << "0. Exit" << endl;
        cout << "=======================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 0: cout << "Exiting the program. Goodbye!" << endl; break;
            default: cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
