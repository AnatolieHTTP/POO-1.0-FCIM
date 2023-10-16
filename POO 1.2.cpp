#include <iostream>
#include <cmath>

struct Vector {
    int* data;
    int size;

    void init(int n) {
        size = n;
        data = new int[n];
    }

    void destroy() {
        delete[] data;
    }

    void resize(int new_size) {
        int* new_data = new int[new_size];
       // int size = new int;
        for (int i = 0; i < std::min(size, new_size); i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        size = new_size;
    }

    int& at(int index) {
        if (index >= 0 && index < size) {
            return data[index];
        }
        else {
            std::cerr << "Index invalid\n";
            exit(1);
        }
    }

    const int& at(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        else {
            std::cerr << "Index invalid\n";
            exit(1);
        }
    }

    double modulus() {
        double sum_of_squares = 0.0;
        for (int i = 0; i < size; i++) {
            sum_of_squares += data[i] * data[i];
        }
        return sqrt(sum_of_squares);
    }
};

void initializeVector(Vector& vector) {
    int n;
    std::cout << "Introduceti dimensiunea vectorului: ";
    std::cin >> n;
    vector.init(n);

    for (int i = 0; i < n; i++) {
        std::cout << "Introduceti elementul " << i << ": ";
        std::cin >> vector.at(i);
    }
}

void displayVector(const Vector& vector) {
    std::cout << "Vector:";
    for (int i = 0; i < vector.size; i++) {
        std::cout << " " << vector.at(i);
    }
    std::cout << std::endl;
}

void displayMenu() {
    std::cout << "Meniu:\n";
    std::cout << "1. Initializare primul vector\n";
    std::cout << "2. Initializare al doilea vector\n";
    std::cout << "3. Eliminare primul vector\n";
    std::cout << "4. Eliminare al doilea vector\n";
    std::cout << "5. Setare/modificare dimensiune primul vector\n";
    std::cout << "6. Setare/modificare dimensiune al doilea vector\n";
    std::cout << "7. Acces la elemente primul vector\n";
    std::cout << "8. Acces la elemente al doilea vector\n";
    std::cout << "9. Calcul modul primul vector\n";
    std::cout << "10. Calcul modul al doilea vector\n";
    std::cout << "11. Adunare cei doi vectori\n";
    std::cout << "12. Afisare primul vector\n";
    std::cout << "13. Afisare al doilea vector\n";
    std::cout << "14. Iesire\n";
    std::cout << "Selectati o optiune: ";
}

int main() {
    Vector vector1, vector2;
    bool initialized1 = false, initialized2 = false;

    while (true) {
        displayMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            initializeVector(vector1);
            initialized1 = true;
            break;

        case 2:
            initializeVector(vector2);
            initialized2 = true;
            break;

        case 3:
            if (initialized1) {
                vector1.destroy();
                initialized1 = false;
                std::cout << "Primul vector a fost eliminat.\n";
            }
            else {
                std::cout << "Primul vector nu este initializat.\n";
            }
            break;

        case 4:
            if (initialized2) {
                vector2.destroy();
                initialized2 = false;
                std::cout << "Al doilea vector a fost eliminat.\n";
            }
            else {
                std::cout << "Al doilea vector nu este initializat.\n";
            }
            break;

        case 5:
            if (initialized1) {
                int new_size;
                std::cout << "Introduceti noua dimensiune a primul vector: ";
                std::cin >> new_size;
                vector1.resize(new_size);
                std::cout << "Dimensiunea primul vector a fost modificata.\n";
            }
            else {
                std::cout << "Primul vector nu este initializat.\n";
            }
            break;

        case 6:
            if (initialized2) {
                int new_size;
                std::cout << "Introduceti noua dimensiune a al doilea vector: ";
                std::cin >> new_size;
                vector2.resize(new_size);
                std::cout << "Dimensiunea al doilea vector a fost modificata.\n";
            }
            else {
                std::cout << "Al doilea vector nu este initializat.\n";
            }
            break;

        case 7:
            if (initialized1) {
                int index;
                std::cout << "Introduceti indexul elementului primul vector: ";
                std::cin >> index;
                if (index >= 0 && index < vector1.size) {
                    std::cout << "Elementul " << index << " are valoarea " << vector1.at(index) << std::endl;
                }
                else {
                    std::cout << "Index invalid.\n";
                }
            }
            else {
                std::cout << "Primul vector nu este initializat.\n";
            }
            break;

        case 8:
            if (initialized2) {
                int index;
                std::cout << "Introduceti indexul elementului al doilea vector: ";
                std::cin >> index;
                if (index >= 0 && index < vector2.size) {
                    std::cout << "Elementul " << index << " are valoarea " << vector2.at(index) << std::endl;
                }
                else {
                    std::cout << "Index invalid.\n";
                }
            }
            else {
                std::cout << "Al doilea vector nu este initializat.\n";
            }
            break;

        case 9:
            if (initialized1) {
                double mod = vector1.modulus();
                std::cout << "Modulul primul vector: " << mod << std::endl;
            }
            else {
                std::cout << "Primul vector nu este initializat.\n";
            }
            break;

        case 10:
            if (initialized2) {
                double mod = vector2.modulus();
                std::cout << "Modulul al doilea vector: " << mod << std::endl;
            }
            else {
                std::cout << "Al doilea vector nu este initializat.\n";
            }
            break;

        case 11:
            if (initialized1 && initialized2) {
                if (vector1.size == vector2.size) {
                    Vector result;
                    result.init(vector1.size);

                    for (int i = 0; i < vector1.size; i++) {
                        result.at(i) = vector1.at(i) + vector2.at(i);
                    }

                    std::cout << "Rezultatul adunarii celor doi vectori:\n";
                    displayVector(result);

                    result.destroy();
                }
                else {
                    std::cerr << "Vectorii au dimensiuni diferite si nu pot fi adunati.\n";
                }
            }
            else {
                std::cout << "Primul si/sau al doilea vector nu sunt initializate.\n";
            }
            break;

        case 12:
            if (initialized1) {
                std::cout << "Primul ";
                displayVector(vector1);
            }
            else {
                std::cout << "Primul vector nu este initializat.\n";
            }
            break;

        case 13:
            if (initialized2) {
                std::cout << "Al doilea ";
                displayVector(vector2);
            }
            else {
                std::cout << "Al doilea vector nu este initializat.\n";
            }
            break;

        case 14:
            if (initialized1) {
                vector1.destroy();
            }
            if (initialized2) {
                vector2.destroy();
            }
            std::cout << "Iesire din program.\n";
            return 0;

        default:
            std::cout << "Optiune invalida. Reincercati.\n";
        }
    }

    return 0;
}
