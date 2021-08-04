#include<iostream>
#include<string>

using namespace std;

class Disease {
    private:
    string diseaseName;
    string virusName;
    // Symptom symptoms;
    string fileName = "disease.dat";

    public:
    // getting information of disease from user
    void getDiseaseDetail() {
        
        cout<<"Enter the name of disease: ";
        getline(cin, diseaseName);
        
        cout<<"Enter the name of virus: ";
        getline(cin, virusName);
    }

    // show disease list
    void showDiseaseList() {
        cout<<endl;
        cout<<"*** Disease: "<<diseaseName<<" ***"<<endl;
        cout<<"Virus: "<<virusName<<endl;
    }
};

int main() {
    Disease d;
    d.getDiseaseDetail();
    d.showDiseaseList();

    return 0;
}