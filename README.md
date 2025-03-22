## **Verificador de Expressões Balanceadas em C++**

### **Descrição do Problema**
Uma expressão matemática é considerada **balanceada** se seguir estas regras:

✅ Para cada abertura de parêntese `(` há um fechamento correspondente `)`.  
✅ Para cada abertura de colchete `[` há um fechamento correspondente `]`.  
✅ Para cada abertura de chave `{` há um fechamento correspondente `}`.  
✅ A ordem dos fechamentos deve ser correta (exemplo: `([)]` não é balanceado).  

### **Exemplos**
✅ **Expressões balanceadas:**  
```
{[()()]}
{([]{})}
((a + b) * (c - d))
```
❌ **Expressões não balanceadas:**  
```
{[()]   // Falta um }
{[(])}  // Ordem incorreta
((a + b] // Uso misto de [ e )
```

---

### **Implementação**
Este programa utiliza **Pilha (Stack)** para verificar se a expressão matemática está balanceada.

🔹 **Passo a passo do algoritmo:**
1. Percorre cada caractere da expressão.  
2. Se encontrar `(`, `[`, ou `{`, **empilha** na pilha.  
3. Se encontrar `)`, `]`, ou `}`, **verifica o topo da pilha**:
   - Se a pilha estiver vazia, a expressão é desbalanceada.
   - Se o topo não corresponder ao fechamento correto, a expressão é desbalanceada.
   - Se corresponder, **desempilha**.  
4. No final, se a pilha **não estiver vazia**, a expressão também é desbalanceada.  

---

### **Tecnologias Utilizadas**
- Linguagem: **C++**
- Estrutura de Dados: **Pilha (Stack)**

---

📌 **Autores**
 **Camila Gomes, Daniel Soares e Rauan Brandão**
