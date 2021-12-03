using namespace std;
class Student {
  private:
  string ft;
  string lt;
  string clasin;

  public:
  Student(string fn, string ln, string clas,int arr[]):ft{f},lt{l},clasin{clas}{}
  
  virtual double FinalAverage() = 0;
  virtual int FinalExam() = 0;

  char Grade(){
  double grade = FinalAverage();
  char rep;

  if(grade >= 90.0 && grade <=100.0)
    rep = 'A';
  else if(grade >= 80.0 && grade < 90.0)
    rep = 'B';
  else if(grade >= 70.0 && grade < 80.0)
    rep = 'C';
  else if(grade >= 60.0 && grade < 70.0)
    rep = 'D';
  else if(grade < 60)
    rep = 'F';

  return rep;
}
  virtual  ~Student(){}
  string getFirst(){return ft;}
  string getLast(){return lt;}
  string getClass(){return clasin;}
};

// Derived Student's classes
class EnglishStudent : public Student {
  int a[4];
  public:
    EnglishStudent(string fn, string ln, string cl,int arr[]):Student{fn,ln,cl,ar}{
    for(int i=0;i<4;i++){
     a[i] =  ar[i] ;
    }
  }

  double FinalAverage() {
    double average = 0.0;
    for(int i=0;i<4;i++){
    double value = static_cast<double>(a[i]);
      if(i = 0)
        average += (value*10)/100;
      else if(i = 1)
        average += (value*(30))/100;
      else if(i = 2)
        average += (value*(30))/100;
      else if(i = 3)
        average += (value*(30))/100;
      }
      return average;
    }
    
  int FinalExam() {
    int grade = 0;
    for(int i=0;i<4;i++){
      if(i==3)
        grade =  a[i];
      }
      return grade;
    }
  };

//History Class
class HistoryStudent : public Student {
private:
  int a[3];

  public:
  HistoryStudent(string fn, string ln, string cl,int arr[]):Student{fn,ln,cl,ar}{
    for(int i=0;i<4;i++){
      a[i]=arr[i];
    }

   double FinalAverage() {
      double average = 0.0;
      for(int i=0;i<=3; i++){
        double value = static_cast<double>(a[i]);
          if(i = 0)
            average += (value*25)/100;
          else if(i = 1)
            average += (value*(35))/100;
          else if(i = 2)
            average += (value*(40))/100;
        }
      }
      return average;
    }
    
  int FinalExam() {
    int grade = 0;
    for(int i=0;i<3;i++){
      if(i==2)
      grade =  a[i];
    }
  return grade;
  }
};

//Math
class MathStudent : public Student {
  private:
  int a[8];

  public:
  MathStudent(string fn, string ln, string cl,int arr[]):Student{fn,ln,cl,ar}{
    for(int i=0;i<8;i++){
      a[i]=arr[i];
    }
  }
  double FinalAverage() {}

  int FinalExam() {
    int grade = 0;
    for(int i=0;i<8;i++){
      if(i==7)
        grade =  a[i];
      }
    return grade;
  }
 };
