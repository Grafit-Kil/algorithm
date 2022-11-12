#include<iostream>

struct Node
{
    Node *next = nullptr;
    int data = 0;
};


class Root
{
private:
    int d = 1;
    Node *begin = new Node;
    Node *iter = begin;
    Node *end = begin;

public:
    Root();

    void display();
    void addNodeToListEnd(const int element_number);
    void addNodeToListEnd();
    void addNodeInsert(const int insert_index);
    void addNodeToListBegin();
    void deleteElement(const int delete_index);
    void deleteElementEnd();
};

Root::Root()
{
    begin->data = d;
    d++;
}

void Root::display()
{
    while (iter != nullptr)
    {
        std::cout << "Address& = " << iter << "  |  data = " << iter->data << "\n";
        iter = iter->next;
    }
    iter = begin;
    std::cout << "\nroot =  " << begin << "\n";
    std::cout << "iter  = " << iter << "\n";
    std::cout << "end  = " << end << "\n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void Root::addNodeToListEnd(const int element_number)
{
    for (size_t i = 0; i < element_number; i++)
    {
        end->next = new Node;
        end->next->data = d;
        end = end->next;
        d++;
    }
}

void Root::addNodeToListEnd()
{
    end->next = new Node;
    end->next->data = d;
    d++;
    end = end->next;
}

void Root::addNodeInsert(const int insert_index)
{

    int count = 0;
    while (iter->next != nullptr && count <= insert_index)
    {
        if (count+1 == insert_index)
        {
            Node *temp = new Node;
            temp->data = d;
            d++;
            temp->next = iter->next;
            iter->next = temp;
            break;
        }
        iter = iter->next;
        count++;
    }
    iter = begin;
}

void Root::addNodeToListBegin()
{
    iter = new Node;
    iter->data = d;
    iter->next = begin;
    begin = iter;
    d++;
}

void Root::deleteElement(const int delete_index)
{
    if (begin->next == nullptr)
    {
        std::cerr << "There are no element to delete.";
    }

    if (begin != nullptr && begin->next != nullptr && delete_index <= 0)
    {
        Node *temp = new Node;
        temp = begin;
        begin = begin->next;
        iter = begin;
    }

    int count = 0;
    while (iter->next != nullptr && count <= delete_index)
    {
        if (iter->next->next == nullptr)
        {
            iter = begin;
            deleteElementEnd();
            break;
        }

        if (count + 1 == delete_index)
        {
            Node *temp = new Node;
            temp->next = iter->next->next;
            delete iter->next;
            iter->next = temp->next;
            delete temp;
        }
        iter = iter->next;
        count++;
    }
    iter = begin;
}

void Root::deleteElementEnd()
{
    if(iter->next != nullptr){
    Node * temp = new Node;
        temp->next = end;
        while(iter->next != nullptr){
            if(iter->next->next == nullptr){
                end = iter;
                end->next = nullptr; 
                iter = begin;
                temp->next = nullptr;
                delete temp;
                break;
            }
            iter = iter->next;
        }
    }
    else{
        std::cout << "Not deleted.\n";
    }
}


int main()
{
    Root root;
    root.display();
    root.addNodeToListEnd(12);
    root.display();
    root.addNodeToListEnd();
    root.display();
    root.addNodeToListBegin();
    root.addNodeToListBegin();
    root.display();
    root.addNodeInsert(4);
    root.display();
    root.deleteElement(7);
    root.display();
    root.deleteElement(20);
    root.display();
    root.deleteElement(0);
    root.display();
    root.deleteElementEnd();
    root.display();
}
