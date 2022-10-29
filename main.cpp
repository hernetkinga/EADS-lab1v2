#include <iostream>
#include "header.h"
using namespace std;


int main()
{
    Sequence<int, int> list;
    cout<<"              CREATING AN EMPTY LIST\n";


    cout<<"Is list empty?   "<< list.isEmpty() <<endl;
    cout<< "List size is:    "<<list.size()<< endl;
    cout<<"              ADDING FIRST ELEMENT\n"<<endl;
    list.pushFront(1,1);
    cout<<"\nTHE LIST\n";
    list.print();
    cout<<"\nIs list empty?   "<<list.isEmpty()<<endl;
    cout<< "\nList size is:    " <<list.size()<<endl;
    cout<<"              ADDING TWO MORE ELEMENTS FROM THE FRONT\n";
    list.pushFront(2,2);
    list.pushFront(3,3);
    cout<<"\nTHE LIST\n";
    list.print();
    cout<<endl;
    cout<< "\nList size is: "<< list.size()<<endl;

    cout<<endl;
    cout<<"              ADDING TWO MORE ELEMENTS FROM THE BACK\n";
    list.pushBack(4,4);
    list.pushBack(5,5);
    cout<<"\nTHE LIST\n";
    list.print();
    cout<< "\nList size is: "<<list.size()<<endl;
    cout<<endl;
    cout<<"              REMOVING AN ELEMENT FROM THE FRONT\n";
    list.popFront();
    cout<<"\nTHE LIST\n";
    list.print();
    cout<<"\nList size is: "<<list.size()<<endl;

    cout<<endl;
    cout<<"              REMOVING AN ELEMENT FROM THE BACK\n";
    list.popBack();
    cout<<"\nTHE LIST\n";
    list.print();
    cout<<"\nList size is:  "<<list.size()<<endl;
    cout<<"              REMOVING ALL THE ELEMENTS\n";
    list.clear();
    cout<<"\nTHE LIST\n";
    list.print();
    cout<<"\nIs list empty?   "<<list.isEmpty()<<endl;
    cout<<"\nList size is: "<<list.size()<<endl;
    list.pushFront(1,1);
    list.pushFront(2,2);
    list.pushFront(3,3);
    list.pushFront(4,4);
    list.pushFront(5,5);

    Sequence<int,int> temp;
    cout<<"\nADDING TO THE LIST AND CREATING A NEW LIST...\n";
    cout<<"\nCOPYING ALL THE ELEMENTS TO THE NEW LIST\n";
    cout<<"\nTHE NEW LIST\n";
    temp=list;
    cout<< endl;
    temp.print();
    cout<< endl;
    cout<<"Is NEW list empty?   "<< temp.isEmpty() <<endl;
    cout<< "NEW list size is:    "<<temp.size()<< endl;
    cout<<"Is OLD list empty?   "<< list.isEmpty() <<endl;
    cout<< "OLD list's size is:    "<<list.size()<< endl;
    Sequence<int,int> one;

    one.pushBack(1,1);
    one.pushBack(2,2);
    one.pushBack(3,3);
    one.pushBack(5,5);
    one.pushBack(6,6);
    cout<<"\nTHE NEW LIST\n";
    one.print();
    cout<<"\n              INSERTING NEW ELEMENT(4,4) AFTER THE SPECIFIED KEY(2 AND 5)\n";
    one.insertAfter(4,4,2);
    one.insertAfter(4,4,5);
    cout<<"\nTHE NEW LIST\n";
    one.print();
    cout<<"\n              INSERTING NEW ELEMENT(7,7) AFTER THE SPECIFIED KEY(1 AND 6)\n";
    one.insertAfter(7,7,1);
    one.insertAfter(7,7,6);
    cout<<"\nTHE NEW LIST\n";
    one.print();
    cout<<"\n              INSERTING NEW ELEMENT AFTER THE NON-EXSISTENT KEY\n\n";
    one.insertAfter(2,3, 40);
    int aggregate(const int one, const int two);
  

    cout<<"\n\n              CHECKING SHUFFLE FUNCTION\n\n";
    Sequence<int, int> S1, S2;
    
    S1.pushBack(1,1);
    S1.pushBack(2,2);
    S1.pushBack(3,3);
    S1.pushBack(4,4);
    S1.pushBack(5,5);
    S1.pushBack(6,6);
    S1.pushBack(7,7);
    S1.pushBack(8,8);
    S1.pushBack(9,9);
    cout<<"List S1\n";
    S1.print();
    
    S2.pushBack(10,10);
    S2.pushBack(11,11);
    S2.pushBack(12,12);
    S2.pushBack(13,13);
    S2.pushBack(14,14);
    S2.pushBack(15,15);
    cout<<"\nList S2\n";
    S2.print();
    
    cout<<"\nUsing shuffle function\n";
    shuffle(S1, 2, S2, 1, 2);
    cout<<"\nUsing shuffle function\n";
    shuffle(S1, 3, S2, 2, 3);
    cout<<"\nUsing shuffle function\n";
    shuffle(S2, 3, S1, 2, 2);
    
     cout<<"\n--------------------------------\n"<<"--------------------------------\n"<<"----------TESTS-PASSED----------\n"<<"--------------------------------\n"<<"--------------------------------\n";
}
