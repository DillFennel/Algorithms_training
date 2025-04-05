#include <iostream>
#include <vector>
#include <unordered_map>

//#include "solution.h"

//using namespace std;

struct Node {
    int val;
    std::vector<Node*> neighbours;
    Node(int val_) {
        val = val_;
        neighbours = {};
    }
};

Node* cloneGraph(Node* node) {
    if(!(node)){
        return {};
    }
    static std::unordered_map<Node*, Node*> already_checked; // Множество уже скопированных вершин
    Node* new_node = new Node(node->val);
    already_checked.insert(node, new_node);
    for(auto child: node->neighbours){
        if(already_checked.find(child) == already_checked.end()){ // Если еще не копировали вершину
            new_node->neighbours.push_back(cloneGraph(child));
        }
        else{
            new_node->neighbours.push_back(already_checked.at(child));
        }
    }
    return new_node;
}

