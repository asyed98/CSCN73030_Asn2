#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

typedef struct STUDENT_DATA {
	string firstName;
	string lastName;
	string eMail;
	string printStudentName() {
		string fullName = lastName + "," + firstName;
		return fullName;
	}
	string printStudentData() {
		string fullData = lastName + "," + firstName + "," + eMail;
		return fullData;
	}
}STUDENTDATA;


//#define PRE_RELEASE

int main() {

	string tempDataStorage;
	vector<STUDENTDATA>studentList;

	ifstream StudentDataFile("..\\StudentData.txt");

	#ifdef PRE_RELEASE
		cout << "Pre Release Version Running " << endl << endl;
		studentList.clear();
		ifstream studentEmailDataFile("..\\StudentData_Emails.txt");

		while (getline(studentEmailDataFile, tempDataStorage))
		{
			int studentDataFileLength = tempDataStorage.length();

			STUDENTDATA newStudent;

			newStudent.lastName = tempDataStorage.substr(0, tempDataStorage.find(','));
			int lastNameLength = newStudent.lastName.length();
			int check = tempDataStorage.rfind(',');
			newStudent.firstName = tempDataStorage.substr(lastNameLength + 1, (tempDataStorage.rfind(',') - lastNameLength - 1));
			int fullNameLength = lastNameLength + newStudent.firstName.length();
			newStudent.eMail = tempDataStorage.substr(fullNameLength + 2, (studentDataFileLength - fullNameLength - 2));

			studentList.push_back(newStudent);
		}

		StudentEmailDataFile.close();
	#else
		cout << "Standard Version Running" << endl << endl;
		studentList.clear();
		while (getline(StudentDataFile, tempDataStorage))
		{
			int studentDataFileLength = tempDataStorage.length();
			STUDENTDATA newStudent;

			newStudent.lastName = tempDataStorage.substr(0, tempDataStorage.find(','));
			newStudent.firstName = tempDataStorage.substr(tempDataStorage.find(',') + 1, studentDataFileLength);

			studentList.push_back(newStudent);
		}
		StudentDataFile.close();
	#endif


	#ifdef _DEBUG
		cout << "DEBUG Running" << endl << endl;
	#ifdef PRE_RELEASE

		for (int i = 0; i < studentList.size(); i++)
			cout << studentList.at(i).printStudentData() << endl;
	#else
		for (int i = 0; i < studentList.size(); i++)
			cout << studentList.at(i).printStudentName() << endl;
	#endif	
	#endif

	return 1;
}