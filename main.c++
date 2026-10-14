#include <iostream>
#include <string> // for using the functionality of the string
using namespace std;
struct Node //  creating the doubly linked list here every line is node
{
    string text; //  for storing the text
    Node *next;  // for storing the next line address
    Node *prev;  // for storing the previous line address
};
void Editorcontroller() // for showing the menu
{
    cout << "1- Insert Text Selected " << endl;
    cout << "2- Delete Text Selected " << endl;
    cout << "3- Undo The Text " << endl;
    cout << "4- Redo the Text " << endl;
    cout << "5- Search Text " << endl;
    cout << "6- Replace Text " << endl;
    cout << "7- Display Document " << endl;
    cout << "8- Save Document " << endl;
    cout << "0- Exit" << endl;
    cout << "Choose the Above Option ";
}
void Insertcontroller()
{
    cout << "1- Insert Text in New Line " << endl;
    cout << "2- Insert Text at Position " << endl;
    cout << "3- Back " << endl;
    cout << "Choose the Above Option : " << endl;
}
void insertnew(struct Node *T) // here considering the T as head of the NODE
{
    int no;
    string t;
    cout << "Enter the Line Number : ";
    cin >> no;

    cin.ignore();

    cout << "Enter The Text to Insert : ";
    getline(cin, t);
    struct Node *temp; // for storing the info in the node
    struct Node *n;    //  for transversing
    temp = new Node();
    temp->text = t;
    if (T == nullptr)
    {
        T = temp;
        temp->next = nullptr;
        temp->prev = nullptr;
        return;
    }
    n = T;
    int count = 1;

    while (n != nullptr && count < no - 1) // here we using no-1 because insert before the line numbera
    {
        n = n->next;
        count++;
    }

    if (n == nullptr || no < 1)
    {
        delete temp;
        cout << "Invalid line number!";
        return;
    }
    temp->next = n->next;
    temp->prev = n;
    if (n->next != nullptr)
    {
        n->next->prev = temp;
    }
    n->next = temp;
}
void insertatpos(struct Node *T)
{
    int no, pos;
    string t;

    cout << "Enter the Line Number : ";
    cin >> no;

    cin.ignore();

    cout << "Enter the Text to Insert ";
    getline(cin, t);

    cout << "Enter the Index of Specific Position ";
    cin >> pos;

    if (T == nullptr || no < 1)
    {
        cout << "Invalid line number!";
        return;
    }
    int count = 1;
    struct Node *temp;
    temp = T;
    while (temp != nullptr && count < no)
    {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr)
    {
        cout << "Invalid Line Number!";
        return;
    }

    if (pos >= 0 && pos <= temp->text.length())
    {
        temp->text.insert(pos, t);
    }
    else
    {
        cout << "Invalid Index!";
        return;
    }
}
void insertatend(struct Node *T)  //  Will work on this at the end
void Deletecontroller()
{
    cout << "1- Delete Text in New Line "<<endl;
    cout << "2- Delete Text at Position "<<endl;
    cout << "3- Back "<<endl;
    cout << "Choose the Above Option : "<<endl;
}
void deletenew(struct Node*& T) // here T consider as a head of Node
{
    int line,count;
    count = 1;
    cout << "Enter the Line Number : ";
    cin >> line;

    if(T == nullptr)
    {
        cout << "Empty Document!";
        return;
    }

    if(line <= 0)
    {
        cout << "Invalid Line Number!";
        return;
    }

    if(line == 1)
    {
        struct Node*special = T;
        T = T->next;  // changing the head position forward
        if(T != nullptr)
        {
            T->prev = nullptr; 
        }
        delete special;
        return;
    }

    struct Node*temp;
    temp = T;
    while (temp != nullptr && count < line-1)
    {
        temp = temp->next;
        count++;
    }

    if(temp == nullptr)
    {
        cout << "Invalid Line Number!";
        return;
    }

    struct Node* var = temp->next;  // for storing the address of the element which is going to be delete; 
    if(var == nullptr)
    {
        cout << "Invalid Line Number!";
        return;
    }
    
    temp ->next = var ->next;
    if(var ->next != nullptr)
    {
        var ->next ->prev = temp;
    }
    delete var;
}
void deleteatpos(struct Node*T)
{

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
            case 1:   // dealing with inserting module
                Insertcontroller();
                cin >> choice;
                switch (choice)
                {
                case 1:
                    insertnew();
                    break;

                case 2:
                    insertatpos();
                    break;
                default:
                    return;
                    break;
                }
                break;
            case 2:  // dealing with deleting module
            Deletecontroller();
            cin >> choice;
            switch (choice)
            {
            case 1:
                
                break;
            
            default:
                break;
            }
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