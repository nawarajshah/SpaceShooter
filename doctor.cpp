// doctor. cpp 
// inherits from availableon , disease and person files

#include "availableOn.cpp"
#include "disease.cpp"
#include "person.cpp"

#include <iostream>
#include <fstream>
using namespace std;

class doctor: public Available , public Disease , public Person{
	private:
		int doctorid;
		Disease diseasename;
		Available availableon;
	public:
		void getdoctordata(){
			cout << "enter data of doctor " << endl;
			getPersonData();
			cout << "enter doctor id ";
			cin >> doctorid;
			cout << "enter name of specializations ";
			getDiseaseDetail();
			whenAvailable();
		}
		
		void showdoctordata(){
			cout << "\n\t\t\t DETAILS OF DOCTOR ARE:" << endl;
			showPersonData();
			cout << "doctor id is " << doctorid << endl;
			showDiseaseList();
			displayAvailable();
		}
		
		void adddoctordata(){
			getdoctordata();
			ofstream doctordatabase("doctordata.dat",ios::binary|ios::out|ios::app);
			doctordatabase.write(reinterpret_cast<char*>(this),sizeof(doctor));	
		}
		
		void showdoctordatafromfile(){
			ifstream readdatafromdatabase("doctordata.dat",ios::binary|ios::in);
			while(!readdatafromdatabase.eof()){
				if(readdatafromdatabase.read(reinterpret_cast<char*>(this),sizeof(doctor))>0)
					showdoctordata();
			}
		}
		
		void deletedoctor(){
			int n;
			cout << "enter the number of doctor you want to delete";
			cin >> n;
			ifstream readdoctordatabase2("doctordata.dat",ios::binary|ios::in);
			ofstream writedoctordatabase2("doctordata2.dat",ios::binary|ios::out);
			while(!readdoctordatabase2.eof()){
				readdoctordatabase2.read(reinterpret_cast<char*>(this),sizeof(doctor));
				if (n != doctorid) {
					writedoctordatabase2.write(reinterpret_cast<char*>(this),sizeof(doctor));
				}
			}
			readdoctordatabase2.close();
			writedoctordatabase2.close();
			remove("doctordata.dat");
			rename("doctordata2.dat","doctordata.dat");
			showdoctordatafromfile();
		}
		
		void editdoctor(){
			int n;
			cout << "enter the number of doctor you want to edit";
			cin >> n;
			int count=1;
			ifstream readdoctordatabase2("doctordata.dat",ios::binary|ios::in);
			ofstream writedoctordatabase2("doctordata3.dat",ios::binary|ios::out);
			while(!readdoctordatabase2.eof()){
				readdoctordatabase2.read(reinterpret_cast<char*>(this),sizeof(doctor));
				 if (n!=doctorid) {
					writedoctordatabase2.write(reinterpret_cast<char*>(this),sizeof(doctor));
				}
				else if(n = doctorid){
					doctor temp;
					temp.getdoctordata();
					writedoctordatabase2.write(reinterpret_cast<char*>(&temp),sizeof(doctor));
				}
			}
			readdoctordatabase2.close();
			writedoctordatabase2.close();
			remove("doctordata.dat");
			rename("doctordata3.dat","doctordata.dat");
			showdoctordatafromfile();
		}
	
};

int main(){
	int flag;
	doctor d1;
	do{
	d1.adddoctordata();
	cout << "add another doctor ? 1 for yes ";
	cin >> flag;
	}while(flag == 1);
	d1.showdoctordatafromfile();
	d1.deletedoctor();
	d1.editdoctor();
	return 0;
}
