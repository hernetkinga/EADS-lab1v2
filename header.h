#include <iostream>
template <typename Key, typename Info>
class Sequence;
template <typename Key, typename Info>

struct Node{
    Key key;
    Info info;
    friend class Sequence<Key,Info>;
   
private:
    Node<Key,Info>* next;
};
template <typename Key, typename Info>

class Sequence
{

private:
Node<Key, Info> *head;


public:
Sequence(){
    head = nullptr;
};
~Sequence(){
    clear();
}
void clear(){
Node<Key, Info>* current = head;
while( current != nullptr) {
    Node<Key,Info>* next = current->next;
    delete current;
    current = next;
    }
    head = nullptr;
}

Sequence(const Sequence& src){
    head = nullptr;
    *this = src;
    };


Sequence<Key,Info> &operator=(const Sequence<Key,Info>& src){
    if(this == & src){
        return *this;
    }
    clear();
    Node<Key, Info>* currentElem = src.head;
   
    
    
    while (currentElem != nullptr)
     {
           
        
        
        currentElem = currentElem->next;
        
     }
     return *this;
};

bool isEmpty(){
    return head == nullptr;
}
void pushback(const Key &key, const Info &info){
    Node<Key,Info> *newLast = new Node<Key,Info>;
    newLast->key= key;
    newLast->info = info;
    newLast->next = nullptr;
    Node<Key, Info> *current = head;

    if(isEmpty()== true){
        head = newLast;
        return;
    }
    
    while(current != nullptr) {
    if(current->next != nullptr)
    current = current->next;

    else break;
    }
    current->next = newLast;

}

void pushfront(const Key &key, const Info &info)
{
    Node<Key,Info>* current = head;
    Node<Key,Info>* newCurrent = new Node<Key, Info>;
    newCurrent->key = key;
    newCurrent->info = info;
    newCurrent->next = current;
    head = newCurrent;
}
bool insertAfterKey(const Key& key, const Info& info, int afterThisKey)
{
    Node<Key,Info>* moment = head;
    while(moment->next != nullptr){
        moment = moment->next;
    }
    if(afterThisKey == moment->key) {
        this->pushback(key, info);
        return true;
        }
    int num = this->size();
    Node<Key,Info>* current = head;
    Node<Key,Info>* newCurrent = new Node<Key, Info>;
    while( --num) {
    if(current->key == afterThisKey) break;
    if(current->key != afterThisKey) {
        current = current->next;
    }
    if(num == 1) std::cout<<"Sorry, the key doesn't exist. The element will not be inserted.\n";
    }
    Node<Key,Info>* temp = head;
           while(temp->next != nullptr){
        if(temp->key == afterThisKey){
        Node<Key,Info>* temp2 = new Node<Key, Info>;
        temp2= temp->next;
        temp->next= newCurrent;
        newCurrent->key = key;
        newCurrent->info = info;
        newCurrent->next = temp2;
        break;
        }else temp = temp->next;
       }
       return true;
    }

bool popfront(){
      if(isEmpty())
    {
       return false;
       }
    Node<Key,Info> *current = head;
    Node<Key,Info>* second = head->next;
    delete current;
    head = second;
    
    return 1;
}
bool popback()
{
    if(isEmpty())
    {
       return false;
    }
    Node<Key, Info> *current = head;
    if(current->next ==  nullptr){
        delete current;
        head = nullptr;
      std::cout<<"now list is empty"<< std::endl;
         return 2;
     }
    while(current->next->next != nullptr) {
    current = current->next;
    }
    delete  current->next;
    current->next = nullptr;


    return 1;
}


unsigned int size()
{
    int count = 0;
    if(isEmpty())return 0;
    Node<Key,Info>* current = head;
    
    while(current->next != nullptr){
        current = current->next;
        count ++;
    }
    count ++;

    return count;
}
void print()
{
        Node<Key,Info> *current = head;
        while (current != NULL)
        {
            std::cout << current->key << " " << current->info << std::endl;
            current = current->next;
        }
}

// Key getKey(){
//     return *this.head->key;
//  }
// Info getInfo(){
//     return *this.head->info;
// }
// Node<Key,Info>* getHead(){
//     return *this.head;
// }
// Node<Key,Info> getNext(){
//     return *this.head->next;
// }
// unsigned int getSize(){
//     return *this.size();
// }
};


//PART 2
// template <typename Key, typename Info>
// Sequence<Key,Info> join(const Sequence<Key,Info>& left,const Sequence<Key,Info>& right, Info (*aggregate)(const Info& left, const Info& right)){
//     Sequence<Key,Info> newList;
//     Node<Key,Info>* current = right.getHead();
//     Node<Key,Info>* SecondCurrent = left.getHead();
    
//     if((right.getSize() != left.getSize()) || !right.getSize()){
//         throw std::invalid_argument("Size not equal or empty");
//     }
//     while((current != nullptr) && (SecondCurrent != nullptr))
//     {
        
//     if(SecondCurrent.getKey() < current.getKey()){
//         newList.pushback(current.getInfo(), current.getKey());
//         current = current->next;

//     }else if(current.getKey() < SecondCurrent.getKey()){
//         newList.pushback(SecondCurrent.getInfo(),SecondCurrent.getKey());
//         SecondCurrent = SecondCurrent->next;
//     }
//     else if(SecondCurrent.getKey() == current.getKey()){
//         Info resInfo = *aggregate(current.getInfo(), SecondCurrent.getInfo());
//         newList.pushback(SecondCurrent.getKey(), resInfo);
//         current = current->next;
//         SecondCurrent = SecondCurrent->next;
        
//     }
        
//     }
//     return newList;
// }




