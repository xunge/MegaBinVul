#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <omp.h>

class RandomNumberGenerator {};

class Integer {
public:
    Integer();
    Integer(const Integer&);
    void Randomize(RandomNumberGenerator&, const Integer&, const Integer&);
    bool IsZero() const;
    bool IsOdd() const;
    Integer operator%(const Integer&) const;
    Integer operator+(const Integer&) const;
    Integer operator-(const Integer&) const;
    Integer operator>>(int) const;
    bool operator!=(const Integer&) const;
    static Integer One();
};

class ModularArithmetic {
public:
    ModularArithmetic(const Integer&);
    Integer MultiplicativeInverse(const Integer&) const;
    Integer Square(const Integer&) const;
    Integer Multiply(const Integer&, const Integer&) const;
};

class Exception {
public:
    enum { OTHER_ERROR };
    Exception(int, const char*);
};

class InvertibleRWFunction {
protected:
    Integer m_n, m_p, m_q, m_u;
public:
    void DoQuickSanityCheck() const;
    Integer ApplyFunction(const Integer&) const;
    Integer CalculateInverse(RandomNumberGenerator&, const Integer&) const;
};

int Jacobi(const Integer&, const Integer&);
Integer ModularSquareRoot(const Integer&, const Integer&);
Integer CRT(const Integer&, const Integer&, const Integer&, const Integer&, const Integer&);
Integer STDMIN(const Integer&, const Integer&);