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

int main() {
	int numOperations;

	cout << "Введите количество операций, которые будут записаны (от 2 до 40): ";

	while (!(cin >> numOperations) || numOperations < 2 || numOperations > 40) {
		cout << "Неверный ввод. Пожалуйста, введите число от 2 до 40: ";
		cin.clear();
	}

}