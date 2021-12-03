#include <iostream>
#include <fstream>
#include "students.h"
#include <iomanip>
#include <string>

using namespace std;

// Read student records
// 1) Allocate a static array for student records
// 2) Read student record and store the corresponding object in the array
// 3) Return number of processed student records
int readStudentsData(const std::string&, Student** &);
// Print students report
void printStudentsReport(const std::string&, Student** , int);
// Deallocate students array
void clearStudents(Student**, int);

int main() {
    std::string inputfile, outputfile;
    Student** students{nullptr};
    int numberOfStudents{0};
    

    // enter (in/out)put file names
    // .... 
    cout<<"Enter name of the input file: "<<"\n";
    cin>>inputfile;
    
    cout<<"Enter a name for the output file: "<<"\n";
    cin>>outputfile;

    // load data into the dynamically allocated student's array
    // update `numberOfStudents` variable with total number of loaded students
    
    numberOfStudents = readStudentsData(inputfile, students);
    if (numberOfStudents == 0)
      return -1;
    

    // print student grade report
    printStudentsReport(outputfile, students, numberOfStudents);


    // deallocate student's array
    clearStudents(students, numberOfStudents);
    

    return 0;
}

int readStudentsData(const std::string &filename, Student** &students){
ifstream read(filename);
string ft{""};
string lt{""};
string emtst{""};
string classin{""};
string tmp{""};
int count{0};
int num{0};
int length{0};
int array1[length];
int m{0};
  
for(int i{0};!read.eof(); i++){
  getline(read,emtst);
  if(i == 0){
    m = stoi(emtst);
    students = new Student*[m];  
  }

  else if(i%2){
    for(int x{0}; x < emtst.length(); x++){
      if(emtst[x] == ','){ 
        x = count+1;
      }
      else if(x < count+1){
        lt += emtst[x]; //Assigns ln
        count++;
      }
      else if(x > count){
      ft+=emtst[x]; //Assigns fn
      }
    }                     
  }

  else{
    if(i > 0){
    for(int z{0}; z < emtst.length(); z++){
      //Array with the student grades
      if(isdigit(emtst[z]) || emtst[z] == ' '){ 
        if(isdigit(emtst[z])){
          tmp += emtst[z];
          if(tmp.length()>1){
            array1[length-1] = stoi(tmp);
            } 
        }

      else{
        length++;
        tmp.clear();
      }
      }

      else{
      classin+= emtst[z];//sets class
      }
    }
    } 
  length = 0;
  }
  
  if(!classin.empty()){
    if(classin == "Math"){
      Student* report = new MathStudent(ft,lt,classin,array1);
      students[num] = report;     
    }
    else if(classin == "English"){
      Student* report1 = new EnglishStudent(ft,lt,classin,array1);
      students[num] = report1;
    }
    else if(classin == "History"){
      Student* report2 = new HistoryStudent(ft,lt,classin,array1);
      students[num] = report2;
    }
  num++;
  ft.clear();
  lt.clear();
  emtst.clear();
  classin.clear();
  count = 0;
  }
}
  read.close();
  return num;
}

void printStudentsReport(const std::string &filename, Student** students, int studentsNum){}

void clearStudents(Student** students, int studentsNum){
  for(int i=0; i <= studentsNum; i++){
   delete students[i];
  }
  delete [] students;
}
