#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int n = 10; 
    int arr[n];
    cout << "Масив:" << endl;
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10; 

        cout << " "<<arr[i];
    }
    cout << endl;
   
    int sum_of_positive = 0; // змінна, що зберігає суму додатніх елементів масиву
    int product_of_elements = 1; // змінна, що зберігає добуток елементів масиву
    bool found_max = false, found_min = false; // змінні, що вказують, чи було знайдено максимальний та мінімальний по модулю елементи
    int max_index, min_index; // індекси максимального та мінімального по модулю елементів

    // обчислюємо суму додатніх елементів та добуток всіх елементів масиву
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            sum_of_positive += arr[i];
        }
        product_of_elements *= arr[i];

        // Пошук максимального та мінімального по модулю елементів
        if (!found_max || abs(arr[i]) > abs(arr[max_index])) {
            max_index = i;
            found_max = true;
        }
        if (!found_min || abs(arr[i]) < abs(arr[min_index])) {
            min_index = i;
            found_min = true;
        }
    }

    // Обчислення добутку елементів масиву, що знаходяться між максимальним та мінімальним по модулю елементами
    int product_between = 1;
    if (max_index < min_index) {
        for (int i = max_index + 1; i < min_index; i++) {
            product_between *= arr[i];
        }
    }
    else {
        for (int i = min_index + 1; i < max_index; i++) {
            product_between *= arr[i];
        }
    }

    cout << "Сума додатніх елементів масиву: " << sum_of_positive << endl;
    cout << "Добуток елементів масиву: " << product_of_elements << endl;
    cout << "Добуток елементів масиву, що знаходяться між максимальним та мінімальним по модулю елементами: " << product_between << endl;
}
