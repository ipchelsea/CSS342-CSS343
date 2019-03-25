/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <cstdlib>
#include <iostream>
#include "LinkedList.h"
#include "Child.h"
#include <fstream>

using namespace std;

int main() 
{
  	Child c1("Angie", "Ham", 7), c2("Pradnya", "Dhala", 8), c3("Bill", "Vollmann", 13), c4("Cesar", "Ruiz", 6);
	Child c5("Piqi", "Tangi", 7), c6("Pete", "Rose", 13), c7("Hank", "Aaron", 3), c8("Madison", "Fife", 7);
	Child c9("Miles", "Davis", 65), c10("John", "Zorn", 4), c11;
	LinkedList<Child> class1, class2, soccer;
	int a = 1, b = -1, c = 13;
	class1.Insert(&c1);
	class1.Insert(&c2);
	class1.Insert(&c3);
	class1.Insert(&c4);
	class1.Insert(&c5);
	class1.Insert(&c6);
	class1.Insert(&c5);
	cout << "class1: "<< class1 << endl;
        if(class1.Insert(&c1))
	{
		cout << "ERROR::: Duplicate"<< endl;
	}
        class2.Insert(&c4);
	class2.Insert(&c5);
	class2.Insert(&c6);
	class2.Insert(&c7);
	class2.Insert(&c10);
	cout << "Class2: "<< class2 << endl;
        
        class1.Merge(class2); //works
	class2.Merge(class1);
        class1.Merge(class2);
	class1.Merge(class1);
	cout << "class1 and 2 Merged: " << class1 << endl;
        //cout << "class2 and 1 Merged: " << class2 << endl;
        //cout << "class1 and 2 Merged: " << class1 << endl;
        //cout << "class1 and 1 Merged: " << class1 << endl;

	if(!class2.isEmpty())
	{
		cout << "ERROR:: Class2 should be empty empty"<< endl;
	}
	
	class1.Remove(c4, c11);
	class1.Remove(c5, c11);
	class1.Remove(c11, c11);
	cout << class1;
	if(class1.Remove(c1, c11))
	{
		cout << "Removed from class1, student "<< c11 << endl;
	}
	
	cout << "class1: " << class1 << endl;
        
	soccer.Insert(&c6);
	soccer.Insert(&c4);
	soccer.Insert(&c9);
	cout << "soccer: "<< soccer << endl;
	
	soccer += class1;
	cout << "soccer += class1 : "<< soccer << endl;
        
        cout << "here" <<endl;
	LinkedList<Child> football = soccer;
	
        cout << "football: " << football << endl;
        
	if(football == soccer)
	{
		cout << "football: "<< football << endl;
	}
	
	if(football.Peek(c6, c11))
	{
		cout << c11 << " is on the football team"<< endl;
	}
	soccer.DeleteList();
	if(!soccer.isEmpty())
	{
		cout << "ERROR: soccer should be empty"<< endl;
	}
        
       
	LinkedList<int> numbers;
	numbers.Insert(&a);
	numbers.Insert(&b);
	numbers.Insert(&c);
	cout << "These are the numbers: "<< numbers << endl;
	numbers.DeleteList();
        cout << "Here" <<endl;
        
        //Testing for build list
        
        LinkedList<Child> Test4;
	Test4.BuildList("Sample.txt");
	cout << Test4 << endl;
	
        LinkedList<Child> Test5;
	Test5.BuildList("Sample1.txt");
	cout << Test5 << endl;
        
	
	
        /*
        LinkedList<int> Chelsea ; //int change to Child to connect to class
        LinkedList<int> Chelsea1;
        LinkedList<int> Chelsea2;
        LinkedList<int> Chelsea3;
        cout << endl;
        cout << "TEST BUILD LIST" << endl;
        Chelsea2.BuildList("Sample.txt");

        int a = 1;
        int b = 2;
        int c = 3;
        int d = 1;
        int e = 2;
        int f = 3;

        cout << endl;
        Chelsea.Insert(a);
        Chelsea.Insert(b);
        Chelsea.Insert(c);
         cout << "Chelsea Linked List" << Chelsea << endl;

        Chelsea1.Insert(d);
        Chelsea1.Insert(e);
        Chelsea1.Insert(f);
        cout << "Chelsea1 Linked List" << Chelsea1 << endl;

        if(Chelsea1 != Chelsea)
        {
            cout << "Testing Chelsea1 != Chelsea: are different." << endl;
        }
        if(Chelsea1 == Chelsea)
        {
            cout << "Testing Chelsea1 == Chelsea: are the same" << endl;
        }
        Chelsea.DeleteList();
        cout << "Has been deleted" <<endl;
        cout << Chelsea <<endl;
        if(!Chelsea.isEmpty())
            {
                    cout << "ERROR: Chelsea should be empty"<< endl;
            }

        //Chelsea += Chelsea1;
        //cout << "TESTING += " << Chelsea << endl;
        //cout << "Chelsea1" << Chelsea1 << endl;
        //Chelsea3 = (Chelsea + Chelsea1);
        //cout<< "Chelsea" << Chelsea <<endl;
        //cout << "Chelsea1" << Chelsea1 << endl;
        //cout << "TESTING + " << Chelsea << endl;
        //cout <<"Chelsea3 = " << Chelsea3 << endl;

        //Chelsea1.Merge(Chelsea);
        cout << "After Merging" << Chelsea1 << endl;
        cout << endl;
        //Chelsea1.Remove()
        //cout << "Chelsea" << Chelsea1 << endl;
        //Chelsea = *(new LinkedList(Chelsea1)); //dereferencing 
        //Chelsea = Chelsea1;
        //cout << "TESTING COPY CONSTRUCTOR" << Chelsea << endl;
      */
        return 0;
    }