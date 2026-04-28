#include <iostream>
#include "GenericArray.h"

int main() {
    GenericArray<int> int_array;

    int_array.addElement(10);
    int_array.addElement(2);
    int_array.addElement(7);
    int_array.addElement(15);
    int_array.addElement(4);
    int_array.addElement(9);
    int_array.addElement(20);
    int_array.addElement(1);
    int_array.addElement(13);
    int_array.addElement(6);
    int_array.addElement(8);

    std::cout << "size of array is " << int_array.size() << std::endl;
    std::cout << "sum of the array is " << int_array.sum() << std::endl;
    std::cout << "maximum and minimum of array is "
              << int_array.max() << "\t" << int_array.min() << std::endl;

    int* sliced_array = int_array.slice(5, 10);
    std::cout << "sliced array: ";
    for (int i = 5; i <= 10; ++i) {
        std::cout << sliced_array[i - 5] << " ";
    }
    std::cout << std::endl;

    delete[] sliced_array;
    return 0;
}
