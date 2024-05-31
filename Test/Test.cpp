#include <iostream>
#include "Windows.h"
#include "..\DinamicLib\Header.h"

int main() {

    setlocale(LC_ALL, "Rus");

    typedef bool (*CheckSymvolsFunc)(const std::string&, const std::string&);

    HMODULE MyLibrary = LoadLibrary(TEXT("DinamicLib.dll"));
    if (!MyLibrary) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    CheckSymvolsFunc LybraryFunc = (CheckSymvolsFunc)GetProcAddress(MyLibrary, "CheckSymbols");
    if (!LybraryFunc) {
        std::cerr << "Error" << std::endl;
        FreeLibrary(MyLibrary);
        return 1;
    }

    std::string place, search;
    std::cout << "������� ������: ";
    std::getline(std::cin, place);
    std::cout << "������� ������� ��� ������: ";
    std::getline(std::cin, search);

    bool found = LybraryFunc(place, search);
    std::cout << "���������: " << (found ? "����� ������� ����!" : "����� ������� ����!") << std::endl;

    FreeLibrary(MyLibrary);
    return 0;
}
