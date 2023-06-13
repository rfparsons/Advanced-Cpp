/*
* Name: Bobby Parsons
* Date: 10/3/21
* Email: rfparsons@dmacc.edu
*
* Description: Program that calculates BMI for 3 people
*/
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Biometrics {
private:
    double heightInCm;
    double weightInKg;
    int age;
public:
    void setHeightFeetInches(double feet, double inches) {
        heightInCm = (feet * 12 + inches) * 2.54;
    }
    void setWeightInPounds(double pounds) {
        weightInKg = pounds * 0.453592;
    }

    void setAge(int newAge) {
        age = newAge;
    }

    double getBmi() {
        int agePoints = age / 10; // intentional integer division

        return (weightInKg / heightInCm / heightInCm) * 10000 - agePoints;
    }
};

class Earthling {
private:
    string m_name;
    string m_country;
    int m_age;
    double m_feet;
    double m_inches;
    double m_pounds;
    Biometrics m_bio;

    void setBiometrics() {
        m_bio.setHeightFeetInches(m_feet, m_inches);
        m_bio.setWeightInPounds(m_pounds);
        m_bio.setAge(m_age);
    }
public:
    Earthling() {
        m_feet = 0;
        m_inches = 0;
        m_pounds = 0;
        m_age = 0;

        setBiometrics();
    }

    Earthling(string name, string country, int age, double feet, double inches, double pounds) {
        m_name = name;
        m_country = country;
        m_age = age;
        m_feet = feet;
        m_inches = inches;
        m_pounds = pounds;

        setBiometrics();
    }

    string getName() {
        return m_name;
    }

    string getCountry() {
        return m_country;
    }

    int getAge() {
        return m_age;
    }

    double getFeet() {
        return m_feet;
    }

    double getInches() {
        return m_inches;
    }

    double getPounds() {
        return m_pounds;
    }

    void setName(string name) {
        m_name = name;
    }

    void setCountry(string country) {
        m_country = country;
    }

    void setAge(int age) {
        m_age = age;

        setBiometrics();
    }

    void setHeightFeetInches(double ft, double in) { //together so they'll both be updated together at all times
        m_feet = ft;
        m_inches = in;

        setBiometrics();
    }

    void setWeightPounds(double weight) {
        m_pounds = weight;

        setBiometrics();
    }

    double getBMI() {
        return m_bio.getBmi();
    }
};

int main() {
    Earthling people[3];

    people[0] = Earthling("Person1", "Country1", 25, 6, 0, 200);
    people[1] = Earthling("Person2", "Country2", 15, 5, 7, 150);
    people[2] = Earthling("Person3", "Country3", 55, 5, 0, 200);

    for (int i = 0; i < 3; i++) {
        cout << people[i].getName() << ": " << people[i].getBMI() << endl;
    }

    return 0;
}

/*
Test output: 

Person1: 25.1246
Person2: 22.4931
Person3: 34.0594
*/