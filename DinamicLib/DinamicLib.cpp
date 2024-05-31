#include "Header.h"
#include <string>

__declspec(dllexport) bool CheckSymvols(const std::string & input, const std::string & symvols) {
    for (char symvol : symvols) {
        if (input.find(symvol) == std::string::npos) {
            return false;
        }
    }
    return true;
}

