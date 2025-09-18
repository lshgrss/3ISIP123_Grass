#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <map>

using namespace std;

struct Expense {
	string description;
	double amount;
};

void clearInputBuffer() {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void bubbleSort(vector<Expense>& expenses) {
	int n = expenses.size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (expenses[j].amount > expenses[j + 1].amount) {
				swap(expenses[j], expenses[j + 1]);
			}
		}
	}
}

void displayData(const vector<Expense>& expenses) {
	cout << "\n--- Все ваши траты ---" << endl;
	if (expenses.empty()) {
		cout << "Нет записанных трат." << endl;
		return;
	}
	cout << left << setw(40) << "Название услуги/товара" << " | " << right << setw(10) << "Сумма (руб.)" << endl;
	cout << string(53, '-') << endl;
	for (const auto& exp : expenses) {
		cout << left << setw(40) << exp.description << " | " << right << setw(10) << fixed << setprecision(2) << exp.amount << endl;
	}
	cout << "-----------------------\n" << endl;
}

int main() {
	int numOperations;

	cout << "Введите количество операций, которые будут записаны (от 2 до 40): ";

	while (!(cin >> numOperations) || numOperations < 2 || numOperations > 40) {
		cout << "Неверный ввод. Пожалуйста, введите число от 2 до 40: ";
		cin.clear();
	}

}