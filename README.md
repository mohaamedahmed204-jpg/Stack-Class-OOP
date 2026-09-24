# Stack-Class-OOP.        

A generic, high-performance Stack Data Structure implementation in C++, built on top of a custom-designed Template Doubly Linked List using Object-Oriented Programming (OOP) principles.

## 📌 Overview

`Stack-Class-OOP` demonstrates how custom data structures can be composed cleanly to provide Last-In, First-Out (LIFO) stack operations. By encapsulating a custom doubly linked list `(clsDblLinkedList)`, the stack achieves dynamic memory management and optimal performance while maintaining a clear separation of concerns.

## 📦 Architecture & Design

    +------------------------------------------+
    |               clsMyStack<T>              |
    +------------------------------------------+
    |  - _MyList: clsDblLinkedList<T>          |
    +------------------------------------------+
    |  + push(Item)                            |
    |  + pop()                                 |
    |  + Top() : T                             |
    |  + Size() : int                          |
    |  + IsEmpty() : bool                      |
    |  + Clear()                               |
    |  + Reverse()                             |
    |  + Print()                               |
    +------------------------------------------+
                         |
                         | Encapsulates
                         v
    +------------------------------------------+
    |           clsDblLinkedList<T>            |
    +------------------------------------------+
    |  - head: Node*                           |
    |  - _Size: long long                      |
    +------------------------------------------+
    |  + InsertAtBeginning()                   |
    |  + DeleteFirstNode()                     |
    |  + GetItem()                             |
    |  + Clear()                               |
    |  + Reverse()                             |
    +------------------------------------------+
    
Composition over Inheritance: clsMyStack encapsulates clsDblLinkedList internally via protected access rather than exposing raw node-manipulation functions to the user interface.

Separation of Concerns: Low-level pointer manipulation (head/prev/next swapping) is handled entirely by clsDblLinkedList, keeping clsMyStack focused purely on LIFO semantics.

## ⚡ Core Operations

| Method | Complexity |	Description |
| :--- | :--- | :--- |
| `push(T Item)` | O(1) | Inserts a new element onto the top of the stack by prepending it to the underlying doubly linked list. |
| `pop()` | O(1) | Removes the top element from the stack by deleting the head node of the underlying list. |
| `Top()` | O(1) | Retrieves the element at the top of the stack without removing it. |
| `Size()` | O(1) | Returns the total number of elements currently stored in the stack. | 
| `IsEmpty()` | O(1) | Returns `true` if the stack contains no elements, otherwise `false`. |
| `Clear()` | O(N) | Deallocates all memory and resets the stack to an empty state. |
| `Reverse()` | O(N) | Reverses the internal sequence of elements in the stack in-place. |
| `Print()` | O(N) | Outputs all elements of the stack sequentially to the standard output. |

## 🧩 Key Concepts Demonstrated

Template Metaprogramming: Enables type-agnostic operations `(clsMyStack<T>)`, allowing the stack to store primitive data types, custom structs, or objects.Object-Oriented Design (OOD): Encapsulation of member variables and explicit abstraction layers.Dynamic Memory Management: Manual heap allocation and node deallocation without memory leaks.Algorithmic Efficiency: O(1) execution time for primary stack push/pop actions.

## 🛠 Technologies

Language: C++ (C++17 / C++20 compatible)

Paradigm: Object-Oriented & Generic Programming

Compiler Support: GCC, Clang, MSVC

## 💡 Tags / Topics:

`cpp` `data-structures` `stack` `doubly-linked-list` `oop` `templates` `generic-programming`

## 👨‍🏫 Instructor

* Dr. Mohammed Abu-Hadhoud
Programming Advices
