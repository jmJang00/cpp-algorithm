#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int cache[101][101];
string W, S;

bool solve(int w, int s) {
    int ret = 0;
    
    if (cache[w][s] != -1) {
        return cache[w][s];
    }

    while (w < W.length() && s < S.length()) {
        if (W[w] == '*')
            break;
        else if (W[w] == '?' || W[w] == S[s]) {
            ++w;
            ++s;
        }
        else {
            return false;
        }
    }

    if (w == W.length() && s < S.length())
        return false;

    for (int i = 0; i + s < S.length(); ++i) {
        if (w + 1 < W.length() && W[w+1] == S[s])
            solve(w, s); // TODO
    }

    return ret;
}

int main()
{
    int numTestCase;
    
    cin >> numTestCase;
    for (int i = 0; i < numTestCase; ++i) {
        cin >> W;
        
        int numTarget;
        cin >> numTarget;
        
        memset(cache, -1, sizeof(int) * 101 * 101);
        
        for (int i = 0; i < numTarget; ++i) {
            cin >> S;
            cout << solve(0, 0) << endl;
        }
    }
    
    return 0;
}