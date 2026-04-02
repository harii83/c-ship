#include <iostream>
#include <string>

int main() {
    std::string os = 
    #ifdef _WIN32
        "Windows";
    #else
        "Linux";
    #endif

    std::cout << "Hello from " << os << "!" << std::endl;
    return 0;
}
