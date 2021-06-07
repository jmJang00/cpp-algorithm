#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solve(int left, int right, vector<int>& fences) {
    if (left == right) return fences[left];
    int mid = (left + right) / 2;
    
    int ret = max(solve(left, mid, fences), solve(mid + 1, right, fences));
    
    int low = mid;
    int high = mid + 1;
    int minHeight = min(fences[low], fences[high]);
    ret = max(ret, minHeight * 2);
    
    while ((left < low) || (right > high)) {
        if ((high < right) && (low == left || fences[low - 1] < fences[high + 1])) {
            ++high;
            minHeight = min(minHeight, fences[high]);
        }
        else {
            --low;
            minHeight = min(minHeight, fences[low]);
        }
        ret = max(ret, minHeight * (high - low + 1));
    }
    
    return ret;
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
        
        cout << solve(0, fences.size() - 1, fences) << endl;
    }
    
    return 0;
}
