#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 987654321;

vector<vector<int>> clocksOnSwitch({
    {0, 1, 2},
    {3, 7, 9, 11}, 
    {4, 10, 14, 15}, 
    {0, 4, 5, 6, 7}, 
    {6, 7, 8, 10, 12}, 
    {0, 2, 14, 15}, 
    {3, 14, 15},
    {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5}, 
    {3, 4, 5, 9, 13}
});

void setTime(int type, int delta, vector<int>& clocks) {
    for (int i = 0; i < clocksOnSwitch[type].size(); i++) {
        int cur = clocksOnSwitch[type][i];
        clocks[cur] = (clocks[cur] + delta + 4) % 4;
    }
}

int solve(int type, int n, vector<int>& clocks) {
    int result = INF;
    
    int start;
    for (start = 0; start < clocks.size(); start++) {
        if (clocks[start] != 0)
            break;
    }
    if (start == clocks.size())
        return n;
        
    if (type == 10)
        return INF;
    
    for (int num = 0; num < 4; ++num) {
        setTime(type, num, clocks);
        result = min(result, solve(type + 1, n + num, clocks));
        setTime(type, -num, clocks);
    }
    
    return result;
}

int main()
{
    int numTestCase;
    
    cin >> numTestCase;
    for (int i = 0; i < numTestCase; ++i) {
        vector<int> clocks(16, 0);
        int answer = 0;
        
        for (int j = 0; j < 16; ++j) {
            cin >> clocks[j];
            clocks[j] = (clocks[j]/3) % 4;
        }
        
        answer = solve(0, 0, clocks);
        if (answer == INF)
            cout << -1 << endl;
        else
            cout << answer << endl;
    }
    
    return 0;
}
