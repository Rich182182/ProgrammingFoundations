/*
ПІ: Вербицький Євген
Група: 121.1
*/
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}
Node *searchElement(Node *head, int eData)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == eData)
        {
            return temp;
        }
        temp = temp->next;
    }
    return temp;
}
inline void addToFront(Node **head, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}
void addToEnd(Node **head, int value)
{
    if (head == nullptr)
    {
        addToFront(head, value);
    }
    else
    {
        Node *temp = *head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        temp->next = newNode;
    }
}

inline void removeFromFront(Node **head)
{
    if (*head != nullptr)
    {
        Node *temp = *head;
        *head = (*head)->next;
        delete temp;
    }
}
void removeFromEnd(Node **head)
{
    if ((*head)->next == nullptr)
    {
        removeFromFront(head);
        return;
    }
    Node *temp = *head;
    Node *temp2 = temp->next;
    if (head != nullptr)
    {
        while (temp2->next != nullptr)
        {
            temp = temp->next;
            temp2 = temp->next;
        }
        temp->next = nullptr;
        Node *temp3 = temp2;
        delete temp3;
    }
}
int listLength(Node *head)
{
    int listLength = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        temp = temp->next;
        listLength++;
    }
    return listLength;
}
Node *searchElementByIndex(Node *head, int index)
{
    Node *temp = head;
    while (index != 0)
    {
        temp = temp->next;
        index--;
    }
    if (index > listLength(head) - 1)
    {
        return nullptr;
    }
    Node *newNode = new Node;
    newNode->data = temp->data;
    return newNode;
}
void reverseList(Node **head)
{
    Node *tempHead = *head;
    *head = searchElementByIndex(*head, listLength(*head) - 1);
    Node *temp1 = *head;
    int listSize = listLength(tempHead);
    for (int i = 1; i < listSize; i++)
    {
        temp1->next = searchElementByIndex(tempHead, listSize - i - 1);
        temp1 = temp1->next;
    }
    temp1->next = nullptr;
}
void bubbleSort(Node **head)
{
    Node *tempHead = *head;

    int listSize = listLength(tempHead);
    for (int i = 0; i < listSize - 1; i++)
    {
        Node *temp = *head;
        for (int j = 0; j < listSize - 1; j++)
        {
            if (searchElementByIndex(*head, j)->data < searchElementByIndex(*head, j + 1)->data)
            {
                int a = searchElementByIndex(*head, j)->data;
                temp->data = searchElementByIndex(tempHead, j + 1)->data;
                temp->next->data = a;
            }
            temp = temp->next;
        }
    }
}
void clearList(Node **head)
{
    while (*head != nullptr)
    {
        removeFromFront(head);
    }
}
struct DNode
{
    DNode *next;
    DNode *prev;
    int data;
};
DNode *circList(Node *head)
{
    DNode *dHead = new DNode{nullptr, nullptr, head->data};
    DNode *dtemp = dHead;
    Node *temp = head->next;
    while (temp != nullptr)
    {
        dtemp->next = new DNode{nullptr, dtemp, temp->data};
        dtemp = dtemp->next;
        temp = temp->next;
    }
    dtemp->next = dHead;
    dHead->prev = dtemp;
    return dHead;
}
int main()
{
    Node *head = nullptr;

    // Adding elements to the list
    addToFront(&head, 50);
    addToFront(&head, 20);
    addToFront(&head, 30);
    printList(head);
    DNode *twoWayList = circList(head);
    cout << listLength(head) << endl;
    cout << searchElementByIndex(head, 0)->data << endl;
    cout << searchElementByIndex(head, 2)->data << endl;
    // Adding element to the end
    addToEnd(&head, 5);
    std::cout << "List after adding an element to the end: ";
    printList(head);
    reverseList(&head);
    std::cout << "List after reversing: ";
    printList(head);
    bubbleSort(&head);
    std::cout << "List after bublesort: ";
    printList(head);
    // Searching for an element
    Node *found = searchElement(head, 30);
    if (found != nullptr)
    {
        std::cout << "Element 30 found in the list." << std::endl;
    }
    else
    {
        std::cout << "Element 30 not found in the list." << std::endl;
    }
    removeFromFront(&head);
    std::cout << "List after removing an element from the front: ";
    printList(head);

    removeFromEnd(&head);
    std::cout << "List after removing an element from the end: ";
    printList(head);
    clearList(&head);
    std::cout << "List after clearing: ";
    printList(head);

    return 0;
}
