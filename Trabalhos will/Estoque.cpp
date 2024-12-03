#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Produto {
private:
    string nome;
    int codigo;
    int quantidade;
    float preco;

public:
    Produto(string nome, int codigo, int quantidade, float preco)
        : nome(nome), codigo(codigo), quantidade(quantidade), preco(preco) {}

    int getCodigo() const { return codigo; }

    void aumentarEstoque(int qtd) {
        quantidade += qtd;
    }

    void diminuirEstoque(int qtd) {
        if (quantidade >= qtd) {
            quantidade -= qtd;
        } else {
            cout << "Estoque insuficiente!" << endl;
        }
    }

    void exibirProduto() const {
        cout << "Nome: " << nome << ", Código: " << codigo
             << ", Quantidade: " << quantidade << ", Preço: R$" << preco << endl;
    }
};

class Funcionario {
private:
    string nome;
    int id;
    string cargo;

public:
    Funcionario(string nome, int id, string cargo)
        : nome(nome), id(id), cargo(cargo) {}

    void exibirFuncionario() const {
        cout << "Nome: " << nome << ", ID: " << id << ", Cargo: " << cargo << endl;
    }
};

void exibirMenu() {
    cout << "\nMenu de Gerenciamento de Estoque" << endl;
    cout << "1. Adicionar Produto" << endl;
    cout << "2. Remover Produto" << endl;
    cout << "3. Entrada de Produto no Estoque" << endl;
    cout << "4. Saída de Produto do Estoque" << endl;
    cout << "5. Exibir Produtos" << endl;
    cout << "6. Adicionar Funcionário" << endl;
    cout << "7. Exibir Funcionários" << endl;
    cout << "8. Sair" << endl;
    cout << "Escolha uma opção: ";
}

int main() {
    vector<Produto> produtos;
    vector<Funcionario> funcionarios;
    int opcao;
    bool rodando = true;

    while (rodando) {
        exibirMenu();
        cin >> opcao;

        switch (opcao) {
        case 1: {
            string nome;
            int codigo, quantidade;
            float preco;
            cout << "Digite o nome do produto: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Digite o código do produto: ";
            cin >> codigo;
            cout << "Digite a quantidade do produto: ";
            cin >> quantidade;
            cout << "Digite o preço do produto: ";
            cin >> preco;

            Produto novoProduto(nome, codigo, quantidade, preco);
            produtos.push_back(novoProduto);
            cout << "Produto adicionado com sucesso!" << endl;
            break;
        }

        case 2: {
            int codigo;
            cout << "Digite o código do produto a ser removido: ";
            cin >> codigo;

            bool encontrado = false;
            for (auto it = produtos.begin(); it != produtos.end(); ++it) {
                if (it->getCodigo() == codigo) {
                    produtos.erase(it);
                    cout << "Produto removido com sucesso!" << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Produto não encontrado!" << endl;
            }
            break;
        }

        case 3: {
            int codigo, quantidade;
            cout << "Digite o código do produto para entrada no estoque: ";
            cin >> codigo;
            cout << "Digite a quantidade a ser adicionada: ";
            cin >> quantidade;

            bool encontrado = false;
            for (auto &produto : produtos) {
                if (produto.getCodigo() == codigo) {
                    produto.aumentarEstoque(quantidade);
                    cout << "Estoque atualizado com sucesso!" << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Produto não encontrado!" << endl;
            }
            break;
        }

        case 4: {
            int codigo, quantidade;
            cout << "Digite o código do produto para saída do estoque: ";
            cin >> codigo;
            cout << "Digite a quantidade a ser removida: ";
            cin >> quantidade;

            bool encontrado = false;
            for (auto &produto : produtos) {
                if (produto.getCodigo() == codigo) {
                    produto.diminuirEstoque(quantidade);
                    cout << "Estoque atualizado com sucesso!" << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Produto não encontrado!" << endl;
            }
            break;
        }

        case 5: {
            cout << "\nLista de Produtos:" << endl;
            if (produtos.empty()) {
                cout << "Nenhum produto cadastrado." << endl;
            } else {
                for (const auto &produto : produtos) {
                    produto.exibirProduto();
                }
            }
            break;
        }

        case 6: {
            string nome, cargo;
            int id;
            cout << "Digite o nome do funcionário: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Digite o ID do funcionário: ";
            cin >> id;
            cout << "Digite o cargo do funcionário: ";
            cin.ignore();
            getline(cin, cargo);

            Funcionario novoFuncionario(nome, id, cargo);
            funcionarios.push_back(novoFuncionario);
            cout << "Funcionário adicionado com sucesso!" << endl;
            break;
        }

        case 7: {
            cout << "\nLista de Funcionários:" << endl;
            if (funcionarios.empty()) {
                cout << "Nenhum funcionário cadastrado." << endl;
            } else {
                for (const auto &funcionario : funcionarios) {
                    funcionario.exibirFuncionario();
                }
            }
            break;
        }

        case 8:
            rodando = false;
            cout << "Saindo do sistema..." << endl;
            break;

        default:
            cout << "Opção inválida! Tente novamente." << endl;
        }
    }

    return 0;
}