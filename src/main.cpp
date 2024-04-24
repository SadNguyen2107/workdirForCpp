#include <iostream>

enum Permission {
    READ = 0b100,
    WRITE = 0b010,
    EXECUTE = 0b001
};

int main(int argc, char const *argv[])
{
    std::cout << "Hello World" << std::endl;
    return 0;
}
