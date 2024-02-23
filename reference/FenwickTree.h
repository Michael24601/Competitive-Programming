#ifndef FENWICK_TREE_H
#define FENWICK_TREE_H

#include "bits/stdc++.h"

using namespace std;


// A Binary Indexed Tree, or a Fenwick Tree, allows us to do sum queries for
// a range in an array. It is the equivalent of creating a 2D array to store
// all combinations of range sums, but instead of O(n) updating, O(1) retrieval,
// and O(n^2) space, it has O(n) space and O(log(n)) retrieval and update.
// Moreover, the space that the array occupies grows exponentially the more
// dimensions you add to the array, while the Fenwick tree is always the same
// size as the array itself.
// So while the array approach works when we have a small array and a lot of
// space (and not a whole lot of dimensions), and when we are sure we never
// want to update, the Fenwick tree approach trades a little speed during
// retrieval for better space complexity and the ability to update values.
// Moreover, to build the array initially, it takes O(n^2) time, while
// a Fenwick tree can be built in O(nlog(n)) time (n times log(n) 
// taking updates).

// It is similar to a segment tree, but has its advantages and disadvantages.
// On one hand, unlike a Segment Tree, it only support a single type of
// operation: sums.
// On the other hand, it is easier to implement, and supports N dimensions
// arrays and subarrays.

// Note that the following implementation, by convention and for ease,
// uses 1 indexing, so the first index in a 3D Fenwick tree is (1, 1, 1).


class FenwickTree1D {
private:
    vector<int> bit;
    int size;

public:
    FenwickTree1D(int n) {
        size = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        for (; idx <= size; idx += (idx & -idx)) {
            bit[idx] += val;
        }
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= (idx & -idx)) {
            sum += bit[idx];
        }
        return sum;
    }

    int queryRange(int x1, int x2) {
        int result =  query(x1);
        result -= query(x2 - 1);
        return result;
    }
};



class FenwickTree2D {
private:
    vector<vector<int>> bit;
    int n, m;

public:
    FenwickTree2D(int rows, int cols) {
        n = rows;
        m = cols;
        bit.assign(n + 1, vector<int>(m + 1, 0));
    }

    void update(int x, int y, int val) {
        for (int i = x; i <= n; i += (i & -i)) {
            for (int j = y; j <= m; j += (j & -j)) {
                bit[i][j] += val;
            }
        }
    }

    int query(int x, int y) {
        int sum = 0;
        for (int i = x; i > 0; i -= (i & -i)) {
            for (int j = y; j > 0; j -= (j & -j)) {
                sum += bit[i][j];
            }
        }
        return sum;
    }

    int queryRange(int x1, int y1, int x2, int y2) {
        int result = query(x2, y2);
        result -= query(x2, y1 - 1);
        result -= query(x1 - 1, y2);
        result += query(x1 - 1, y1 - 1);
        return result;
    }
};


class FenwickTree3D {
private:
    vector<vector<vector<int>>> bit;
    int x, y, z;

public:
    FenwickTree3D(int sizeX, int sizeY, int sizeZ) {
        x = sizeX;
        y = sizeY;
        z = sizeZ;
        bit.assign(x + 1, vector<vector<int>>(y + 1, vector<int>(z + 1, 0)));
    }

    void update(int i, int j, int k, int val) {
        for (int a = i; a <= x; a += (a & -a)) {
            for (int b = j; b <= y; b += (b & -b)) {
                for (int c = k; c <= z; c += (c & -c)) {
                    bit[a][b][c] += val;
                }
            }
        }
    }

    int query(int i, int j, int k) {
        int sum = 0;
        for (int a = i; a > 0; a -= (a & -a)) {
            for (int b = j; b > 0; b -= (b & -b)) {
                for (int c = k; c > 0; c -= (c & -c)) {
                    sum += bit[a][b][c];
                }
            }
        }
        return sum;
    }

    int queryRange(int x1, int y1, int z1, int x2, int y2, int z2) {
        int result = query(x2, y2, z2) ;
        result -= query(x2, y2, z1 - 1);
        result -= query(x2, y1 - 1, z2);
        result -= query(x1 - 1, y2, z2);
        result += query(x2, y1 - 1, z1 - 1); 
        result += query(x1 - 1, y2, z1 - 1); 
        result += query(x1 - 1, y1 - 1, z2);
        result -= query(x1 - 1, y1 - 1, z1 - 1);
        return result;
    }
};


class FenwickTree4D {
private:
    vector<vector<vector<vector<int>>>> bit;
    int w, x, y, z;

public:
    FenwickTree4D(int sizeW, int sizeX, int sizeY, int sizeZ) {
        w = sizeW;
        x = sizeX;
        y = sizeY;
        z = sizeZ;
        bit.assign(w + 1, vector<vector<vector<int>>>(x + 1, 
        vector<vector<int>>(y + 1, vector<int>(z + 1, 0))));
    }

    void update(int i, int j, int k, int l, int val) {
        for (int a = i; a <= w; a += (a & -a)) {
            for (int b = j; b <= x; b += (b & -b)) {
                for (int c = k; c <= y; c += (c & -c)) {
                    for (int d = l; d <= z; d += (d & -d)) {
                        bit[a][b][c][d] += val;
                    }
                }
            }
        }
    }

    int query(int i, int j, int k, int l) {
        int sum = 0;
        for (int a = i; a > 0; a -= (a & -a)) {
            for (int b = j; b > 0; b -= (b & -b)) {
                for (int c = k; c > 0; c -= (c & -c)) {
                    for (int d = l; d > 0; d -= (d & -d)) {
                        sum += bit[a][b][c][d];
                    }
                }
            }
        }
        return sum;
    }

    int queryRange(int w1, int x1, int y1, int z1, int w2, int x2, int y2, int z2) {
    int result = query(w2, x2, y2, z2);
    result -= query(w1 - 1, x2, y2, z2);
    result -= query(w2, x1 - 1, y2, z2);
    result -= query(w2, x2, y1 - 1, z2);
    result += query(w1 - 1, x1 - 1, y2, z2);
    result += query(w1 - 1, x2, y1 - 1, z2);
    result += query(w2, x1 - 1, y1 - 1, z2);
    result -= query(w1 - 1, x1 - 1, y1 - 1, z2);
    result -= query(w2, x2, y2, z1 - 1);
    result += query(w1 - 1, x2, y2, z1 - 1);
    result += query(w2, x1 - 1, y2, z1 - 1);
    result += query(w2, x2, y1 - 1, z1 - 1);
    result -= query(w1 - 1, x1 - 1, y2, z1 - 1);
    result -= query(w1 - 1, x2, y1 - 1, z1 - 1);
    result -= query(w2, x1 - 1, y1 - 1, z1 - 1);
    result += query(w1 - 1, x1 - 1, y1 - 1, z1 - 1);
    return result;
}
};

class FenwickTree5D {
private:
    vector<vector<vector<vector<vector<int>>>>> bit;
    int v, w, x, y, z;

public:
    FenwickTree5D(int sizeV, int sizeW, int sizeX, int sizeY, int sizeZ) {
        v = sizeV;
        w = sizeW;
        x = sizeX;
        y = sizeY;
        z = sizeZ;
        bit.assign(v + 1, vector<vector<vector<vector<int>>>>(
            w + 1, vector<vector<vector<int>>>(
                x + 1, vector<vector<int>>(
                    y + 1, vector<int>(z + 1, 0)))));
    }

    void update(int i, int j, int k, int l, int m, int val) {
        for (int a = i; a <= v; a += (a & -a)) {
            for (int b = j; b <= w; b += (b & -b)) {
                for (int c = k; c <= x; c += (c & -c)) {
                    for (int d = l; d <= y; d += (d & -d)) {
                        for (int e = m; e <= z; e += (e & -e)) {
                            bit[a][b][c][d][e] += val;
                        }
                    }
                }
            }
        }
    }

    int query(int i, int j, int k, int l, int m) {
        int sum = 0;
        for (int a = i; a > 0; a -= (a & -a)) {
            for (int b = j; b > 0; b -= (b & -b)) {
                for (int c = k; c > 0; c -= (c & -c)) {
                    for (int d = l; d > 0; d -= (d & -d)) {
                        for (int e = m; e > 0; e -= (e & -e)) {
                            sum += bit[a][b][c][d][e];
                        }
                    }
                }
            }
        }
        return sum;
    }

    int queryRange(int v1, int w1, int x1, int y1, int z1,
        int v2, int w2, int x2, int y2, int z2) {
        int result = query(v2, w2, x2, y2, z2);
        result -= query(v1 - 1, w2, x2, y2, z2);
        result -= query(v2, w1 - 1, x2, y2, z2);
        result -= query(v2, w2, x1 - 1, y2, z2);
        result += query(v1 - 1, w1 - 1, x2, y2, z2);
        result += query(v1 - 1, w2, x1 - 1, y2, z2);
        result += query(v2, w1 - 1, x1 - 1, y2, z2);
        result -= query(v1 - 1, w1 - 1, x1 - 1, y2, z2);
        
        result -= query(v2, w2, x2, y1 - 1, z2);
        result += query(v1 - 1, w2, x2, y1 - 1, z2);
        result += query(v2, w1 - 1, x2, y1 - 1, z2);
        result += query(v2, w2, x1 - 1, y1 - 1, z2);
        result -= query(v1 - 1, w1 - 1, x2, y1 - 1, z2);
        result -= query(v1 - 1, w2, x1 - 1, y1 - 1, z2);
        result -= query(v2, w1 - 1, x1 - 1, y1 - 1, z2);
        result += query(v1 - 1, w1 - 1, x1 - 1, y1 - 1, z2);

        result -= query(v2, w2, x2, y2, z1 - 1);
        result += query(v1 - 1, w2, x2, y2, z1 - 1);
        result += query(v2, w1 - 1, x2, y2, z1 - 1);
        result += query(v2, w2, x1 - 1, y2, z1 - 1);
        result -= query(v1 - 1, w1 - 1, x2, y2, z1 - 1);
        result -= query(v1 - 1, w2, x1 - 1, y2, z1 - 1);
        result -= query(v2, w1 - 1, x1 - 1, y2, z1 - 1);
        result += query(v1 - 1, w1 - 1, x1 - 1, y2, z1 - 1);

        result += query(v2, w2, x2, y1 - 1, z1 - 1);
        result -= query(v1 - 1, w2, x2, y1 - 1, z1 - 1);
        result -= query(v2, w1 - 1, x2, y1 - 1, z1 - 1);
        result -= query(v2, w2, x1 - 1, y1 - 1, z1 - 1);
        result += query(v1 - 1, w1 - 1, x2, y1 - 1, z1 - 1);
        result += query(v1 - 1, w2, x1 - 1, y1 - 1, z1 - 1);
        result += query(v2, w1 - 1, x1 - 1, y1 - 1, z1 - 1);
        result -= query(v1 - 1, w1 - 1, x1 - 1, y1 - 1, z1 - 1);

        return result;
    }
};


// We can generalize the code with an n-dimensional Fenwick Tree.
// Note that although it is easier to work with, it is a little bit
// slower. This is because it has some extra overhead:
// We need to nest the loops n times, so we have to use recursion.
// Moreover, in these recursive update and query functions, we need
// to send a vector (current) by value each time in order to capture
// all the branching coordinates we must change.
// We also need to save the n-dimensional array in a 1D array and convert
// between n-dimensional coordinates and linear coordinates.
// The class is still fast, but marginally slower than the above classes.
// The time complexity is of course still the same.


class FenwickTreeND {

private:

    vector<int> dimensions;
    // Number of dimensions
    int n;
    vector<int> values;

    // Goes from loop depth = 0 to n-1
    // Make sure current is an n sized vector
    // Usually, we would need n nested loops, however, in this case, since
    // n is set at runtime, we can instead use recursion to call the function
    // within each loop up to a depth of n.
    // To keep track of each index in each loop, we have the vector current.
    // which we need to pass by value. 
    void updateRec(vector<int>& coordinates, int val, int loopDepth, 
        vector<int> current) {

        if(loopDepth < n){
            for (int a = coordinates[loopDepth]; a <= dimensions[loopDepth]; a += (a & -a)) {
                current[loopDepth] = a;
                updateRec(coordinates, val, loopDepth + 1, current);
            }
        }
        else if (loopDepth == n){
            values[getLinearCoordinate(current)] += val;
        }
    }


    // Sum starts at 0 and is returned in the end,
    // it will be filled with the value in the end
    // Like the previous function, we need to have n nested loops, so we use
    // recursion, also with a current vector to keep track of the indeces.
    void queryRec(vector<int>& coordinates, int loopDepth, int& sum,
        vector<int> current) {

        if(loopDepth < n){
            for (int a = coordinates[loopDepth]; a > 0; a -= (a & -a)) {
                current[loopDepth] = a;
                queryRec(coordinates, loopDepth + 1, sum, current);
            }
        }
        else if (loopDepth == n){
            sum += values[getLinearCoordinate(current)];
        }
    }

    public:

    FenwickTreeND(vector<int> dimensions) {
        this->dimensions = dimensions;
        n = dimensions.size();
        values.resize(getDimensionsProduct());
    }


    // Nunber of elements according to the dimensions
    int getDimensionsProduct(){
        int product = 1;
        for(int i = 0; i < dimensions.size(); i++){
            product *= dimensions[i];
        }
        return product;
    }


    int getLinearCoordinate(vector<int> coordinate) const {
        if (coordinate.size() != n) {
            // Check if the coordinate has the same number of dimensions as the tree
            throw std::invalid_argument("Coordinate has incorrect dimensions.");
        }

        int linear_index = 0;
        int multiplier = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (coordinate[i] < 1 || coordinate[i] > dimensions[i]) {
                throw std::out_of_range("Coordinate out of bounds.");
            }
            linear_index += (coordinate[i] - 1) * multiplier;
            multiplier *= dimensions[i];
        }

        return linear_index;
    }


    vector<int> getArrayCoordinate(int linear_index) {
        int n = dimensions.size();
        vector<int> coordinate(n);

        int multiplier = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (dimensions[i] <= 0) {
                throw std::invalid_argument("Dimension size must be positive.");
            }
            coordinate[i] = (linear_index % (dimensions[i] * multiplier)) / multiplier + 1;
            multiplier *= dimensions[i];
        }

        return coordinate;
    }


    // Publicly available update function
    void update(vector<int> coordinates, int val){
        vector<int> current(n);
        updateRec(coordinates, val, 0, current);
    }


    // Publicly available query function
    // Note that querying here is always done from the very first n-dimensional
    // coordinate, and spans to the given coordinate.
    int query(vector<int> coordinate) {
        int sum{};
        vector<int> current(n);
        queryRec(coordinate, 0, sum, current);
        return sum;
    }

    // In order to query in a range that doesn't start at the beginning index,
    // we need to use this function, which removes and adds portions starting
    // at the first coordinate in such a way as to give the correct answer.
    int queryRange(vector<int> from, vector<int> to) {

        int numConfigurations = 1 << n;
        
        int sum{};

        for (int i = numConfigurations - 1; i >= 0; --i) {

            vector<bool> config(n);

            for (int j = 0; j < n; ++j) {
                config[j] = (i & (1 << j)) != 0;
            }

            vector<int> newTo (n);
            int countOfFalse{};
            // config is the array
            for(int i = 0; i < n; i++){
                if(config[i]){
                    newTo[i] = to[i];
                }
                else{
                    newTo[i] = from[i] - 1;
                    countOfFalse++;
                }
            }

            // The count of false values in the code indicates if the sign
            // should be + or -. There is always 0 false values in the
            // first iteration, and then after that the sign alternates 
            // with each number of false values.
            if(countOfFalse % 2 == 0)
                sum += query(newTo);
            else
                sum -= query(newTo);
        }

        return sum;
    }
};


#endif