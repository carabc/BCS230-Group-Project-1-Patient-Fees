#include "classes.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>
using namespace std;

/*BEGIN PATIENT ACCOUNT FUNCTION DEFINITIONS*/
void PatientAccount::setSurgeryBill(double surgeryBill) { /* This is a member function of the PatientAccount class. We define it in this separate file by using the scope
														  resolution operator, which tells the program that this function can be found in the PatientAccount class.
														  It has one double parameter, which is the price of the surgical procedure the patient recieved. It is passed from the
														  "updateSurgeryBill" function in the Surgery class. The parameter is then stored in a member variable of the
														  PatientAccount class called finalSurgeryBill. Once the scope of this class is left, the data in the
														  finalSurgeryBill is thrown away. However, we are able to recieve the clean data that was originally set by also
														  calling the "getSurgeryBill" function of the PatientAccount class directly after setSurgeryBill is called. The value is
														  returned to a function named "printSurgeryList* where it is stored in a variable that is passed back to main using
														  pass by reference.*/
	finalSurgeryBill = surgeryBill;
}

void PatientAccount::setMedicationBill(double pharmacyBill) { /*A member function of the PatientAccount class defined using the scope resolution operator, this sets the pharmacy
															  bill of the patient into a double member variable of the PatientAccount class called "finalMedicationBill." Just like
															  before, this data is thrown away once the program leaves the scope of this class. However, we can recieve the data
															  from the variable once it is set by calling the member function "getMedicationBill" right after the function
															  "setMedicationBill" is  called in the updateMedicationBill function. This value is passed back to a function in main
															  called "printMedicationList", and it is then passed back to main using pass by reference.*/
	finalMedicationBill = pharmacyBill;
}

double PatientAccount::getMedicalBill(double daysInCare, double surgeryBill, double pharmacyBill) { /* A member function of the PatientAccount class defined using the scope
																									resolution operator, this function accepts 3 parameters passed to it by a
																									function in main called printTotal. It calculates the total of the bill by
																									adding the pharmacy charges and surgical charges to the product of the number days
																									of days that the patient stayed in the hospital and the rate that the hospital
																									charges. This is returned to the printTotal function, and the value is stored
																									in a variable called total, which is passed by reference back to main in a variable
																									called totalBill.*/
	daysOfStay = daysInCare;
	return surgeryBill + pharmacyBill + daysOfStay * 70.0;
}

double PatientAccount::getSurgeryBill() { /* A member function of the PatientAccount class defined using the scope resolution operator, this function gets the surgery bill
										  and returns it to the updateSurgeryBill function of the Surgery class, where it is then returned to the printSurgeryList function in main. This value
										  is then stored in a variable called surgeryBill and is passed to main in the variable surgCharge using pass by reference. */
	return finalSurgeryBill;
}

double PatientAccount::getMedicationBill() { /* A member function of the PatientAccount class defined using the scope resolution operator, this function gets the pharmacy bill
											 and returns it to the updateMedicationBill function of the Pharmacy class, where it is then returned to the printMedicationList function
											 in main. This value is then stored in a variable called pharmacyBill and is passed to main in a variable called
											 medCharge using pass by reference.*/
	return finalMedicationBill;
}
/*END PATIENT ACCOUNT FUNCTION DEFINITIONS*/



/*BEGIN PHARMACY ACCOUNT FUNCTION DEFINITIONS*/
double Pharmacy::updateMedicationBill(int medicationChoice) { /* A member function of the Pharmacy class defined using the scope resolution operator, this function has one
															  parameter which is the choice of medication from the printed list of medications. It then sets the pharmacy
															  bill by calling the setMedicationBill on the patient object (object composition) and its arguement is the
															  position of a price in the pricesOfEachMedication array in the Pharmacy class. Since the list of medications
															  matches up with the list of the prices of the medications, if the user inserts choice 0, the price of that medication
															  is determined by the 0 position of the pricesOfEachMedication array. We call the getMedicationBill() member function
															  of the PatientAccount class in the same function that we set the medication bill. It returns the correct price and not
															  a random number in memory, because the program never left the scope of the function after setting the medication bill, 
															  and we can get it right away by using the getMedicationBill() function.*/

	patient.setMedicationBill(pricesOfEachMedication[medicationChoice]);
	return patient.getMedicationBill();

}
/*END PHARMACY ACCOUNT FUNCTION DEFINITIONS*/



/*BEGIN SURGERY ACCOUNT FUNCTION DEFINITIONS*/
double Surgery::updateSurgeryBill(int surgeryChoice) { /* A member function of the Surgery class defined using the scope resolution operator, this function has one paramter
													   which is the choice of surgery from the printed list of surgeries. It then sets the surgery bill by calling the setSurgeryBill()
													   on the patient object (object composition) and its arguement is the position of a price in the pricesOfEachSurgery array in the
													   Surgery class. Since the list of surgeries matches up with the list of the prices of the surgeries, if the user inserts choice
													   0, the price of that surgery is determined by the 0 position of the pricesOfEachSurgery array.*/

	patient.setSurgeryBill(pricesOfEachSurgery[surgeryChoice]);
	return patient.getSurgeryBill();

}
/*END SURGERY CLASS ACCOUNT FUNCTION DEFINITION*/



/*BEGIN FUNCTION DEFINITIONS FOR MAIN*/
void printSurgeryList(double& surgeryBill) { /* This function instanciates an instance of the Surgery class and has one parameter that is passed by reference from main. This
											 variable will eventually hold the surgical bill of the patient. The user is asked what surgery was performed, and then a for loop
											 is called that prints the list of surgeries from the Surgery class on the surgery object. A user inputs a number from the list of choices,
											 and is then passed to the updateSurgeryBill of the Surgery class. That function then returns the price back to this function, and it
											 is stored in the surgeryBill variable which is passed back to main using pass by reference and is stored in the surgCharge variable.*/
	Surgery surgery;
	int holder;

	cout << "What Surgery Was Performed During Your Stay?" << endl;


	for (int i = 0; i < 5; i++)
	{
		cout << i << ".)    " << surgery.listOfAvailableSurgeries[i] << endl;
	}
	cin >> holder;
	surgeryBill = surgery.updateSurgeryBill(holder);
	cout << "========================================================" << endl;

}

void printMedicationList(double& pharmacyBill) { /* This function instanciates an instance of the Pharmacy class and has one parameter that is passed by reference from main. This
											 variable will eventually hold the pharmacy bill of the patient. The user is asked what medication was prescribed, and then a for loop
											 is called that prints the list of medications from the Pharmacy class on the pharmacy object. A user inputs a number from the list of choices,
											 and is then passed to the updateMedicationBill of the Surgery class. That function then returns the price back to this function, and it
											 is stored in the pharmacyBill variable which is passed back to main using pass by reference and is stored in the medCharge variable.*/
	Pharmacy pharmacy;
	int holder;


	cout << "What Medication Were You Prescribed During Your Stay?" << endl;


	for (int i = 0; i < 5; i++)
	{
		cout << i << ".)    " << pharmacy.listOfAvailableMedications[i] << endl;
	}
	cin >> holder;
	pharmacyBill = pharmacy.updateMedicationBill(holder);
	cout << "========================================================" << endl;
}

void printTotal(double& total, int& daysSpent, double surgeryBill, double pharmacyBill) { /* This function has 4 parameters, two of which are passed by reference. These variables
																						  are the total(totalBill), daysSpent(daysSpentInCare), surgeryBill(surgCharge), and
																						  the pharmacyBill(medCharge). Its purpose is to set the amount of days that the user
																						  spent in the hospital and pass it back to main using pass by reference, and store it into
																						  the daysSpentInCare variable. Further more, its main purpose is to calculate the total
																						  bill of the patient by instanciating an object of the PatientAccount class called patient.
																						  the variable total equals the value returned by the getMedicalBill member function of the
																						  PatientAccount class, which is the surgical bill, pharmacy bill, and the product of the
																						  rate the hospital charges and the days spent in the hospital added together. The function
																						  getMedicalBill is explained in further detail at the top of this file. */
	PatientAccount patient;
	int holder;


	cout << "How Many Days Were You In Care at the Farmingdale State College Medical Center?" << endl;


	cin >> holder;

	daysSpent = holder;

	total = patient.getMedicalBill(daysSpent, surgeryBill, pharmacyBill);

	cout << "========================================================" << endl;
}

void printReciept(double surgeryBill, double pharmacyBill, double rate, double bill, int daysSpent) { /* This function takes 5 parameters, and serves to print the final total bill
																									  that the patient has been charged, in reciept form. These parameters are
																									  the surgeryBill(surgCharge from main), pharmacyBill(medCharge from main),
																									  rate(dailyRate from main), bill(totalBill from main), and daysSpent(days
																									  SpentInCare from main). Fixed and setprecision are used in the output
																									  to correctly display the number of decimal places of monetary value. No
																									  objects are instantiated here and neither are any member functions, because
																									  the variables we need were all acquired by using them in previous functions.
																									  Those values were all conviently passed back to main, where they now live.
																									  We can use those charges by sending them from main to this function in the
																									  form of arguements. */
	cout << "==========================" << endl;
	cout << "\t" << "+ Reciept +" << endl;
	cout << "==========================" << endl;

	cout << endl;
	cout << endl;

	cout << "-------Surgery Bill-------" << endl;
	cout << endl;
	cout << "           " << "$" << fixed << setprecision(2) << surgeryBill << endl; /* surgeryBill was acquired from the updateSurgeryBill member function of the
																					 Surgery class, was returned to the printSurgeryList function, and passed back to main
																					 using pass by reference and was stored in the surgCharge variable.*/

	cout << endl;
	cout << endl;

	cout << "-------Pharmacy Bill-------" << endl;
	cout << "           " << "$" << fixed << setprecision(2) << pharmacyBill << endl; /* pharmacyBill was acquired from the updatePharmacyBill member function of the
																					 Pharmacy class, was returned to the printMedicationList function, and passed back
																					 to main using pass by reference and was stored in the medCharge variable.*/

	cout << endl;
	cout << endl;

	cout << "-------Stay Charge-------" << endl;
	cout << "           " << daysSpent << " days in care." << endl; /* daysSpent was made when printToal function was called, and daysSpentInCare was passed in using pass by
																	reference. The user was asked how many days were spent in the hospital, and that value was stored in daysSpent.
																	It was then passed back to main using pass by reference, and was stored in the daysSpentInCare variable.*/
	cout << "           " << "Our daily rate here at the Farmingdale State College Medical Center is: $" << fixed << fixed << setprecision(2) << rate << endl; /* rate lives in main
																																								and is user defined
																																								at the beginning of
																																								this program. The
																																								rate that the hospital
																																								charges is $70.00.*/
	cout << "           " << "Stay Charge: " << "$" << fixed << setprecision(2) << daysSpent * rate << endl; /* The bill of the patients stay is then calculated by taking the
																											 product of the daysSpent and rate variable. */

	cout << endl;
	cout << endl;

	cout << "-------TOTAL BILL-------" << endl;
	cout << "        " << "$" << fixed << setprecision(2) << bill << endl; /* bill(totalBill) was acquired when the function printTotal was called. totalBill was passed to
																		   printTotal using pass by reference, and it equaled the value returned from the getMedicalBill member
																		   function of the PatientAccount class. getMedicalBill accepted the daysSpent(daysSpentInCare from main), surgeryBill
																		   (surgCharge from main), and pharmacyBill(medCharge from main) to calculate the total bill of the patient.
																		   This value was stored in total (totalBill from main) and passed back to main using pass by reference to
																		   store in the variable totalBill.*/

	cout << endl;
	cout << endl;

	cout << "==========================" << endl;
	cout << "      " << "+ End Reciept +" << endl;
	cout << "==========================" << endl;

	cout << endl;
	cout << endl;

}
/*END FUNCTION DEFINITIONS FOR MAIN*/




