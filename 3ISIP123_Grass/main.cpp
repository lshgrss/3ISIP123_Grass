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

void displayStatistics(const vector<Expense>& expenses) {
	cout << "\n--- Статистика трат ---" << endl;
	if (expenses.empty()) {
		cout << "Нет записанных трат для статистики." << endl;
		return;
	}

	double sum = 0.0;
	double minAmount = numeric_limits<double>::max();
	double maxAmount = numeric_limits<double>::min();

	for (const auto& exp : expenses) {
		sum += exp.amount;
		if (exp.amount < minAmount) {
			minAmount = exp.amount;
		}
		if (exp.amount > maxAmount) {
			maxAmount = exp.amount;
		}
	}

	double average = sum / expenses.size();

	cout << "Общая сумма потраченных средств: " << fixed << setprecision(2) << sum << " руб." << endl;
	cout << "Средняя сумма одной траты:     " << fixed << setprecision(2) << average << " руб." << endl;
	cout << "Минимальная сумма траты:       " << fixed << setprecision(2) << minAmount << " руб." << endl;
	cout << "Максимальная сумма траты:      " << fixed << setprecision(2) << maxAmount << " руб." << endl;
	cout << "-----------------------\n" << endl;
}

void convertCurrency(vector<Expense>& expenses) {
	cout << "\n--- Конвертация валюты ---" << endl;
	map<string, double> exchangeRates;
	exchangeRates["USD"] = 90.0; 
	exchangeRates["EUR"] = 98.0; 
	exchangeRates["GBP"] = 115.0; 

	cout << "Доступные валюты для конвертации:" << endl;
	int i = 1;
	for (const auto& pair : exchangeRates) {
		cout << i++ << ". " << pair.first << " (1 " << pair.first << " = " << fixed << setprecision(2) << pair.second << " руб.)" << endl;
	}

	int choice;
	cout << "Выберите валюту для конвертации (введите номер): ";
	while (!(cin >> choice) || choice < 1 || choice > exchangeRates.size()) {
		cout << "Неверный ввод. Пожалуйста, выберите номер из списка: ";
		cin.clear();
		clearInputBuffer();
	}
	clearInputBuffer();

	string selectedCurrency;
	i = 1;
	for (const auto& pair : exchangeRates) {
		if (i == choice) {
			selectedCurrency = pair.first;
			break;
		}
		i++;
	}
	double rate = exchangeRates[selectedCurrency];

	cout << "Конвертировать все траты из " << selectedCurrency << " в рубли по курсу " << rate << "?" << endl;
	cout << "1. Да" << endl;
	cout << "2. Нет" << endl;
	cout << "Ваш выбор: ";
	while (!(cin >> choice) || (choice != 1 && choice != 2)) {
		cout << "Неверный ввод. Пожалуйста, выберите 1 или 2: ";
		cin.clear();
		clearInputBuffer();
	}
	clearInputBuffer();

	if (choice == 1) {
		for (auto& exp : expenses) {
			exp.amount *= rate;
		}
		cout << "Все траты успешно конвертированы в рубли." << endl;
	}
	else {
		cout << "Конвертация отменена." << endl;
	}
	cout << "-----------------------\n" << endl;
}

void searchByName(const vector<Expense>& expenses) {
	cout << "\n--- Поиск по названию ---" << endl;
	if (expenses.empty()) {
		cout << "Нет записанных трат для поиска." << endl;
		return;
	}

	string searchTerm;
	cout << "Введите часть названия услуги или товара для поиска: ";
	getline(cin, searchTerm);

	vector<Expense> foundExpenses;
	for (const auto& exp : expenses) {
		if (exp.description.find(searchTerm) != string::npos) {
			foundExpenses.push_back(exp);
		}
	}

	if (foundExpenses.empty()) {
		cout << "Ничего не найдено по вашему запросу." << endl;
	}
	else {
		cout << "\n--- Найденные траты ---" << endl;
		cout << left << setw(40) << "Название услуги/товара" << " | " << right << setw(10) << "Сумма (руб.)" << endl;
		cout << string(53, '-') << endl;
		for (const auto& exp : foundExpenses) {
			cout << left << setw(40) << exp.description << " | " << right << setw(10) << fixed << setprecision(2) << exp.amount << endl;
		}
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