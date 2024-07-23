#include <iostream>
#include <exception>
#include <string>

using namespace std;

// Definição da classe ExcecaoValorInvalidoDado, que herda de std::exception
class ExcecaoValorInvalidoDado : public exception {
public:
    // Sobrescrevendo o método what() para retornar a mensagem de erro
    const char* what() const noexcept override {
        return "Erro: Valor inválido para o dado.";
    }
};

int main() {
    int resultado;
    cout << "Digite o número do dado" << endl;
    cin >> resultado;

    try {
        if (resultado < 1 || resultado > 6) {
            // Lançando a exceção personalizada ExcecaoValorInvalidoDado
            throw ExcecaoValorInvalidoDado();
        } else {
            cout << "O valor do dado foi: " << resultado << endl;
        }
    } catch (ExcecaoValorInvalidoDado& ex) {
        cout << "Erro: " << ex.what() << endl;
    }

    return 0;
}
