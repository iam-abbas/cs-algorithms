#include <iostream>

class Node {

public:

    Node *next;

    int data;
};

typedef Node * ListType;

void insertionSort(ListType &list) {
    ListType *p = &list;

    while ( (*p)->next && (*p)->next->data < (*p)->data)
    {
        ListType node= *p;

        *p=node->next;

        node->next=node->next->next;

        (*p)->next=node;

        p= &(*p)->next;
    }
}

int main()
{
    Node *head=0;

    int n;

    while (std::cout << "enter the number ", std::cin >> n)
    {
        Node *p=new Node;

        p->data=n;

        p->next=head;
        head=p;

        insertionSort(head);

        for (p=head; p; p=p->next)
            std::cout << p->data << " ";
        std::cout << std::endl;
    }
}
