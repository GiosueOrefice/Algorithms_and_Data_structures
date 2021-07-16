#ifndef DISJOINT_H
#define DISJOINT_H
#include <Set.h>
#include <vector>

using namespace std;

class Disjoint
{
     public:
        Set *makeSet(Set *x);
        Set *FindSet(Set *x);
        void Link(Set *x,Set *y);
        void Union(Set *x,Set *y);
};

#endif // DISJOINT_H
