#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int getLongestIncreasingPath(int n, int m, const vector<vector<int>>& matrixs) {
    if( n <= 0 || m <= 0){
        return 0;
    }
    int max_path = 0;
    priority_queue< pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > to_go; // Приоритетная очередь для сортировки всех клеток
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            to_go.push({matrixs[y][x], {y, x}});
        }
    }
    vector<vector<int>> checked (n, vector<int>(m, 0));
    int y, x;
    int curr_max;
    pair<int, int> moves[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // Все возможные ходы
    while(!(to_go.empty())){ // Пока есть неразобранные клетки
        curr_max = 1;
        y = to_go.top().second.first;
        x = to_go.top().second.second;
        for(auto move: moves){ // Для всех возможных ходов
            if(y+move.first >= 0 && y+move.first<n && x+move.second >= 0 && x+move.second < m && matrixs[y+move.first][x+move.second] < matrixs[y][x]){ // Можем сходить отсюда
                if(curr_max < checked[y+move.first][x+move.second]+1){
                    curr_max = checked[y+move.first][x+move.second]+1;
                }
            }
        }
        checked[y][x] = curr_max;
        if(curr_max > max_path){
            max_path = curr_max;
        }
        to_go.pop();
    }
    
    return max_path;
}

int readInt() {
    int x;
    cin >> x;
    return x;
}

vector<int> readList(int n) {
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    return res;
}

vector<vector<int>> readMatrix(int n, int m) {
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        matrix[i] = readList(m);
    }
    return matrix;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix = readMatrix(n, m);
    cout << getLongestIncreasingPath(n, m, matrix);
}