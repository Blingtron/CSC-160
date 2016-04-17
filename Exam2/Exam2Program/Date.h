//---------------------------------------------------------------------------
// CSC160 Exam Two - Date.h
//---------------------------------------------------------------------------

using namespace std;
namespace ExamTwo
{
#ifndef DATE_H
#define DATE_H
class Date
{
public:
    Date();
    Date(int numberOfDays);
    Date(int month, int day, int year);
    void setDate(int month, int day, int year);
    friend Date operator +(const Date& first, const Date& second);
    friend Date operator -(const Date& first, const Date& second);
    friend istream& operator >>(istream& in, Date& thisDate);
    friend ostream& operator <<(ostream& out, const Date& thisDate);
private:
    double internalDate;
    double numDays(int month, int day, int year);
    void getDetails(int& month, int& day, int& year);
    bool isLeapYear(int year);
};
#endif
}
