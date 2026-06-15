#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

// --- ФУНКЦІЇ ДЛЯ ЗАВДАННЯ 1.11 ---
// Функція обчислює значення виразу: z = (x^2 + y^2) / (x - y)
void executeTask1_11() {
    cout << "\n=== Task 1.11: Math Expression Calculation ===" << endl;
    double x, y;
    
    // Введення даних з клавіатури
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    
    // Перевірка на ділення на нуль
    if (x == y) {
        cout << "Error: Division by zero (x cannot equal y)!" << endl;
    } else {
        double z = (pow(x, 2) + pow(y, 2)) / (x - y);
        cout << "Result z = (x^2 + y^2) / (x - y) is: " << z << endl;
    }
}

// --- ФУНКЦІЇ ДЛЯ ЗАВДАННЯ 2.11 ---
// Функція знаходить мінімальний елемент у масиві та його індекс
void executeTask2_11() {
    cout << "\n=== Task 2.11: Minimum Element in Array ===" << endl;
    int size;
    
    cout << "Enter the size of the array: ";
    cin >> size;
    
    if (size <= 0) {
        cout << "Invalid array size!" << endl;
        return;
    }
    
    vector<int> arr(size);
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
    
    // Пошук мінімуму
    int minVal = arr[0];
    int minIndex = 0;
    
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIndex = i;
        }
    }
    
    cout << "\nMinimum element: " << minVal << endl;
    cout << "Index of minimum element: " << minIndex << endl;
}

// --- ФУНКЦІЇ ДЛЯ ЗАВДАННЯ 3.11 ---
// Функція перевіряє, чи є введений рядок паліндромом
void executeTask3_11() {
    cout << "\n=== Task 3.11: Palindrome Check ===" << endl;
    string str;
    
    cout << "Enter a string (single word): ";
    cin >> str;
    
    string reversedStr = str;
    reverse(reversedStr.begin(), reversedStr.end());
    
    if (str == reversedStr) {
        cout << "The string \"" << str << "\" is a palindrome." << endl;
    } else {
        cout << "The string \"" << str << "\" is NOT a palindrome." << endl;
    }
}

// --- ГОЛОВНА ФУНКЦІЯ З МЕНЮ ---
int main() {
    int choice;
    
    // Головний цикл програми (працює, поки користувач не вийде)
    do {
        cout << "\n=====================================" << endl;
        cout << "             MAIN MENU               " << endl;
        cout << "=====================================" << endl;
        cout << "1. Run Task 1.11" << endl;
        cout << "2. Run Task 2.11" << endl;
        cout << "3. Run Task 3.11" << endl;
        cout << "0. Exit" << endl;
        cout << "=====================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        // Обробка вибору користувача
        switch (choice) {
            case 1:
                executeTask1_11();
                break;
            case 2:
                executeTask2_11();
                break;
            case 3:
                executeTask3_11();
                break;
            case 0:
                cout << "\nExiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }
        
    } while (choice != 0); // Повторювати, поки не введено 0
    
    return 0;
}
