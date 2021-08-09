#include "person.cpp"
#include "disease.cpp"
#include<fstream>

class patient : public Person {
    protected:
        int patientId;
        Disease disease;
        string appointDate;
        char patientFile[20] = "patientData.dat";
        char patientTempFile[20] = "patientData2.dat";

    public:
        void getPatientInformation() {
            // getting patient information using person class
            getPersonData();

            // getting disease, appointDate
            cout<<"Disease details"<<endl;
            cin.get();
            disease.getDiseaseDetail();

            cout<<"Appoint date: ";
            getline(cin, appointDate);
        }

        // add patient to the file
        void addPatient() {
            // getting patientId
            cout<<"Patient Id: ";
            cin>>patientId;

            getPatientInformation();
            ofstream patientDatabase(patientFile,ios::binary | ios::out | ios::app);
			patientDatabase.write((char*)this,sizeof(patient));	
        }

        // show patient data
        void showPatientData() {
            cout<<"\n\n\t\t---- PATIENT DATA ----"<<endl;
            cout<<"Patient Id: "<<patientId<<endl;
            showPersonData();
            disease.showDiseaseList();
            cout<<"Appointment date: "<<appointDate;
        }

        // showing patient data from file
        void showPatientDataFromFile() {
            ifstream readdatafromdatabase(patientFile,ios::binary|ios::in);
			while(!readdatafromdatabase.eof()){
				if(readdatafromdatabase.read((char*)this,sizeof(patient)))
					showPatientData();
			}
        }        

        // deleting patient details from file
        void dischargePatient() {
            int n, flag = 0;
			cout << "\nEnter the Id of doctor you want to delete"<<endl;
			cin >> n;

			ifstream ifpatient;
            ifpatient.open(patientFile, ios::in | ios::binary);
			ofstream ofpatient;
            ofpatient.open(patientTempFile, ios::out | ios::binary);
            
			while(!ifpatient.eof()){
				ifpatient.read((char*)this,sizeof(patient));
                if(ifpatient) {

                    // comparing the patient Id with that
                    // of the entered patient Id
                    if (n == patientId) {
                        flag = 1;
                    }
                    else {
                        ofpatient.write((char*)this,sizeof(patient));
                    }
                }
			}
			ifpatient.close();
			ofpatient.close();
			remove(patientFile);
			rename(patientTempFile,patientFile);
			showPatientDataFromFile();
            
            if (flag == 1)
                cout << "\nRecord successfully deleted \n";
            else
                cout << "\nRecord not found \n";
        }

        void editPatient() {
			int n, pos, flag = 0;
			cout << "\nEnter the Id of doctor you want to edit"<<endl;
			cin >> n;

			fstream fpatient;
            fpatient.open(patientFile, ios::binary | ios::in | ios::out);

			while(!fpatient.eof()){
                // storing the position of
                // current file pointeri.e. at
                // the end of previously read record
                pos = fpatient.tellg(); 
                               
				fpatient.read((char*)this,sizeof(patient));
                if(fpatient) {

                    // comparing the patient Id with that
                    // of the entered patient Id
                    if(n == patientId){
                        flag = 1;

                        // setting the new (modified )
                        // data of the object or new record
                        getPatientInformation();

                        // placing the put(writing) pointer
                        // at the starting of the  record
                        fpatient.seekp(pos);

                        // writing the object to the file
                        fpatient.write((char*)this,sizeof(patient));
			            
                        // display the data
                        showPatientData();
                        break;
                    }
                }
			}
			fpatient.close();

            if (flag == 1)
                cout << "\nRecord successfully modified \n";
            else
                cout << "\nRecord not found \n";
        }
};

int main() {
    patient p;
    // p.addPatient();
    p.showPatientDataFromFile();
    p.dischargePatient();
    // p.editPatient();

    return 0;
}