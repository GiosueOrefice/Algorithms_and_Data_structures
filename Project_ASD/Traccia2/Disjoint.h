#include <list>
#include <vector>
#include <set.h>

using namespace std;

class Disjoint
{
    private:
        vector <Set*> VSet;

    public:
        void makeSet(Node *x);
        Set* GetSet(int i);
        Set* FindSet(Set *x);
        void Link(Set *x,Set *y);
        void Union(Set *x, Set *y);

};
