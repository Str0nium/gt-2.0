#include <iostream>
using namespace std;

class Beverage {
private:
    string name;
    int volume;
    bool isChilled;
public:
    Beverage(string name, int volume, bool isChilled) : name(name), volume(volume), isChilled(isChilled) {}

    bool isEmpty() const { return volume == 0; }
    string getname() { return name; }
    int getvolume() { return volume; }
    bool getisChilled() { return isChilled; }

    string toString() const {
        string status = isChilled ? "is still chilled" : "is not chilled anymore";
        return name + " (" + to_string(volume) + "mL) " + status;
    }
};

class Water : public Beverage {
private:
    string type;
public:

    Water(int volume, bool isChilled, string type = "Regular")  : Beverage("Water", volume, isChilled), type(type) {}

    string gettype() { return type; }
};

class Beer : public Beverage {
private:
    double alcoholicContent;
public:
    Beer(int volume, bool isChilled, double alcoholicContent) : Beverage("Beer", volume, isChilled), alcoholicContent(alcoholicContent) {}

    string getType() {
        if (alcoholicContent < 0.03) {
            return "Flavored";
        } else if (alcoholicContent < 0.06) {
            return "Regular";
        } else {
            return "Strong";
        }
    }

    string toString() const {
        string base = Beverage::toString();
        double percentage = alcoholicContent * 100.0;
        int whole = (int)percentage;
        int decimal = (int)((percentage - whole) * 10);

        return base + " (" + to_string(whole) + "." + to_string(decimal) + "% alcoholic content)";
    }

    double getAlcoholicContent() const { return alcoholicContent; }
};

int main() {
    int volume;
    string chilledInput;
    bool isChilled;
    string choice;
    string waterType;
    double alcoholicContent;


    cout << "Enter Water Volume (mL): ";
    cin >> volume;
    cout << "Is the water Chilled? (yes/no): ";
    cin >> chilledInput;
    isChilled = (chilledInput == "yes");

    cout << "Do you want to specify water type? (yes/no): ";
    cin >> choice;

    if (choice == "yes") {
        cout << "Enter Water Type (Purified, Regular, Distilled): ";
        cin >> waterType;
        cout<<endl;
        Water water(volume, isChilled, waterType);
        cout<<"Water Details"<<endl;
        cout << water.toString()<<"["<<water.gettype() <<"]";
        cout<<endl;
        cout<<endl;
    }
    else if (choice == "no") {
        Water water(volume, isChilled);
        cout<<endl;
        cout << water.toString()<<"["<<water.gettype() <<"]";
        cout<<endl;
        cout<<endl;
    }
    else {
        cout << "Invalid Input" << endl;
    }


    cout << "Enter Beer Volume (mL): ";
    cin >> volume;
    cout << "Is the beer Chilled? (yes/no): ";
    cin >> chilledInput;
    isChilled = (chilledInput == "yes");

    cout << "Enter Alcoholic Content (e.g., 0.05 for 5%): ";
    cin >> alcoholicContent;
    cout<<endl;
    cout<<endl;

    Beer beer(volume, isChilled, alcoholicContent);
    cout<<"Beer Details"<<endl;
    cout << beer.toString() << "["<<beer.getType() <<"]"<< endl;

    return 0;
}
