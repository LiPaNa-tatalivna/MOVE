#include <iostream>
#include <vector>
#include <string>
#include <utility>

template <typename T>
void move_vectors(std::vector<T>& source, std::vector<T>& destination)
{
    // Используем std::move() для перемещения элементов из source в destination
    destination = std::move(source);
}

int main()
{
    std::vector<std::string> one = { "test_string1", "test_string2" };
    std::vector<std::string> two = {"gh"};

    move_vectors(one, two);

    std::cout << "Contents of 'one': ";
    for (const auto& str : one) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    std::cout << "Contents of 'two': ";
    for (const auto& str : two) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}
