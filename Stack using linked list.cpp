// Stack using linked list.cpp : 

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node()
    {
        data = 0;
        next = nullptr;
    }
};
class Stack
{
private:
    Node* top;
public:
    Stack()
    {
        top = nullptr;
    }
    ~Stack()
    {
        Clear();
    }
    bool IsEmpty()
    {
        return top == nullptr;
    }
    void Push(int value)
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
    int Pop()
    {
        if (IsEmpty())
        {
            cout << "Stack is Empty you can't delete" << endl;
            return -1;
        }
        Node* delptr = top;
        int delValue = delptr->data;
        top = top->next;
        delete delptr;
        return delValue;
    }
    void Clear()    
    {
        while(!IsEmpty())
        {            
            Pop();
        }
    }
    void Print()
    {
        if (IsEmpty())
        {
            cout << "Stack is Empty " << endl;
        }
        else
        {
            cout << "Stack is :";
            Node* temp = top;
            while (temp != nullptr)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
    int Count()
    {
        int counter = 0;
            Node* temp = top;
            while (temp != nullptr)
            {
                counter++;
                temp = temp->next;
            }
        return counter;
    }
    int Top()
    {
        if(IsEmpty())
        {
            cout << "Stack is Empty " << endl;
            return -1;
        }
        return top->data ;
    }
    bool IsFound(int value)
    {
            Node* temp = top;
            while (temp != nullptr)
            {
                if (temp->data == value)
                    return true;
                   temp = temp->next;
            }
            return false;
    }
};
int main()
{
    Stack s;
    for (int i = 0; i < 4; i++)
    {
        int x;
        cout << "add num to stack " << endl;
        cin >> x;
        s.Push(x);
    }
    s.Print();
    cout << "The top is " << s.Top() << endl;
    cout << "count of stack is " << s.Count() << endl;
    cout << "After pop : " << endl;
    s.Pop();
    s.Print();
    cout << "The top is " << s.Top() << endl;
    cout << "count of stack is " << s.Count() << endl;
    int check;
    cout << "Enter num to check if it exist " << endl;
    cin >> check;
    if (s.IsFound(check))
    {
        cout << check << "is found " << endl;
    }
    else
    {
        cout << check << " is not found " << endl;
    }
}

