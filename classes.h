#ifndef CLASSES_H
#define CLASSES_H

#include "classes.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>
using namespace std;

/*BEGIN MAIN FUNCTION PROTOTYPES*/

void printReciept(double surgeryBill, double pharmacyBill, double rate, double bill, int daysSpent); /* Specification (prototype) of the printReciept function that prints the
																									 summary of the patients charges at the end of the program.*/

void printTotal(double& total, int& daysSpent, double surgeryBill, double pharmacyBill); /* Specification (prototype) of the printTotal function that recieves the total of the
																						 surgery charges, pharmacy charges, and stay charges. A more detailed explanation of this
																						 function can be found in the classes.cpp file.*/

void printMedicationList(double& pharmacyBill); /* Specification (prototype) of the printMedicationList. This function serves to get the price of the medication bill and return
												it to main using pass by refernce to store it in a variable called medCharge. A more detailed explanation of this function
												can be found in the classes.cpp file.*/
void printSurgeryList(double& surgeryBill); /* Specification (prototype) of the printSurgeryList. This function serves to get the price of the surgery bill and return it to main
											using pass by reference to store it in a variable called surgCharge. A more detailed explanation of this function can be found
											in the classes.cpp file.*/

/*END MAIN FUNCTION PROTOTYPES*/


/*BEGIN PATIENTACCOUNT CLASS*/

class PatientAccount { /* This is the class definition of the PatientAccount class. Below, its private member variables (data hiding) are daysOfStay (the amount of days that the
					   patient stays in the hospital), finalSurgeryBill (the price of the chosen surgical procedure), and finalMedicationBill (the price of the chosen prescribed
					   medication). These cannot be accessed unless a member function of the same class is used. */
private:

	int daysOfStay;
	double finalSurgeryBill;
	double finalMedicationBill;

public: /* The public member variables of the PatientAccount class are all of its member functions.  */

	void setSurgeryBill(double surgeryBill); /* The prototype of the setSurgeryBill member function sets the value of the finalSurgeryBill variable. It gets this value from the
											 updateSurgeryBill member function of the Surgery class.*/

	void setMedicationBill(double pharmacyBill);/* The prototype of the setMedicationBill member function sets the value of the finalMedicationBill variable. It gets this value from the
											 updateMedicationBill member function of the Pharmacy class.*/

	double getMedicalBill(double daysInCare, double surgeryBill, double pharmacyBill); /* The prototype of the getMedicalBill member function of the PatientAccount class. This
																					   function serves to calculate the total expenditure of the patients stay, return it to the
																					   printTotal function, where it is passed by reference back to main in the variable totalBill.
																					   A more detailed explanation of  this function can be found in the classes.cpp file.*/

	double getSurgeryBill(); /* The prototype of the getSurgeryBill member function of the PatientAccount class. This function serves to return the surgery bill right after
							 it was set in the updateSurgeryBill member function of the Surgery class. The value is then returned to the printSurgeryList function where it
							 is passed back to main using pass by reference and is stored in the surgCharge variable.*/

	double getMedicationBill(); /* The prototype of the getMedicationBill member function of the PatientAccount class. This function serves to return the pharmacy bill right after
							 it was set in the updateMedicationBill member function of the Pharmacy class. The value is then returned to the printMedicationList function where it
							 is passed back to main using pass by reference and is stored in the surgCharge variable.*/
};

/*END PATIENTACCOUNT CLASS*/


/*BEGIN PHARMACY CLASS*/

class Pharmacy { /* This is the class definition of the Pharmacy class. Below, its only private member variable is an instantiation of the PatientAccount class, which is known as
				 object composition (an instantiation of one class is a member variable of another class). This object is destructed once the scope of the program leaves the
				 Pharmacy class and its only member function.*/

private:

	PatientAccount patient;

public: /* Below are the classe's public member functions and member variables. The medication list and price arrays are public because they have to be accessed by means that don't
		include using functions. They can be accessed by using the dot operator on an instance of the Pharmacy class.*/
	string listOfAvailableMedications[5] = { "Xanax" , "Vicodin" , "Amoxicillin" , "Atorvastatin" , "Levothyroxine" };
	double pricesOfEachMedication[5] = { 100.00,200.00,8.00,10.00,20.00 };
	double updateMedicationBill(int medicationChoice); /* The prototype of the updateMedicationBill member function of the Pharmacy class. This function serves to send the price
													   of the selected medication to the setMedicationBill member function of the PatientAccount class. Once the medication bill
													   is set, the member function getMedicationBill is immediately called to return the price back to the printMedicationList
													   function where it is passed back to main using pass by reference and is stored in the medCharge variable.*/
};

/*END PHARMACY CLASS*/


/*BEGIN SURGERY CLASS*/

class Surgery { /* This is the class definition of the Surgery class. Below, its only private member variable is an instantiation of the PatientAccount class, which is known as
				object composition (an instanciation of one class is a member variable of another class). This object is destructed once the scope of the program leaves the
				Surgery class and its only member function.*/
private:
	PatientAccount patient;
public: /* Below are the classe's public member functions and member variables. The surgery list and price arrays are public because they have to be accessed by means that don't include
		using member functions. They can be accessed by using the dot operator on an instance of the Surgery class.*/
	string listOfAvailableSurgeries[5] = { "Appendectomy", "Cataract Surgery", "Coronary Artery Bypass", "Hysterectomy", "Inguinal Hernia Repair" };
	double pricesOfEachSurgery[5] = { 1000.00,2500.00,10000.00,5000.00,500.00 };
	double updateSurgeryBill(int surgeryChoice); /* The prototype of the updateSurgeryBill member function of the Surgery class. This function serves to send the price of the
												 selected surgery to the setSurgeryBill member function of the PatientAccount class. Once the surgery bill is set, the member function
												 getSurgeryBill is immediately called to return the price back to the printSurgeryList function where it is passed back to main using
												 pass by reference and is stored in the surgCharge variable.*/
};

/*END SURGERY CLASS*/

#endif