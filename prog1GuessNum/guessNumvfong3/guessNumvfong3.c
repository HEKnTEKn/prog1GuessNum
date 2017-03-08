//  guessnumvfong3.c : A program that will take user input and use it to "predict" a final solution as inspired by a youtube video seen by Mr. Reed.
//	Author: Victor Fong
//	Program : #1, Guess Number
//	TA : Nianzu Ma, Tues @ 4PM
//	1 / 20 / 2017



/*SAMPLE OUTPUT:

Author: Victor Fong
Program: #1, Guess Number
TA: Nianzu Ma, Tues @ 4PM
1/20/2017



Welcome to the number guessing game!

If you concentrate, sometimes you can connect to the electrons in the computer!
Let's try it. Think of a three digit number (To make it harder, make the digits all different from each other).
Type in your number!: 123

I'll help you with the math. Let's randomize those digits by reversing them, and do a subtraction:

321
- 123
=====
198

Press 'Y' to continue or 'X' to exit...y

Now lets again scramble the numbers by reversing them, and adding them this time:

198
+ 891
=====
???

Before you continue, take a look at my number guess written down on paper...

Press 'D' to display the answer or 'X' to exit...d

Answer is 1089!!!!!!!!!

Press 'T' to show all possible combinations that don't work or 'X' to exit...

t
0  1  2  3  4  5  6  7  8  9  10  11  20  22  30  33  40  44  50  55  60  66  70  77  80  88  90  99  100  101  110  111  112  113  114  115  116  117  118  119  121  122  131  133  141  144  151  155  161  166  171  177  181  188  191  199  200  202  211  212  220  221  222  223  224  225  226  227  228  229  232  233  242  244  252  255  262  266  272  277  282  288  292  299  300  303  311  313  322  323  330  331  332  333  334  335  336  337  338  339  343  344  353  355  363  366  373  377  383  388  393  399  400  404  411  414  422  424  433  434  440  441  442  443  444  445  446  447  448  449  454  455  464  466  474  477  484  488  494  499  500  505  511  515  522  525  533  535  544  545  550  551  552  553  554  555  556  557  558  559  565  566  575  577  585  588  595  599  600  606  611  616  622  626  633  636  644  646  655  656  660  661  662  663  664  665  666  667  668  669  676  677  686  688  696  699  700  707  711  717  722  727  733  737  744  747  755  757  766  767  770  771  772  773  774  775  776  777  778  779  787  788  797  799  800  808  811  818  822  828  833  838  844  848  855  858  866  868  877  878  880  881  882  883  884  885  886  887  888  889  898  899  900  909  911  919  922  929  933  939  944  949  955  959  966  969  977  979  988  989  990  991  992  993  994  995  996  997  998  999
There are 280 values that do not work.
Thank you for playing...
Press any key to continue . . .
*/


#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)



void displayInfo(void) {    //function Displays general information of program

	printf("Author: Victor Fong\n");
	printf("Program: #1, Guess Number\n");
	printf("TA: Nianzu Ma, Tues @ 4PM\n");
	printf("1/20/2017\n");
	printf("\n\n\n");
	return;
}



void displayInstructions(void) {    //function displays instructions of program

	printf("Welcome to the number guessing game!\n\n");
	printf("If you concentrate, sometimes you can connect to the electrons in the computer!\n");
	printf("Let's try it. Think of a three digit number (To make it harder, make the digits all different from each other).\n");
	printf("Type in your number!: ");

	return;
}



int getInt(int userInput) { //function acquires input of an integer number- namely the three digit number to be input by user

	scanf(" %d", &userInput);

	return userInput;
}



char getChar(char charInput) {  //function acquires input of a character- namely an "X" to exit program or anything else to continue program

	scanf(" %c", &charInput);

	return charInput;
}


int reverseNumber(int numStart) {   //function reverses a three digit number

									//initialize variables  

	int numReversed = 0;
	int onesDigit = 0;
	int newNum = 0;
	int tensDigit = 0;
	int centDigit = 0;

	//perform body text

	onesDigit = numStart % 10;  //get ones digit
	newNum = numStart / 10; //get 2 digit number

	tensDigit = newNum % 10; //get ten digit
	newNum /= 10;   //get 1 digit number

	centDigit = newNum; // get tens digit

	if (onesDigit == tensDigit || onesDigit == centDigit || tensDigit == centDigit) {   //check input for repeating digits

		printf(". . . HEY! NOT EVERY DIGIT IS DISTINCT! EXITING PROGRAM . . . ");
		exit(1);
	}
	else {
		numReversed = (onesDigit * 100) + (tensDigit * 10) + (centDigit);   //store result
		return numReversed;
	}
}



int displaySubtractionAndStore(int in, int revIn) { //function will display the subtraction of the user input and it's reverse
													//initialize variables

	int bigger = 0;
	int smaller = 0;
	int difference = 0;

	//perform body text
	if (in > revIn) {    //check for bigger digit
		bigger = in;    //
		smaller = revIn;    //
	}   //
	else {  //
		bigger = revIn; //
		smaller = in;   //
	}   //

	difference = bigger - smaller;  //subtract larger from smaller

	printf("\nI'll help you with the math. Let's randomize those digits by reversing them, and do a subtraction:\n\n"); //print subtraction
	printf("%5d\n", bigger);    //
	printf("- %3d\n", smaller); //
	printf("=====\n");  //
	printf("%5d\n\n", difference);  //


	return difference;
}



void displayAddition(int difference, int reverseNum) {   //function that prints addition of difference and it's reverse

	printf("\nNow lets again scramble the numbers by reversing them, and adding them this time:\n\n");
	printf("%5d\n", difference);
	printf("+ %3d\n", reverseNum);
	printf("=====\n  ???\n\n");
	return;
}





int checkX(char charBegin) {    //function that takes character variable and checks for for 'x' or 'X'. if true then program exits

	if (charBegin == 'x' || charBegin == 'X') {
		printf("Exiting Program . . . \n");
		exit(2);   //this is return integer
	}
}





int main(void) { //main program

				 //initialize functions  

	int numBegin = 0;
	int numReversed = 0;
	char charBegin = ' ';
	int difference = 0;
	int num = 000;
	int bigger = 0;
	int smaller = 0;
	int total = 0;
	int onesDigit = 0;
	int newNum = 0;
	int tensDigit = 0;
	int centDigit = 0;

	//call functions and make calculations

	displayInfo();  //self-explanatory

	displayInstructions();  //self-explanatory

	numBegin = getInt(0);   // store integer input

	numReversed = reverseNumber(numBegin);  //store reversed number

	difference = displaySubtractionAndStore(numBegin, numReversed); //displays substraction AND stores difference into main function

	printf("Press 'Y' to continue or 'X' to exit...");  //prompt for continuation

	charBegin = getChar(' ');   //scan for character
	checkX(charBegin);  //check for x to exit

	numReversed = reverseNumber(difference);    //store new reverse-num

	displayAddition(difference, numReversed);   //call function to display addition

	printf("Before you continue, take a look at my number guess written down on paper...\n\n"); //print the punch line
	printf("Press 'D' to display the answer or 'X' to exit...");    //print prompt to ask to show answer or exit

	charBegin = getChar(' ');   //scan for character
	checkX(charBegin);  //check char to exit program

	printf("\nAnswer is 1089!!!!!!!!!\n\n");    //show answer
	printf("Press 'T' to show all possible combinations that don't work or 'X' to exit...\n\n");    //prompt to exit program or show all numbers that don't work

	charBegin = getChar(' ');   //scan for character
	checkX(charBegin);  //check to continue or exit

	int badCount = 0;   //keeps track of total "non-working" numbers

						//loop that will check all possible 3 digit numbers for those that don't work. bad numbers will be printed and add 1 to total badcount. All code below here aside from for loop exists earlier in program with comments.
						//Please move up to see comments if necessary.
	for (num = 0; num < 1000; ++num) {


		onesDigit = num % 10;
		newNum = num / 10;

		tensDigit = newNum % 10;
		newNum /= 10;

		centDigit = newNum;


		if (onesDigit == tensDigit || onesDigit == centDigit || tensDigit == centDigit) {

			badCount += 1;
			printf("%d  ", num);
			continue;

		}

		numReversed = (onesDigit * 100) + (tensDigit * 10) + (centDigit);

		if (num > numReversed) {
			bigger = num;
			smaller = numReversed;
		}
		else {
			bigger = numReversed;
			smaller = num;
		}

		difference = bigger - smaller;


		onesDigit = difference % 10;
		newNum = difference / 10;

		tensDigit = newNum % 10;
		newNum /= 10;

		centDigit = newNum;

		numReversed = (onesDigit * 100) + (tensDigit * 10) + (centDigit);

		if ((numReversed + difference) != 1089) {
			badCount += 1;
			printf("%d ", num);

		}
	}
	printf("\nThere are %d values that do not work.\nThank you for playing...\n", badCount);

	return 0;
}
