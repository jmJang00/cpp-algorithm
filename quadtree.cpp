#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string solve(int& num, string& compressed) {
    if (compressed == "w" || compressed == "b")
        return compressed;
    
    ++num;
    vector<string> part(4);
    for (int i = 0; i < 4; ++i) {
        if (compressed[num] == 'x') {
            part[i] = solve(num, compressed);
        }
        else {
            part[i] += compressed[num];
            ++num;
        }
    }
    
    return "x" + part[2] + part[3] + part[0] + part[1];
}

int main()
{
    int numTestCase;
    
    cin >> numTestCase;
    for (int i = 0; i < numTestCase; ++i) {
        string compressed;
        int num = 0;
        cin >> compressed;
        
        cout << solve(num, compressed) << endl;
    }
    
    return 0;
}
