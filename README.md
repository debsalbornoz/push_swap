<h1 align="center"> Push_swap</h1>

<div align="center">
<img src="https://github.com/debsalbornoz/push_swap/assets/119970138/9f579a43-3c59-4020-b57e-e464e80880fd">
</div> 
<div align="center">
<img alt="Static Badge" src="https://img.shields.io/badge/Status-Finished-green">
</div>

[pshhh.webm](https://github.com/user-attachments/assets/dff23ac6-0189-4d67-a216-4fcf791724ec)


## Push Swap


## Descrição


O **Push Swap** é um projeto que visa ordenar uma pilha de números inteiros utilizando duas pilhas e um conjunto de operações básicas. O objetivo é ordenar a pilha original com o menor número possível de operações.
O projeto implementa uma abordagem eficiente para resolver o problema, levando em consideração a complexidade das operações e a necessidade de otimização.


## Funcionamento


O projeto é inicializado com duas pilhas, `a` e `b`, `a` recebe os argumentos do programa na ordem em que foram passados e `b` não recebe nada.  O algoritmo para ordenar a pilha é dividido em várias etapas interdependentes, descritas a seguir:


1. **Configuração das Posições**:
   - Cada nó na pilha é atribuído uma posição atual e uma indicação se está acima ou abaixo da mediana da pilha. Isso ajuda a decidir quais nós são mais "importantes" para serem movidos primeiro.

2. **Definição do Nó-Alvo**:
   - Para cada nó na pilha `b`, o algoritmo determina o melhor nó na pilha `a` para ser o "alvo" desse nó. O alvo é o menor maior nó da pilha `b`. Se não há tal nó, o alvo é o menor nó da pilha `a`.

3. **Cálculo dos Preços de Movimentação**:
   - A cada nó na pilha `b` é atribuído um "preço" que representa o custo total de operações para movê-lo para a pilha `a`. Este preço é baseado na posição atual do nó na pilha `b` e na posição do nó alvo na pilha `a`. O cálculo leva em conta se o nó está acima ou abaixo da mediana, influenciando o custo de movimentação.

4. **Identificação do Nó Mais Barato**:
   - Entre todos os nós na pilha `b`, é identificado aquele com o menor preço de movimentação. Esse nó é marcado como o mais barato e é o próximo a ser movido.

Esse processo é repetido até que todos os nós estejam ordenados na pilha `a`.

### Ordenação de Pilhas Pequenas

- Para pilhas pequenas, uma função específica realiza a ordenação com um conjunto básico de operações:
  - **Rotate**: Rotaciona a pilha para cima, movendo o primeiro elemento para o final.
  - **Reverse Rotate**: Rotaciona a pilha para baixo, movendo o último elemento para o início.
  - **Swap**: Troca os dois primeiros elementos da pilha.

Estas operações são utilizadas para ajustar a pilha de forma a aproximá-la da ordenação desejada.

## Regras

- **Regras**:
  - Utilizar apenas as operações básicas: `push`, `swap`, `rotate`, e `reverse rotate`.
  - A ordenação deve ser eficiente, minimizando o número total de operações.

## Instalação e Compilação

Para começar a trabalhar com o projeto, clone o repositório para o seu ambiente local utilizando o comando:


```
git clone https://github.com/debsalbornoz/push_swap.git
```

Após clonar o repositório, acesse o diretório do projeto:

```
cd push_swap

```

Certifique-se de que o compilador C e outras ferramentas necessárias estão instalados no seu sistema. Compile o projeto usando o comando "make". Isso irá compilar o código-fonte e gerar o executável do projeto.

