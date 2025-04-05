#include <iostream>
#include <vector>
#include <queue>


struct Building {
    int needCapital;
    int addedCapital;

    Building(int c, int p) {
        needCapital = c;
        addedCapital = p;
    }
};


long long getMaxFinalCapital(const std::vector<Building>& buildings, int m, int k) {
    long long result = m;
    if(k==0 || buildings.empty()){
        return result;
    }
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int, int>>> builds;
    for(auto b: buildings){
        builds.push({b.needCapital, b.addedCapital});
    }
    std::priority_queue<int> plus_money;
    while(k!=0 && !(builds.empty() && plus_money.empty()) ){
        while(!(builds.empty()) && builds.top().first <= result){
            plus_money.push(builds.top().second);
            builds.pop();
        }
        if(plus_money.empty() || plus_money.top() <= 0){
            break;
        }
        result += plus_money.top();
        plus_money.pop();
        k--;
    }
    return result;
}


std::vector<Building> readBuildings(int n) {
    std::vector<Building> buildings;
    for (int i = 0; i < n; i++) {
        int c, p;
        std::cin >> c >> p;
        buildings.push_back(Building(c, p));
    } 
    return buildings;
}

int main() {
        int n;
        std::cin >> n;
        int k;
        std::cin >> k;
        std::vector<Building> buildings = readBuildings(n);
        int M;
        std::cin >> M;
        std::cout << getMaxFinalCapital(buildings, M, k) << std::endl;
}