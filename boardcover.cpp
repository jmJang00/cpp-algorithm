#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

// X X X    X X X   X X X   X X X
// X O O    X O O   X O X   X O X
// X O X    X X O   O O X   X O O

const int shapes[4][3][2] = {{{0, 1}, {0, 0}, {1, 0}}, {{0, 0}, {1, 0}, {1, 1}}, {{0, 0}, {0, 1}, {-1, 1}}, {{0, 0}, {0, 1}, {1, 1}}};

bool set(int x, int y, int type, int delta, vector<vector<int>>& board) {
    bool ret  = true;
    for (int i = 0; i < 3; ++i) {
        const int tx = x + shapes[type][i][0];
        const int ty = y + shapes[type][i][1];
        
        if (tx < 0 || tx >= board[0].size() || ty < 0 || ty >= board.size())
            return false;
        else if ((board[ty][tx] += delta) > 1)
            ret = false;
    } 
    
    return ret;
}

int solve(vector<vector<int>>& board) {
    int x, y;
    for (y = 0; y < board.size(); ++y) {
        for (x = 0; x < board[0].size(); ++x) {
            if (board[y][x] == 0)
                break;
        }
        if (x != board[0].size())
            break;
    }
    
    if (y == board.size())
        return 1;
    
    int result = 0;
    
    for (int type = 0; type < 4; type++) {
        if (set(x, y, type, 1, board))
            result += solve(board);
        set(x, y, type, -1, board);
    }
    
    return result;
}

int main()
{
    int numTestCase, height, width;
    
    cin >> numTestCase;
    for (int i = 0; i < numTestCase; i++) {
        cin >> height >> width;
        vector<vector<int>> board(height, vector<int>(width, 0));
        
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                char target;
                cin >> target;
                if (target == '#')
                    board[j][k] = 1;
            }
        }
        
        cout << solve(board) << endl;
    }

    return 0;
}
