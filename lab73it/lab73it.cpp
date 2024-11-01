#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillMatrix(int** matrix, int k, int n);
void printMatrix(int** matrix, int k, int n);
int sumOfNegativeColumns(int** matrix, int k, int n);
void sortColumnsByCharacteristics(int** matrix, int k, int n);
int columnCharacteristic(int** matrix, int k, int col);

int main() {
    int k, n;

    cout << "Enter number of rows (k): ";
    cin >> k;
    cout << "Enter number of columns (n): ";
    cin >> n;

    // Динамічне виділення пам'яті для матриці
    int** matrix = new int* [k];
    for (int i = 0; i < k; ++i) {
        matrix[i] = new int[n];
    }

    fillMatrix(matrix, k, n);
    cout << "Original Matrix:\n";
    printMatrix(matrix, k, n);

    int sum = sumOfNegativeColumns(matrix, k, n);
    cout << "Sum of elements in columns with negative elements: " << sum << endl;

    sortColumnsByCharacteristics(matrix, k, n);
    cout << "Sorted Matrix:\n";
    printMatrix(matrix, k, n);

    // Звільнення пам'яті
    for (int i = 0; i < k; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

void fillMatrix(int** matrix, int k, int n) {
    srand(static_cast<unsigned int>(time(0))); // Ініціалізація генератора випадкових чисел
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 21 - 10; // Заповнення значеннями в діапазоні [-10, 10]
        }
    }
}

void printMatrix(int** matrix, int k, int n) {
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int sumOfNegativeColumns(int** matrix, int k, int n) {
    int sum = 0;
    for (int j = 0; j < n; ++j) {
        bool hasNegative = false;
        for (int i = 0; i < k; ++i) {
            if (matrix[i][j] < 0) {
                hasNegative = true;
                break;
            }
        }
        if (hasNegative) {
            for (int i = 0; i < k; ++i) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

void sortColumnsByCharacteristics(int** matrix, int k, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (columnCharacteristic(matrix, k, i) > columnCharacteristic(matrix, k, j)) {
                // Перестановка стовпців
                for (int row = 0; row < k; ++row) {
                    swap(matrix[row][i], matrix[row][j]);
                }
            }
        }
    }
}

int columnCharacteristic(int** matrix, int k, int col) {
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        if (matrix[i][col] < 0 && matrix[i][col] % 2 != 0) { // Від’ємний непарний елемент
            sum += abs(matrix[i][col]); // Сума модулів
        }
    }
    return sum;
}