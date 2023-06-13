/*
* Name: Bobby Parsons
* Date: 10/28/21
* Email: rfparsons@dmacc.edu
*
* Description: Program that prompts the user for a planet and returns the 
* distance of that planet from the sun
*/

#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, double> planets;
    string planet;

    // distance is in AU
    planets["Mercury"] = 0.39;
    planets["Venus"] = 0.72;
    planets["Earth"] = 1;
    planets["Mars"] = 1.52;
    planets["Jupiter"] = 5.2;
    planets["Saturn "] = 9.54;
    planets["Uranus"] = 19.2;
    planets["Neptune"] = 30.06;

    cout << "Enter the name of a planet: ";
    cin >> planet;

    cout << planets[planet] << " AU away from the Sun." << endl;

    return 0;
}

/*
* Enter the name of a planet: Mars
* 1.52 AU away from the Sun.
* -----
* Enter the name of a planet: Neptune
* 30.06 AU away from the Sun.
* -----
* Enter the name of a planet: Mercury
* 0.39 AU away from the Sun.
*/
