#include <iostream>
#include <string>

struct Rate {
    double _sm;
    Rate *_next;
    Rate() {
        _sm = 0;
        _next = nullptr;
    }
    Rate(double sm, Rate *next) {
        _sm = sm;
        _next = next;
    }
    virtual void print() = 0;
};

struct MTC : Rate {
    std::string _type;
    std::string _specialConditions;
    double _shet;
    MTC() : Rate() {
        _type = "MTC";
        _shet = 0;
        _specialConditions = "None";
    }
    MTC(double sm, std::string type, std::string specialConditions, double shet, MTC *next) : Rate(sm, next) {
        _type = type;
        _shet = shet;
        _specialConditions = specialConditions;
    }
    void print() {
        std::cout << "=========================================\n";
        std::cout << "Type: " << _type << '\n';
        std::cout << "Cost of one minute: " << _sm << '\n';
        std::cout << "Balance: " << _shet << '\n';
        std::cout << "Special conditions: " << _specialConditions << '\n';
        std::cout << "=========================================\n";
    }
};

struct Megafon : Rate {
    std::string _type;
    double _shet;
    double _kolmin;
    Megafon() : Rate() {
        _type = "Megafon";
        _shet = 0;
        _kolmin = 0;
    }
    Megafon(double sm, std::string type, double shet, double kolmin, Megafon *next) : Rate(sm, next) {
        _type = type;
        _shet = shet;
        _kolmin = kolmin;
    }
    void print() {
        std::cout << "=========================================\n";
        std::cout << "Type: " << _type << '\n';
        std::cout << "Cost of one minute: " << _sm << '\n';
        std::cout << "Numer of minutes: " << _kolmin << '\n';
        std::cout << "Balance: " << _shet << '\n';
        std::cout << "=========================================\n";
    }
};

int main() {
    Megafon Vlad(550, "Megafon", 564.3, 1000, nullptr);
    MTC Emil(650, "MTC", "Tatarstan", 1000, nullptr);
    Vlad._next = &Emil;
    MTC Dima(550, "MTC", "Doter", 1000, nullptr);
    Emil._next = &Dima;
    
    Rate *ptr = &Vlad;
    while (ptr != nullptr) {
        ptr->print();
        ptr = ptr->_next;
    }
    return 0;
}
