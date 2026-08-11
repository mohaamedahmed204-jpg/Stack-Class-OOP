#pragma once
#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;
template <class T>

class clsMyStack {

protected:
	clsDblLinkedList <T> _MyList;

public:

	void push(T Item) {
		_MyList.InsertAtBeginning(Item);
	}

	void pop() {
		_MyList.DeleteFirstNode();
	}

    void Print() {
		_MyList.PrintList();
	}

	int Size() {
		return _MyList.Size();
	}

	bool IsEmpty() {
		return _MyList.IsEmpty();
	}

	T Top() {
		return _MyList.GetItem(0);
	}

    void Reverse() {
        _MyList.Reverse();
    }

    void Clear() {
        _MyList.Clear();
    }
};

