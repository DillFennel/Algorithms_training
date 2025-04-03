#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long func(int n, int k, const vector<int>& numbers) { // O(n*2k) = O(nk)
	bool prev_layer[k+1], curr_layer[k+1];
    prev_layer[0] = 1;
    for(int i=1; i<k+1; i++){
        prev_layer[i] = 0;
    }
    for(auto weight: numbers){ // O(n)
        curr_layer[0] = 1;
        for(int i=1; i<k+1; i++){ // O(k)
            curr_layer[i] = (prev_layer[i] || (i>=weight && prev_layer[i-weight]));
        }
        for(int i=1; i<k+1; i++){ // O(k)
            prev_layer[i] = curr_layer[i];
        }
    }
    int max_i = 0;
    for(int i=0; i<k+1; i++){
        if(prev_layer[i]){
            max_i = i;
        }
    }
    return max_i;
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
    cout << func(n, k, numbers);
}