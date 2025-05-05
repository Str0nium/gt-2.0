#include <iostream>
#include <string>

using namespace std;


class DiscountStrategy {
public:
    virtual double applyDiscount(double amount) = 0;
    virtual string getDescription() const = 0;
    virtual ~DiscountStrategy() {}
};


class NoDiscount : public DiscountStrategy {
public:
    double applyDiscount(double amount) override {
        return amount;
    }
    string getDescription() const override {
        return "No discount";
    }
};


class PercentageDiscount : public DiscountStrategy {
private:
    double discountRate;
    string description;
public:
    PercentageDiscount(double rate, const string& desc) : discountRate(rate), description(desc) {}
    double applyDiscount(double amount) override {
        return amount * (1.0 - discountRate);
    }
    string getDescription() const override {
        return description;
    }
};


DiscountStrategy* getDiscountStrategy(int choice) {
    if (choice == 1) {
        return new NoDiscount();
    } else if (choice == 2) {
        return new PercentageDiscount(0.10, "10% discount");
    } else if (choice == 3) {
        return new PercentageDiscount(0.20, "20% discount");
    } else {
        return new NoDiscount(); 
    }
}

int main() {
    double amount;
    int discountChoice;
    double finalAmount;
    DiscountStrategy* selectedDiscountStrategy = nullptr;

    cout << "Enter the amount: ";
    cin >> amount;

    cout << "\nSelect a discount option:" << endl;
    cout << "1. No discount" << endl;
    cout << "2. 10% discount" << endl;
    cout << "3. 20% discount" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> discountChoice;

    selectedDiscountStrategy = getDiscountStrategy(discountChoice);
    finalAmount = selectedDiscountStrategy->applyDiscount(amount);
    cout << selectedDiscountStrategy->getDescription() << " applied." << endl;
    cout << "Final amount: " << finalAmount << " pesos" << endl;

    delete selectedDiscountStrategy; // Remember to clean up the allocated strategy

    return 0;
}