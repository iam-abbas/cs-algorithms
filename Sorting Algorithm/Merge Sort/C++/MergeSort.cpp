#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

void addLast(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        head = tail = new Node(data, NULL);
    }
    else
    {
        Node *nn = new Node(data, NULL);
        tail->next = nn;
        tail = nn;
    }
}
void display(Node *head)
{
    for (Node *i = head; i != NULL; i = i->next)
    {
        cout << i->data << " ";
    }
    cout << endl;
}
void mergeSL(Node *h1, Node *h2, Node *&oh, Node *&ot)
{

    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data < h2->data)
        {
            addLast(oh, ot, h1->data);
            h1 = h1->next;
        }
        else if (h2->data < h1->data)
        {
            addLast(oh, ot, h2->data);
            h2 = h2->next;
        }
    }
    while (h1 != NULL)
    {
        addLast(oh, ot, h1->data);
        h1 = h1->next;
    }
    while (h2 != NULL)
    {
        addLast(oh, ot, h2->data);
        h2 = h2->next;
    }
    //display(oh);
}
Node *midNode(Node *head, Node *tail)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != tail && fast->next != tail)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
void mergesort(Node *&head, Node *&tail) // nLog(n) complexity
{
    if (head == tail)
    {
        Node *nn = new Node(head->data, NULL);
        head = tail = nn;
        return;
    }
    Node *mid = midNode(head, tail);
    Node *lh = head;
    Node *lt = mid;
    Node *rh = mid->next;
    Node *rt = tail;

    mergesort(lh, lt);
    mergesort(rh, rt);
    Node *fh = NULL;
    Node *ft = NULL;
    mergeSL(lh, rh, fh, ft);
    head = fh;
    tail = ft;
}
void imergeSL(Node *lh, Node *lt, Node *rh, Node *rt, Node *&oh, Node *&ot)
{
    Node *t1 = lh;
    Node *t2 = rh;
    while (t1 != NULL && t2 != NULL)
    {
        Node *rm = NULL;
        if (t1->data < t2->data)
        {
            rm = t1;
            t1 = t1->next;
            rm->next = NULL;
        }
        else
        {
            rm = t2;
            t2 = t2->next;
            rm->next = NULL;
        }
        if (oh == NULL)
        {
            oh = ot = rm;
        }
        else
        {
            ot->next = rm;
            ot = rm;
        }
    }
    if (t1 != NULL)
    {
        ot->next = t1;
        ot = lt;
    }
    else
    {
        ot->next = t2;
        ot = rt;
    }
}
void imergeSort(Node *&head, Node *&tail)
{
    if (head == tail)
    {
        return;
    }
    Node *mid = midNode(head, tail);
    Node *lh = head;
    Node *lt = mid;
    Node *rh = mid->next;
    Node *rt = tail;
    mid->next = NULL;
    imergeSort(lh, lt);
    imergeSort(rh, rt);
    Node *fh = NULL;
    Node *ft = NULL;
    imergeSL(lh, lt, rh, rt, fh, ft);
    head = fh;
    tail = ft;
}

int main(int argc, char **argv)
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *h1 = NULL;
    Node *t1 = NULL;
    Node *oh = NULL;
    Node *ot = NULL;
    addLast(head, tail, 10);
    addLast(head, tail, 20);
    addLast(head, tail, 30);
    addLast(head, tail, 90);
    addLast(head, tail, 50);
    addLast(head, tail, 100);
    addLast(head, tail, 70);
    display(head);
    cout << "///////////////////////" << endl;
    mergesort(head,tail);
   display(head);
}