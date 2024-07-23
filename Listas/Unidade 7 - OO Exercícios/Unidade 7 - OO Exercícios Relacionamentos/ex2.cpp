#include <iostream>

using namespace std;

class AnimalEstimacao {
    string nome;
    string raca;

public:
    AnimalEstimacao(string nome, string raca) {
        this->nome = nome;
        this-> raca = raca;
    }

    void caminha() {
        cout << this->getIdentificacao() << " caminhando" << endl;
    }



protected:
    string getIdentificacao() {
        return nome + " da raca " + raca;
    }


};

class Cachorro : public AnimalEstimacao {
public:
    Cachorro(string nome, string raca) : AnimalEstimacao(nome, raca) {
    }

    void late() {
        cout << this->getIdentificacao() << " latindo... au au" << endl;
    }
};

class Gato : public AnimalEstimacao {
public:
    Gato(string nome, string raca) : AnimalEstimacao(nome, raca) {
    }

    void mia() {
        cout << this->getIdentificacao() << " miando... miaaaauuuu" << endl;
    }
};

int main()
{
    Cachorro cachorro("Tufao", "Labrador");
    cachorro.caminha();
    cachorro.late();

    Gato gato("Manoel", "Siames");
    gato.caminha();
    gato.mia();

    return 0;
}
