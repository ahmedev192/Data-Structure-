// Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "_Vector.cpp"  // Include the source file
using namespace std;
int main()
{
    // Create an instance of _Vector with int type
    _Vector<int> myVector;

    // Populate the vector with some values
    for (int i = 1; i <= 5; ++i) {
        myVector.pushBack(i);
    }

    // Display the original vector
    std::cout << "Original Vector: ";
    myVector.printAll();
    std::cout << std::endl;

    // Test pop functionality
    std::cout << "Popping the last element..." << std::endl;
    myVector.pop();
    std::cout << "Vector after pop: ";
    myVector.printAll();
    std::cout << std::endl;

    // Test deleteElement functionality
    int indexToDelete = 2;  // Replace with the index you want to delete
    std::cout << "Deleting element at index " << indexToDelete << "..." << std::endl;
    myVector.deleteElement(indexToDelete);
    std::cout << "Vector after deletion: ";
    myVector.printAll();
    std::cout << std::endl;

    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
