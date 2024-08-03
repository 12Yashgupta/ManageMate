
#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<bits/stdc++.h>
class Employee;
using namespace std;
// Function declarations
void displayEmployees(const vector<Employee> &employees);
void tableDisplayEmployees(const vector<Employee> &employees);
void idSort(vector<Employee> &employees);
void nameSort(vector<Employee> &employees);
void salarySort(vector<Employee> &employees);
void expSort(vector<Employee> &employees);
void highestSalary(const vector<Employee> &employees);
void highestExp(const vector<Employee> &employees);
void searchEmployee(const vector<Employee> &employees);
void modifyEmployee(vector<Employee> &employees);
void addEmployee(vector<Employee> &employees);
void deleteEmployee(vector<Employee> &employees);
int menuChoice(vector<Employee> &employees);
Employee enterEmployeeData();
void EmployeeManagement();
void login();
void registration();
void forgot();





int main()
{
        int c;   // c for choice
        cout<<"\t\t\t__________________________________________________________________________\n\n\n";
        cout<<"\t\t\t                     Welcome to the Login page                               \n\n";
        cout<<"\t\t\t______________________        MENU        ________________________________\n\n";
        cout<<"                                                                                \n\n";
        cout<<"\t|  Press 1 to LOGIN                    |"<<endl;
        cout<<"\t|  Press 2 to REGISTER                 |"<<endl;
        cout<<"\t|  Press 3 if you forgot your PASSWORD |"<<endl;
        cout<<"\t|  Press 4 to Exit                     |"<<endl;
        cout<<"\n\t\t\tPlease Enter your choice :";
        cin>>c;
        cout<<endl;
        switch(c)
        {
                case 1:
                        login();
                        break;
                case 2:
                        registration();
                        break;
                case 3:
                        forgot();
                        break;
                case 4:

                        cout<<"\t\t\tThankyou!\n\n";
                        break;
                default:
                        system("cls");
                        cout<<"\t\t\tPlease select from the options given above , Try again..\n"<<endl;
                        main();
        }

}


//Login For User
void login()
{
        
        
        int count;
        string userId,password,id,pass;
        system("cls");
        cout<<"\t\t\tplease enter the username & password"<<endl;
        cout<<"\t\t\tUSERNAME :";
        cin>>userId;
        cout<<"\t\t\tPASSWORD :";
        cin>>password;

        ifstream input("records.txt");
        while(input>>id>>pass)                     //here reading is taking place
        {
                if(id==userId && pass==password)

                {
                        count=1;
                        system("cls");
                }
        }
        input.close();     //this is for closing the file
        if(count==1)
        {
                cout<<userId<<"\n Your Login is Successful\nThanks for logging in!\n";
               // cin.get();
              //  cin.get();
               EmployeeManagement();
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                main();
        }
}

//Signup for user

void registration()
{

        string ruserId,rpassword,rid,rpass;
        system("cls");
        cout<<"\t\t\tEnter the username :";
        cin>>ruserId;
        cout<<"\n\t\t\tEnter the password :";
        cin>>rpassword;

        ofstream f1("records.txt",ios::app);
        f1<<ruserId<<' '<<rpassword<<endl;             //here we are writing the information in the file.
        system("cls");
        cout<<"\n\t\t\tRegistration is Successful\n";
        main();


}
//Incase if poassword is forgoten
void forgot()
{
        int option;
        system("cls");
        cout<<"\t\t\tYou forgot your password? No worries\n";
        cout<<"Press 1 to Search your id by username"<<endl;
        //cout<<"2.Search your id by password"<<endl;
        cout<<"Press 2 to go Back to the Main menu"<<endl;
        cout<<"\t\t\tEnter your choice :";
        cin>>option;
        switch(option)
        {
                case 1:
                {
                        int count=0;
                        string suserId,sId,spass;
                        cout<<"\n\t\t\tEnter the username which you remembered :";
                        cin>>suserId;

                        ifstream f2("records.txt");
                        while(f2>>sId>>spass)
                        {
                                if(sId==suserId)
                                {
                                        count=1;
                                }
                        }
                        f2.close();
                        if(count==1)
                        {
                                cout<<"\n\n\tYour account is found\n";
                                cout<<"\n\tYour password is "<<spass;
                            //    cin.get();
                            //    cin.get();
                              //  system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"\n\tSorry, Account not found! \n";
                            //    cin.get();
                            //    cin.get();
                                main();
                        }
                        
                        break;
                }
             break;
                case 2:
                {
                       // cin.get();
                        main();
                }
                default:
                        cout<<"\t\t\tWrong choice! Please try again"<<endl;
                        forgot();
        }
}



//Employee management code
class Employee {
private:
    int id;
    string name;
    int salary;
    float exp;

public:
    // Constructor
    Employee(int id, const string &name, int salary, float exp)
        : id(id), name(name), salary(salary), exp(exp) {}

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    int getSalary() const { return salary; }
    float getExp() const { return exp; }

    // Setters
    void setId(int newId) { id = newId; }
    void setName(const string &newName) { name = newName; }
    void setSalary(int newSalary) { salary = newSalary; }
    void setExp(float newExp) { exp = newExp; }

    // Display employee information
    void display() const {
        cout << "Id number: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Work experience: " << exp << " years" << endl;
    }

    // Display employee information in table format
    void tableDisplay(int index) const {
        printf("|  %d   |   %d   |  %d   |    %.2f years    |   %s        \n",
               index + 1, id, salary, exp, name.c_str());
    }
};




// Employee Management function
void EmployeeManagement() {
    int n;
    cout << "Enter the number of employees." << endl;
    cin >> n;
    vector<Employee> employees;

    for (int i = 0; i < n; i++) {
        cout << "Enter the details of " << i + 1 << " employee." << endl;
        employees.push_back(enterEmployeeData());
    }

    displayEmployees(employees);
    tableDisplayEmployees(employees);

    char ch;
    do {
        menuChoice(employees);

        cout << "Press N to exit program or Y to continue." << endl;
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    cout << "********************PROGRAM HAS BEEN TERMINATED*********************\n\n";
    cout << "*****************************THANK YOU!*****************************\n";

  
}


// Enter employee data
Employee enterEmployeeData() {
    int id, salary;
    string name;
    float exp;
    int i = 0, c = 0;

    do {
        if (i == 0) {
            cout << "Enter id number in 3 digits." << endl;
            cin >> id;
        } else {
            cout << "Entered id number is not in 3 digits." << endl;
            cout << "Enter id number in 3 digits." << endl;
            cin >> id;
        }
        c = 0;
        for (int j = id; j != 0; j = j / 10)
            c++;
        i++;
    } while (c != 3);

    cin.ignore(); // Clear the input buffer
    cout << "Enter name of the employee." << endl;
    getline(cin, name);

    i = c = 0;
    do {
        if (i == 0) {
            cout << "Enter salary in 5 digits." << endl;
            cin >> salary;
        } else {
            cout << "Entered salary is not in 5 digits." << endl;
            cout << "Enter salary in 5 digits." << endl;
            cin >> salary;
        }
        c = 0;
        for (int j = salary; j != 0; j = j / 10)
            c++;
        i++;
    } while (c != 5);

    cout << "Enter work experience in years." << endl;
    cin >> exp;

    return Employee(id, name, salary, exp);
}

// Display all employees
void displayEmployees(const vector<Employee> &employees) {
    cout << endl;
    for (size_t i = 0; i < employees.size(); i++) {
        cout << "Info related to " << i + 1 << " employee:" << endl;
        employees[i].display();
        cout << endl;
    }
}

// Display employees in tabular form
void tableDisplayEmployees(const vector<Employee> &employees) {
    cout << "********************Tabular display of data********************\n";
    cout << " _________________________________________________________________\n";
    cout << "|                                                                 |\n";
    cout << "|S. No.|Id number|  Salary  | Work experience  |       Name       |\n";
    cout << "|_________________________________________________________________|\n";
    for (size_t i = 0; i < employees.size(); i++) {
        employees[i].tableDisplay(i);
    }
    cout << "|_________________________________________________________________|\n";
}

// Sort employees by id
void idSort(vector<Employee> &employees) {
    sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b) {
        return a.getId() < b.getId();
    });
}

// Sort employees by name
void nameSort(vector<Employee> &employees) {
    sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b) {
        return a.getName() < b.getName();
    });
}

// Sort employees by salary
void salarySort(vector<Employee> &employees) {
    sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b) {
        return a.getSalary() < b.getSalary();
    });
}

// Sort employees by experience
void expSort(vector<Employee> &employees) {
    sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b) {
        return a.getExp() < b.getExp();
    });
}

// Display employee with highest salary
void highestSalary(const vector<Employee> &employees) {
    auto maxIt = max_element(employees.begin(), employees.end(), [](const Employee &a, const Employee &b) {
        return a.getSalary() < b.getSalary();
    });

    if (maxIt != employees.end()) {
        cout << "Person with highest salary is:" << endl;
        cout << " _________________________________________________________\n";
        cout << "|                                                         |\n";
        cout << "|Id number|  Salary  | Work experience |       Name       |\n";
        cout << "|_________________________________________________________|\n";
        maxIt->tableDisplay(0);
        cout << "|_________________________________________________________|\n";
    }
}

// Display employee with highest experience
void highestExp(const vector<Employee> &employees) {
    auto maxIt = max_element(employees.begin(), employees.end(), [](const Employee &a, const Employee &b) {
        return a.getExp() < b.getExp();
    });

    if (maxIt != employees.end()) {
        cout << "Person with highest work experience is:" << endl;
        cout << " _________________________________________________________\n";
        cout << "|                                                         |\n";
        cout << "|Id number|  Salary  | Work experience |       Name       |\n";
        cout << "|_________________________________________________________|\n";
        maxIt->tableDisplay(0);
        cout << "|_________________________________________________________|\n";
    }
}

// Search for employee by id or name
void searchEmployee(const vector<Employee> &employees) {
    int i, id, m = 0;
    string name;
    cout << "Press 1 to search data using id number.\nPress 2 to search data using name.\n";
    cin >> i;

    if (i == 1) {
        cout << "Enter the id number to search data." << endl;
        cin >> id;
        cout << " _________________________________________________________\n";
        cout << "|                                                         |\n";
        cout << "|Id number|  Salary  | Work experience |       Name       |\n";
        cout << "|_________________________________________________________|\n";
        for (size_t j = 0; j < employees.size(); j++) {
            if (employees[j].getId() == id) {
                employees[j].tableDisplay(j);
                cout << "|_________________________________________________________|\n";
                m++;
            }
        }
    } else if (i == 2) {
        cout << "Enter the name to search data." << endl;
        cin.ignore();
        getline(cin, name);
        cout << " _________________________________________________________\n";
        cout << "|                                                         |\n";
        cout << "|Id number|  Salary  | Work experience |       Name       |\n";
        cout << "|_________________________________________________________|\n";
        for (size_t j = 0; j < employees.size(); j++) {
            if (employees[j].getName() == name) {
                employees[j].tableDisplay(j);
                cout << "|_________________________________________________________|\n";
                m++;
            }
        }
    } else {
        cout << "Entered number is invalid." << endl;
    }

    if (m == 0)
        cout << "Sorry, no data has been found related to your search." << endl;
}

// Modify employee data
void modifyEmployee(vector<Employee> &employees) {
    int id, found = 0;
    cout << "Enter the id number of employee whose data you want to modify." << endl;
    cin >> id;

    for (size_t i = 0; i < employees.size(); i++) {
        if (employees[i].getId() == id) {
            employees[i] = enterEmployeeData();
            found++;
            cout << "Data has been modified." << endl;
            break;
        }
    }

    if (found == 0)
        cout << "Employee with id number " << id << " not found." << endl;
}

// Add a new employee
void addEmployee(vector<Employee> &employees) {
    cout << "Enter the details of the new employee." << endl;
    employees.push_back(enterEmployeeData());
    cout << "Data has been added." << endl;
}

// Delete an employee
void deleteEmployee(vector<Employee> &employees) {
    int id, found = 0;
    cout << "Enter the id number of employee whose data you want to delete." << endl;
    cin >> id;

    auto it = remove_if(employees.begin(), employees.end(), [id](const Employee &e) {
        return e.getId() == id;
    });

    if (it != employees.end()) {
        employees.erase(it, employees.end());
        cout << "Data has been deleted." << endl;
    } else {
        cout << "Employee with id number " << id << " not found." << endl;
    }
}

// Menu for user choices
int menuChoice(vector<Employee> &employees) {
    int choice;
    cout << "Enter your choice from the menu below." << endl;
    cout << "1. Sort data using id number.\n"
         << "2. Sort data using name.\n"
         << "3. Sort data using salary.\n"
         << "4. Sort data using work experience.\n"
         << "5. Search data.\n"
         << "6. Modify data.\n"
         << "7. Add data.\n"
         << "8. Delete data.\n"
         << "9. Display person with highest salary.\n"
         << "10. Display person with highest work experience.\n";
    cin >> choice;

    switch (choice) {
    case 1:
        idSort(employees);
        tableDisplayEmployees(employees);
        break;
    case 2:
        nameSort(employees);
        tableDisplayEmployees(employees);
        break;
    case 3:
        salarySort(employees);
        tableDisplayEmployees(employees);
        break;
    case 4:
        expSort(employees);
        tableDisplayEmployees(employees);
        break;
    case 5:
        searchEmployee(employees);
        break;
    case 6:
        modifyEmployee(employees);
        tableDisplayEmployees(employees);
        break;
    case 7:
        addEmployee(employees);
        tableDisplayEmployees(employees);
        break;
    case 8:
        deleteEmployee(employees);
        tableDisplayEmployees(employees);
        break;
    case 9:
        highestSalary(employees);
        break;
    case 10:
        highestExp(employees);
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
    }

    return choice;
}
