#include <iostream>
using namespace std;
 
struct point
{
    int data;           //информационное поле
    point *left;        //адрес левого поддерева
    point *right;       //адрес правого поддерева
};
 
point* Tree(int x, point *p)
{
    if(!p)
    {
        p=new point;
        p->left=NULL;
        p->right=NULL;
        p->data=x;
    }
 
    else
    {
        if(p->data>x)   {p->left=Tree(x, p->left);}
        else    {p->right=Tree(x, p->right);}
    }
    return p;
}
 
void Print(point *p, int l) 
{
    if(p)
    {
        Print(p->left,l+5);
        for(int i=0;i<l;i++)
            cout<<" ";
        cout<<p->data<<endl;
        Print(p->right,l+5);
    }
}
 
 
int maxim(int *mas, int *i)
{
    int n, min, t;
    min=mas[0];
    for(n=0;n<*i;n++)
        if(mas[n]>min)
        {
            min=mas[n];
            t=n;
        }
    return t;
}
 
 
 
int getlen(point* p, int level, int *k, int *mas, int *mas2, int *i)
{
 
    if (p->left) { getlen(p->left, level + 1, k, mas, mas2, i); }
    if (p->right) { getlen(p->right, level + 1, k, mas, mas2, i); }
 
    if ((!p->left) & (!p->right))
    {
        mas[*i]=p->data;
        mas2[*i]=level; 
        (*i)++;             
    }
    return mas[*i];
            
}   
 
 
 
int main()
{
    const int t=5;
    int n,i=0, k, s, x, f;
    int mas[t], mas2[t];
    cout<<"Задайте количество элементов дерева\n";
    cin>>n;
    point *root=NULL;
    
    for(i=0;i<n;i++)
    {
        cout<<"элемент:";
        cin>>x;
        root=Tree(x, root); 
    }
    i=0;
    Print(root,0);      
    s=getlen(root, 1, &k, mas, mas2, &i);   
    cout<<"Элемент самой длинной ветки дерева: "<<mas[maxim(mas2, &i)]<<endl;
    return 0;
}