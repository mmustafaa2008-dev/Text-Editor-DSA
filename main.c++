#include <iostream>
#include <string>   // for using the functionality of the string 
using namespace std;
void Editorcontroller()   // for showing the menu
{
    cout << "1- Insert Text Selected " << endl;
    cout << "2- Delete Text Selected " << endl;
    cout << "3- Undo The Text " << endl;
    cout << "4- Redo the Text " << endl;
    cout << "5- Search Text " << endl;
    cout << "6- Replace Text " << endl;
    cout << "7- Display Document "<<endl;
    cout << "8- Save Document " << endl;
    cout << "0- Exit" << endl;
    cout << "Choose the Above Option ";
}
void Insertcontroller()
{
    cout << "1- Insert New Line "<<endl;
    cout << "2- Insert at Position "<<endl;
    cout << "3- Back "<<endl;
    cout << "Choose the Above Option "<<endl;
} 
struct Node   //  creating the doubly linked list here every line is node 
{
    string text;  //  for storing the text
    Node* next;   // for storing the next line address
    Node* prev;  // for storing the previous line address
};

void insertnew(struct Node* T) // here considering the T as head of the NODE
{
    int no;
    string t;
    cout << "Enter the Line Number : ";
    cin >> no;

    cin.ignore();

    cout << "Enter The Text to Enter : ";
    getline(cin, t);
    struct Node* temp;  // for storing the info in the node
    struct Node* n;  //  for transversing
    temp = new Node();
    temp ->text = t;
    if(T== nullptr)
    {
        T = temp;
        temp -> next = nullptr;
        temp -> prev = nullptr;
        return;
    }
    n = T;
    int count =1;

    while (n != nullptr && count < no-1)  // here we using no-1 because insert before the line numbera
    {
        n = n->next;
        count ++;
    }

    if(n == nullptr || no < 1)
    {
        delete temp;
        cout << "Invalid line number!";
        return;
    }
    temp ->next = n->next;
    temp -> prev = n;
    if(n->next != nullptr)
    {
        n->next->prev = temp;
    }
    n->next = temp;
}
void controller()
{
    cout << "Welcome to the Text Editor" << endl;
    int choice;
    do
    {
        cout << "1- Create New Document " << endl;
        cout << "2- Open Existing Document " << endl;
        cout << "0- Exit" << endl;
        cout << "Choose the Above Option : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // for the create new document
            break;

        case 2:
            Editorcontroller();
            cin >> choice;
            switch (choice)
            {
            case 1:
                Insertcontroller();
                cin >> choice;
                switch (choice)
                {
                case 1:
                    insertnew();
                    break;
                
                default:
                    break;
                }
                break;
            
            default:
                break;
            }
            break;
        default:
            break;
        }
    } while (choice != 0);
}
int main()
{
}