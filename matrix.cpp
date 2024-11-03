#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {

private:
    int data[SIZE][SIZE]; // 2D array for matrix data (using int for simplicity)

public:
    // 1. Read values from stdin into a matrix
    void readFromStdin(ifstream &f) {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                f >> data[row][col];
            }
        }
    }
    
    // 2. Display a matrix
    void display() const {
        for (int i = 0; i < SIZE; i++) {
            cout << "\n";
            for (int j = 0; j < SIZE; j++) {
                cout << "\t" << data[j][i];
            }
        }
        cout << endl;
    }
    
    // 3. Add two matrices (operator overloading for +)
    Matrix operator+(const Matrix& other) const {
        Matrix sum;
        //searches through every row and column, adds them together and assigns them to the same place on m3
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                sum.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return sum;
    }
    
    // 4. Multiply two matrices (operator overloading for *)
    Matrix operator*(const Matrix& other) const {
        Matrix product;
        //iterate over each row and column before performing product of i row of m1 and j column of m2
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < SIZE; k++) {
                    product.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return product;
    }
    
    // 5. Compute the sum of matrix diagonal elements
    int sumOfDiagonals() const {
        int sum = 0;
        //stores the sum of both diagonals by adding each value from a diagonal to sum
        for (int i = 0; i < SIZE; i++) {
            sum += data[i][i];
            sum += data[i][SIZE - i - 1];
        }
        return sum;
    }
    
    // 6. Swap matrix rows
    void swapRows(int row1, int row2) {
        //uses for loop and temp variable to store data while swapping and find the rows to swap as appropriate
        for (int col = 0; col < SIZE; col++) {
            int temp = data[row1][col];
            data[row1][col] = data[row2][col];
            data[row2][col] = temp;
        }
    }

};

int main() {
    ifstream infile("matdat.txt");

    if (!infile) {
        cout << "Error opening file." << endl;
        return 0;
    }
    // Example usage:
    Matrix mat1;
    cout << "Enter values for Matrix 1:" << endl;
    mat1.readFromStdin(infile);
    cout << "Matrix 1:" << endl;
    mat1.display();
    Matrix mat2;
    cout << "Enter values for Matrix 2:" << endl;
    mat2.readFromStdin(infile);
    cout << "Matrix 2:" << endl;
    mat2.display();
    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();
    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();
    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;
    mat1.swapRows(0, 2);
    cout << "Matrix 1 after swapping rows:" << endl;
    mat1.display();
    return 0;
}