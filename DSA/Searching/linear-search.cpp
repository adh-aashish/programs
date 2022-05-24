#include <iostream>
#include "searching.hpp"

int main()
{
    int array[50] = {1, 3, 5, 6, 9, 14, 19, 20};
    int elemSize = 8;
    int data;
    std::cout << "Enter the data element to search: ";
    std::cin >> data;
    std::cout << linearSearch(array, elemSize, data) << std::endl;
    return 0;
}