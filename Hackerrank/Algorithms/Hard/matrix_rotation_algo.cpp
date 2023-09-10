/*
    Website: Hackerank
    Difficulty: Hard
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/matrix-rotation-algo/problem
*/


#include <bits/stdc++.h>

using namespace std;

// It is always possible to rotate the matrix because
// the smaller of the two dimensions is always even, so
// we can always make a 2 by k square in the middle.
// Now note that the number of squares will always be
// the smaller dimension/2, and the smallest square will be
// 2 * k where k is 2 + bigger dimension - smaller dimension.
// Each square after the smallest just adds 2 to both its
// dimensions. The total perimeter of the squares can thus
// always be gotten.

// Moreover, we can always apply (r mod perimeter) of the
// square rotations instead of r, as the rotation
// perimeter-times leaves the square as is. So we only
// need to do, at most, m*n moves in mapping our data.
// This is because we have m*n entries, and if we flatten
// our squares into arrays, we can just swap their indeces,
// using the % square size operator to create a circular
// shift, and to avoid having to work with a large r.  

// We use a struct yo save the flattened squares, which, for later
// recalls where each element of the square was in the original matrix
struct flatSquareElement {
    long value;
    long originalRow;
    long originalColumn;
};

// This function returns a square in the matrix, with
// a specific number, starting with square 1, which is the
// one in the middle, and ending at square (smallerDimension/2)
// which is the outer one. It returns it as a 1D array 
// starting at the top right corner and going counter clockwise.
vector<flatSquareElement> returnSquare(vector<vector<long>>& matrix, long n) {

    long verticalSide, horizontalSide;
    // If horizontal side is longer
    if (matrix.size() < matrix[0].size()) {
        verticalSide = n * 2;
        horizontalSide = matrix[0].size() - matrix.size() + verticalSide;
    }
    // Else if vertical side is longer
    else if (matrix.size() > matrix[0].size()) {
        horizontalSide = n * 2;
        verticalSide = matrix.size() - matrix[0].size() + horizontalSide;
    }
    else {
        verticalSide = horizontalSide = n * 2;
    }

    // In counter clockwise order
    vector<flatSquareElement> square;

    // Start coordinate at the top right of this square
    long startRow = (matrix[0].size() - horizontalSide) / 2; // Always an integer
    long startColumn = (matrix.size() - verticalSide) / 2; // Also an integer

    // Gets verticalSide - 1 elements 
    for (long i = 0; i < verticalSide - 1; i++) {
        square.push_back({
            matrix[startRow][startColumn],
            startRow,
            startColumn
            });
        startRow++;
    }
    // Gets Horizontal - 1 elements 
    for (long i = 0; i < horizontalSide - 1; i++) {
        square.push_back({
            matrix[startRow][startColumn],
            startRow,
            startColumn
            });
        startColumn++;
    }
    // Gets Vertical - 1 elements 
    for (long i = 0; i < verticalSide - 1; i++) {
        square.push_back({
            matrix[startRow][startColumn],
            startRow,
            startColumn
            });
        startRow--;
    }
    // Gets Horizontal - 1 elements 
    for (long i = 0; i < horizontalSide - 1; i++) {
        square.push_back({
            matrix[startRow][startColumn],
            startRow,
            startColumn
            });
        startColumn--;
    }

    return square;
}

// This function takes the array of flattened squares in
// counter clockwise order (shifted) and turns them into 
// a 2D array matrix again. Basically reverse the last function.
// It also takes the dimensions we want the matrix to be in.
// Because we saved the original position of each element,
// This won't be hard.
vector<vector<long>> returnMatrix(vector<vector<flatSquareElement>>& squares,
    long m, long n) {

    vector<vector<long>> matrix(m, vector<long>(n, 0));

    for (long i = 0; i < squares.size(); i++) {
        for (long j = 0; j < squares[i].size(); j++)
            // Because the entries changed but the originalRow and
            // originalColumn values remained the same, but the 
            // value of the element was shifted, we just automatically
            // rebuild it
            matrix[squares[i][j].originalRow][squares[i][j].originalColumn]
            = squares[i][j].value;
    }

    return matrix;
}

int main() {

    long m, n, r;
    cin >> m >> n >> r;

    vector<vector<long>> matrix(m, vector<long>(n, 0));

    for (long i = 0; i < m; i++) {
        for (long j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Number of squares in the matrix as explained earlier is
    // the smaller dimension / 2
    long num = min(n, m)/2; // Always an integer

    vector<vector<flatSquareElement>> shiftedSquares;

    // Gets every square from inside to out and shifts them
    for (long i = 1; i <= num; i++) {

        vector<flatSquareElement> square = returnSquare(matrix, i);
        vector<flatSquareElement> shifted(square.size());
        // Shift them
        // Note that when we place the shifted element
        // In the new vector, we only change the actual
        // numerical entry, but keep the originalRow and originalColumn
        // in the same place in the array, so that we can rebuild the
        // matrix, but with just the entry values shifted
        for (long j = 0; j < square.size(); j++) {
            // Same originalRow and originalColumn
            shifted[(j + r) % square.size()]
                = square[(j + r) % square.size()];
            // Shifts the entry only
            shifted[(j + r) % square.size()].value = square[j].value;
        }
        shiftedSquares.push_back(shifted);
    }

    vector<vector<long>> newMatrix = returnMatrix(shiftedSquares, m, n);

    for (long i = 0; i < m; i++) {
        for (long j = 0; j < n; j++) {
            cout << newMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

