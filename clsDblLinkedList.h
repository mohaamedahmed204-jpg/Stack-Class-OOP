#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList {

public:
    class Node {
    public:
        T value;
        Node* next;
        Node* prev;
    };

protected:
    inline static long long _Size = 0;

    void SwapNode(Node*& Current) {
        Node* NextCurrent = Current->next;
        Current->next = Current->prev;
        Current->prev = NextCurrent;
    }

public:
    Node* head = NULL;

    T Size() {     // O(1) Complexity
        return _Size;
    }

    void InsertAtBeginning(T value) {
        /*
            1-Create a new node with the desired value.
            2-Set the next pointer of the new node to the current head of the list.
            3-Set the previous pointer of the current head to the new node.
            4-Set the new node as the new head of the list.
        */

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }
        ++_Size;
        head = newNode;
    }

    // Print the linked list
    void PrintList() {
        Node* Current = head;

        while (Current != NULL) {
            cout << Current->value << ' ';
            Current = Current->next;
        }
        cout << "\n";
    }

    Node* Find(T Value) {
        Node* Current = head;
        while (Current != NULL) {
            if (Current->value == Value) return Current;
            Current = Current->next;
        }

        return NULL;
    }

    void InsertAfter(Node* current, T value) {
        /* 
            1 - Create a new node with the desired value.
            2-Set the next pointer of the new node to the next node of the current node.
            3-Set the previous pointer of the new node to the current node.
            4-Set the next pointer of the current node to the new node.
            5-Set the previous pointer of the next node to the new node(if it exists).
        */

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        ++_Size;
        current->next = newNode;
    }

    void InsertAtEnd(T value) {
        /*
            1-Create a new node with the desired value.
            2-Traverse the list to find the last node.
            3-Set the next pointer of the last node to the new node.
            4-Set the previous pointer of the new node to the last node.
        */

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
        ++_Size;
    }

    void DeleteNode(Node*& NodeToDelete) {
        /*
            1-Set the next pointer of the previous node to the next pointer of the current node.
            2-Set the previous pointer of the next node to the previous pointer of the current node.
            3-Delete the current node.
        */
        if (head == NULL || NodeToDelete == NULL) {
            return;
        }
        if (head == NodeToDelete) {
            head = NodeToDelete->next;
        }
        if (NodeToDelete->next != NULL) {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }
        if (NodeToDelete->prev != NULL) {
            NodeToDelete->prev->next = NodeToDelete->next;
        }
        --_Size;
        delete NodeToDelete;
    }

    void DeleteFirstNode() {
        /*
            1-Store a reference to the head node in a temporary variable.
            2-Update the head pointer to point to the next node in the list.
            3-Set the previous pointer of the new head to NULL.
            4-Delete the temporary reference to the old head node.
        */

        if (head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        --_Size;
        delete temp;
    }

    void DeleteLastNode() {
        /*
            1-Traverse the list to find the last node.
            2-Set the next pointer of the second-to-last node to NULL.
            3-Delete the last node.
        */

        if (head == NULL) {
            return;
        }
        if (head->next == NULL) {
            delete head;
            --_Size;
            head = NULL;
            return;
        }

        Node* current = head;
        // we need to find the node before last node.
        while (current->next->next != NULL) {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = NULL;
        --_Size;
        delete temp;
    }

    bool IsEmpty() {
        return !Size();
    }

    void Clear() {
        while(!IsEmpty()) {
            DeleteFirstNode();
        }
    }

    void Reverse() {
        if(head == nullptr) return;

        Node* Current = head;

        while (Current->next != NULL) {
            SwapNode(Current);
            Current = Current->prev;
        }
        SwapNode(Current);
        head = Current;
    }

    Node* GetNode(unsigned int Order) {
        if( Order < 0 || Order > Size() - 1 ) {
            return nullptr;   
        }
        unsigned int Cnt = 0;
        Node* Current = head;

        while (Cnt++ != Order) {
            Current = Current->next;
        }
        return Current;
    }

    T GetItem(unsigned int Order) {
        return GetNode(Order)->value;
    }

    void UpdateItem(unsigned int Order, T Value) {
        Node* ItemToUpdate = GetNode(Order);
        if(ItemToUpdate == nullptr) return;
        ItemToUpdate->value = Value;
    }

    void InsertAfter(unsigned int Order, T Value) {
        Node* N = GetNode(Order);
        if(N != nullptr)
            InsertAfter(N, Value);
    }
};

