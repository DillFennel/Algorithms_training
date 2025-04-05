#include <vector>
#include <iostream>
#include <queue>

using namespace std;

long long getEnergyForUnion(const vector<int>& stones) {
    if(stones.empty() || stones.size() == 1){
        return 0;
    }
    priority_queue<int, vector<int>, greater<int>> kuchki;
    for(auto i: stones){ // O(n) -> Общая сложность = O(nlogn)
        kuchki.push(i); // O(logn)
    }
    int result = 0;
    int kucha_1, kucha_2;
    while(kuchki.size() > 1){ // O(n)
        kucha_1 = kuchki.top(); // O(1)
        kuchki.pop(); // O(logn)
        kucha_2 = kuchki.top(); // O(1)
        kuchki.pop(); // O(logn)
        result += kucha_1+kucha_2;
        kuchki.push(kucha_1+kucha_2); // O(logn)
    }
    /*
    Итог: 
    Сначала создаем приоритетную очередь, туда заносим все кучи
    Делается это за O(nlogn)
    Потом пока в очереди больше одной кучки
    Берем две минимальные кучки, суммируем - это энергия на этом шаге
    Добавляем энергию на этом шаге к результату
    Кладем сумму кучки в очередь
    */
    return result;
}

vector<int> readList(int n) {
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> stones = readList(n);

    cout << getEnergyForUnion(stones);
}