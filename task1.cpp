#include <iostream>
#include <array>

const int MAXNUMBEROFROWS = 100;
const int MAXNUMBEROFCOLUMNS = 100;

void fillArray(std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr, int rows, int columns) {
    if (rows > MAXNUMBEROFROWS || columns > MAXNUMBEROFCOLUMNS) {
        throw std::invalid_argument("Incorrect number of rows or columns");
    }
    
    int startValue = 1;
    
    for (int i = rows - 1; i >= 0; i--) {
        if ((rows - 1 - i) % 2 == 0) {
            for (int j = 0; j < columns; j++) {
                arr[i][j] = startValue;
                startValue++;
            }
        } else {
            for (int j = columns - 1; j >= 0; j--) {
                arr[i][j] = startValue;
                startValue++;
            }
        }
    }
}

void printArray(const std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS> arr;
    int numberOfRows, numberOfColumns;
    
    std::cout << "Enter the number of rows: ";
    std::cin >> numberOfRows;
    std::cout << "Enter the number of columns: ";
    std::cin >> numberOfColumns;
    
    try {
        fillArray(arr, numberOfRows, numberOfColumns);
        printArray(arr, numberOfRows, numberOfColumns);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}
