// Parth Patel - Review Activity 2 (2 bonus questions from class)

#include <iostream>
#include <cmath>
using namespace std;

void calculateFunction() {  // Bonus Question from Lecture1 - the function will calculate the output of a hard coded x value to a math function


    int x = 5;

    int function = pow(x, 3) + pow(x, 2) + 2 * x + 5;   //the sample function which the x value will be entered in is: x^3 + x^2 + 2x + 5

    cout << function; //testing this with our hard coded x value of 5, the output is 165. Calculating this with a calculator, the output is 165 as well

}
 
void horoscope() {     //Bonus Question #2 - horoscope function determines someones Horoscope and astro sign.

    //To test.  my bday is nov 29, so my horo sign is sagistaurius and my astro sign is fire

    int month;
    int day;    // initilizes month and day int variables which user will input values
    cout << "Enter your Birth Month (For example, Jan = 1): \n";
    cin >> month;
    cout << "Enter your Day of Birth: ";
    cin >> day;

    if ((month == 1 && day >= 20) || (month == 2 && day <= 18)) {

        cout << "Your horoscope sign is Aquarius and astrological element is Air!";   // Aquarais (jan 20 - feb 18)
    }

    else if ((month == 2 && day >= 19) || (month == 3 && day <= 20)) {

        cout << "Your horoscope sign is Pisces and astrological element is Water!"; //Pisces (feb 19 - mar 20)
    }

    else if ((month == 3 && day >= 21) || (month == 4 && day <= 19)) {

        cout << "Your horoscope sign is Aries and astrological element is Fire!"; //Aries (Mar 21 - Apr 19)
    }

    else if ((month == 4 && day >= 20) || (month == 5 && day <= 20)) {

        cout << "Your horoscope sign is Taurus and astrological element is Earth!"; //Taurus (Apr 20 - may 20)
    }

    else if ((month == 5 && day >= 21) || (month == 6 && day <= 20)) {

        cout << "Your horoscope sign is Gemini and astrological element is Air!"; //Gemini (May 21 - Jun 20)
    }

    else if ((month == 6 && day >= 21) || (month == 7 && day <= 22)) {

        cout << "Your horoscope sign is Cancer and astrological element is Water!"; //Cancer (Jun 21 - Jul 22)
    }

    else if ((month == 7 && day >= 23) || (month == 8 && day <= 22)) {

        cout << "Your horoscope sign is Leo and astrological element is Fire!"; //Leo (Jul 23 - Aug 22)
    }

    else if ((month == 8 && day >= 23) || (month == 9 && day <= 22)) {

        cout << "Your horoscope sign is Virgo and astrological element is Earth!"; //Virgo (Aug 23 - Sep 22)
    }

    else if ((month == 9 && day >= 23) || (month == 10 && day <= 22)) {

        cout << "Your horoscope sign is Libra and astrological element is Air!"; //Libra (Sep 23 - Oct 22)
    }


    else if ((month == 10 && day >= 23) || (month == 11 && day <= 21)) {

        cout << "Your horoscope sign is Scorpio and astrological element is Water!"; //Scorpio (Oct 23 - Nov 21)
    }

    else if ((month == 11 && day >= 22) || (month == 12 && day <= 21)) {

        cout << "Your horoscope sign is Sagittarius and astrological element is Fire!"; //Sagittarius (Nov 22 - Dec 21)
    }

    else {
        cout << "Your horoscope sign is Capricorn and astrological element is Earth!"; //Capricorn (Dec 22 - Jan 21)
    }
}


int main()
{
    horoscope();
    //calculateFunction();    // the two bonus questions's functions.
}