#include <iostream>
#include <vector>

using namespace std;

class FenwickTreeND {

private:

    vector<int> dimensions;
    // Number of dimensions
    int n;
    vector<int> values;

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


    // Goes from loop depth = 0 to n-1
    // Make sure current is an n sized vector
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


    // Publicly available update function
    void update(vector<int> coordinates, int val){
        vector<int> current(n);
        updateRec(coordinates, val, 0, current);
    }


    // Sum starts at 0 and is returned in the end,
    // it will be filled with the value in the end
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


    // Publicly available query function
    int query(vector<int> coordinates) {
        int sum{};
        vector<int> current(n);
        queryRec(coordinates, 0, sum, current);
        return sum;
    }

    int queryRange(vector<int> from, vector<int> to) {

        int numConfigurations = 1 << n;
        
        int sum{};

        for (int i = numConfigurations - 1; i >= 0; --i) {

            std::vector<bool> config(n);

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


int main() {

    int d;
    cin >> d;

    vector<int> dim(d);
    for (int i = 0; i < d; ++i) {
        cin >> dim[i];
    }

    FenwickTreeND tree(dim);
    int size = tree.getDimensionsProduct();

    for (int i = 0; i < size; ++i) {
        int val;
        cin >> val;
        tree.update(tree.getArrayCoordinate(i), val);
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

        int result = tree.queryRange(l, r);
        cout << result << "\n";
    }

    return 0;
}