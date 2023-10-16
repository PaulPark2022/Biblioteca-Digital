#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Node {
private:
    std::string data;
    Node* prev;
    Node* next;
    friend class Functions;
public:    
    Node(const std::string&);
    std::string getData() const;
};

Node::Node(const std::string& value) : data(value), prev(0), next(0) {}

std::string Node::getData() const {
    return data;
}

class Functions {
public:
	Functions();
	void push(const std::string&);
	std::string printList();
	void split(Node*, Node**, Node**);
	Node* merge(Node*, Node*);
	void mergeSort();
	int search(const std::string&);
	bool deleteNode(const std::string&);
private:
    Node* head;
    Node* tail;
};

Functions::Functions() : head(0), tail(0) {}

void Functions::push(const std::string& value) {
        Node* newNode = new Node(value);
        if (head == 0) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
}

std::string Functions::printList() {
        std::stringstream aux;   
        if (head == 0) {
            return "NULL";
        }
        Node* current = head;
        while (current != 0) {
            aux << current->data;
            if (current->next != 0) {
                aux << ", ";
            }
            current = current->next;
        }
        return aux.str();
    }

void Functions::split(Node* source, Node** left, Node** right) {
        Node* slow = source;
        Node* fast = source->next;

        while (fast != 0) {
            fast = fast->next;
            if (fast != 0) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *left = source;
        *right = slow->next;
        slow->next = 0;
        (*right)->prev = 0;
    }

Node* Functions::merge(Node* left, Node* right) {
        if (left == 0) {
            return right;
        }
        if (right == 0) {
            return left;
        }
        
         Node* result = 0;
        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
            result->next->prev = result;
        } else {
            result = right;
            result->next = merge(left, right->next);
            result->next->prev = result;
        }
        return result;
    }

void Functions::mergeSort() {
        if (head == 0 || head->next == 0) {
            return;
        }

        Node* left;
        Node* right;
        split(head, &left, &right);
        
        Functions leftList;
        Functions rightList;
        leftList.head = left;
        leftList.tail = left;
        rightList.head = right;
        rightList.tail = right;

        leftList.mergeSort();
        rightList.mergeSort();

        head = merge(leftList.head, rightList.head);
        tail = rightList.tail;

}

int Functions::search(const std::string& value) {
        Node* current = head;
        int index = 0;

        while (current != 0) {
            if (current->data == value) {
                return index; 
            current = current->next;
            index++;
        }
        return -1; 
    }
    
bool Functions::deleteNode(const std::string& value) {
        Node* current = head;
        while (current != 0) {
            if (current->data == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                
                delete current;
                return true;
            }
            current = current->next;
        }
        return false; 
    }
#endif /* FUNCTIONS_H_ */
