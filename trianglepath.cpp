#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int>> triangle;
int cache[100][100];

int solve(int row, int col) {
    int& ret = cache[row][col];

    if (ret != -1)
        return cache[row][col];
    
    if (row + 1 == triangle.size())
        return ret = triangle[row][col];

    ret = max(solve(row+1, col), solve(row+1, col+1)) + triangle[row][col];

    return ret;
}

int main() {
    int numTestCase;
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; ++i) {
        int sideLength;
        cin >> sideLength;

        triangle.clear();
        triangle.assign(sideLength, vector<int>());
        memset(cache, -1, sizeof(int) * 10000);

        for (int j = 0; j < sideLength; ++j) {
            for (int k = 0; k < j + 1; ++k) {
                int num;
                cin >> num;
                triangle[j].push_back(num);
            }
        }

        cout << solve(0, 0) << endl;
    }
    
    return 0;
}