#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<pair<int, int>> findPath(const vector<vector<int>>& grid, pair<int, int> src, pair<int, int> dst) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    unordered_map<int, pair<int, int>> parent;

    vector<pair<int, int>> directions = { {-1,0}, {1,0}, {0,-1}, {0,1} }; // up, down, left, right

    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = true;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        if (x == dst.first && y == dst.second) {
            break;
        }

        for (size_t i = 0; i < directions.size(); i++) {
            int dx = directions[i].first;
            int dy = directions[i].second;
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
                grid[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                parent[nx * cols + ny] = current;
                q.push(make_pair(nx, ny));
            }
        }
    }

    // Reconstruct path from destination to source
    vector<pair<int, int>> path;
    pair<int, int> current = dst;

    while (current != src) {
        path.push_back(current);
        if (parent.find(current.first * cols + current.second) == parent.end()) {
            // No path found (shouldn't happen if path is guaranteed)
            return {};
        }
        current = parent[current.first * cols + current.second];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 1, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}
    };

    pair<int, int> src = make_pair(0, 0);
    pair<int, int> dst = make_pair(3, 3);

    vector<pair<int, int>> path = findPath(grid, src, dst);

    if (path.empty()) {
        cout << "No path found." << endl;
    }
    else {
        cout << "Path:" << endl;
        for (size_t i = 0; i < path.size(); i++) {
            cout << "(" << path[i].first << ", " << path[i].second << ") ";
        }
        cout << endl;
    }

    return 0;
}

