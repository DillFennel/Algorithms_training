#include <iostream>
#include <unordered_map>

using namespace std;


int convertToArabic(const string& romanNumber) {
    if(romanNumber.size() == 0){
        return 0;
    }
    unordered_map<char, int> alphabet = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    if(romanNumber.size() == 1){
        return alphabet[romanNumber[0]];
    }
    unordered_map<char, bool> VLD = { // Встречалось ли уже число
        {'V', 0},
        {'L', 0},
        {'D', 0}
    };
    int count = 1, result = 0;
    int pre_val = alphabet[romanNumber[0]], cur_val;
    if(VLD.find(romanNumber[0]) != VLD.end()){
        VLD[romanNumber[0]]=true;
    }
    for(int i=1; i<romanNumber.size(); i++){
        if(i<romanNumber.size()-1 && alphabet[romanNumber[i-1]] < alphabet[romanNumber[i]] && romanNumber[i-1] == romanNumber[i+1] && romanNumber[i] != romanNumber[i-1]){
            return -1;
        }
        if(VLD.find(romanNumber[i]) != VLD.end()){ // Проверка, что VLD вчтречается не более одного раза
            if(VLD[romanNumber[i]]){
                return -1;
            }
            VLD[romanNumber[i]] = true;
        }
        if(romanNumber[i] == romanNumber[i-1]){ // Проверка, что число не может идти больше трех раз подряд
            count++;
            if(count > 3){
                return -1;
            }
        }
        cur_val = alphabet[romanNumber[i]];
        if(pre_val != 0 && pre_val < cur_val){
            result += cur_val - pre_val;
            cur_val = 0;
        }
        else{
            result += pre_val;
        }
        pre_val = cur_val;
    }
    result += pre_val;
    return result;
}

int main() {
    string romanNumber;
    cin >> romanNumber;
    cout << convertToArabic(romanNumber);
}