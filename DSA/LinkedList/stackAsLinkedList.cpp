#include <iostream>
using namespace std;
 
 
struct Node
{
    int data;
    struct Node* link;
};
 
struct Node* top;
 
void push(int data)
{
     
    // Create new node temp and allocate memory
    struct Node* temp;
    temp = new Node();
 
    temp->data = data;
    temp->link = top;
    top = temp;
}
 
int isEmpty()
{
    return top == NULL;
}
 
int peek()
{
     
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}
 
void pop()
{
    struct Node* temp;
 
    if (top == NULL)
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {
         
        temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
}
 
void display()
{
    struct Node* temp;
 
    if (top == NULL)
    {
        cout << "\nStack Underflow";
        exit(1);
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
 
            cout << temp->data << endl;
            temp = temp->link;
        }
    }
}
 
int main()
{
     
    push(1);
    push(2);
    push(3);
    push(4);
 
    display();
 
    cout << "\nTop element is "
         << peek() << endl;
 
    pop();
    pop();
 
    display();
 
    cout << "\nTop element is "
         << peek() << endl;
          
    return 0;
}
 
