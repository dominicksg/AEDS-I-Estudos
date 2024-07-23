#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cliente
{
    string nome;
    string cpf;

public:
    Cliente() {}
    Cliente(string nome, string cpf)
    {
        this->nome = nome;
        this->cpf = cpf;
    }

    string getNome()
    {
        return nome;
    }

    string getCPF()
    {
        return cpf;
    }
};

class ItemComanda
{
private:
    string descricao;
    double valor;

public:
    ItemComanda() {}
    ItemComanda(string descricao, double valor)
    {
        this->descricao = descricao;
        this->valor = valor;
    }

    double getValor()
    {
        return valor;
    }
};

class Comanda
{
private:
    Cliente cliente;
    string data;
    string garcom;
    ItemComanda itens[10];
    int nItens;

public:
    Comanda(Cliente cliente, string data, string garcom, ItemComanda itens[])
    {
        this->cliente = cliente;
        this->data = data;
        this->garcom = garcom;
        // Copiando cada elemento do array itens para o array desta classe
        for (int i = 0; i < 10; ++i)
        {
            this->itens[i] = itens[i];
        }
    }

    void adicionarItemComanda(ItemComanda pedido)
    {
        if (nItens < 10)
        {
            itens[nItens] = pedido;
            nItens++;
        }
    }

    int getNumeroItensComanda()
    {
        return nItens;
    }

    double getValorTotal()
    {
        double total = 0;
        for (int i = 0; i < nItens; i++)
            total += itens[i].getValor();
        return total;
    }
};

int main()
{

    Cliente cliente1("Dom", "696969");
    // ItemComanda itens[];

    Comanda comanda1(cliente1, "15/02", "Gefferson", itens);

    ItemComanda item1("Caviar", 540);
    ItemComanda item2("Hamburgao", 54);

    comanda1.adicionarItemComanda(item1);
    comanda1.adicionarItemComanda(item2);

    return 0;
}