#include <iostream>
#include <string>

using namespace std;

class Pessoa
{
    string nome;
    int idade;
    double altura;

public:
    // get
    string getNome() const { return nome; }
    int getIdade() const { return idade; }
    double getAltura() const { return altura; }

    // set
    void setNome(string name)
    {
        nome = name;
    }
    void setIdade(int age)
    {
        idade = age;
    }
    void setAltura(double height)
    {
        altura = height;
    }
    // prints
    void printDados()
    {
        cout << "nome: " << nome << endl;
        cout << "idade: " << idade << " anos" << endl;
        cout << "altura: " << altura << " metros" << endl;
    }
};

int main()
{
    Pessoa pessoa1;
    pessoa1.setNome("Maria");
    pessoa1.setIdade(12);
    pessoa1.setAltura(1.52);

    pessoa1.printDados();

    // Obtendo os valores dos atributos usando os métodos "get"

    // string nome = pessoa1.getNome();
    // int idade = pessoa1.getIdade();
    // double altura = pessoa1.getAltura();

    return 0;
}
