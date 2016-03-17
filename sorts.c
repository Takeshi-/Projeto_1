
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define TAMANHO 70000
#define REPETICOES 5

int* gPiorCaso(int tam);   //Gera vetor para Pior caso = vetor não ordenado
int* gMedioCaso(int tam);  //Gera vetor para Medio caso = vetor semi-ordenado
int* gMelhorCaso(int tam); //Gera vetor para Melhor caso = Vetor ordenado

//A ordem dos vetores esta em Bolha, Seleção, Inserção, Quick, Heap, Shell, Merge
double mediaMelhorCaso[7];
double mediaMedioCaso[7];
double mediaPiorCaso[7];

double tempo();

void bolha(int *v,int n);
void selecao(int *v, int n);
void insercao(int *v, int n);
void quicksort(int *v, int inicio, int fim);
long heapsort(int *v, int N);
void shellsort(int *v, int n);
void mergeSort(int *vetor, int posicaoInicio, int posicaoFim);
void tirarMedia(int rep, int tam);

void piorcaso(int tam); //Executa os 7 metodos de ordenacao usando um vetor desordenado
void mediocaso(int tam); //Executa os 7 metodos de ordenacao usando um vetor semi-ordenado
void melhorcaso(int tam); //Executa os 7 metodos de ordenacao usando um vetor ordenado
void resultados(char *str,double *info, int tam); //recebe o caso testado e as suas respectivas informações para a exibicao dos resultados
void inicializaVetorMedia(); //inicializa os vetores de media

int main(int argc, char* argv[])
{
	int tam, rep;
	tam = TAMANHO;
	rep = REPETICOES;
	/*
	if(argc > 3)
	{
		printf("Numero demasiado grande de entradas. O limite de entradas maximo e 2 numeros, e o minimo, nenhum.\nPrograma abortado\n ");
		return 0;
	}
	else if(argc <= 3 && argc > 1)
	{
		printf("O primeiro numero inserido sera correspondente ao tamanho do vetor: " );
		tam = atoi(argv[1]);
		printf("%d\n", tam);
		if(argc == 3)
		{
			printf("O segundo numero sera correspondente ao numero de iteracoes: ");
			rep = atoi(argv[2]);
			printf("%d\n", rep);
		}
		else
		{
			printf("o numero de iteracoes sera o numero padrao do programa: %d\n", REPETICOES);
		}
	}	
	else
	{
		printf("O tamanho do vetor e o numero de iteracoes serao os padroes, que corresponde respectivamente: \n");
		printf("tamanho = %d\nrepeticoes = %d\n", TAMANHO, REPETICOES);
	}
	*/
	inicializaVetorMedia();
	
	for (int i = 0; i < rep; i++) {
	
		piorcaso(tam);
		mediocaso(tam);
		melhorcaso(tam);

	}
	
	tirarMedia(rep, tam);

	
	return 0;
}

void tirarMedia(int rep, int tam) {
	
	int i;
	char a[17] = {"Media Melhor Caso"}, b[16] = {"Media Caso Medio"}, c[15] = {"Media Pior Caso"};
	for (i = 0; i < 7; i++) {
		mediaMedioCaso[i] /= rep;
		mediaMelhorCaso[i] /= rep;
		mediaPiorCaso[i] /= rep;
	}
	
	for (i = 0; i < 5; i++){
		puts("+----------------------------------------------------------------------------+");
	}
	printf("*************	MEDIA GERAL DE CADA CASO	**********\n");
	resultados(a,mediaMelhorCaso,tam);
	resultados(b,mediaMedioCaso,tam);
	resultados(c,mediaPiorCaso,tam);
}

void inicializaVetorMedia() {
	
	int i;
	
	for (i = 0; i < 7; i++) {
		mediaMedioCaso[i] = 0;
		mediaMelhorCaso[i] = 0;
		mediaPiorCaso[i] = 0;
	}
	
}

int* gPiorCaso(int tam)  //Gera vetor para Pior caso = vetor não ordenado
{
    int i, *vetor;
    vetor = (int*) malloc(sizeof(int) * tam);

    for(i=tam; i>0; i--)
        vetor[tam-i] = i;

    return vetor;
}

int* gMedioCaso(int tam) //Gera vetor para Medio caso = vetor semi-ordenado
{
    /*
    *   Preenche o vetor de maneira ordenada até a metade
    *   e de maneira desordenada da metade do vetor até o final.
    */

    int i, j, meioTamanho=tam/2, *vetor;
    vetor = (int*) malloc(sizeof(int) * tam);

    for(i=0; i<meioTamanho; i++) //Preenche ordenado até a metade
        vetor[i] = i;

    for(i=tam-1,j=meioTamanho; i>=meioTamanho; i--,j++) //Preenche desordenado da metade até o fim
    {
        vetor[i] = j;
    }
    return vetor;
}

int* gMelhorCaso(int tam) //Gera vetor para Melhor caso = Vetor ordenado
{
    int i, *vetor;
    vetor = (int*) malloc(sizeof(int) * tam);

    for(i=0; i<tam; i++)
        vetor[i] = i;

    return vetor;
}


double tempo()
{
    struct timeval instante;

    gettimeofday(&instante, NULL);
    return instante.tv_sec+(instante.tv_usec/1000000.0);
}

void mergeSort(int *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho, *vetorTemp;

    if(posicaoInicio == posicaoFim) return;

    // ordenacao recursiva das duas metades
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);

    // intercalacao no vetor temporario t
    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) { // i passou do final da primeira metade, pegar v[j]
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        } 
        else {
            if (j == posicaoFim + 1) { // j passou do final da segunda metade, pegar v[i]
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            } 
            else {
                if (vetor[i] < vetor[j]) { 
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                } 
                else { 
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }
    // copia vetor intercalado para o vetor original
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}

void bolha(int *v,int n)
{
    int i,j,aux;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(v[i] > v[j])
            {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }
}

void selecao(int *v, int n)
{
    int i,j,menor,aux;
    for(i=0; i<n-1; i++)
    {
        menor=i;
        for(j=i+1; j<n; j++)
            if(v[j]<v[menor])
                menor=j;
        aux=v[i];
        v[i]=v[menor];
        v[menor]=aux;
    }
}

void insercao(int *v, int n)
{
    int i,j,aux;


    for(j=1; j<n; j++)
    {
        aux=v[j];
        for(i=j-1; i>=0 && v[i]>aux; i--)
            v[i+1]=v[i];
        v[i+1]=aux;
    }

}

void quicksort(int *v, int inicio, int fim)
{

    int i, j, x, aux;
    x = v[(inicio+fim)/2];
    i=inicio;
    j=fim;

    while (i<=j)
    {
        while ( v[i] < x && i < fim ) i++;
        while ( v[j] > x && j > inicio) j--;

        if ( i <= j )
        {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }

    }

    if ( j > inicio )
        quicksort(v, inicio, j);
    if ( i < fim )
        quicksort(v, i, fim);
}

long heapsort(int *v, int n)
{
    long trocas =0;
    int meioTamanho = n/2, parent, child, t;

    for (;;)
    {
        if (meioTamanho > 0)
        {
            meioTamanho--;
            t = v[meioTamanho];
        }
        else
        {
            n--;
            if (n == 0) return trocas;
            t = v[n];
            v[n] = v[0];
        }

        parent = meioTamanho;
        child = meioTamanho*2 + 1;

        while (child < n)
        {
            if (child + 1 < n  &&  v[child + 1] > v[child])
            {
                child++;
            }
            if (v[child] > t)
            {
                v[parent] = v[child];
                parent = child;
                child = parent*2 + 1;
                trocas = trocas +1;
            }
            else
            {
                break;
            }
        }
        v[parent] = t;
    }

}

void shellsort(int *v, int n)
{
    int x, i, j, k, passo[5], inc;
    passo[0] = 9;
    passo[1] = 7;
    passo[2] = 5;
    passo[3] = 3;
    passo[4] = 1;

    for (k=0; k<5; k++)
    {
        inc = passo[k];
        for (i=inc; i<n; i++)
        {
            x = v[i];
            for (j=i-inc; j>=0 && v[j]>x; j=j-inc)
                v[j+inc] = v[j];
            v[j+inc] = x;
        }
    }
}


void piorcaso(int tam)
{
    int *vetor, i;
    double processo,inicial,info[7]; //Bolha, Seleção, Inserção, Quick, Heap, Shell, Merge
    char caso[10] = {"PIOR CASO"};

    processo = tempo();

    vetor = gPiorCaso(tam);

    inicial = tempo();
    bolha(vetor,tam);
    info[0]=tempo()-inicial;
    free(vetor);

    vetor = gPiorCaso(tam);

    inicial = tempo();
    selecao(vetor,tam);
    info[1]=tempo()-inicial;
    free(vetor);

    vetor = gPiorCaso(tam);

    inicial = tempo();
    insercao(vetor,tam);
    info[2]=tempo()-inicial;
    free(vetor);

    vetor = gPiorCaso(tam);

    inicial = tempo();
    quicksort(vetor,0,tam-1);
    info[3]=tempo()-inicial;
    free(vetor);

    vetor = gPiorCaso(tam);

    inicial = tempo();
    heapsort(vetor,tam);
    info[4]=tempo()-inicial;
    free(vetor);

    vetor = gPiorCaso(tam);

    inicial = tempo();
    shellsort(vetor,tam);
    info[5]=tempo()-inicial;
    free(vetor);
    
    vetor = gPiorCaso(tam);

    inicial = tempo();
    mergeSort(vetor,0, tam -1);
    info[6]=tempo()-inicial;
    free(vetor);

	for (i = 0; i < 7; i++) {
		mediaPiorCaso[i] += info[i];
	}

    resultados(caso,info, tam);
    printf("\nO processo de teste para o vetor desordenado(%s) demorou: %fs\n\n",caso,tempo()-processo);
}

void mediocaso(int tam)
{
    int *vetor, i;
    double processo,inicial,info[7]; //Bolha, Seleção, Inserção, Quick, Heap, Shell, Merge
    char caso[10] = {"CASO MEDIO"};

    processo = tempo();

    vetor = gMedioCaso(tam);

    inicial = tempo();
    bolha(vetor,tam);
    info[0]=tempo()-inicial;
    free(vetor);

    vetor = gMedioCaso(tam);

    inicial = tempo();
    selecao(vetor,tam);
    info[1]=tempo()-inicial;
    free(vetor);

    vetor = gMedioCaso(tam);

    inicial = tempo();
    insercao(vetor,tam);
    info[2]=tempo()-inicial;
    free(vetor);

    vetor = gMedioCaso(tam);

    inicial = tempo();
    quicksort(vetor,0,tam-1);
    info[3]=tempo()-inicial;
    free(vetor);

    vetor = gMedioCaso(tam);

    inicial = tempo();
    heapsort(vetor,tam);
    info[4]=tempo()-inicial;
    free(vetor);

    vetor = gMedioCaso(tam);

    inicial = tempo();
    shellsort(vetor,tam);
    info[5]=tempo()-inicial;
    free(vetor);
    
    vetor = gMedioCaso(tam);

    inicial = tempo();
    mergeSort(vetor,0, tam -1);
    info[6]=tempo()-inicial;
    free(vetor);

	for (i = 0; i < 7; i++) {
		mediaMedioCaso[i] += info[i];
	}

    resultados(caso,info, tam);
    printf("\nO processo de teste para o vetor semi-ordenado(%s) demorou: %fs\n\n",caso,tempo()-processo);
}

void melhorcaso(int tam)
{
    int *vetor, i;
    double processo,inicial,info[7]; //Bolha, Seleção, Inserção, Quick, Heap, Shell, Merge
    char caso[11] = {"MELHOR CASO"};

    processo = tempo();

    vetor = gMelhorCaso(tam);

    inicial = tempo();
    bolha(vetor,tam);
    info[0]=tempo()-inicial;
    free(vetor);

    vetor = gMelhorCaso(tam);

    inicial = tempo();
    selecao(vetor,tam);
    info[1]=tempo()-inicial;
    free(vetor);

    vetor = gMelhorCaso(tam);

    inicial = tempo();
    insercao(vetor,tam);
    info[2]=tempo()-inicial;
    free(vetor);

    vetor = gMelhorCaso(tam);

    inicial = tempo();
    quicksort(vetor,0,tam-1);
    info[3]=tempo()-inicial;
    free(vetor);

    vetor = gMelhorCaso(tam);

    inicial = tempo();
    heapsort(vetor,tam);
    info[4]=tempo()-inicial;
    free(vetor);

    vetor = gMelhorCaso(tam);

    inicial = tempo();
    shellsort(vetor,tam);
    info[5]=tempo()-inicial;
    free(vetor);
    
    vetor = gMelhorCaso(tam);

    inicial = tempo();
    mergeSort(vetor,0, tam -1);
    info[6]=tempo()-inicial;
    free(vetor);

	for (i = 0; i < 7; i++) {
		mediaMelhorCaso[i] += info[i];
	}

    resultados(caso,info, tam);
    printf("\nO processo de teste para o vetor ordenado(%s) demorou: %fs\n\n",caso,tempo()-processo);
}

void resultados(char *str,double *info, int tam)
{
    int i,maior,menor;
    char metodos[7][20] = {"Bubblesort", "Selection Sort", "Insertion Sort", "Quicksort", "Heapsort", "Shellsort", "Mergesort"};

    puts("+----------------------------------------------------------------------------+");
    printf("\tResultados do (%s) com vetor de %d posicoes:\n",str,tam);
    for (i=0; i<7; i++)
        printf("\t%s \t--> %fs\n",metodos[i],info[i]);

    maior = 0; //maior tempo = pior metodo
    menor = 0; //menor tempo = melhor metodo
    for (i=0; i<7; i++)
    {
        if (info[maior] < info[i])
            maior = i;
        if (info[menor] > info[i])
            menor = i;
    }
    printf("\nMelhor metodo:\n\t%s \t-> %fs\n",metodos[menor],info[menor]);
    printf("\nPior metodo:\n\t%s \t-> %fs\n",metodos[maior],info[maior]);
}
