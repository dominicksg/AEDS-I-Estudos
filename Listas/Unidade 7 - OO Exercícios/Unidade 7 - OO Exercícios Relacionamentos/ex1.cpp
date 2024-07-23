#include <iostream>
#include <string>

using namespace std;

class Cliente {
private:
    string nome;
    string cpf;

public:
    Cliente() { }

    Cliente(string nome, string cpf) {
        this->nome = nome;
        this->cpf = cpf;
    }

    string getNome() {
        return nome;
    }

    string getCpf() {
        return cpf;
    }
};

class ItemComanda {
private:
    string descricao;
    double valor;

public:
    ItemComanda() {}

    ItemComanda(string d, double v): descricao(d), valor(v) { }

    string getDescricao() {
        return descricao;
    }

    double getValor() {
        return valor;
    }
};

class Comanda {
    string data;
    string garcom;
    Cliente cliente;
    ItemComanda itens[10];
    int nItens;

public:
    Comanda(string data, string garcom): nItens(0) {
        this->data = data;
        this->garcom = garcom;
    }

    string getData() {
        return data;
    }

    string getGarcom() {
        return garcom;
    }

    void setCliente(Cliente cliente) {
        this->cliente = cliente;
    }

    Cliente getCliente() {
        return cliente;
    }

    void adicionarItemComanda(ItemComanda item) {
        if(nItens < 10) {
            itens[nItens++] = item;
        }
    }

    int getNumeroItensComanda() {
        return nItens;
    }

    double getValorTotal() {
        double total = 0;
        for(int i = 0; i < nItens; i++)
            total += itens[i].getValor();
        return total;
    }
};

int main()
{
    Cliente cliente("Amanda", "123456789-00");
    Comanda comanda("12/10/2023", "Carlos");
    comanda.setCliente(cliente);
    comanda.adicionarItemComanda(ItemComanda("File com fritas", 56.00));
    comanda.adicionarItemComanda(ItemComanda("Guarana Antartica", 5.00));
    cout << "Resumo de comanda" << endl;
    cout << "Data: " << comanda.getData() << endl;
    cout << "Garcom: " << comanda.getGarcom() << endl;
    cout << "Cliente: " << comanda.getCliente().getNome() << " | " << comanda.getCliente().getCpf() << endl;
    cout << "Total de itens: " << comanda.getNumeroItensComanda() << endl;
    cout << "Valor Total: " << comanda.getValorTotal() << endl;
    return 0;
}
