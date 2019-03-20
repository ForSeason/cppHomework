#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;


// CLASS FRACTION:

class Fraction {
    private:
        __int128  common_factor();
        void transform();
    public:
        __int128 nume;
        __int128 deno;
        Fraction(__int128 nume, __int128 deno);
        Fraction operator+(const Fraction &y);
        Fraction operator-(const Fraction &y);
        Fraction operator*(const Fraction &y);
        Fraction operator/(const Fraction &y);
        void     operator=(const Fraction &y);
        friend ostream &operator<<(ostream &output, const Fraction &f);
};

Fraction::Fraction(__int128 nume, __int128 deno) {
    this->nume = nume;
    this->deno = deno;
    this->transform();
}

__int128 Fraction::common_factor() {
    __int128 x, y, r;
    x = (this->nume > this->deno)? this->nume: this->deno;
    y = (this->nume < this->deno)? this->nume: this->deno;
    while (y) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

void Fraction::transform() {
    __int128 cf;
    cf = this->common_factor();
    this->nume /= cf;
    this->deno /= cf;
}

Fraction Fraction::operator+(const Fraction &y) {
    __int128 nume, deno;
    deno = y.deno * this->deno;
    nume = this->nume * y.deno + y.nume * this->deno;
    Fraction res(nume, deno);
    return res;
}

Fraction Fraction::operator-(const Fraction &y) {
    __int128 nume, deno;
    deno = y.deno * this->deno;
    nume = this->nume * y.deno - y.nume * this->deno;
    Fraction res(nume, deno);
    return res;
}

Fraction Fraction::operator*(const Fraction &y) {
    __int128 nume, deno;
    deno = y.deno * this->deno;
    nume = y.nume * this->nume;
    Fraction res(nume, deno);
    return res;
}

Fraction Fraction::operator/(const Fraction &y) {
    __int128 nume, deno;
    deno = y.nume * this->deno;
    nume = y.deno * this->nume;
    Fraction res(nume, deno);
    return res;
}

void Fraction::operator=(const Fraction &y) {
    this->deno = y.deno;
    this->nume = y.nume;
}

ostream &operator<<(ostream &os, __int128 t) {
    if (t == 0) return os << "0";
    if (t < 0) {
        os << "-";
        t = -t;
    }
    int a[50],ai = 0;
    memset(a, 0, sizeof a);
    while (t != 0){
        a[ai++] = t % 10;
        t /= 10;
    }
    for (int i = 1; i <= ai; i++) os << abs(a[ai-i]);
    return os << "";
}

ostream &operator<<(ostream &output, const Fraction &f) {
    output << f.nume << '/' << f.deno;
    return output;
}

//END FRACTION


__int128 fib(__int128 n) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else if (n > 2) {
        return fib(n - 1) + fib(n - 2);
    } else {
        return 0;
    }
}


int main() {
    Fraction sum(0, 1);
    for (int i = 1; i <= 20; i++) sum = sum + Fraction(fib(i + 1), fib(i));
    cout << sum << endl;
    return 0;
}
