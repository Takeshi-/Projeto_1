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

Basta executar o programa, e se desejar armazenar a resposta que é impressa no terminal, basta executar o programa da seguinte maneira:
./sorts > saida.txt

## Como medir o desempenho

O tempo mostrado mede tempo de execução de cada algoritmo diferente de ordenação e qual é o melhor para cada tipo de vetor, melhor,médio e pior caso.
Faça a média aritmética de 5 vezes, já é o suficiente para se ter um resultado considerável. Mas se quiser fazer mais vezes mude o valor da constante REPETICOES.
O desempenho será analizado atraves das médias dos melhores tempos de cada caso (melhor, medio e pior caso). Estas informações serão impressas no final da execução do programa.

## Como apresentar o desempenho

Como o desempenho deverÃ¡ ser mostrado. Margem de erro, etc. 

## Medições base

A maquina utilizada tem as seguintes expecificações: 
Intel® Core™ i5-4590 CPU @ 3.30GHz × 4;  Memory 8 GiB;  64-bit graph: Intel® Haswell Desktop , Gnome: Version 3.18.2; Disk 216.9 GB; Fedora 23
As medições foram feitas com a execução do programa, e extraídas por um dos integrantes do grupo.
