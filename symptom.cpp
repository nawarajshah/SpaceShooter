#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Symptom {
    private:
    vector<string> symptomList;
    string symptom;
    char ch;

    public:
    // call this function to add list of symptoms for a disease
    void addSymptom() {
        int i = 0;
        cout<<"Enter symptom for disease:"<<endl;

        do {
            // inserting each symptom in symptomList
            cout<<++i<<". ";
            getline(cin, symptom);
            symptomList.push_back(symptom);

            cout<<"Do you have next symptom to enter or not?(y/n)";
            cin>>ch;
            cin.get();// very usefull while using getline inside the loop
        } while(ch=='y'||ch=='Y');      
    }

    // show all the symptoms for a disease
    void showSymptom() {
        cout << "List of symptoms:"<<endl;
        for (int i = 0; i < symptomList.size(); ++i)
            cout <<i+1<<". "<<symptomList[i]<<endl;
    }

    // remove symptoms from symptoms list
    void removeSymptom() {
        int symptomIndex;
        // first display all the symptoms and erase by its index
        showSymptom();

        cout<<"Enter the index no. of symptom that you want to remove. "<<endl;
        cin>>symptomIndex;
        symptomList.erase(symptomList.begin() + symptomIndex -1);
        //removeSymptom();
    }
};

// for testing propse only
// int main() {
//     Symptom symptomDemo;
//     symptomDemo.addSymptom();
//     symptomDemo.showSymptom();
//     symptomDemo.removeSymptom();

//     return 0;
// }