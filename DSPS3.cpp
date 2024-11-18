#include <iostream>
using namespace std;

int n, r;

class student {
    int roll;
    char name[10], T_name[100];
    
    public:
        void accept();
        void display();
        void Lsearch();
        void Bsearch();
}s[100];

void student::accept() {
    cout << "Enter the Roll no:";
    cin>>roll;
    cout<<"Enter the Name of student:";
    cin>>name;
    cout<<"Enter the Traning name:";
    cin>>T_name;
}

void student::display() 
{
    cout << "\n" << roll << "\t" << name << "\t" <<T_name;
}

void student::Lsearch()
{
    cout << "Enter the roll number of the student you want to search: ";
    cin >> r;
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].roll == r)
        {
            cout << "Student Attended training Program.\n";
            f = 1;
            break;
        }
    }
    if (f == 0)
    {
        cout << "Student not attended training Program.\n";
    }
}

void student::Bsearch()
{
    
    student temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i].roll > s[j].roll) 
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    cout << "Enter the roll number of the student you want to search: ";
    cin >> r;

    int low = 0, high = n - 1, mid;
    int f = 0;
    
    while (low <= high) {
        mid = (low + high) / 2;
        if (s[mid].roll == r) {
            f = 1;
            break;
        } else if (s[mid].roll < r) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    if (f == 1) {
        cout << "Student Attended training Program.\n";
    } else {
        cout << "Student  not attended training Program.\n";
    }
}

int main() {
    int ch;
    cout << "Enter the total number of students: ";
    cin >> n;

    do {
        cout << "\nMENU\n" << "1. ACCEPT\n" << "2. DISPLAY\n" << "3. LINEAR SEARCH\n" << "4. BINARY SEARCH\n";
        cout << "Enter Choice (Enter 0 for exit): ";
        cin >> ch;

        switch (ch) {
            case 1:
                for (int i = 0; i < n; i++) {
                    s[i].accept();
                }
                break;

            case 2:
                cout << "\n" << "Roll NO." << "\t" << "Name" << "\t" << "T_name";
                for (int i = 0; i < n; i++) {
                    s[i].display();
                }
                break;

            case 3:
                s[0].Lsearch();
                break;

            case 4:
                s[0].Bsearch();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (ch != 0);

    return 0;
}