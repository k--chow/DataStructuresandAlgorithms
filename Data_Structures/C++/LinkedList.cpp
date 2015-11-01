#include <iostream>
using namespace std;
class Link {
    public:
    int data; //data
    Link* pNext; //pointer to next link
    Link(int data) : data(data)
    {
    }
    void displayLink()
    {
        cout << data;
    }

};

class LinkList
{
    private:
    Link* pFirst;
    public:
    LinkList() : pFirst(NULL)
    {
    }

    bool add(int newb) // adds first
    {
        Link* pNewLink = new Link(newb);
        pNewLink -> pNext = pFirst;
        pFirst = pNewLink;
        return true;
    }

    bool remove(int old) // removes first
    {
        if (!isEmpty())
        {
            Link* pTemp = pFirst;
            pFirst = pFirst->pNext;
            delete pTemp;
        }
        return false;
    }

    bool isEmpty()
    {
        return pFirst == NULL;
    }

    Link* getFirst()
    {
        return pFirst;
    }

    void displayList()
    {
        cout << "List: ";
        Link* pCurrent = pFirst;
        while(pCurrent != NULL)
        {
            pCurrent->displayLink();
            pCurrent = pCurrent->pNext;
        }
        cout << endl;
    }
};

int main()
{
    LinkList LL;
    LL.add(5);
    LL.add(4);
    LL.add(126);

    LL.displayList();
}
