#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Vertex {
    int left;
    int right;

    Vertex(int left, int right) : left(left), right(right) {
    }
};


vector<int> getTreeBorder(const vector<Vertex>& tree, int root) { // O(n)
    if(tree.empty()){
        return {};
    }
    vector<int> boarder_nodes;
    list<int> pre_layer, next_layer;
    pre_layer.push_back(root);
    while(!(pre_layer.empty())){ // O(кол-во слоев)
        boarder_nodes.push_back(pre_layer.front()); // Заносим самую левую вершину
        for(auto node: pre_layer){ // O(длина слоя)
            if(tree[node].left==-1 && tree[node].right==-1 && node != pre_layer.front() && node != pre_layer.back()){ // Если у вершины нет детей и она не крайняя в ряду (их и так добавим)
                boarder_nodes.push_back(node);
                continue;
            }
            if(tree[node].left != -1){
                next_layer.push_back(tree[node].left);
            }
            if(tree[node].right != -1){
                next_layer.push_back(tree[node].right);
            }
        }
        if(pre_layer.size() != 1){
            boarder_nodes.push_back(pre_layer.back()); // Заносим самую правую вершину, если она не совпадает с левой
        }
        pre_layer = next_layer;
        next_layer.clear(); // O(длина слоя)
    }
    return boarder_nodes;
}

void outputAnswer(const vector<int>& treeBorder) {
    for (int elem : treeBorder) {
        cout << elem << " ";
    }
    cout << endl;
}

vector<Vertex> readTree(int n) {
    vector<Vertex> tree;
    for (int i = 0; i < n; i++) {
        int left, right;
        cin >> left >> right;
        tree.push_back(Vertex(left, right));
    }
    return tree;
}

int main() {
        int n;
        cin >> n;
        int root;
        cin >> root;
        vector<Vertex> tree = readTree( n);
        outputAnswer(getTreeBorder(tree, root));
}