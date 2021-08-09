#include<iostream>
#include<string>

using namespace std;

class Disease {
    private:
    char diseaseName[25];
    char virusName[25];
    // Symptom symptoms;
    //string fileName = "disease.dat";

    public:
    // getting information of disease from user
    void getDiseaseDetail() {
        
        cout<<"Enter the name of disease: ";
        cin >>  diseaseName;
        
        cout<<"Enter the name of virus: ";
      	cin >> virusName;
    }

    // show disease list
    void showDiseaseList() {
        cout<<endl;
        cout<<"*** Disease: "<<diseaseName<<" ***"<<endl;
        cout<<"Virus: "<<virusName<<endl;
    }
};

/*int main() {
    Disease d;
    d.getDiseaseDetail();
    d.showDiseaseList();
    return 0;
}*/
