#include <iostream>
#include <stdio.h>

using namespace std;

class Employee
{
  public:
    Employee();
    Employee(string fN, string lN, int sl=0) {
      firstName = fN;
      lastName = lN;

      if (sl<0) 
        salary = 0;
      else
        salary = sl;
    }
    
    

    void setFirstName(string fN) {
      firstName = fN;
    };

    void setlastName(string lN) {
      lastName = lN;
    };

    void setSalary(int money) {
      firstName = money;
    };
    
    string getFirstName() {
      return firstName;
    }

    string getLastName() {
      return lastName;
    }

    string getFullName() {
      string name;
      name += firstName;
      name += " ";
      name += lastName;
      return name;
    }

    int getSalaryFor(int month) {
      return salary*month;
    }

    void payRaise(double rate) {
      salary += salary * (1+rate);
    }

  private:
    string firstName;
    string lastName;
    int salary;
};


int main(int argc, const char *argv[])
{
  Employee A("Homer", "Simpson", 1000);
  Employee B("Waylon", "Smithers", 10000);
  std::cout << A.getFullName() << " earns $" << A.getSalaryFor(12) << std::endl;
  std::cout << B.getFullName() << " earns $" << B.getSalaryFor(12) << std::endl;

  std::cout << "\nMr.Burns \"Give them a pay raise of... 10 percent\"\n" << std::endl;
  A.payRaise(0.1);
  B.payRaise(0.1);

  std::cout << A.getFullName() << " earns $" << A.getSalaryFor(12) << std::endl;
  std::cout << B.getFullName() << " earns $" << B.getSalaryFor(12) << std::endl;
  
  return 0;
}
