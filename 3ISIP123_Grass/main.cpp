#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Expense {
	string description;
	double amount;
};

void clearInputBuffer() {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
	int numOperations;

	cout << "Введите количество операций, которые будут записаны (от 2 до 40): ";

	while (!(cin >> numOperations) || numOperations < 2 || numOperations > 40) {
		cout << "Неверный ввод. Пожалуйста, введите число от 2 до 40: ";
		cin.clear();
	}

}