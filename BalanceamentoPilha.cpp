#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Protótipo da função que realizará o balanceamento
void balanceamento(string expressao);

int main()
{
    string expressao;
    cout << "\nDigite uma expressão: ";
    getline(cin >> ws, expressao);

    balanceamento(expressao); // Chamada correta da função
    return 0;
}

void balanceamento(string expressao) // Função que verifica se a expressão está balanceada
{
    stack<char> PilhaBalanceamento; // Declaração da pilha para armazenar os símbolos de entrada

    for (int i = 0; i < expressao.size(); i++)
    {
        if (expressao[i] == '(' or expressao[i] == '[' or expressao[i] == '{')
        {
            PilhaBalanceamento.push(expressao[i]);
        }
        else if (expressao[i] == ')' or expressao[i] == ']' or expressao[i] == '}')
        {
            if (PilhaBalanceamento.empty())
            {
                cout << "Expressão desbalanceada!";
                return;
            }
            else if (PilhaBalanceamento.top() == '(' and expressao[i] == ')')
            {
                PilhaBalanceamento.pop();
            }
            else if (PilhaBalanceamento.top() == '[' and expressao[i] == ']')
            {
                PilhaBalanceamento.pop();
            }
            else if (PilhaBalanceamento.top() == '{' and expressao[i] == '}')
            {
                PilhaBalanceamento.pop();
            }
            else
            {
                cout << "Expressão desbalanceada!";
                return;
            }
        }
    }

    // Verifica se a pilha está vazia no final
    if (!PilhaBalanceamento.empty())
        cout << "Expressão desbalanceada!"; // Se a pilha ainda tiver elementos, há aberturas sem fechamentos
    else
        cout << "Expressão balanceada!";
}