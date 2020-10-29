#include <iostream>
#include <fstream>
#include <string>

std::string writeInStr() {
	std::ifstream file("input.txt");
	std::string stroka{ "" }, stroka2{ "" };
	while (!file.eof()) {
		getline(file, stroka2);
		stroka += '\n' + stroka2;
	}
	file.close();
	//cout << stroka << endl;
	for (int i{ 0 }; i < stroka.size(); ++i) {
		if (stroka[i + 1] == '\n') {
			if (stroka[i] == '-') {
				stroka.erase(i, 2);
			}
			else {
				stroka[i + 1] = ' ';
			}
		}
	}
	return stroka;
}

int findSymbolInSdvigSymbol(std::string symbolOfSdvig, char symbol) {
	int dlina = symbolOfSdvig.size();
	for (int i{ 0 }; i < dlina; ++i) {
		if (symbolOfSdvig[i] == symbol) {
			return i;
		}
	}
	return -1;
}

int checkSymbol(std::string str, char symbol) {
	int dlina = str.size();
	for (int i{ dlina - 1 }; i >= 0; --i) {
		if (str[i] == symbol) {
			return dlina - i;
		}
	}
	return -1;
}

std::string printTableSdvig(std::string str, std::string subStr, 
	std::string symbolOfSdvig, int* numberOfSdvig) {
	std::string sdvigi{ "" };
	bool isFounded{ false };
	int dlinaStroka = str.size(), dlinaSubStroka = subStr.size(),
		konechInd{ dlinaSubStroka - 1 };

	do {
		std::string newSubStr{ "" };
		int sdvig{ 0 };

		for (int i{ konechInd - dlinaSubStroka + 1 }; i <= konechInd; ++i) {
			newSubStr += str[i];
		}
		//если сразу же нет совпадений 			
		if (newSubStr[dlinaSubStroka - 1] != subStr[dlinaSubStroka - 1]) {
			//если этот символ есть в таблице сдвигов
			if (findSymbolInSdvigSymbol(symbolOfSdvig, newSubStr[dlinaSubStroka - 1]) != -1) {
				int indInSymbolSdvig = findSymbolInSdvigSymbol(symbolOfSdvig, newSubStr[dlinaSubStroka - 1]);
				sdvig = numberOfSdvig[indInSymbolSdvig];
			}
			//если его нет
			else {
				sdvig = dlinaSubStroka;
			}
			konechInd += sdvig;
			sdvigi += std::to_string(sdvig);
		}
		//если есть хотя бы одно совпадение
		else {
			int ind{ dlinaSubStroka - 1 };
			//пока есть совпадения
			while ((ind >= 0) && (newSubStr[ind] == subStr[ind])) {
				++sdvig;
				--ind;
			}
			//если мы полностью прошли и цикл не прервался
			if (sdvig == dlinaSubStroka) {
				isFounded = true;
				goto end;
			}
			//если прервался, сдвигаем на столько, сколько прошли
			else {
				konechInd += sdvig;
				sdvigi += std::to_string(sdvig);
			}
		}
	end:;
	} while (!isFounded && konechInd <= dlinaStroka);
	//если мы просто прошли, но не нашли подстроку
	if (!isFounded) {
		return "sorry, there is no your substring";
	}
	return sdvigi;
}
