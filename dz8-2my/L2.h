#include <iostream>

class L2_elem
{
public:
    int el;
    L2_elem* next;
    L2_elem* prev;
    L2_elem();
    L2_elem (int c, L2_elem* n,L2_elem* p);        
    int get_el();
    L2_elem* get_n();
    L2_elem* get_p();
};
class L2
{
    L2_elem* head;
    L2_elem* tail;
    L2_elem* GetElemById(int i);

public:
    L2();
    ~L2();
    L2(const L2 &List);
    L2& operator = (const L2& List);
    bool isEmpty ()const;
    int popHead ();
    int popTail ();
    void pushHead (int c);
    void pushTail (int c);
    void AddAfter(int c, int i);
    int DelAfter( int i);

    void printTail()const;
    int size ()const;
    void makeEmpty();
    static void L2_menu();
    friend std::istream& operator>>(std::istream& i, L2& L);
    friend std::ostream& operator<<(std::ostream& o, const L2& L);
};
