#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"

using namespace std;

int main() {
	cout << "stroka from file: " << endl;
	string stroka = writeInStr();
	cout << stroka << endl;
 
	stroka.erase(0, 1);
	//cout << stroka[0] << endl;
	string subStroka{ "" };
	cout << endl << "your substring: " << endl;
	getline(cin, subStroka);
	//cout << stroka << endl << subStroka << endl;
	int dlinaSubStroka = subStroka.size(), 
		dlinaTableSdvig{dlinaSubStroka - 1}, ind{0};
	string sdvigSymbol{ "" };
	int* sdvigNumber = new int[dlinaTableSdvig] {0};
	//создание таблицы сдвигов
	for (int i{dlinaSubStroka - 2}; i >= 0; --i) {
		if (checkSymbol(sdvigSymbol, subStroka[i]) == -1) {
			sdvigSymbol += subStroka[i];
			sdvigNumber[ind] = dlinaSubStroka - 1 - i;
			++ind;
		}
		else {
			--dlinaTableSdvig;
		}

	}
	//вывожу чисто для проверки
	cout << "symbols in tableSdvig: " << sdvigSymbol << endl << "their sdvigi: ";
	for (int i{0}; i < dlinaTableSdvig ; ++i) {
		cout << sdvigNumber[i] << " ";
	}

	cout << endl << "all sdvigi: ";
	string result = printTableSdvig(stroka, subStroka, sdvigSymbol, sdvigNumber);
	for (int i{ 0 }; i < result.size(); ++i) {
		cout << result[i] << " ";
	}

	ofstream res("output.txt");
	res << result;
	res.close();
}
