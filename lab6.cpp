#include <iostream>
#include <string>
#include <vector>

struct Book {
    unsigned long int _URN;
    std::string _title;
    std::string _author;
    unsigned  int _year;
    unsigned  int _count;
    Book() {}
    Book(unsigned long int URN, std::string title, std::string author, unsigned int year, unsigned int count) {
        _URN = URN;
        if (title.length() <= 50) {
            _title = title;
        } else {
            std::cout << "Title is too long";
            throw new std::exception();
        }
        if (author.length() <= 20) {
            _author = author;
        } else {
            std::cout << "Author's name is too long";
            throw new std::exception();
        }
        _year = year;
        _count = count;
    }
    int input() {
        std::cout << "Input book's united registration number:\n";
        std::cin >> _URN;
        std::cout << "Input book's title:\n";
        std::cin.ignore();
        std::getline(std::cin, _title, '\n');
        if (_title.length() > 50) {
            std::cout << "Error, try again!\n";
            return -1;
        }
        std::cout << "Input book's author:\n";
        std::getline(std::cin, _author, '\n');
        if (_author.length() > 20) {
            std::cout << "Error, try again!\n";
            return -1;
        }
        std::cout << "Input book's year:\n";
        std::cin >> _year;
        std::cout << "Input book's count:\n";
        std::cin >> _count;
        return 0;
    }
    void output() {
        std::cout << "Current URN: " << _URN << '\n';
        std::cout << "Current title: " << _title << '\n';
        std::cout << "Current author: " << _author << '\n';
        std::cout << "Current year: " << _year << '\n';
        std::cout << "Current count: " << _count << '\n';
    }
};

struct Library {
    std::vector<Book> _container;
    int _N;
    Library() {}
    Library (int N) {
        _container = std::vector<Book>(N);
        for (int i = 0; i < N; ++i) {
            int result = _container.at(i).input();
            if (result == -1) {
                --i;
            }
        }
        _N = N;
    }
    bool increase(const unsigned long int &URN) {
        for (int index = 0; index < _N; ++index) {
            if (_container[index]._URN == URN) {
                _container[index]._count += 100;
                break;
            }
        }
    }
    void print() {
        for (auto it = _container.begin(); it != _container.end(); ++it) {
            std::cout << "============================================\n";
            it->output();
            std::cout << "============================================\n";
        }
    }
};


int main() {
    int num;
    std::cin >> num;
    Library lib(num);
    system("clear");
    lib.print();
    lib.increase(1);
    std::cout << "After:\n";
    lib.print();
    return 0;
}
