#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

struct Vertex {
    int w;
    int p;

    Vertex(int inp_w, int inp_p) {
        w = inp_w;
        p = inp_p;
    }
};

int getNumberOfUpgoingPaths_NKvadrat(vector<Vertex> tree, int x) { // O(n^2)
    int result = 0;
    int curr_sum, parent;
    for(auto i: tree){ // O(n)
        curr_sum = i.w;
        if(i.w == x){
            result++;
        }
        parent = i.p;
        while(parent != -1){ // O(n)
            curr_sum += tree[parent].w;
            parent = tree[parent].p;
            if(curr_sum == x){
                result++;
            }
        }
    }
    return result;
}

int getNumberOfUpgoingPaths(vector<Vertex> tree, int x) {
    int result = 0;
    unordered_map<int, vector<int>> get_children;
    vector<vector<int>> count_weights (tree.size(), vector<int>(x+1, 0));
    queue<int> to_go;
    for(int i=0; i<tree.size(); i++){ // O(n) -> Итого О(n)
        if(get_children.find(tree[i].p) != get_children.end()){ // O(1)
            get_children[tree[i].p].push_back(i); // O(1)
        }
        else{
            get_children[tree[i].p] = {i}; // O(1)
        }
    }

    for(auto i: get_children[-1]){
        if(tree[i].w <= x){
            count_weights[i][tree[i].w] = 1;
        }
        if(tree[i].w == x){
            result++;
        }
        if(get_children.find(i) != get_children.end()){
            for(auto child: get_children[i]){
                to_go.push(child);
            }
        }
    }
    int curr_verc;
    while(!(to_go.empty())){
        curr_verc = to_go.front();
        to_go.pop();
        for(int i=0; i<x+1; i++){
            if(i-tree[curr_verc].w >= 0){
                count_weights[i]
            }
        }
    }
    return result;
}

vector<Vertex> readTree(int n) {
    vector<Vertex> tree;
    for (int i = 0; i < n; i++) {
        int parent, weight;
        cin >> parent >> weight;
        tree.push_back(Vertex(weight, parent));
    }
    return tree;
}

int main() {
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<Vertex> tree = readTree(n);
    cout << getNumberOfUpgoingPaths(tree, x);

}