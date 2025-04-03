#include <iostream>
#include <vector>

using namespace std;

int func(const vector<double> inp, double k){
	double n = inp.size();
    if(k == 0 || inp.empty()){
        return 0;
    }
    double cur_sum = 0, min_sum = 0, all_sum = 0;
    for (int i = 0; i< n-k; i++){
        cur_sum += inp[i];
        all_sum += inp[i];
    }
    min_sum = cur_sum;
    for(int i = n-k; i<inp.size(); i++){
        cur_sum -= inp[i-n+k];
        cur_sum += inp[i];
        all_sum += inp[i];
        if(cur_sum < min_sum){
            min_sum = cur_sum;
        }
    }
    return all_sum - min_sum;
}


int main(){
    double n, k;
    cin >> n >> k;
    vector<double> inp (n);
    for(int i=0; i<n; i++){
        cin >> inp[i];
    }
    cout << func(inp, k);
    return 0;
}