#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int val_, Node* next_) {
        val = val_;
        next = next_;
    }
};

Node* Reverse(Node* head, int left, int right) {
    if(!(head)){
        return {};
    }
    if(right == left){
        return head;
    }
    int count = 1;
    Node* verc = head;
    Node* last_static_node = nullptr;
    if(left > 1){
        for(int i=0; i<left-2; i++){
            verc = verc->next;
        }
        last_static_node = verc;
    }
	Node* pre_verc;
	if(left == 1){
    	pre_verc = head; // Первая изменяемая вершина
    }
	else{
    	pre_verc = last_static_node->next; // Первая изменяемая вершина
    }
    Node* first_edit_node = pre_verc; // Запомним начало разворота, потом привяжем его к началу второго неизменяемого куска
    verc = pre_verc->next; //Первая вершина, у путь которой будем разворачивать
    Node* next_verc;
    for(int i=0; i < right-left; i++){
        next_verc = verc->next;
        verc->next = pre_verc;
        pre_verc = verc;
        verc = next_verc;
    } // В конце pre_verc станет последним изменяемым элементым, а verc - первым неизменяемым элементом во второй части
    if(verc){
        first_edit_node->next = verc;
    }
    if(left == 1){
        return pre_verc;
    }
	last_static_node->next = pre_verc;
    return head;
}

int main(){
    Node *a = new Node(5, nullptr);
    Node *b = new Node(4, a);
    Node *c = new Node(3, b);
    Node *d = new Node(2, c);
    Node *e = new Node(1, d);
    Node* res = Reverse(e, 2, 4);
    return 0;
}