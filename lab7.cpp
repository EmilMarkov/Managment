#include <iostream>
#include <string>
#include <vector>

struct Abonent {
    unsigned int _number;
    std::string _secondName;
    unsigned long int _passNumber;
    Abonent() {}
    Abonent(unsigned int number, std::string secondName, unsigned long int passNumber) {
        _number = number;
        _secondName = secondName;
        _passNumber = passNumber;
    }
    void input() {
        std::cout << "Input second name\n";
        std::cin >> _secondName;
        std::cout << "Input number\n";
        std::cin >> _number;
        std::cout << "Input number of passport\n";
        std::cin >> _passNumber;
    }
    void output() {
        std::cout << "=======================================\n";
        std::cout << "The abonent " << _secondName << '\n';
        std::cout << "Number: +" << _number << '\n';
        std::cout << "=======================================\n";
    }
};

struct AbonentExtended : Abonent {
    long double _debtValue;
    AbonentExtended() {}
    AbonentExtended(unsigned int number, std::string secondName, unsigned long int passNumber, long double debtValue) :
    Abonent(number, secondName, passNumber) {
        _debtValue = debtValue;
    }
    bool checkDebetor(long double base) {
        return !(_debtValue < base);
    }
    void input() {
        std::cout << "Input second name\n";
        std::cin >> _secondName;
        std::cout << "Input number\n";
        std::cin >> _number;
        std::cout << "Input number of passport\n";
        std::cin >> _passNumber;
        std::cout << "Input debt value\n";
        std::cin >> _debtValue;
    }
    void output() {
        std::cout << "=======================================\n";
        std::cout << "The abonent " << _secondName << '\n';
        std::cout << "Number: " << _number << '\n';
        std::cout << "Debt: " << _debtValue << '\n';
        std::cout << "=======================================\n";
    }
};

int main() {
    unsigned int N;
    long double debtVal;
    std::cin >> N;
    std::vector<AbonentExtended> table = std::vector<AbonentExtended>(N);
    for (auto it = table.begin(); it != table.end(); ++it) {
        it->input();
    }
    system("clear");
    std::cout << "Input debt base value: ";
    std::cin >> debtVal;
    std::cout << "Searching debetors...\n";
    for (auto it = table.begin(); it != table.end(); ++it) {
        if (it->checkDebetor(debtVal)) {
            it->output();
        }
    }
    return 0;
}
