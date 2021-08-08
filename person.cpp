#include <iostream>
#include<string>

using namespace std;

class Person
{
    private:
        int age;
        string name, address, email, phoneNo;

    public:
        //getting person information
        void getPersonData() {
            cout<<"Enter age: ";
            cin>>age;
            cout<<"Enter phone number: ";
            cin.get();// very usefull while using getline multiple times
            getline(cin, phoneNo);

            cout<<"Enter name: ";
            cin.get();
            getline(cin, name);

            cout<<"Enter address: ";
            cin.get();
            getline(cin, address);

            cout<<"Enter email address: ";
            cin>>email;
        };

        // displaying person information
        void showPersonData(){
            cout<<"Age: "<<age<<endl;
            cout<<"Phone number: "<<phoneNo<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Address: "<<address<<endl;
            cout<<"Email address: "<<email<<endl;
        };
};

// for testing porpose only
/*int main()
{
    Person person;
    person.getPersonData();
    person.showPersonData();

    return 0;
}*/
