#include <iostream>
#include "TargetHeartRateCalculator.h"

targetHeartRateCalculator::targetHeartRateCalculator()
{
	setFirstName();

	setLastName();

	setMonth(birthMonth, 0);

	setDay(birthDay, 0);

	setYear(birthYear, 0);

	getAge();
	cout << endl;
}

void targetHeartRateCalculator::setFirstName()
{
	string fName; //Represents first name
	cout << "Please enter your first name: ";
	getline(cin, fName);
	firstName = fName; 
}

string targetHeartRateCalculator::getFirstName() const
{
	return firstName;
}

void targetHeartRateCalculator::setLastName()
{
	string lName; //Represents last name
	cout << "Please enter your last name: ";
	getline(cin, lName);
	lastName = lName; 
}

string targetHeartRateCalculator::getLastName() const
{
	return lastName;
}

void targetHeartRateCalculator::setMonth(double &monthVar, float birthOrCurrentMonth)
{	
	double month;
	if(birthOrCurrentMonth == 0)
		cout << "Please enter birth month: ";
	if (birthOrCurrentMonth == 1)
		cout << "Please enter current month: ";
	
	cin >> month;
	cin.ignore();

	if (month >= 1 && month <= 12)
		monthVar = month;
	else
		throw invalid_argument("Please enter a month in number form or a number in the interval from 1 to 12.");	
}

double targetHeartRateCalculator::getBirthMonth() const
{
	return birthMonth;
}

double targetHeartRateCalculator::getCurrentMonth() const
{
	return currentMonth;
}

void targetHeartRateCalculator::setDay(double &dayVar, float birthOrCurrentDay)
{
	double day;
	if(birthOrCurrentDay == 0)
		cout << "Please enter birth day: ";
	if (birthOrCurrentDay == 1)
		cout << "Please enter current day: ";
	
	cin >> day;
	cin.ignore();

	if (day >= 1 && day <= 31)
		dayVar = day;
	else
		throw invalid_argument("Please enter a day in number form or a number in the interval from 1 to 31.");	
}

double targetHeartRateCalculator::getBirthDay() const
{
	return birthDay;
}

double targetHeartRateCalculator::getCurrentDay() const
{
	return currentDay;
}


void targetHeartRateCalculator::setYear(double &yearVar, float birthOrCurrentYear)
{	
	double year;
	if(birthOrCurrentYear == 0)
		cout << "Please enter birth year: ";
	if (birthOrCurrentYear == 1)
		cout << "Please enter current year: ";

	cin >> year;
	cin.ignore();

	if (year >= 1777 && year <= 2022)
		yearVar = year;
	else
		throw invalid_argument("Please enter a year in number form or a number in the interval from 1777 to 2022.");	
}

double targetHeartRateCalculator::getBirthYear() const
{
	return birthYear;
}

double targetHeartRateCalculator::getCurrentYear() const
{
	return currentYear;
}

double targetHeartRateCalculator::getAge()
{
	setMonth(currentMonth, 1);
	setDay(currentDay, 1);
	setYear(currentYear, 1);
	
	// This checks if their birthday has passed
	if(birthMonth <= currentMonth)
	{
		if(birthDay <= currentDay)
		{
			age++;
		}
	}
	
	// This finds how many years have changed since you were born. 
	age += ((currentYear-birthYear) - 1);
	if (age >= 0)
		return age;
	else
		throw invalid_argument("You are suppose to be born later in time????, please enter a valid age.");
}

double targetHeartRateCalculator::getMaximumHeartRate()
{
	return 220 - age; 
}

double targetHeartRateCalculator::getTargetHeartRate()
{
	double exertionRate;
	double exertionRateDecimal;
	double targetHeartRate;
	cout << "Please enter in a percentage exertion rate from(50 to 85): ";
	
	cin >> exertionRate;
	cin.ignore();
	
	if (exertionRate >= 50 && exertionRate <= 85)
	{
		exertionRateDecimal = exertionRate / 100;
		targetHeartRate = exertionRateDecimal * getMaximumHeartRate();	
	}
	else
		throw invalid_argument("Please enter in a valid percent between 50 and 85");


	return targetHeartRate;	
}

void targetHeartRateCalculator::print()
{
	cout << "\nYour name: " << getFirstName() << " " << getLastName() << endl
	     << "Birth date: " << getBirthMonth() << "/" << getBirthDay() << "/" << getBirthYear() << endl
	     << "Age: " << age << endl
	     << "Current date: " << getCurrentMonth() << "/" << getCurrentDay() << "/" << getCurrentYear() << endl
	     << "Max heart rate: " << getMaximumHeartRate() << endl
	     << "Target heart rate: " << endl << getTargetHeartRate() << endl;
}

