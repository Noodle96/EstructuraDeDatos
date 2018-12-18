#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;

class Student
{
    int admno;
    char name[50];
public:
    void setData()
    {
        cout << "\nEnter admission no. ";
        cin >> admno;
        cout << "Enter name of student ";
        cin.getline(name,50);
    }

    void showData()
    {
        cout << "\nAdmission no. : " << admno;
        cout << "\nStudent Name : " << name;
    }

    int retAdmno()
    {
        return admno;
    }
};

/*
* function to write in a binary file.
*/

void write_record()
{
    ofstream outFile;
    outFile.open("student.dat", ios::binary | ios::app);

    Student obj;
    obj.setData();

    outFile.write((char*)&obj, sizeof(obj));

    outFile.close();
}

/*
* function to display records of file
*/


void display()
{
    ifstream inFile;
    inFile.open("student.dat", ios::binary);

    Student obj;

    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        obj.showData();
    }

    inFile.close();
}

/*
* function to search and display from binary file
*/

void search(int n)
{
    ifstream inFile;
    inFile.open("student.dat", ios::binary);

    Student obj;

    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() == n)
        {
            obj.showData();
        }
    }

    inFile.close();
}

/*
* function to delete a record
*/

void delete_record(int n)
{
    Student obj;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);

    ofstream outFile;
    outFile.open("temp.dat", ios::out | ios::binary);

    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() != n)
        {
            outFile.write((char*)&obj, sizeof(obj));
        }
    }

    inFile.close();
    outFile.close();

    remove("student.dat");
    rename("temp.dat", "student.dat");
}

/*
* function to modify a record
*/

void modify_record(int n)
{
    fstream file;
    file.open("student.dat",ios::in | ios::out);

    Student obj;

    while(file.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() == n)
        {
            cout << "\nEnter the new details of student";
            obj.setData();

            int pos = -1 * sizeof(obj);
            file.seekp(pos, ios::cur);

            file.write((char*)&obj, sizeof(obj));
        }
    }

    file.close();
}

int main()
{
    //Store 4 records in file
    for(int i = 1; i <= 4; i++)
       write_record();

    //Display all records
    cout << "\nList of records";
    display();

    //Search record
    cout << "\nSearch result";
    search(100);

    //Delete record
    delete_record(100);
    cout << "\nRecord Deleted";

    // //Modify record
    // cout << "\nModify Record 101 ";
    // modify_record(101);

    return 0;
}
