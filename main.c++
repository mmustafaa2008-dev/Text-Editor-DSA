#include <iostream>
#include <string> // for using the functionality of the string
#include <cctype> //  for comparing the lower and upper case
using namespace std;
struct Node //  creating the doubly linked list here every line is node
{
    string text; //  for storing the text
    Node *next;  // for storing the next line address
    Node *prev;  // for storing the previous line address
};
void Editorcontroller() // for showing the menu
{
    cout << "1- Insert Text Selected " << endl; // done
    cout << "2- Delete Text Selected " << endl; // done
    cout << "3- Search Text " << endl;
    cout << "4- Replace Text " << endl;
    cout << "5- Undo The Text " << endl; // done
    cout << "6- Redo the Text " << endl; //  done
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
void insertnew(struct Node *&T) // here considering the T as head of the NODE
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
void insertatend(struct Node *T) //  Will work on this at the end
{
}
void Deletecontroller()
{
    cout << "1- Delete Text in New Line " << endl;
    cout << "2- Delete Text at Position " << endl;
    cout << "3- Delete Range of Line " << endl;
    cout << "0- Back " << endl;
    cout << "Choose the Above Option : " << endl;
}
void deletenew(struct Node *&T) // here T consider as a head of Node
{
    int line, count;
    count = 1;
    cout << "Enter the Line Number : ";
    cin >> line;

    if (T == nullptr)
    {
        cout << "Empty Document!";
        return;
    }

    if (line <= 0)
    {
        cout << "Invalid Line Number!";
        return;
    }

    if (line == 1)
    {
        struct Node *special = T;
        T = T->next; // changing the head position forward
        if (T != nullptr)
        {
            T->prev = nullptr;
        }
        delete special;
        return;
    }

    struct Node *temp;
    temp = T;
    while (temp != nullptr && count < line - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr)
    {
        cout << "Invalid Line Number!";
        return;
    }

    struct Node *var = temp->next; // for storing the address of the element which is going to be delete;
    if (var == nullptr)
    {
        cout << "Invalid Line Number!";
        return;
    }

    temp->next = var->next;
    if (var->next != nullptr)
    {
        var->next->prev = temp;
    }
    delete var;
}
void deleteatpos(struct Node *&T)
{
    int line, count;
    size_t index;
    string t;
    count = 1;
    cout << "Enter the Line Number : ";
    cin >> line;

    cin.ignore();
    do
    {
        getline(cin, t);
    } while (t.empty());

    if (T == nullptr)
    {
        cout << "Empty Document!";
        return;
    }

    if (line <= 0)
    {
        cout << "Invalid Line Number!";
        return;
    }

    struct Node *temp = T;
    while (temp != nullptr && count < line)
    {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr)
    {
        cout << "Invalid Line Number!";
        return;
    }

    index = temp->text.find(t);
    if (index != string::npos) // here npos stands for not found
    {
        temp->text.erase(index, t.length());
        cout << "Text Deleted Successfully!";
    }
    else
    {
        cout << "Text Not Found in this Line!";
    }
}
void deleterange(struct Node *&T)
{
    int start, end, count = 0;

    cout << "Enter Starting Line: ";
    cin >> start;

    cout << "Enter Ending Line: ";
    cin >> end;

    if (T == nullptr)
    {
        cout << "Empty Document!";
        return;
    }
    struct Node *temp = T;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    if (start < 1 || end < start || end > count)
    {
        cout << "Invalid Line Range!";
        return;
    }

    temp = T;
    count = 1;
    // Move to the starting line
    while (count < start)
    {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr)
    {
        cout << "Invalid Starting Line!";
        return;
    }

    struct Node *before = temp->prev;

    // Delete nodes from start to end
    count = start;

    while (count <= end)
    {
        struct Node *del = temp;
        temp = temp->next;
        delete del;
        count++;
    }

    // Reconnect the remaining list
    if (before != nullptr)
    {
        before->next = temp;
    }
    else
    {
        T = temp;
    }

    if (temp != nullptr)
    {
        temp->prev = before;
    }

    cout << "Lines Deleted Successfully!";
}
void searchcontroller()
{
    cout << "1- Search Text in Document " << endl;
    cout << "2- Search Text in Specific Line " << endl;
    cout << "3- Search Text Without Case Sensitive " << endl;
    cout << "0- Exit " << endl;
    cout << "Choose the Above Option : ";
}
void searchtext(struct Node *T, string element)
{
    struct Node *temp = T;
    int count = 1;
    int occ = 0; // for storing the occurrence of the element in the line or document
    if (temp == nullptr)
    {
        cout << "Empty Document" << endl;
        return;
    }
    while (temp != nullptr)
    {
        size_t index = temp->text.find(element); //  for storing the index of the text if found
        while (index != string::npos)            // searching for the text in the same line
        {
            cout << "Line Number : " << count << endl;
            cout << "Index Number : " << index << endl;
            oc++;
            index = temp->text.find(element, index + element.length()); // if found the index then we add the element index + length of the text for finding next text
        }
        temp = temp->next;
        count++;
    }
    if (occ > 0)
    {
        cout << "Total Occurrences: " << occ << endl;
    }
    else
    {
        cout << "Text Not Found in the Document!" << endl;
    }
}
void specifictext(struct Node *T)
{
    int line;
    string text;
    cout << "Enter the Line Number : ";
    cin >> line;
    int count = 1;

    if (line < 1)
    {
        cout << "Invalid Line Number!";
        return;
    }
    cin.ignore();

    cout << "Enter the Desired Text To Search : ";
    getline(cin, text);

    if (T == nullptr)
    {
        cout << "Empty Document";
        return;
    }

    if (text.empty())
    {
        cout << "Search text cannot be empty!";
        return;
    }

    struct Node *temp = T;
    while (temp != nullptr && count < line) // transver for going to the specific line number
    {
        temp = temp->next;
        count++;
    }
    if (temp == nullptr)
    {
        cout << "Invalid Line Number!";
        return;
    }

    int occ = 0;

    size_t index = temp->text.find(text);
    while (index != npos)
    {
        cout << "Index Number : " << index << endl;
        occ++;
        index = temp->text.find(text, index + text.length());
    }
    if (occ > 0)
    {
        cout << "Total Occurrences: " << occ << endl;
    }
    else
    {
        cout << "Text Not Found in the Line Number " << line << endl;
    }
}
void caseinsensitivesearch(struct Node *T, string element)
{
    struct Node *temp = T;
    int count = 1;
    int occ = 0; // for storing the occurrence of the element in the line or document
    if (temp == nullptr)
    {
        cout << "Empty Document" << endl;
        return;
    }
    for (int i = 0; i < element.length(); i++)
    {
        element[i] = tolower(element[i]);
    }
    while (temp != nullptr)
    {
        string line = temp->text;
        for (int i = 0; i < line.length(); i++)
        {
            line[i] = tolower(line[i]);
        }
        size_t index = line.find(element); //  for storing the index of the text if found
        while (index != string::npos)      // searching for the text in the same line
        {
            cout << "Line Number : " << count << endl;
            cout << "Index Number : " << index << endl;
            oc++;
            index = line.find(element, index + element.length()); // if found the index then we add the element index + length of the text for finding next text
        }
        temp = temp->next;
        count++;
    }
    if (occ > 0)
    {
        cout << "Total Occurrences: " << occ << endl;
    }
    else
    {
        cout << "Text Not Found in the Document!" << endl;
    }
}
void replacecontroller()
{
    cout << "1- Replace Specific Occurence " << endl;
    cout << "2- Replace All Occurence " << endl;
    cout << "3- Replace In Line " << endl;
    cout << "4- Replace Case Insensitive Word " << endl;
    cout << "0- Exit " << endl;
    cout << "Select The Above Option : ";
}
void specificoccurence(struct Node *T) // replacing all specific number occurence in the document
{
    string t, r;
    int occ;
    cout << "Enter the Text to Replace : ";
    getline(cin, t);

    cout << "Enter the Replace Text : ";
    getline(cin, r);

    cout << "Enter the Occurence Number : ";
    cin >> occ;

    if (T == nullptr)
    {
        cout << "Empty Document!";
        return;
    }

    if (t.empty() || occ < 1)
    {
        cout << "Invalid Input!";
        return;
    }

    struct Node *temp = T;
    int count = 0;
    while (temp != nullptr)
    {
        size_t index = temp->text.find(t);

        while (index != npos || count < occ)
        {
            count++;
            if (count == occ)
            {
                temp->text.erase(index, t.length());
                temp->text.insert(index, r);
                cout << "Text Replaced Successfully!";
                return;
            }
            index = temp->text.find(t, index + t.length());
        }
        temp = temp->next;
    }
    cout << "Specified Occurrence Not Found!";
}
void alloccurence(struct Node *T) // replacing all the occurence in the document
{
    string t, r;
    cout << "Enter the Text to Replace : ";
    getline(cin, t);

    cout << "Enter the Replace Text : ";
    getline(cin, r);

    if (T == nullptr)
    {
        cout << "Empty Document!";
        return;
    }

    if (t.empty())
    {
        cout << "Invalid Input!";
        return;
    }

    int count = 0;
    struct Node *temp = T;

    while (temp != nullptr)
    {
        size_t index = temp->text.find(t);

        while (index != npos)
        {
            temp->text.erase(index, t.length());
            temp->text.insert(index, r);
            count++;
            index = temp->text.find(t, index + r.length());
        }
        temp = temp->next;
    }
    if (count == 0)
    {
        cout << "Word Not Found In the Entire Document!" << endl;
        return;
    }
    cout << "Replaced " << count << " Occurrences Successfully!" << endl;
}
void occurenceinline(struct Node *T) // replacing the occurence in the specific line number
{
    string t, r;
    int line;
    cout << "Enter the Text to Replace : ";
    getline(cin, t);

    cout << "Enter the Replace Text : ";
    getline(cin, r);

    cout << "Enter the Line Number : ";
    cin >> line;

    if (T == nullptr)
    {
        cout << "Empty Document!";
        return;
    }

    if (t.empty() || line < 1)
    {
        cout << "Invalid Input!";
        return;
    }

    int count = 1;
    struct Node *temp = T;
    while (temp != nullptr && count < line) // going toward the desired line number
    {
        count++;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Invalid Line Number!";
        return;
    }
    size_t index = temp->text.find(t);

    int occ = 0;
    while (index != npos)
    {
        temp->text.erase(index, t.length());
        temp->text.insert(index, r);
        occ++;
        index = temp->text.find(t, index + r.length());
    }

    if (occ == 0)
        cout << "Text Not Found in the Specified Line!";
    else
        cout << "Replaced " << occ << " Occurrences Successfully!";
}
void ignorecasesensitive(struct Node *T) // here replacing all case insensitive word
{
    string t, r;

    cout << "Enter the Text to Replace: ";
    getline(cin, t);

    cout << "Enter the Replace Text: ";
    getline(cin, r);

    if (T == nullptr)
    {
        cout << "Empty Document!";
        return;
    }

    if (t.empty())
    {
        cout << "Invalid Input!";
        return;
    }
    struct Node *temp = T;
    int occ = 0; // for storing the occurrence of the element in the line or document

    for (int i = 0; i < t.length(); i++)
    {
        t[i] = tolower(t[i]);
    }
    while (temp != nullptr)
    {
        string line = temp->text;
        for (int i = 0; i < line.length(); i++)
        {
            line[i] = tolower(line[i]);
        }
        size_t index = line.find(t); //  for storing the index of the text if found

        while (index != string::npos) // searching for the text in the same line
        {
            temp->text.erase(index, t.length());
            temp->text.insert(index, r);
            oc++;

            line = temp->text;
            for (int i = 0; i < line.lenth(); i++)
            {
                line[i] = tolower(line[i]); // update the lower after the replacement
            }
            index = line.find(t, index + r.length()); // if found the index then we add the element index + length of the text for finding next text
        }
        temp = temp->next;
    }
    if (occ > 0)
    {
        cout << "Replaced " << occ << " Occurrences Successfully!";
    }
    else
    {
        cout << "Text Not Found in the Document!" << endl;
    }
}
void displaydocument(struct Node* T)
{
    int line=0,character=0;
    if(T==nullptr)
    {
        cout << "Empty Document!"<<endl;
        cout << "Total Line : 0 "<<endl;
        cout << "Total Character : 0 "<<endl;
        return;
    }
    
    struct Node*temp = T;
    while (temp != nullptr)
    {
        line++;
        character += temp->text.length();
        cout << "Line "<<line<<" "<<temp->text <<endl;
        temp = temp->next;
    }

    cout << "Total Line : "<<line<<endl;
    cout << "Total Character : "<<character<<endl;
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
            case 1: // dealing with inserting module
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
                    break;
                }
                break;
            case 2: // dealing with deleting module
                Deletecontroller();
                cin >> choice;
                switch (choice)
                {
                case 1:
                    deletenew();
                    break;

                case 2:
                    deleteatpos();
                    break;

                case 3:
                    deleterange();
                    break;

                default:
                    break;
                }
                break;

            case 3:
                searchcontroller(); // dealing with Search Module
                cin >> choice;
                switch (choice)
                {
                case 1:
                    searchtext();
                    break;

                case 2:
                    specifictext(); // for searching the desired text in the specific line number
                    break;

                case 3:
                    caseinsensitivesearch();
                    break;
                }
                break;

            case 4:
                replacecontroller(); //  dealing with Replace Module
                cin >> choice;
                switch (choice)
                {
                case 1:
                    specificoccurence();
                    break;

                case 2:
                    alloccurence();
                    break;

                case 3:
                    occurenceinline();
                    break;

                case 4:
                    ignorecasesensitive();
                    break;

                default:
                    break;
                }
                break;

            case 5:  // undo
            break;

            case 6:  // redo
            break;

            case 7:  // display document
            displaydocument();
            break;


            default:
                break;
            }
        }
        while (choice != 0);
    }
}
int main()
{
}