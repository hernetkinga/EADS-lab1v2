
#include <iostream>

#include "header.h"

using namespace std;

// int sum(const int& three, const int& two)
// {
//     return three + two;
// }
 
int main()
{
Sequence<int, int> list;
cout<<"              CREATING A EMPTY LIST\n";


cout<<"Is list empty?   "<< list.isEmpty() <<endl;
cout<< "List size is:    "<<list.size()<< endl;
cout<<"              ADDING FIRST ELEMENT\n"<<endl;
list.pushfront(1,1);
cout<<"\nTHE LIST\n";
list.print();
cout<<"\nIs list empty?   "<<list.isEmpty()<<endl;
cout<< "\nList size is:    " <<list.size()<<endl;
cout<<"              ADDING TWO MORE ELEMENTS FROM THE FRONT\n";
list.pushfront(2,2);
list.pushfront(3,3);
cout<<"\nTHE LIST\n";
list.print();
cout<<endl;
cout<< "\nList size is: "<< list.size()<<endl;

cout<<endl;
cout<<"              ADDING TWO MORE ELEMENTS FROM THE BACK\n";
list.pushback(4,4);
list.pushback(5,5);
cout<<"\nTHE LIST\n";
list.print();
cout<< "\nList size is: "<<list.size()<<endl;
cout<<endl;
cout<<"              REMOVING AN ELEMENT FROM THE FRONT\n";
list.popfront();
cout<<"\nTHE LIST\n";
list.print();
cout<<"\nList size is: "<<list.size()<<endl;

cout<<endl;
cout<<"              REMOVING AN ELEMENT FROM THE BACK\n";
list.popback();
cout<<"\nTHE LIST\n";
list.print();
cout<<"\nList size is:  "<<list.size()<<endl;
cout<<"              REMOVING ALL THE ELEMENTS\n";
list.clear();
cout<<"\nTHE LIST\n";
list.print();
cout<<"\nIs list empty?   "<<list.isEmpty()<<endl;
cout<<"\nList size is: "<<list.size()<<endl;
list.pushfront(1,1);
list.pushfront(2,2);
list.pushfront(3,3);
list.pushfront(4,4);
list.pushfront(5,5);

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

one.pushback(1,1);
one.pushback(2,2);
one.pushback(3,3);
one.pushback(5,5);
one.pushback(6,6);
cout<<"\nTHE NEW LIST\n";
one.print();
cout<<"\n              INSERTING NEW ELEMENT(4,4) AFTER THE SPECIFIED KEY(2 AND 5)\n";
one.insertAfterKey(4,4,2);
one.insertAfterKey(4,4,5);
cout<<"\nTHE NEW LIST\n";
one.print();
cout<<"\n              INSERTING NEW ELEMENT(7,7) AFTER THE SPECIFIED KEY(1 AND 6)\n";
one.insertAfterKey(7,7,1);
one.insertAfterKey(7,7,6);
cout<<"\nTHE NEW LIST\n";
one.print();
cout<<"\n              INSERTING NEW ELEMENT AFTER THE NON-EXSISTENT KEY\n\n";
one.insertAfterKey(2,3, 40);
 int aggregate(const int one, const int two);
// Sequence<int,int> two;
// Sequence<int,int> three;
// two.pushback(1,1);
// two.pushback(2,2);
// two.pushback(3,3);
// two.pushback(5,5);
// two.pushback(6,6);
// three.pushback(1,1);
// three.pushback(2,2);
// three.pushback(3,3);
// three.pushback(5,5);
// three.pushback(6,6);
// join(two, three, &sum);

 cout<<"\n--------------------------------\n"<<"--------------------------------\n"<<"----------TESTS-PASSED----------\n"<<"--------------------------------\n"<<"--------------------------------\n";

}
