/*
Задача: Поиск первого вхождения в отсортированном массиве

Дан отсортированный массив nums и число target. Нужно найти индекс первого вхождения target в массиве. Если target нет в массиве, вернуть -1.

Вход: nums = [1, 2, 2, 2, 3, 4, 5], target = 2
Выход: 1  # (первое вхождение 2 на индексе 1)

Вход: nums = [1, 3, 5, 7], target = 2
Выход: -1  # (число 2 отсутствует)

Ограничения
 • 1 ≤ len(nums) ≤ 10^5
 • -10^9 ≤ nums[i], target ≤ 10^9
 • Решение должно быть лучше O(n) (нельзя использовать обычный линейный поиск)

*/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int func(const vector<int> inp, int goal){ //Используем метод бинарного поиска
    if(inp.empty()){
        return -1;
    }
    int l=0, r=inp.size()-1;
    while(l!=r){
        if(inp[(r+l)/2] < goal){
            l = (r+l)/2+1;
        }
        else {
            r = (r+l)/2;
        }
    }
    assert(r==l);
    if(inp[l] == goal){
        return l;
    }
    return -1;
}


int main(){
    cout << func({1, 2, 2, 2, 3, 4, 5},  2) << endl << func({1, 3, 5, 7},  2) << endl <<  func({}, 1) << endl;
    return 0;
}