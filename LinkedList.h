#include <iostream>
#include <fstream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

template <class ItemType>
class LinkedList 
{

    friend ostream& operator<<(ostream &outStream, const LinkedList<ItemType> &list) 
    {   
        outStream << endl;
        if (list.head != NULL) //means there's a list
        {
            Node* current = list.head;
            while (current != NULL) {
                cout << (*current->data) << endl;
                current = current -> next;
            }
            return outStream;
        }
        cout << "LinkedList does not exist" << endl;
        return outStream;
    }
    
public:
    //constructor
    LinkedList();
    ~LinkedList(); //call delete list
    LinkedList(LinkedList &rhs);
    
    bool Insert(ItemType* obj); //need to change this to *obj
    bool BuildList(string fileName);
    void DeleteList();
    bool isEmpty() const;
    void printList();
    bool Peek(ItemType target, ItemType& result) const;
    bool Remove(ItemType target, ItemType& result);
    bool Merge(LinkedList& list1);
    
    LinkedList operator+(const LinkedList &List1) const; //const here
    bool operator+=(const LinkedList &list1);
    bool operator==( const LinkedList &list1) const;
    void operator=(const LinkedList &source);
    bool operator!=(const LinkedList &list1) const;


private:
    
    struct Node
    {
        ItemType* data; //changed int
        Node* next;
    };
    Node* head;
    
};
#include "LinkedList.cpp"
#endif /* LINKEDLIST_H */
