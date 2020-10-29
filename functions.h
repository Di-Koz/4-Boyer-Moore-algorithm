#include <iostream>
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

std::string writeInStr();
int findSymbolInSdvigSymbol(std::string symbolOfSdvig, char symbol);
int checkSymbol(std::string str, char symbol);
std::string printTableSdvig(std::string str, std::string subStr, 
	std::string symbolOfSdvig, int* numberOfSdvig);
#endif