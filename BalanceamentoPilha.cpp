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

    balanceamento(expressao); // Chamada da função de balanceamento
    return 0;
}

void balanceamento(string expressao) // Função que verifica se a expressão está balanceada
{
    stack<char> PilhaBalanceamento, pilha; // Declaração da pilha para armazenar os símbolos de entrada
    char d;

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
                cout << "\nExpressão desbalanceada!";
            }
        }
    }

    // Verifica se a pilha está vazia no final, caso não esteja:
    if (!PilhaBalanceamento.empty())
    {
        cout << "\nDeseja balancear a expressao? (s/n) ";
        cin >> d;
        if (d == 'S' or d == 's')
        {
            string resultado = "";
            // size_t percorre toda a string, onde .size() vai retornar o tamanho dela para ser percorrida, onde o indice vai de 0 até o tamanho final da string.
            for (size_t i = 0; i < expressao.size(); i++)
            {
                char ch = expressao[i];

                // Se for um smbolo de abertura, empilha e adiciona ao resultado
                if (ch == '(' or ch == '[' or ch == '{')
                {
                    pilha.push(ch);
                    resultado += ch;
                }
                // caso contrario, Se for um simbolo de fechamento
                else if (ch == ')' or ch == ']' or ch == '}')
                {
                    // Se a pilha estiver vazia, adiciona o par de abertura correspondente
                    if (pilha.empty())
                    {
                        if (ch == ')')
                            resultado += "(" + string(1, ch);
                        else if (ch == ']')
                            resultado += "[" + string(1, ch);
                        else
                            resultado += "{" + string(1, ch);
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
                            else
                                fechamento = '}';

                            pilha.pop();
                            resultado += fechamento;
                            i--; // Processa o mesmo caractere novamente
                        }
                    }
                }
                // Qualquer outro caractere,  ex: a,b,+,-..., etc, apenas adiciona ao resultado
                else
                {
                    resultado += ch;
                }
            }

            // Fecha qualquer delimitador que ficou aberto (, [ ou {
            string fechamentos = "";
            while (!pilha.empty())
            {
                char topo = pilha.top();
                pilha.pop();

                if (topo == '(')
                    fechamentos = ')' + fechamentos;
                else if (topo == '[')
                    fechamentos = ']' + fechamentos;
                else
                    fechamentos = '}' + fechamentos;
            }
            resultado += fechamentos;
            cout << "\nExpressão balanceada: " << resultado << "\n\n";
        }
    }
    else
        cout << "\nExpressao balanceada!";
}
