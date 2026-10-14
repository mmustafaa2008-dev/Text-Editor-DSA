#include <iostream>
using namespace std;
void secontroller()
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
            secontroller();
            cin >> choice;
            switch (choice)
            {
            case 1:
                // for inserting the text //  using the 
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