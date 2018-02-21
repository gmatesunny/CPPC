#include <bits/stdc++.h>
using namespace std;

class Node
{
    int data;
    Node *next;

  public:
    Node() {}
    void set_data(int a_data)
    {
        data = a_data;
    }
    void set_next(Node *a_next)
    {
        next = a_next;
    }

    int get_data()
    {
        return data;
    }

    Node *get_next()
    {
        return next;
    }
};

class List
{
    Node *head;

  public:
    List()
    {
        head = NULL;
    }

    void print_list();
    void append_node(int data);
    void delete_node(int data);
};

void List::print_list()
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "empty" << endl;
        return;
    }

    if (temp->get_next() == NULL)
    {
        cout << temp->get_data() << "--->";
        cout << "NULL" << endl;
    }
    else
    {
        do
        {
            cout << temp->get_data() << "+++>";
            temp = temp->get_next();
        } while (temp != NULL);
        cout << "NULL" << endl;
    }
}

void List::append_node(int data)
{
    Node *new_node = new Node();
    new_node->set_data(data);
    new_node->set_next(NULL);

    Node *temp = head;
    if (temp != NULL)
    {
        while (temp->get_next() != NULL)
        {
            temp = temp->get_next();
        }
        temp->set_next(new_node);
    }
    else
    {
        head = new_node;
    }
}

void List::delete_node(int data) //delete is special <3
{
    Node *temp = head;
    if (temp == NULL)
    {
        return;
    }
    else if (temp->get_data() == data)
    {
        head = head->get_next();
        delete temp;
    }
    else
    {
        Node *prev = NULL;
        while (temp != NULL)
        {
            if (temp->get_data() == data)
            {
                prev->set_next(temp->get_next());
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->get_next();
        }
    }
}

int main()
{
    List list;
    list.append_node(10);
    list.append_node(20);
    list.append_node(30);
    list.append_node(40);
    list.append_node(50);
    list.append_node(60);

    list.delete_node(20); //

    list.print_list();
    return 0;
}


//reverse iterative 5 lines in while

    void List::reverse()
    {
        Node *n1, *n2=NULL, *n3=NULL;
        n1 = head;
        while(n1!=NULL)
        {
            head = n1;
            n2 = n1->next;
            n1->next = n3;
            n3 = n1;
            n1 = n2;
        }
    }
