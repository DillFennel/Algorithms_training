#include <iostream>
#include <set>

using namespace std;

string convertToGoodString(const string& probablyBadString) {
    if(probablyBadString.size() < 2){
        return probablyBadString;
    }
    set<int, greater<int>> good_coords;
    for(int i=0; i<probablyBadString.size(); i++){
        good_coords.insert(i);
    }
    int left = 0, right = 1;
    set<int>::iterator new_left;
    while(right < probablyBadString.size()){
        if( tolower(probablyBadString[left]) == tolower(probablyBadString[right]) && probablyBadString[left] != probablyBadString[right]){ // Символы нужно удалить
            good_coords.erase(left);
            good_coords.erase(right);

            right++;
            new_left =  good_coords.upper_bound(left);
            if(new_left == good_coords.end()){ // Левее элементов не осталось
                left = right;
                right++;
            }
            else{
                left = *new_left;
            }     
        }
        else{ // Текущие элементы удалять не нужно
            left = right;
            right ++;
        }
    }
    string result;
    for(auto i: good_coords){
        result = probablyBadString[i] + result;
    }
    return result;
}   

int main() {
    string probablyBadString;
    cin >> probablyBadString;
    cout << convertToGoodString(probablyBadString);
} 