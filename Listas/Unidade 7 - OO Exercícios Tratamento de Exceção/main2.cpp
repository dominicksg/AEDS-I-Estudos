#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class ExcecaoValorInvalidoDado : public exception {
private:
    string mensagem;

public:
    ExcecaoValorInvalidoDado(const string& valor) : mensagem(valor) {}

    const char* what() const noexcept override {
        return mensagem.c_str();
    }
};

int main() {
    int numeroLancamento;

    cout << "Digite o valor do lancamento do dado (de 1 a 6): ";
    cin >> numeroLancamento;

    try {
        if (numeroLancamento < 1 || numeroLancamento > 6) {
            throw ExcecaoValorInvalidoDado(to_string(numeroLancamento));
        } else {
            cout << "O valor do dado foi: " << numeroLancamento << endl;
        }
    } catch (ExcecaoValorInvalidoDado& ex) {
        cout << "Valor invalido: " << ex.what() << endl;
    }

    return 0;
}
