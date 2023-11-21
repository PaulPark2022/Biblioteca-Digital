#ifndef NODE_H
#define NODE_H

#include "book.h"

class Node {
public:
    Book data;
    Node* next;

    Node(const Book& b);
};

Node::Node(const Book& b) : data(b), next(nullptr) {}

#endif