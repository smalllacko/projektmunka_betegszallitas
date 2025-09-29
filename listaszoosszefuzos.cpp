#include <string>
#include <cctype>

std::string kebabCase(const char** words) {
    std::string result;
    bool first = true;
    for (const char** p = words; *p != nullptr; ++p) {
        if (!first) {
            result += '-';
        }
        first = false;
        // �talak�tjuk kisbet�ss� �s hozz�f�zz�k
        for (const unsigned char* pc = reinterpret_cast<const unsigned char*>(*p); *pc != '\0'; ++pc) {
            result += static_cast<char>(std::tolower(*pc));
        }
    }
    return result;
}
