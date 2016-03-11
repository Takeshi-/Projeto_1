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

Não existe entradas além do executável: ./sorts
Porém caso queira mudar o tamanho do vetor verifique a constante TAMANHO. Coloque valores menores que 1000000, pois a partir desse valor o programa começa a levar muito tempo.
Será criado um novo arquivo com todas as informações e na saída padrão aparecerá o melhor tempo e qual foi o algoritmo.

## Como medir o desempenho

O tempo mostrado mede tempo de execução de cada algoritmo diferente de ordenação e qual é o melhor para cada tipo de vetor, melhor,médio epior caso.
Faça a média aritmética de 5 vezes, já é o suficiente para se ter um resultado considerável. 

## Como apresentar o desempenho

Como o desempenho deverÃ¡ ser mostrado. Margem de erro, etc. 

## MediÃ§Ãµes base (uma mÃ¡quina)

Inclua a especificaÃ§Ã£o dos componentes relevantes e os resultados de desempenho.
