#ifndef Header_h
#define Header_h
#include <iostream>
using namespace std;

template<typename Key, typename Info>
class Sequence
{
    struct Node
    {
        Key key;
        Info info;
        Node* next;
    };
    Node* head;
    
public:
    Sequence();
    ~Sequence();
    Sequence(const Sequence& src);//copy constructor
    Sequence<Key, Info>& operator=(const Sequence<Key, Info>& src);
    
    //these functions are used in shuffle so that we can access private members of the class
    void switchHead();
    Key getKey();
    Info getInfo();
    
    bool isEmpty();
    void clear();
    void pushFront(const Key &key, const Info &info);
    void pushBack(const Key &key, const Info &info);
    bool insertAfter(const Key& k, const Info& i, int afterThis);
    bool popFront();
    bool popBack();
    unsigned int size();
    void print();
};

template<typename Key, typename Info>
Sequence<Key, Info>::Sequence()
{
    head = nullptr;
}

template<typename Key, typename Info>
Sequence<Key, Info>::~Sequence()
{
    clear();
}

template<typename Key, typename Info>
Sequence<Key, Info>::Sequence(const Sequence& src)
{
    head = nullptr;
    *this = src;
}

template<typename Key, typename Info>
Sequence<Key, Info>& Sequence<Key, Info>:: operator=(const Sequence<Key, Info>& src)
{
    if(this == &src)
        return *this;
    
    clear();
    Node* current_element = src.head;
    
    while(current_element != nullptr)
    {
        pushBack(current_element->key, current_element->info);
        current_element = current_element->next;
    }
    return *this;
}

template<typename Key, typename Info>
void Sequence<Key, Info>:: switchHead()
{
    this->head = this->head->next;
}

template<typename Key, typename Info>
Key Sequence<Key, Info>::getKey()
{
    return this->head->key;
}

template<typename Key, typename Info>
Info Sequence<Key, Info>::getInfo()
{
    return this->head->info;
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::isEmpty()
{
    return head == nullptr;
}

template<typename Key, typename Info>
void Sequence<Key, Info>::clear()
{
    Node* current = head;
    
    while(current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

template<typename Key, typename Info>
void Sequence<Key, Info>::pushFront(const Key &key, const Info &info)
{
    Node* current = head;
    Node* new_current = new Node;
    new_current->key = key;
    new_current->info = info;
    new_current->next = current;
    head = new_current;
}

template<typename Key, typename Info>
void Sequence<Key, Info>::pushBack(const Key &key, const Info &info)
{
    Node* new_last = new Node;
    new_last->key = key;
    new_last->info = info;
    new_last->next = nullptr;
    
    Node* current = head;
    if(isEmpty() == true)
    {
        head = new_last;
        return;
    }
    
    while(current != nullptr)
    {
        if(current->next != nullptr)
            current = current->next;
        else
            break;
    }
    current->next = new_last;
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::insertAfter(const Key& key, const Info& info, int afterThis)
{
    Node* dummy = head;
    
    while(dummy->next != nullptr)
    {
        dummy = dummy->next;
    }
    
    if(afterThis == dummy->key)
    {
        this->pushBack(key, info);
        return true;
    }
    
    int num = this->size();
    Node* current = head;
    Node* new_current = new Node;
    
    while(--num)
    {
        if(current->key == afterThis)
            break;
        
        if(current->key != afterThis)
            current = current->next;
        
        if(num == 1)
            cout<<"Key doesn't exist! Element is not going to be inserted!!\n";
    }
    
    Node* temp = head;
    
    while(temp->next != nullptr)
    {
        if(temp->key == afterThis)
        {
            Node* new_temp = new Node;
            new_temp = temp->next;
            temp->next = new_current;
            new_current->key = key;
            new_current->info = info;
            new_current->next = new_temp;
            break;
        }
        else
            temp = temp->next;
    }
    return true;
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::popFront()
{
    if(isEmpty() == true)
        return false;
    
    Node* current = head;
    Node* new_node = head->next;
    delete current;
    head = new_node;
    
    return 1;
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::popBack()
{
    if(isEmpty() == true)
        return false;
    
    Node* current = head;
    if(current->next == nullptr)
    {
        delete current;
        head = nullptr;
        cout<<"List is empty\n";
        return 2;
    }
    
    while(current->next->next != nullptr)
        current = current->next;
    
    delete current->next;
    current->next = nullptr;
    return 1;
}

template<typename Key, typename Info>
unsigned int Sequence<Key, Info>::size()
{
    int counter = 0;
    
    if(isEmpty())
        return 0;
    
    Node* current = head;
    while(current->next != nullptr)
    {
        current = current->next;
        counter++;
    }
    counter++;
    return counter;
}

template<typename Key, typename Info>
void Sequence<Key, Info>::print()
{
    Node* current = head;
    
    while(current != nullptr)
    {
        cout<<current->key<<" "<<current->info<<endl;
        current = current->next;
    }
}

template<typename Key, typename Info>
Sequence<Key, Info> shuffle(const Sequence<Key, Info> &s1, int len1, const Sequence<Key, Info> &s2, int len2, int repeat)
{
    Sequence<Key, Info> new_list, seq1, seq2;
    seq1 = s1;
    seq2 = s2;
    
    if(seq1.size() < len1*repeat || seq2.size() < len2*repeat)
        throw std::invalid_argument("Over the boundaries!\n");
    
    for(int rep = 0; rep < repeat; rep++)
    {
        for(int i = 0; i < len1; i++)
        {
            new_list.pushBack(seq1.getKey(), seq1.getInfo()); //if it was in class we would use seq1.head->key etc.
            seq1.switchHead(); //here it would be seq2.head = seq2.head->next
        }
        
        for(int j = 0; j < len2; j++)
        {
            new_list.pushBack(seq2.getKey(), seq2.getInfo());
            seq2.switchHead();
        }
    }
    new_list.print();
    return new_list;
}
#endif
