typedef struct {
	long long numerator;
	long long denominator;
} Fraction;

Fraction CreateFrac(long long, long long);
void Reduction(Fraction*);
Fraction Add(Fraction, Fraction);
Fraction Sub(Fraction, Fraction);
Fraction Mul(Fraction, Fraction);
Fraction Div(Fraction, Fraction);
int Compare(Fraction, Fraction);
long long gcd(long long, long long);

Fraction CreateFrac(long long a, long long b){
    return (Fraction){
        .numerator = a,
        .denominator = b
    };
}

void Reduction (Fraction*a) {
    long long GCD = gcd(a->numerator, a->denominator);
    a->numerator /= GCD;
    a->denominator /= GCD;
}

Fraction Add(Fraction a, Fraction b){
    a.numerator *= b.denominator;
    b.numerator *= a.denominator;
    a.numerator += b.numerator;
    a.denominator *= b.denominator;
    Reduction(&a);
    return a;
}

Fraction Sub(Fraction a, Fraction b) {
    a.numerator *= b.denominator;
    b.numerator *= a.denominator;
    a.numerator -= b.numerator;
    a.denominator *= b.denominator;
    Reduction (&a);
    return a;
}

Fraction Mul (Fraction a, Fraction b) {
    a.numerator *= b.numerator;
    a.denominator *= b.denominator;
    Reduction (&a);
    return a;
}

Fraction Div (Fraction a, Fraction b) {
    a.numerator *= b.denominator;
    a.denominator *= b.numerator;
    Reduction (&a);
    return a;
}

int Compare (Fraction a, Fraction b) {
    a.numerator *= b.denominator;
    b.numerator *= a.denominator;
    return a.numerator > b.numerator;
}

long long gcd(long long a, long long b) {
    if(b == 0) return a;
    gcd (b, a%b);
}
