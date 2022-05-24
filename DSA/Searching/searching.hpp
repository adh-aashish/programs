#pragma once
#include <iostream>

template <class T>
int binarySearch(const T *array, int size, T value)
{
    int lowerLimit = 0;
    int upperLimit = size - 1;
    while (size >= 1)
    {
        T check = array[lowerLimit + size / 2];
        if (value < check)
        {
            upperLimit = lowerLimit + size / 2 - 1;
            size /= 2;
        }
        else if (value > check)
        {
            lowerLimit = lowerLimit + size / 2 + 1;
            if (size % 2 == 0)
                size = size / 2 - 1;
            else
                size = size / 2;
        }
        else if (value == check)
        {
            return lowerLimit + size / 2;
        }
    }
    throw "No such element is found.";
}

// does linear search for an element in an array and returns that index
template <class T>
int linearSearch(const T *array, const int &size, T data)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == data)
        {
            return i;
        }
    }
    throw "Match did not happen";
}