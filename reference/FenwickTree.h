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
// arrays and subarrays. Sadly, it is too complex to implement a single
// class for a general n dimensions, and each class for now is seperate.

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

    int queryRange(int from, int to) {
        return query(to) - query(from - 1);
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
        return query(x2, y2) - query(x2, y1 - 1) 
        - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
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
        return query(x2, y2, z2) - query(x2, y2, z1 - 1) 
        - query(x2, y1 - 1, z2) - query(x1 - 1, y2, z2)
             + query(x2, y1 - 1, z1 - 1) + query(x1 - 1, y2, z1 - 1) 
             + query(x1 - 1, y1 - 1, z2) - query(x1 - 1, y1 - 1, z1 - 1);
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


#endif