#include <iostream>
#include <string>
using namespace std;

class Number {
private:
    int rawValue;
public:
    Number(int rawValue) : rawValue(rawValue) {}

    void setRawValue(const int& newRawValue) {
        rawValue = newRawValue;
    }

    int getRawValue() const {
        return rawValue;
    }
};

class WholeNumber : public Number {
public:
    WholeNumber(int value) : Number(value) {}

    void multiply(WholeNumber otherWhole) {
        int result = getRawValue() * otherWhole.getRawValue();
        setRawValue(result);
    }

    string toString() const {
        return to_string(getRawValue());
    }
};

class DecimalNumber : public Number {
private:
    int decimalPlaces;

public:
    DecimalNumber(int value, int decimalPlaces)
        : Number(value), decimalPlaces(decimalPlaces) {}

    void setDecimalPlaces(const int& newDecimalPlaces) {
        decimalPlaces = newDecimalPlaces;
    }

    int getDecimalPlaces() const {
        return decimalPlaces;
    }

    void multiply(DecimalNumber decimalNumber) {
        int newValue = getRawValue() * decimalNumber.getRawValue();
        int newDecimalPlaces = decimalPlaces + decimalNumber.getDecimalPlaces();
        setRawValue(newValue);
        setDecimalPlaces(newDecimalPlaces);
    }

    string toString() const {
        string rawStr = to_string(getRawValue());
        while (rawStr.length() < decimalPlaces) {
            rawStr = "0" + rawStr;
        }

        string integerPart = "0";
        string decimalPart = rawStr;
        if (rawStr.length() > decimalPlaces) {
            integerPart = rawStr.substr(0, rawStr.length() - decimalPlaces);
            decimalPart = rawStr.substr(rawStr.length() - decimalPlaces);
        }
        return integerPart + "." + decimalPart;
    }
};

int main() {
    int Num1, Num2, decimal1, decimal2, DecRaw1, DecRaw2;

    cout << "Enter First Whole Number: ";
    cin >> Num1;
    cout << "Enter Second Whole Number: ";
    cin >> Num2;

    WholeNumber N1(Num1);
    WholeNumber N2(Num2);
    N1.multiply(N2);

    cout << "WholeNumber Result (Multiplication): " << N1.toString() << endl << endl;

    cout << "Enter first decimal raw value: ";
    cin >> DecRaw1;
    cout << "Enter number of decimal places for first decimal: ";
    cin >> decimal1;

    cout << "Enter second decimal raw value: ";
    cin >> DecRaw2;
    cout << "Enter number of decimal places for second decimal: ";
    cin >> decimal2;

    DecimalNumber D1(DecRaw1, decimal1);
    DecimalNumber D2(DecRaw2, decimal2);
    D1.multiply(D2);

    cout << "DecimalNumber Result: " << D1.toString() << endl;

    return 0;
}