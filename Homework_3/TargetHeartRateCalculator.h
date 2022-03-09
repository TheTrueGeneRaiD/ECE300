#ifndef TARGETHEARTRATECALCULATOR_H
#define TARGETHEARTRATECALCULATOR_H

#include <iostream>
#include <string>
using namespace std;

class targetHeartRateCalculator
{
	private:
		string firstName;
		string lastName;
		double birthMonth;
		double birthDay;
		double birthYear;
	
	 	double currentMonth;
		double currentDay;
		double currentYear;
		
		double age;
	public:
		targetHeartRateCalculator();

		void setFirstName();
		string getFirstName() const;
	
		void setLastName();
		string getLastName() const;

		void setMonth(double &monthVar, float birthOrCurrentMonth);
		double getBirthMonth() const;
		double getCurrentMonth()const;

		void setDay(double &dayVar, float birthOrCurrentDay);
		double getBirthDay() const;
		double getCurrentDay() const;

		void setYear(double &yearVar, float birthOrCurrentYear);
		double getBirthYear() const;
		double getCurrentYear() const;		
		
		double getAge();
		double getMaximumHeartRate();
		double getTargetHeartRate();
		
		void print();
};

#endif //!TARGETHEARTRATECALCULATOR_H
