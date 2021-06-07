#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solve(vector<int>& fences) {
    int maxSize = 0;
    int maxHeight = *max_element(fences.begin(), fences.end());
    
    for (int h = 1; h <= maxHeight; ++h) {
        int w = 0;
        for (int i = 0; i < fences.size(); ++i) {
            if (fences[i] >= h) ++w;
            else {
                maxSize = max(w * h, maxSize);
                w = 0;
            }
        }
        
        maxSize = max(w * h, maxSize);
    }
    
    return maxSize;
}

int main()
{
    int numTestCase;
    
    cin >> numTestCase;
    for (int i = 0; i < numTestCase; ++i) {
        int numFence;
        cin >> numFence;
        vector<int> fences(numFence);
        
        for (int j = 0; j < numFence; ++j) {
            cin >> fences[j];
        }
        
        cout << solve(fences) << endl;
    }
    
    return 0;
}
