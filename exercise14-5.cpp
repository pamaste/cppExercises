//Answer to exercise 14-5 in Malik. Code could be improved.

#include <iostream>
#include <string>
#include <exception>

using namespace std;


int main() {
string temp;
string monthName;
int day;
int month;
int year;

class invalidDay: public exception {
public:
    virtual const char* what() const throw() {
        return "Invalid value for day.";
    }
};

class invalidMonth: public exception {
public:
    virtual const char* what() const throw() {
        return "Invalid value for month.";
    }
};

try 
{
    cout << "Enter year: " << endl;
    cin >> year;

    cout << "Enter month: " << endl;
    cin >> month;

    if (month > 12)
        throw invalidMonth();
}

catch (invalidMonth invMonthObj)
  {
    cout << invMonthObj.what() << endl;
    cout << "Enter new month: ";
    cin >> month; 
  }

try 
{
    cout << "Enter day: " << endl;
    cin >> day;

    if (day > 31)
        throw invalidDay();
        
}

catch (invalidDay invDayObj)
  {
    cout << invDayObj.what() << endl;
    cout << "enter new day: ";
    cin >> day;
  }

switch(month)
{
  case 1: 
    monthName = "January";
    break;
  case 2:
    monthName = "February"; 
    break;
  case 3:
      monthName = "March";  
      break;
  case 4:
      monthName = "April";
      break;
  case 5:
      monthName = "May";
      break;
  case 6:
      monthName = "June";
      break;
  case 7:
      monthName = "July";
      break;
  case 8:
      monthName = "August";
      break;
  case 9:
      monthName = "September";
      break;
  case 10:
      monthName = "October";
      break;
  case 11:
      monthName = "November";
      break;
  case 12:
      monthName = "December"; 
      break;
}

cout << monthName << " " << day << ", " << year << "." << endl;

return 0;
}
