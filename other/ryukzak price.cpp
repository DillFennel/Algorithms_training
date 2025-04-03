#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

long long func(int n, int k, const vector<int>& weights, const vector<int>& prices) { // O(n*2k) = O(nk)
	int prev_layer[k+1], curr_layer[k+1];
    for(int i=0; i<k+1; i++){
        prev_layer[i] = 0;
    }
    for(int w=0; w<weights.size(); w++){ // O(n)
        for(int i=0; i<k+1; i++){ // O(k)
            if(i>=weights[w]){
                curr_layer[i] = max(prev_layer[i], prev_layer[i-weights[w]] + prices[w]);
            }
            else{
                curr_layer[i] = prev_layer[i];
            }
        }
        for(int i=0; i<k+1; i++){ // O(k)
            prev_layer[i] = curr_layer[i];
        }
    }
    int max_price = 0;
    for(int i=0; i<k+1; i++){
        if(prev_layer[i] > max_price){
            max_price = prev_layer[i];
        }
    }
    return max_price;
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

int main() {
    int n = readInt(), k=readInt();
    vector<int> numbers = readList(n);
    vector<int> prices = readList(n);
    cout << func(n, k, numbers, prices);
}