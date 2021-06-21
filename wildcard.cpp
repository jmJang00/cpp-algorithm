#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int cache[101][101];
string W, S;

int solve(int w, int s) {
    int& ret = cache[w][s];
    
    if (ret != -1) {
        return ret;
    }

    while (w < W.length() && s < S.length() && (W[w] == '?' || W[w] == S[s])) {
        ++w;
        ++s;
    }

    if (w == W.length())
        return ret = (s == S.length());

    if (W[w] == '*') {
        for (int i = 0; i + s <= S.length(); ++i) {
            if (solve(w+1, s+i) == 1)
                return ret = 1;
        }
    }

    return ret = 0;
}

int main()
{
    int numTestCase;
    
    cin >> numTestCase;
    for (int i = 0; i < numTestCase; ++i) {
        cin >> W;
        
        int numTarget;
        cin >> numTarget;
        vector<string> targets;
        
        for (int i = 0; i < numTarget; ++i) {
            memset(cache, -1, sizeof(int) * 101 * 101);
            cin >> S;
            if (solve(0, 0))
                targets.push_back(S);
        }

        sort(targets.begin(), targets.end());
        
        for (auto p: targets) cout << p << endl;
    }
    
    return 0;
}