#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool isAllChecked(vector<bool>& check) {
    for (auto p : check) {
        if (!p) return false;
    }
    return true;
}

int recursion(int n, vector<bool> check, vector<pair<int, int>>& pairedId) {
    if (isAllChecked(check)) return 1;
    
    int result = 0;
    for (int i = n; i < pairedId.size(); i++) {
        if (check[pairedId[i].first] || check[pairedId[i].second]) continue;
        
        check[pairedId[i].first] = true;
        check[pairedId[i].second] = true;
        result += recursion(i, check, pairedId);
        check[pairedId[i].first] = false;
        check[pairedId[i].second] = false;
    }
    
    return result;
}

int main()
{
    int numTestCase, students, pairs;
    
    cin >> numTestCase;
    for (int i = 0; i < numTestCase; i++) {
        vector<pair<int, int>> pairedId;
        cin >> students >> pairs;
        
        vector<bool> check(students, 0);
        for (int j = 0; j < pairs; j++) {
            int pairX, pairY;
            cin >> pairX >> pairY;
            if (pairX > pairY) swap(pairX, pairY);
            pairedId.push_back(make_pair(pairX, pairY));
        }
        
        cout << recursion(0, check, pairedId) << endl;
    }

    return 0;
}
