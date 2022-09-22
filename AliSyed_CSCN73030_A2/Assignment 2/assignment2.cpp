#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

typedef struct STUDENT_DATA {
	string firstName;
	string lastName;

}STUDENTDATA;

int main() {

	string tempDataStorage;
	vector<STUDENTDATA>studentList;

	ifstream StudentDataFile("..\\StudentData.txt");

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


	return 1;
}