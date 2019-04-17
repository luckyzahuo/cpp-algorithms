//
// Created by codercat on 19-3-13.
//

#ifndef ALGORITHM_LINKEDLIST_H
#define ALGORITHM_LINKEDLIST_H

#include <cstring>
#include <assert.h>
#include <string>

using namespace std;

class LinkedList {
private:
    typedef struct Node {
        int v;
        Node *next;
        Node *prev;
    } Node;
    Node *head = NULL;
    unsigned int size = 0;

public:
    LinkedList() {
        this->head = NULL;
        this->size = 0;
    }

    void remove(int v) {
        Node *dummyNode = new Node;
        dummyNode->next = this->head;

        Node *prevNode = dummyNode;
        while(prevNode->next != NULL) {
            if (prevNode->next->v == v) {
                Node *delNode = prevNode->next;
                prevNode->next = prevNode->next->next;
                delete delNode;
            } else {
                prevNode = prevNode->next;
            }
        }

        this->head = dummyNode->next;

    }

    void insert(int v) {
        Node *node = new Node();
        node->v = v;
        node->next = this->head;
        if (NULL != this->head) {
            this->head->prev = node;
        }
        this->head = node;
        this->size ++;
    }

    string toString() {
        Node *currentNode = this->head;
        string str = "head";
        while(NULL != currentNode) {
            str = str + "->" + to_string(currentNode->v);
            currentNode = currentNode->next;
        }

        return str;
    }

};


#endif //ALGORITHM_LINKEDLIST_H
