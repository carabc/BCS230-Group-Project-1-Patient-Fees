#include "classes.h" /*Header file containting all the function prototypes and the class declarations, along with their member function prototypes.*/
#include "classes.cpp"/*The program does not seem to compile unless we include the "classes.cpp" directive, even though classes.cpp is linked with classes.h.
						I mentioned this in class, but the solution did not work.*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;



int main()
{
	int daysSpentInCare; /*This variable type int will hold the amount of days that the patient spend in the hospital. Data is stored in it when the function "printTotal
						 is called, and is passed in as an arguement by reference using "&." The input within the printTotal function passes the variable back to main,
						 and the data that was inserted into the variable transfers because of the "&" reference operator.*/

	double dailyRate = 70.00; /*This is the rate that our imaginary facility charges per day that a patient stays in its care.*/
	double totalBill = 0; /*totalBill will hold the total of the patient's charges, which includes the bill from the pharmacy, surgical operation, and daily rate.
						  It is passed to the function printTotal using pass by reference, so that the function can edit it's data and pass it back to main. */

	double surgCharge; /*surgCharge will hold the bill of the surgical procedure performed on the patient. It is passed to the function printSurgeryList as a reference, so the
					   contents of the function can edit the variable's data and pass it back to main.*/

	double medCharge; /*medCharge will hold the bill of the medications prescribed from the pharmacy. It is passed to the function printMedicationList as a reference, so the
					   contents of the function can edit the variable's data and pass it back to main. */

	cout << "========================================================" << endl;
	cout << " + Welcome to the Farmingdale State College Medical Center. + " << endl; //Style
	cout << "========================================================" << endl;

	printSurgeryList(surgCharge); /* See the "classes.cpp" file for the explanation of what the below functions do. This function takes in a single arguement, the surgery bill
								  (surgCharge)*/
	printMedicationList(medCharge); //This function takes in a single arguement, the pharmacy bill (medCharge). See the classes.cpp file for an explanation on what the function does.
	printTotal(totalBill, daysSpentInCare, surgCharge, medCharge); /*This function takes in four different arguements, the total of the bill (totalBill), how many days were spent in the hospital
																	(daysSpentInCare), the surgical bill (surgCharge), and the pharmacy bill (medCharge). See the classes.cpp file for an explanation
																	on what this function does.*/
	cout << endl;//Whitespace in the console for easy reading.
	cout << endl;//Whitespace in the console for easy reading.
	printReciept(surgCharge, medCharge, dailyRate, totalBill, daysSpentInCare); /*This function takes in 5 arguements, and prints the patients bill along with the totals of each
																				bill (pharmacy bill, surgical bill, amount of days spent in the hospital multiplied by the rate).
																				For a full explanation on what this function does, see the classes.cpp file.*/
	cout << endl; //Whitespace in the console for easy reading.
	cout << endl; //Whitespace in the console for easy reading.

	cout << "==========================================================================" << endl;
	cout << " + Thank you for choosing the Farmingdale State College Medical Center. + " << endl; //Style
	cout << "==========================================================================" << endl;


	return 0;
}



