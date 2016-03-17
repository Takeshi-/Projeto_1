# Sorts.c - Ordenação

## O que faz? Para que serve?

O programa retorna os tempos de execução de diversos tipos de algoritmos de ordenação.
Serve para conferir qual o algoritmo mais rápido e quanto tempo ele demora em relação a diferentes tipos de vetores, melhor(já ordenado) ou pior(vetor ao contrário) caso.

## Por que é bom para medir desempenho?

Análise de memória e alocação do vetor, principalmente pelo fato de usar vetores dinâmicos.

## O que baixar
O código sorts.c está no repositório do GitHub: https://github.com/Takeshi-/Projeto_1

## Como compilar/instalar

Basta criar um novo arquivo sorts.c a partir do código fonte e utilizar o Makefile.
Utilize no terminal a linha de comando: time make

## Como executar

Existe 3 opções de executar o programa: com nenhuma entrada, com 1 entrada numérica de inteiro, ou com 2 entradas numéricas de inteiro.
Se não utilizar nenhuma entrada, ele vai usar o default definido no código executavel (tamanho do vetor de 10.000) e número de repetições de 5 iterações.
A primeira entrada, para os dois casos(com uma ou duas entradas) corresponderá ao tamanho do vetor. A segunda entrada corresponderá ao número de iterações de cada algoritmo de ordenação, para cada caso (se não colocar, sera usado o default).
A saida será impressa no terminal. Caso deseje que ela seja inserida no arquivo, basta executar o programa, e depois inserir "> (nome do arquivo de saida)", que sera gerado o arquivo de saida.

Exemplos de entradas e execuções:
1. ./sorts : Ele fara com o tamanha do vetor e numero de repetições definidos no programa, e imprimirá no terminal.
2. ./sorts 1000000 20 > saida.txt : ele fara as ordenações com um vetor de tamanho 10e6, com 20 repetições em cada caso, e gerara o arquivo saida.txt, com o conteúdo da saida.
3. ./sorts 100 100 100 : ele não executará o programa. O número máximo de entradas é de 2 termos númericos.

## Como medir o desempenho

O tempo mostrado mede tempo de execução de cada algoritmo diferente de ordenação e qual é o melhor para cada tipo de vetor, melhor,médio e pior caso.
Faça a média aritmética de 5 vezes, já é o suficiente para se ter um resultado considerável. Mas se quiser fazer mais vezes mude o valor da constante REPETICOES.

## Como apresentar o desempenho

Como o desempenho deverÃ¡ ser mostrado. Margem de erro, etc. 

## MediÃ§Ãµes base (uma mÃ¡quina)

Inclua a especificaÃ§Ã£o dos componentes relevantes e os resultados de desempenho.
