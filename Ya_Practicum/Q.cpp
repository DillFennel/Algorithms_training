#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;

    Point(int x, int y): x(x), y(y) {
    }
};


bool isOnOneLine(const vector<Point>& points) {
    if(points.size() <= 2){
        return 1;
    }
    // Изначальная точка всегда с индексом ноль. Вторую вибираем так, чтобы она не совпала
    int i=1;
    while(points[0].x == points[i].x && points[0].y == points[i].y){ // Ищем такую точку, чтобы она не совпадала с первой точкой
        if(i == points.size()-1){
            return true; // Если мы обошли все точки и все они совпали, то все они точно лежат на одной прямой
        }
        i++;
    }
    long long del_x, del_y, cur_y, cur_x; // исходное k = del_y/del_x
    del_x = points[i].x -  points[0].x;
    del_y = points[i].y - points[0].y;
    int x0 = points[0].x, y0 = points[0].y;
    i++; // Теперь i - первая из непроверенных точек. Но она может быть и концом списка
    for( ;i<points.size(); i++){
        if(points[i].x == x0 && points[i].y == y0){
            continue;
        }
        cur_y = points[i].y - y0;
        cur_x = points[i].x - x0;
        if(del_y*cur_x != del_x*cur_y){
            return false;
        }
        if(y0*del_x-del_y*x0 != points[i].y*del_x-del_y*points[i].x){
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<Point> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back(Point(x, y));
    }
    if (isOnOneLine(points)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}