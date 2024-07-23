#include <iostream>
#include <string>
using namespace std;

class AnimalEstimacao{
private: 
  string nome;
  string raca;
public:
//construtor
  AnimalEstimacao(string nome, string raca){
    this->nome = nome;
    this->raca = raca;
  }

//getters
  string getNome(){
    return nome;
  }
  string getRaca(){
    return raca;
  }

  void caminha(){
    cout << "O animal " << nome << " da raça " << raca << " caminha";
  }

};

class Cachorro : public AnimalEstimacao{
public:
  //construtor
  Cachorro(string nome, string raca):AnimalEstimacao(nome, raca) {}

  void late(){
    AnimalEstimacao::caminha();
    cout << " e late" << endl;
  }
};

class Gato: public AnimalEstimacao{
public:
//construtor
  Gato(string nome, string raca):AnimalEstimacao(nome, raca){}

  void mia(){
    AnimalEstimacao::caminha();
    cout << " e mia" << endl;
  }
};

int main(){
  AnimalEstimacao a1("Fofo", "Poodle");
  a1.caminha();
  cout << "\n";
  Cachorro c1("Totó", "Yorkshire");
  c1.late();
  Gato g1("Mingau", "Siamês");
  g1.mia();
  return 0;
}