#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


long long getNumberOfGoodPairs(int n, const vector<int>& numbers) {
	if (n <= 1){
    	return 0;
	}
    unordered_map <int, int> prev_ost;
	int result = 0;
	for(int i = 0; i<n; i++){
    	if(prev_ost.find(numbers[i]%200) == prev_ost.end()){
        	prev_ost[numbers[i]%200] = 1;
        }
    	else{	
        	result += prev_ost[numbers[i]%200];
            prev_ost[numbers[i]%200]++;
    	}
    }
    return result;
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
    int n = readInt();
    vector<int> numbers = readList(n);
    cout << getNumberOfGoodPairs(n, numbers);
}