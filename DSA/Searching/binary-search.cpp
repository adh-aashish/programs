#include <iostream>
#include "searching.hpp"
using namespace std;

int main()
{
    int array[100] = {1, 3, 7, 10, 12, 13, 19, 22, 23, 30, 48, 54};
    int size = 12;
    int num;
    cout << "Enter the element to search: " << endl;
    cin >> num;
    try
    {
        cout << binarySearch(array, size, num) << endl;
    }
    catch (const char *e)
    {
        cout << "Error is :" << e << endl;
    }
    return 0;
}