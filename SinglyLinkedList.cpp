#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
    Node *head;

    public:
        LinkedList()
        {
            head = NULL;
        }

        void insert(int val)
        {
            Node *newNode = new Node;
            newNode->data = val;
            newNode->next = NULL;

            if(head == NULL)
                head = newNode;

            else
            {
                newNode->next = head;
                head = newNode;
            }
        }

        bool search(int val)
        {
            Node *temp = head;
            while(temp != NULL)
            {
                if(temp->data == val)
                    return true;
                temp = temp->next;
            }
            return false;
        }

        void remove(int val)
        {
            if(head->data == val)
            {
                delete head;
                head = head->next;
                return;
            }

            if(head->next == NULL)
            {
                if(head->data == val)
                {
                    delete head;
                    head = NULL;
                    return;
                }

                else
                cout<<"Value not found"<<endl;
                return;
            }

            else
            {
                Node *temp = head;
                while(temp->next != NULL)
                {
                    if(temp->next->data == val)
                    {
                        Node *tempPtr = temp->next->next;
                        delete temp->next;
                        temp->next = tempPtr;
                        return;
                    }
                    temp = temp->next;
                }
                cout<<"Value not found"<<endl;
            }
        }

};

int main()
{
    LinkedList l;

    l.insert(5);
    l.insert(55);

    l.remove(55);

    cout<<"Searching for 5: "<<l.search(5)<<endl;

    return 0;
}