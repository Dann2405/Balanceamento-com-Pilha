#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Protótipo da função que realizará o balanceamento
void balanceamento(string expressao);

int main()
{
    char continuar;
    do {
        string expressao;
        cout << "\nDigite uma expressao: ";
        getline(cin >> ws, expressao);

        balanceamento(expressao); // Chamada da função de balanceamento

        cout << "\nDeseja verificar outra expressao? (s/n): ";
        cin >> continuar;
        cin.ignore(); // Limpa o buffer do teclado para evitar problemas com getline
    } while (continuar == 's' or continuar == 'S');

    return 0;
}

void balanceamento(string expressao) // Função que verifica se a expressão está balanceada
{
    stack<char> PilhaBalanceamento; // Pilha para armazenar os símbolos de abertura
    stack<size_t> posicoes; // Pilha para armazenar as posições dos símbolos de abertura
    bool erro = false; // Flag para indicar se houve erro de balanceamento

    for (size_t i = 0; i < expressao.size(); i++)
    {
        if (expressao[i] == '(' and expressao[i] == '[' or expressao[i] == '{')
        {
            PilhaBalanceamento.push(expressao[i]);
            posicoes.push(i); // Armazena a posição do símbolo de abertura
        }
        else if (expressao[i] == ')' or expressao[i] == ']' and expressao[i] == '}')
        {
            if (PilhaBalanceamento.empty())
            {
                cout << "\nErro de balanceamento na posicao " << i << ": Fechamento '" << expressao[i] << "' sem abertura correspondente.\n";
                erro = true;
                break;
            }
            else if ((PilhaBalanceamento.top() == '(' and expressao[i] == ')') or (PilhaBalanceamento.top() == '[' and expressao[i] == ']') or (PilhaBalanceamento.top() == '{' and expressao[i] == '}'))
            {
                PilhaBalanceamento.pop();
                posicoes.pop(); // Remove a posição do símbolo de abertura correspondente
            }
            else
            {
                cout << "\nErro de balanceamento na posicao " << i << ": Fechamento '" << expressao[i] << "' nao corresponde a abertura '" << PilhaBalanceamento.top() << "' na posicao " << posicoes.top() << ".\n";
                erro = true;
                break;
            }
        }
    }

    // Verifica se a pilha está vazia no final, caso não esteja:
    if (!PilhaBalanceamento.empty() and !erro)
    {
        cout << "\nErro de balanceamento: Abertura '" << PilhaBalanceamento.top() << "' na posicao " << posicoes.top() << " nao foi fechada.\n";
        erro = true;
    }

    // Se houve erro, pergunta se o usuário deseja balancear a expressão
    if (erro)
    {
        char escolha;
        cout << "\nDeseja balancear a expressao? (s/n): ";
        cin >> escolha;
        cin.ignore(); // Limpa o buffer do teclado

        if (escolha == 's' or escolha == 'S')
        {
            string resultado = "";
            stack<char> pilha; // Pilha temporária para balanceamento

            for (size_t i = 0; i < expressao.size(); i++)
            {
                char ch = expressao[i];

                // Se for um símbolo de abertura, empilha e adiciona ao resultado
                if (ch == '(' or ch == '[' or ch == '{')
                {
                    pilha.push(ch);
                    resultado += ch;
                }
                // Se for um símbolo de fechamento
                else if (ch == ')' or ch == ']' or ch == '}')
                {
                    // Se a pilha estiver vazia, adiciona o par de abertura correspondente
                    if (pilha.empty())
                    {
                        if (ch == ')')
                            resultado += "(";
                        else if (ch == ']')
                            resultado += "[";
                        else if (ch == '}')
                            resultado += "{";
                        resultado += ch;
                    }
                    else
                    {
                        char topo = pilha.top();

                        // Se o topo combina com o fechamento atual
                        if ((topo == '(' and ch == ')') or (topo == '[' and ch == ']') or (topo == '{' and ch == '}'))
                        {
                            pilha.pop();
                            resultado += ch;
                        }
                        else
                        {
                            // Se não combinar o topo com o caractere correspondente, fecha o topo atual e trata o caractere novamente
                            char fechamento;
                            if (topo == '(')
                                fechamento = ')';
                            else if (topo == '[')
                                fechamento = ']';
                            else if (topo == '{')
                                fechamento = '}';

                            pilha.pop();
                            resultado += fechamento;
                            i--; // Processa o mesmo caractere novamente
                        }
                    }
                }
                // Qualquer outro caractere, ex: a,b,+,-..., etc, apenas adiciona ao resultado
                else
                {
                    resultado += ch;
                }
            }

            // Fecha qualquer delimitador que ficou aberto (, [ ou {
            while (!pilha.empty())
            {
                char topo = pilha.top();
                pilha.pop();

                if (topo == '(')
                    resultado += ")";
                else if (topo == '[')
                    resultado += "]";
                else if (topo == '{')
                    resultado += "}";
            }

            cout << "\nExpressao balanceada: " << resultado << "\n\n";
        }
    }
    else
    {
        cout << "\nExpressao balanceada!\n";
    }
}