/*
    Website: IEEEXtreme
    Difficulty: Hard
    Language: c++
    Link: https://csacademy.com/ieeextreme-practice/task/46e8a03f242b875f1ae5fb84a3b4321f/
*/


#include <bits/stdc++.h>

using namespace std;

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
        return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
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


// When summing the elements of an n-dimensional array, we usually have
// 3 methods that can be used:
// Segment trees let us update and retrieve ranges in O(log(n)) time, 
// with the main advantage being that they are not limited to sum queries
// (we can also have min/max queries) and the main disadvantage being that
// they are complex and can't be extended to multiple dimensions, at least not
// easily.
// Another approach is keeping a 2n-dimensional array that records the 
// sum of all combinations of an n-dimensional sub array. This appraoch is
// very fast for retrieval, with O(1) time complexity, but takes too much space,
// takes too much time to build the initial array with O(n^2) time, and
// does not allow us to update the values (or does, but forces us to rebuild
// the affectef portion of the array in O(n) time).
// On the other hand, Fenwick Trees, or Binary Indexed Trees let us retrieve
// values a little bit slower, with O(log(n)) reitrieval, but build the 
// tree in O(nlog(n)) time, which is faster, update a value in O(log(n)) time,
// and only take as much space as the original array, so O(n).
// Even though we don't intend to update values in the array, Fenwick Trees
// provide the best solution to this problem.


int main() {
    int d;
    cin >> d;

    vector<int> dim(d);
    for (int i = 0; i < d; ++i) {
        cin >> dim[i];
    }

    int totalSize = 1;
    for (int i = 0; i < d; ++i) {
        totalSize *= dim[i];
    }

    // Since we don't have a general n dimensional Fenwick tree class,
    // we handle each case individually.
    if (d == 1) {
        FenwickTree1D fenwick(dim[0]);
        vector<int> values(totalSize);

        for (int i = 0; i < dim[0]; ++i) {
            cin >> values[i];
            fenwick.update(i + 1, values[i]);
        }

        int q;
        cin >> q;
        while (q--) {
            vector<int> l(d), r(d);
            for (int i = 0; i < d; ++i) {
                cin >> l[i];
            }
            for (int i = 0; i < d; ++i) {
                cin >> r[i];
            }

            int result = fenwick.queryRange(l[0], r[0]);
            cout << result << "\n";
        }
    }
    else if (d == 2) {
        FenwickTree2D fenwick(dim[0], dim[1]);
        vector<vector<int>> values(dim[0], vector<int>(dim[1]));

        // Read values into a 2D vector
        for (int i = 0; i < dim[0]; ++i) {
            for (int j = 0; j < dim[1]; ++j) {
                cin >> values[i][j];
                fenwick.update(i + 1, j + 1, values[i][j]);
            }
        }

        int q;
        cin >> q;
        while (q--) {
            vector<int> l(d), r(d);
            for (int i = 0; i < d; ++i) {
                cin >> l[i];
            }
            for (int i = 0; i < d; ++i) {
                cin >> r[i];
            }

            int result = fenwick.queryRange(l[0], l[1], r[0], r[1]);
            cout << result << "\n";
        }
    }
    else if (d == 3) {
        FenwickTree3D fenwick(dim[0], dim[1], dim[2]);
        vector<vector<vector<int>>> values(dim[0], 
        vector<vector<int>>(dim[1], vector<int>(dim[2])));

        // Read values into a 3D vector
        for (int i = 0; i < dim[0]; ++i) {
            for (int j = 0; j < dim[1]; ++j) {
                for (int k = 0; k < dim[2]; ++k) {
                    cin >> values[i][j][k];
                    fenwick.update(i + 1, j + 1, k + 1, values[i][j][k]);
                }
            }
        }

        int q;
        cin >> q;
        while (q--) {
            vector<int> l(d), r(d);
            for (int i = 0; i < d; ++i) {
                cin >> l[i];
            }
            for (int i = 0; i < d; ++i) {
                cin >> r[i];
            }

            int result = fenwick.queryRange(l[0], l[1], l[2], r[0], r[1], r[2]);
            cout << result << "\n";
        }
    }
    else if (d == 4) {
        FenwickTree4D fenwick(dim[0], dim[1], dim[2], dim[3]);
        vector<vector<vector<vector<int>>>> values(dim[0], 
        vector<vector<vector<int>>>(dim[1], 
        vector<vector<int>>(dim[2], vector<int>(dim[3]))));

        // Read values into a 4D vector
        for (int i = 0; i < dim[0]; ++i) {
            for (int j = 0; j < dim[1]; ++j) {
                for (int k = 0; k < dim[2]; ++k) {
                    for (int l = 0; l < dim[3]; ++l) {
                        cin >> values[i][j][k][l];
                        fenwick.update(i + 1, j + 1, k + 1, l + 1, values[i][j][k][l]);
                    }
                }
            }
        }

        int q;
        cin >> q;
        while (q--) {
            vector<int> l(d), r(d);
            for (int i = 0; i < d; ++i) {
                cin >> l[i];
            }
            for (int i = 0; i < d; ++i) {
                cin >> r[i];
            }

            int result = fenwick.queryRange(l[0], l[1], l[2], l[3], r[0], r[1], r[2], r[3]);
            cout << result << "\n";
        }
    }
    else if (d == 5) {
        FenwickTree5D fenwick(dim[0], dim[1], dim[2], dim[3], dim[4]);
        vector<vector<vector<vector<vector<int>>>>> 
        values(dim[0], vector<vector<vector<vector<int>>>>(dim[1], 
        vector<vector<vector<int>>>(dim[2], 
        vector<vector<int>>(dim[3], vector<int>(dim[4])))));

        // Read values into a 5D vector
        for (int i = 0; i < dim[0]; ++i) {
            for (int j = 0; j < dim[1]; ++j) {
                for (int k = 0; k < dim[2]; ++k) {
                    for (int l = 0; l < dim[3]; ++l) {
                        for (int m = 0; m < dim[4]; ++m) {
                            cin >> values[i][j][k][l][m];
                            fenwick.update(i + 1, j + 1, k + 1, l + 1, m + 1, values[i][j][k][l][m]);
                        }
                    }
                }
            }
        }

        int q;
        cin >> q;
        while (q--) {
            vector<int> l(d), r(d);
            for (int i = 0; i < d; ++i) {
                cin >> l[i];
            }
            for (int i = 0; i < d; ++i) {
                cin >> r[i];
            }

            int result = fenwick.queryRange(l[0], l[1], l[2], l[3], l[4], 
                r[0], r[1], r[2], r[3], r[4]);
            cout << result << "\n";
        }
    }
        
    return 0;
}