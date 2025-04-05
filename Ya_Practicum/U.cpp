#include <iostream>
#include <vector>

using namespace std;

void outputAnswer(const vector<string>& sequences) {
    for (const string& sequence : sequences) {
        cout << sequence << endl;
    }
}

vector<string> generateSequences(int n) {
    if(n%2 != 0 || n==0 || n==NULL){
        return {};
    }

    static string posled; // Нагенерированная строка
    static vector<int> pre_open (n); // Список, где по позиции символа в последовательности храним, на какой позиции была предыдущая открытающая скобка;
    static int last_open = -1; // Индекс последней незакрытой скобки
    
    vector<string> result; // Список результатов
    vector<string> new_result;

    if(posled.size() == n){ // Если больше скобок нельзя поставить
        if(last_open == -1){
            return {posled};
        }
        return {};
    }

    if(last_open == -1 || posled[last_open] != '['){ // Так как мы не можем ставить внутрь квадратных скобок круглые
        //Предположим, поставим на последнее место (
        posled.push_back('(');
        pre_open[posled.size()-1] = last_open;
        last_open = posled.size()-1;
        new_result = generateSequences(n);
        result.insert(result.end(), new_result.begin(), new_result.end());
        posled.pop_back();
        last_open = pre_open[posled.size()];
    }

    //Предположим, поставим на последнее место [
    posled+="[";
    pre_open[posled.size()-1] = last_open;
    last_open = posled.size()-1;
    new_result = generateSequences(n);
    result.insert(result.end(), new_result.begin(), new_result.end());
    posled.pop_back();
    last_open = pre_open[posled.size()];

    //Попробуем закрыть скобку
    if(last_open != -1){
        if(posled[last_open] == '('){
            posled+=")";
            pre_open[posled.size()-1] = last_open;
            last_open = pre_open[last_open];
            new_result = generateSequences(n);
            result.insert(result.end(), new_result.begin(), new_result.end());
            posled.pop_back();
            last_open = pre_open[posled.size()-1];
        }
        if(posled[last_open] == '['){
            posled+="]";
            pre_open[posled.size()-1] = last_open;
            last_open = pre_open[last_open];
            new_result = generateSequences(n);
            result.insert(result.end(), new_result.begin(), new_result.end());
            posled.pop_back();
            last_open = pre_open[posled.size()-1];
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    outputAnswer(generateSequences(n));
}