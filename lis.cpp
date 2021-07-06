#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> cache;
int N;

int solve(int start, vector<int>& lis) {
    int cacheSize = 1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < cacheSize;) {
            if (lis[i] <= cache[j]) {
                cache[j] = lis[i];
                break;
            }
            else {
                ++j;
                if (cacheSize == j) {
                    ++cacheSize;
                }
            }
        }
    }

    return cacheSize;
}

int main() {
    int numTestCase;
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; ++i) {
        cin >> N;

        cache.assign(500, 1000000);

        vector<int> lis(N);
        for (int j = 0; j < N; ++j) {
            cin >> lis[j];
        }
        
        cout << solve(0, lis) << endl;
    }
    
    return 0;
}