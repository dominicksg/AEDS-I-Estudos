










































#include <iostream>

using namespace std;

class AnimalEstimacao
{
private:
    string nome;
    string raca;

public:
    AnimalEstimacao(string name, string race)
    {
        nome = name;
        raca = race;
    }

    string getNome()
    {
        return nome;
    }

    string getRaca() { return raca; }

    void caminha()
    {
        cout << "O animal " << nome << " da raca " << raca << " caminha";
    }
};

class Cachorro : public AnimalEstimacao
{
public:
    Cachorro(string name, string race) : AnimalEstimacao(name, race) {}

    void late()
    {
        AnimalEstimacao::caminha();
        cout << " e late" << endl;
    }
};

class Gato : public AnimalEstimacao
{
public:
    Gato(string name, string race) : AnimalEstimacao(name, race) {}

    void mia()
    {
        AnimalEstimacao::caminha();
        cout << " e mia" << endl;
    }
};

int main()
{
    AnimalEstimacao animal("Morcego", "Bruce");
    Cachorro dog("Sif", "Golden");
    Gato cat("Mike", "Siames");

    animal.caminha();
    cout << "\n";
    dog.late();
    cat.mia();
}
