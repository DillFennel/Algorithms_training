#include <vector>
#include <iostream>

using namespace std;

bool check(const string& stringToCheck, const string& templateString, string::const_iterator str_itr, string::const_iterator temp_itr){
    bool check_result;
    while(temp_itr != templateString.end() && str_itr != stringToCheck.end()){
        switch(*temp_itr){
            case '*':
                temp_itr++;
                check_result = check(stringToCheck, templateString, str_itr, temp_itr);
                while(str_itr != stringToCheck.end() && !check_result){
                    str_itr++;
                    check_result = check(stringToCheck, templateString, str_itr, temp_itr);
                }
                if(check_result){
                    return true;
                }
                else{
                    return false;
                }
                break;
            case '?':
                if(str_itr == stringToCheck.end()){
                    return false;
                }
                else{
                    temp_itr++;
                    str_itr++;
                }
                break;
            default:
                if(*temp_itr == *str_itr){
                    temp_itr++;
                    str_itr++;
                }
                else{
                    return false;
                }
        }
    }
    if(str_itr == stringToCheck.end()){
        if(temp_itr == templateString.end()){
            return true;
        }
        if(*temp_itr == '*'){
            temp_itr++;
            if(temp_itr == templateString.end()){
                return true;
            }
        }
        return true;
    }
    return false;
}

bool stringMatchesTemplate(const string& stringToCheck, const string& templateString) {
    if(templateString.empty()){
        return (stringToCheck.empty());
    }
    auto str_itr = stringToCheck.begin(), temp_itr = templateString.begin();
    return check(stringToCheck, templateString, str_itr, temp_itr);
}

int main() {
    string templateString;
    cin >> templateString;
    string stringToCheck;
    cin >> stringToCheck;

    if (stringMatchesTemplate(stringToCheck, templateString)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}