#include <iostream>
#include <cstring>

using namespace std;

class Information
{
protected:
    char age[5], personID[15];
    char name[25], contact[25], address[45], illstatus[25], emailadd[45];
    char BloodGroup[5], gender[15], specialization[45], RoomNo[10], DateTime[45], appointment[25];

public:
    //current used functions
    void getdata(){};
    void showdata(){};

    //Required Data in Future
    void writedataonFile(){};
    void readalldatafromFile(){};
    void displayalldataFromFile(){};
    void editdatainFile(){};
    void deletedataFromFile(){};
};

//////////////////Class Doctor contain all Informations related to Doctor/////////////

class Doctor : public virtual Information
{
public:
    void getdata()
    {
        cout << "-------------------- Taking Doctor Information ------------------ " << endl;
        cout << "Enter Doctor name :";
        gets(name);
        cout << "Address :";
        gets(address);
        cout << "Enter his/her specialization :";
        gets(specialization);
        cout << "Enter contact :";
        gets(contact);
        cout << "Enter email address :";
        gets(emailadd);
        cout << "Room Number:";
        gets(RoomNo);
        cout << "Available Time :";
        gets(DateTime);
        cout << endl
             << endl
             << endl;
    }
    void showdata()
    {
        cout << "-------------------- Showing Doctor Information ------------------ "
             << endl;
        cout << "Name of Doctor : " << name << endl;
        cout << "Address :" << address << endl;
        cout << "Specialization Field :" << specialization << endl;
        cout << "Contact Number :" << contact << endl;
        cout << "Email Address :" << emailadd << endl;
        cout << "Room No. :" << RoomNo << endl;
        cout << "Available Time :" << DateTime << endl;
        cout << endl
             << endl
             << endl;
    }
};

//////////////////Class Patient contain all Informations related to Patients/////////

class Patient : public virtual Information
{
public:
    void getdata()
    {
        cout << "-------------------- Taking Patient Information ------------------ " << endl;
        cout << "Enter Patient Name : ";
        gets(name);
        cout << "Gender :";
        gets(gender);
        cout << "Enter Address :";
        gets(address);
        cout << "Enter Age : ";
        gets(age);
        cout << "Enter Contact Number :";
        gets(contact);
        cout << "Illness Condition of Patient :";
        gets(illstatus);
        cout << "Blood Group :";
        gets(BloodGroup);
        cout << "Patient ID number :";
        gets(personID);
        cout << "Appointed Doctor :";
        gets(appointment);
        cout << "Enter appointment Data & Time :";
        gets(DateTime);
        cout << endl
             << endl
             << endl;
    }
    void showdata()
    {
        cout << "-------------------- Showing Patient Information ------------------"
             << endl;
        cout
            << "Patient Name :" << name << endl;
        cout << "Gender :" << gender << endl;
        cout << "Address :" << address << endl;
        cout << "Age :" << age << endl;
        cout << "Contact Number :" << contact << endl;
        cout << "Condition of Patient :" << illstatus << endl;
        cout << "Blood Group :" << BloodGroup << endl;
        cout << "Patient ID No :" << personID << endl;
        cout << "Appointment Date & Time :" << DateTime << endl;
        cout << endl
             << endl
             << endl;
    }
};
int main()
{
    Doctor D;
    Patient P;

    //////For Calling getdata function////////
    D.getdata();
    P.getdata();

    /////For Calling showdata function////////
    D.showdata();
    P.showdata();

    return 0;
}