#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP
#include <exception>

using namespace std;

class EmptyPotion : public exception {
    public:
    virtual const char* what() const throw();
};

class IllegalFury : public exception {
    bool entering;
    public:
    virtual const char* what() const throw();
    public:
    IllegalFury(bool entering) : entering(entering) {}
};

class UnknownJob : public exception {
    public:
    virtual const char* what() const throw();
};


#endif