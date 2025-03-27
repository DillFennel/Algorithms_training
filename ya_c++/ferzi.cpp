#include <iostream>
#include <math.h>

using namespace std;

#define can_move(x1, y1, x2, y2) (x1 == x2 || y1 == y2 || abs(x1-x2) == abs(y2-y1))

int main(){
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<(can_move(x1, y1, x2, y2) ? "YES" : "NO" );
}