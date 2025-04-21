#include <iostream>
#include <string>

using namespace std;

class Performer {

private:
    string name;
    int age;

public:
    Performer(string name, int age) : name(name), age(age) {}

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }
};

class Singer : public Performer {

private:
    string vocalRange;

public:
    Singer(string name, int age, string vocalRange) : Performer(name, age), vocalRange(vocalRange) {}

    string getVocalRange() {
        return vocalRange;
    }

    void sing() {
        cout << getName() << " (Age: " << getAge() << ") is singing with a " << getVocalRange() << " vocal range." << endl;
    }
};

class Dancer : public Performer {

private:
    string danceStyle;

public:
    Dancer(string name, int age, string danceStyle) : Performer(name, age), danceStyle(danceStyle) {}

    string getDanceStyle() {
        return danceStyle;
    }

    void dance() {
        cout << getName() << " (Age: " << getAge() << ") is performing a " << getDanceStyle() << " dance." << endl;
    }
};

int main() {
    int performerType;

    cout << "Enter '1' for Singer or '2' for Dancer: ";
    cin >> performerType;

    if (performerType == 1) {
        Singer mySinger("Johnny", 30, "Soprano");
        mySinger.sing();
    } else if (performerType == 2) {
        Dancer myDancer("Jane", 25, "Ballet");
        myDancer.dance();
    } else {
        cout << "Invalid performer type." << endl;
    }

    return 0;
}