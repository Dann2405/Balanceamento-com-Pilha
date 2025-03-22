#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    stack <char> PilhaBalanceamento;
    string expressao;
    cout << "\nDigite uma expressão: ";
    getline(cin>>ws,expressao);

   for (int i=0; i<expressao.size(); i++){
        if (expressao[i]=='(' or expressao[i]=='[' or expressao[i]=='{'){
            PilhaBalanceamento.push(expressao[i]);
        } else 
                if (expressao[i]==')' or expressao[i]==']' or expressao[i]=='}'){
                        if (PilhaBalanceamento.empty()) {
                            cout << "Expressão desbalanceada!";
                            return 0;
                        }
                        else if (PilhaBalanceamento.top() == '(' and expressao[i]==')'){
                            PilhaBalanceamento.pop();
                        }
                        else if (PilhaBalanceamento.top() == '[' and expressao[i]==']'){
                                    PilhaBalanceamento.pop();
                        }  
                        else if (PilhaBalanceamento.top() == '{' and expressao[i] == '}'){
                                PilhaBalanceamento.pop();
                        }
                        else
                            cout << "Expressão desbalanceada!";
                        }
        }
    }
    
    // Verifica se a pilha está vazia no final
    if (!PilhaBalanceamento.empty())
        cout << "Expressão desbalanceada!";
    else
        cout << "Expressão balanceada!";

   
    return 0;
}
