#include <iostream>
#include "L2.h"
#include "error.h"
using namespace std;
L2_elem :: L2_elem()
    : prev(0), next(0)
{

}
int L2_elem :: get_el()
{
    return el;
}

L2_elem*  L2_elem :: get_p()
{
    return prev;
}

L2_elem :: L2_elem (int c, L2_elem* n,L2_elem* p)
{
    el = c;
    next = n;
    prev = p;
}




L2 :: L2()
{
    head = 0;
    tail = 0;
}

bool L2 :: isEmpty () const
{
    return head == 0;
}

void L2 :: makeEmpty()
{

    L2_elem* p = 0;
    while (head)
    {
        p = head;
        head = head->next;
        delete p;
    }
    head = 0;
    tail = head;
}

L2 :: ~L2()
{

    makeEmpty();
}

L2 :: L2 (const L2 &List)
{
    try
    {
        head = 0;
        tail = 0;
        L2_elem* temp = List.head;

        while (temp)
        {
            int c = temp->el;
            temp = temp->next;
            pushTail(c);
        }
    }
    catch (bad_alloc e)
    {
        makeEmpty();
        throw;
    }
}

L2& L2::operator = (const L2& List)
{
    makeEmpty();
    L2_elem* temp = List.head;
    while(temp)
    {
        int c = temp->el;
        temp = temp->next;
        pushTail(c);
    }
    return *this;
}

void L2 :: pushHead (int c)
{

    {
        L2_elem* NewEl = new L2_elem(c,head,0);
        if (isEmpty())
        {
            head = NewEl;
            tail = head;
        }
        else
        {
            NewEl->next = head;
            head->prev = NewEl;
            head = NewEl;
        }
    }

}
void L2 :: pushTail (int c)
{
        L2_elem* NewEl = new L2_elem(c,0,tail);
        if ( isEmpty() )
        {
            tail = NewEl;
            head = tail;
        }
        else
        {
            NewEl->prev = tail;
            tail->next =  NewEl;
            tail = NewEl;
        }
}

L2_elem *L2::GetElemById(int i)
{
    L2_elem *p = (i<0?0:head);
    for(int k = 0; k < i && p; k++)
    {
        p = p->next;
    }
    return p;
}

void L2 :: AddAfter(int c, int i)
{
    if (i == 0)
    {
        pushHead(c);
        return;
    }

    L2_elem *p = GetElemById(i);
    if(!p) { throw ListError(); }

    if (p == tail)
    {
        pushTail(c);
        return;
    }

    L2_elem* NewEl = new L2_elem(c,p->next,p);
    NewEl->next->prev = NewEl;
    NewEl->prev->next = NewEl;
}

int L2 :: DelAfter(int i)
{
    if (i == 0)
    {
        return popHead();
    }

    L2_elem *p = GetElemById(i);
    if(!p) { throw ListError(); }

    if (p == tail)
    {
        return popTail();
    }

    int c = p->el;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    return c;
}

int L2 :: popHead ()
{
    if ( isEmpty() )
    {
        throw ListError();
    }
    int c = head->el;
    if ( head->next == 0 )
    {
        delete head;
        head = 0;
        tail = 0;
    }
    else
    {
        head = head->next;
        delete  head->prev;
        head->prev = 0;
    }
    return c;
}

int L2 :: popTail ()
{
    if ( isEmpty() )
    {
        throw ListError();
    }
    int c = tail->el;
    if ( tail->prev == 0 )
    {
        delete tail;
        head = 0;
        tail = 0;
        return c;
    }
    else
    {
        tail = tail->prev;
        delete ( tail->next );                          
        tail->next = 0;
    }
    return c;
}




int L2 :: size()const
{
    if (isEmpty())
    {
        return 0;
    }
    L2_elem* temp = head;
    int size = 0;
    while (temp)
    {
        temp = temp->next;
        size++;
    }
    return size;
}

std::istream& operator>>(std::istream& i, L2& L)
{
    int c;
    cin >>c;
    L.pushHead(c);
    return i;
}

std::ostream& operator<<(std::ostream& o, const L2& L)
{
    L2_elem* temp = L.tail;
    while (temp)
    {
        o << temp->el << "\t";
        temp = temp->prev;
    }
    return o;
}
