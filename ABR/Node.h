#ifndef NODE_H
#define NODE_H
#include <Data.h>

class Node
{
    private:
        Data *val;
        Node *sx;
        Node *dx;
        Node *parent;

    public:
        Node(Data *Val);
        Data *GetVal();
        void SetVal();
        void SetSX(Node *x);
        void SetDX(Node *x);
        void SetParent(Node *x);
        Node *GetSX();
        Node *GetDX();
        Node *GetParent();

};

#endif // NODE_H
