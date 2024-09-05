#include <iostream>
#include <string.h>
using namespace std;

class Exam {
	char* stdname;
	char* examdate;
	int score;
	
	public:
		Exam(const char* name, const char* date, int score){
			stdname = new char(strlen(name) + 1);
			strcpy(stdname, name);
			
			examdate = new char(strlen(date) + 1);
			strcpy(examdate, date);
			
			this->score = score;
		}
		
		Exam(const Exam &other){
			stdname = new char(strlen(other.stdname) + 1);
			strcpy(stdname, other.stdname);
			
			examdate = new char(strlen(other.examdate) + 1);
			strcpy(examdate, other.examdate);
			
			score = other.score;
		}
		
		Exam& operator=(const Exam& other){
			if (this != &other){
				delete[] stdname;
				delete[] examdate;
				
				stdname = new char(strlen(other.stdname) + 1);
				strcpy(stdname, other.stdname);
				
				examdate = new char(strlen(other.examdate) + 1);
				strcpy(examdate, other.examdate);
				
				score = other.score;
			}
			return *this;
		}
		
		~Exam(){
			delete[] stdname;
			delete[] examdate;
		}
		
		void setdetails(const char* name, const char* date, int score){
			delete[] stdname;
			delete[] examdate;
			
			stdname = new char(strlen(name) + 1);
			strcpy(stdname, name);
			
			examdate = new char(strlen(date) + 1);
			strcpy(examdate, date);
			
			this->score = score;
		}
		
		void display(){
			cout << "Student Name: " << stdname << endl;
			cout << "Exam Date: " << examdate << endl;
			cout << "Score: " << score << "\n" << endl;
		}
};

int main(){
	Exam exam1("Hasan Sheikh", "02/08/2024", 88);
	cout << "Exam1 Details:" << endl;
	exam1.display();
	
	Exam exam2 = exam1;
	cout << "Copied Exam2 Details: " << endl;
	exam2.display();
	
	exam2.setdetails("Anas Shoaib", "28/08/2024", 94);
	
	cout << "Original Exam1 Details:" << endl;
	exam1.display();
	
	cout << "Copied Exam2 Details after Modification:" << endl;
	exam2.display();
	
}