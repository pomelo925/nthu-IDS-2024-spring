// https://acm.cs.nthu.edu.tw/contest/2991/#problem14289

#include <bits/stdc++.h>
using namespace std;

const char DIRECTIONS[4] = {'U', 'R', 'L', 'D'};
const int DIR[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

int main() {
    int width, length;
    cin >> width >> length;

    Point start(0, 0), finish(0, 0);
    vector<vector<char>> maze(width+2, vector<char>(length+2, '#'));

    for(int i = 1; i <= width; i++) {
        for(int j = 1; j <= length; j++) {
            cin >> maze[i][j];
            if(maze[i][j] == 'A') start = Point(i, j);
            if(maze[i][j] == 'B') finish = Point(i, j);
        }
    }

    queue<Point> q;
    q.push(start);

    while(!q.empty()) {
        Point current = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            Point next(current.x + DIR[i][0], current.y + DIR[i][1]);
            if(maze[next.x][next.y] == '.') {
                maze[next.x][next.y] = i;
                q.push(next);
            }
            else if(maze[next.x][next.y] == 'B') {
                maze[next.x][next.y] = i;
                break;
            }
        }
    }

    if(maze[finish.x][finish.y] == 'B') {
        cout << "NO" << endl;
        return 0;
    }

    vector<char> path;
    Point iter(finish.x, finish.y);

    while(maze[iter.x][iter.y] != 'A') {
        int d = maze[iter.x][iter.y];
        path.push_back(DIRECTIONS[d]);
        iter.x -= DIR[d][0];
        iter.y -= DIR[d][1];
    }

    cout << "YES" << endl;
    cout << path.size() << endl;
    return 0;
}