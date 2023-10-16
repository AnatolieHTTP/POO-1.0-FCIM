#include <iostream>
#include <cmath>

struct Complex {
    double real;
    double imag;
};

// Funcții pentru adunare, scădere, înmulțire și împărțire a două numere complexe
Complex adunare(const Complex& numar1, const Complex& numar2) {
    Complex rezultat;
    rezultat.real = numar1.real + numar2.real;
    rezultat.imag = numar1.imag + numar2.imag;
    return rezultat;
}

Complex scadere(const Complex& numar1, const Complex& numar2) {
    Complex rezultat;
    rezultat.real = numar1.real - numar2.real;
    rezultat.imag = numar1.imag - numar2.imag;
    return rezultat;
}

Complex inmultire(const Complex& numar1, const Complex& numar2) {
    Complex rezultat;
    rezultat.real = numar1.real * numar2.real - numar1.imag * numar2.imag;
    rezultat.imag = numar1.real * numar2.imag + numar1.imag * numar2.real;
    return rezultat;
}

Complex impartire(const Complex& numar1, const Complex& numar2) {
    Complex rezultat;
    double numitor = numar2.real * numar2.real + numar2.imag * numar2.imag;
    rezultat.real = (numar1.real * numar2.real + numar1.imag * numar2.imag) / numitor;
    rezultat.imag = (numar1.imag * numar2.real - numar1.real * numar2.imag) / numitor;
    return rezultat;
}

// Funcție pentru calculul modulului
double modul(const Complex& numarComplex) {
    return std::sqrt(numarComplex.real * numarComplex.real + numarComplex.imag * numarComplex.imag);
}

int main() {
    Complex numar1, numar2;

    std::cout << "Introduceti partea reala si partea imaginara pentru primul numar complex: ";
    std::cin >> numar1.real >> numar1.imag;

    std::cout << "Introduceti partea reala si partea imaginara pentru al doilea numar complex: ";
    std::cin >> numar2.real >> numar2.imag;

    Complex suma = adunare(numar1, numar2);
    Complex diferenta = scadere(numar1, numar2);
    Complex produs = inmultire(numar1, numar2);
    Complex cat = impartire(numar1, numar2);

    std::cout << "Suma: " << suma.real << " + " << suma.imag << "i" << std::endl;
    std::cout << "Diferenta: " << diferenta.real << " + " << diferenta.imag << "i" << std::endl;
    std::cout << "Produs: " << produs.real << " + " << produs.imag << "i" << std::endl;
    std::cout << "Impartire: " << cat.real << " + " << cat.imag << "i" << std::endl;

    std::cout << "Modulul primului numar complex: " << modul(numar1) << std::endl;
    std::cout << "Modulul celui de-al doilea numar complex: " << modul(numar2) << std::endl;

    return 0;
}
