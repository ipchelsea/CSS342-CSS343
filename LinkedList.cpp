/*
 * Name: Chelsea Ip Tze Hwan
 * Programming Assignment Lab 4
 * Professor Eyal Arian
 * 
 * This programming assignment will require the usage of dynamic memory, pointers and linked lists.
 * It will also require the usage of File IO and templates, operator overloading, overloading
 * the assignment and copy constructors. I will build a class for a fully ordered list. 
 * The list class, called LinkedList, will be templatized so that different types of objects can be stored in it.
 */

//#include "Linkedlist.h"
#include <iostream>
#include <fstream>
using namespace std;

template <class ItemType>
LinkedList<ItemType>::LinkedList() 
{
    head = NULL;
}

template <class ItemType>
LinkedList<ItemType>::~LinkedList() 
{
    DeleteList();
}

template <class ItemType>
LinkedList<ItemType>::LinkedList(LinkedList& rhs) 
{
    this->head = NULL;
    *this = rhs;
}

/*
 Insert an object in the list in the correct place. Returntrue or false depending on whether the insert was successful. 
 Duplicates of an object are not allowed. If there is a duplicate the function should return false. 
 Note that a pointer to the object is passed in but the Insert should create a copy of the object to keep in the list.
 */
template <class ItemType>
bool LinkedList<ItemType>::Insert(ItemType* obj)//o(n)
{
        Node *newNode = new Node();
        ItemType *Tdata = new ItemType();
        *Tdata = *obj;
        newNode->data = Tdata;
        if (head == NULL) 
        {
            head = newNode;
            return true;
        }
        Node* curr = head; //pointing at the same address, not identical to head. points to first element
        while (curr->next != NULL && *obj > *(curr->next->data)) 
        {
            curr = curr->next;
        }
        if (((curr -> next != NULL && *obj == *(curr->next->data)) || *head->data == *obj)) 
        {
            return false;
        }
        if (*obj > *(curr->data)) 
        {
            newNode->next = curr->next;
            curr->next = newNode;
        } 
        else//when is curr->data > obj
        {
            //newNode->data = obj;
            newNode->next = head;
            head = newNode;
        }
        return true;
}

template <class ItemType>
bool LinkedList<ItemType>::isEmpty() const 
{
    return (head == NULL);
}

/*
 Given a string which represents a file, open the file,read the objects from file, 
 and build an ordered list. Note that BuildList puts the responsibility on the 
 Object class to know how to read from a file. That is, do not have object specific logic in 
 the implementation. You can insert each item into the list as you read it from the file. 
 If a list already has items, add the new items to the list.
 Assume that the list passed in is well-formed for the object being read into.
 */
template <class ItemType>
bool LinkedList<ItemType>::BuildList(string fileName) 
{
        ifstream inFile;
        inFile.open(fileName);
        if (inFile) //if file is founds 
        {
            while (!inFile.eof())//if not end of file yet
            {
                string firstName;
                string lastName;
                int age;
                inFile >> firstName >> lastName >> age;
                ItemType* Child = new ItemType(firstName, lastName, age);
                this-> Insert(Child);
                cout << firstName << " " << lastName << " " << age << " " << endl;
            }
            inFile.close();
        } else {
            cout << "File" << fileName << "was not opened." << endl;
        }
        return false;
}

/*
 Remove all items from the list. Deallocate all memory appropriately.
 This includes not only the nodes in the list but the items being pointed to by the nodes.
 */
template <class ItemType>
void LinkedList<ItemType>::DeleteList() 
{
    if(head == NULL)
    {
            return;
    }
    Node* temp = head;
    while(head != NULL)
    {
            head = head -> next;
            delete temp -> data;
            delete temp;
            temp = head;
    }
}
/*
 The same as Remove except the item is not removed from the list. Again, the second item is returned by reference.
 Make sure this function works correctly since it will be used frequently in testing code.
 */
template <class ItemType>
bool LinkedList<ItemType>::Peek(ItemType target, ItemType& result) const 
{
    if (head != NULL) 
    {
        if (*(head->data) != target) 
        {
            Node* curr = head;
            while (curr->next != NULL && *(curr->next->data) != target) 
            {
                curr = curr ->next; //traverse
            }
            if (*(curr->next->data) == target) 
            {
                result = *(curr->next->data);
                return true;
            }
        }
        else
        {
            result = *head->data;
            return true;
        }
    }
    return false;
}

/*
 Remove the target item from the list. Return the item using a second parameter that is passed in by reference. 
 If the item was found and removed return true, else return false.
 */
template <class ItemType>
bool LinkedList<ItemType>::Remove(ItemType target, ItemType& result) 
{
    if(head != NULL)
    {
        if(*head -> data != target)
        {
            Node* current = head;
            while(current -> next != NULL && target > *(current -> next -> data))
            {
                current = current -> next;
            }
            if(current -> next != NULL && *(current -> next -> data) == target)
            {
                Node* newNode = new Node();
                newNode = current -> next;
                result = *(current -> next -> data);
                current -> next = current -> next -> next;
                delete newNode -> data;
                delete newNode;
                return true;
            }
        }
        else
        {
            Node* newNode = head -> next;
            result = *(head -> data); 
            delete head -> data;
            delete head;
            head = newNode;
            return true;
        }
    }
    return false;
}


template <class ItemType>
void LinkedList<ItemType>::operator=(const LinkedList& source) 
{
    this->DeleteList();
    Node* temp = source.head;
    Node* newer = new Node();
    head = newer;
    //cout << "here" <<endl;
    while (temp != NULL) {
        //cout << *temp->data<<endl;
        ItemType* T = new ItemType();
        *T = *(temp -> data);
        newer->data = T;
      
        temp = temp->next;
        if (temp != NULL) {
            newer->next = new Node();
            newer = newer->next;
        }
        else {
            newer->next = NULL;
        }
    }
}

/*
 Takes a sorted list and merges into the calling sorted list
 (no new memory should be allocated). At termination of function, 
 the list passed in (list1)should be empty (unless it is the calling list).
 No duplicates are allowed.
 */
template <class ItemType>
bool LinkedList<ItemType>::Merge(LinkedList& list1) 
{
    bool check = false;
    Node *newHead;
    Node *a = head; //original
    Node *b = list1.head;
    
    if(a != NULL)
    {
        while (b != NULL) 
        {
            //if 3 greater than 1
            if (*(b->data) < *(head->data)) 
            {
                check = true;
                newHead = b->next;
                b->next = head;
                this->head = b;
                b = newHead;
                a = this->head;
            }
                //if object, need to use *, if you are accessing data than just put a .
            else if (a->next != NULL && (*(b->data) == *(a->data) || *(b->data) == *(a->next->data)))
            {
                b = b->next;
            }
            else if (a->next != NULL && (*(b->data) < *(a->next->data))) 
            {
                check = true;
                Node *newHead = b->next;
                b->next = a->next;
                a->next = b;
                b = newHead;
            } 
            else if (a->next != NULL && (*(b->data) > *(a->next->data))) 
            {
                //cout << "when a > b" << *this <<endl;
                a = a->next;
            } 
            else 
            {
                if(b!= NULL)
                    check = true;
                //cout << "printing this" << *this << endl;
                if (a -> data == b -> data)//111
                {
                    Node* temp = b -> next;
                    delete b->data;
                    delete b;
                    b = temp;
                }
                a->next = b; //if its case 10 to 11
                list1.head = NULL; //empty list
                return check; //because we changed the value in the array
            }
        }
        return check;
    }
    while(b != NULL)
    {
        Node* temp = new Node();
        ItemType* tdata = new ItemType();
        *tdata = *(b -> data);

        temp -> data = tdata;
        if(head == NULL)
        {
                head = temp;
                a = head;
        }
        else
        {
                //cout <<  " and add -> data = " << *(add -> data) << endl;
                a -> next = temp;
                //cout << "checking check points" << endl;
                a = a -> next;
        }
        b = b -> next;
        check = true;
    }
    list1.DeleteList();
    return check;
}

/*
 +, += : This should add two lists together. The lists are assumed to be sorted and
 there turned list must also be sorted. Use an efficient sort algorithm and avoid 
 unnecessary data allocations.Duplicates are not allowed and expected.
 */
template <class T>
bool LinkedList<T>::operator+=(const LinkedList& List1) 
{
    LinkedList *List2 = new LinkedList();
    *List2 = List1;
    return this->Merge(*List2);
}

template <class ItemType>
LinkedList<ItemType> LinkedList<ItemType>::operator+(const LinkedList &List1) const 
{
    LinkedList* l = this;
    *l += List1;
    return *l;
}

//== and != : check for equality or inequality.
template <class ItemType>
bool LinkedList<ItemType>::operator==(const LinkedList& list1) const 
{
    Node *a = head;
    Node *b = list1.head;
     //cout << "a -> data = " << *(a -> data) << " and b -> data = " << *(b -> data) << endl;
    while ((a != NULL && b != NULL) && (*(a->data) == *(b->data))) 
    {
        //cout << "a -> data = " << *(a -> data) << " and b -> data = " << *(b -> data) << endl;
        a = a->next; //move to the next element
        b = b->next;

    }
    if (a == NULL && b == NULL) //checks if node a and b are null
    {
        return true;
    }
    return false;
}

template <class ItemType>
bool LinkedList<ItemType>::operator!=(const LinkedList& list1) const 
{
    return !(this == &list1);
}




