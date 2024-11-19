#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct livro pLivro;

struct livro{
    char nome[50];
    char isbn[50];
    float preco;
    int score;
    char editora[50];
};

pLivro* livro_aloc(int qtde);
void livro_ler(pLivro *biblio, int qtde);
void livro_exibe(pLivro *biblio, int qtde);
void livro_desaloca(pLivro *biblio);


int main(){
    setlocale(LC_ALL, "Portuguese");
    int qtde;
    pLivro *biblio;
    scanf("%d", &qtde);
    
    biblio = livro_aloc(qtde);

    livro_ler(biblio, qtde);
    
    livro_exibe(biblio, qtde);

    livro_desaloca(biblio);
    return 0;
}

pLivro* livro_aloc(int qtde){
    pLivro *biblio = (pLivro*) malloc(qtde * sizeof(pLivro));
    return biblio;
}

void livro_ler(pLivro *biblio, int qtde){
    for(int i = 0; i < qtde; i++){
        fgets(biblio[i].nome, 50, stdin);
        getchar();
        fgets(biblio[i].isbn, 50, stdin);
        getchar();
        scanf("%f", &biblio[i].preco);
        scanf("%d", &biblio[i].score);
        fgets(biblio[i].editora, 50, stdin);
        getchar();
    } 
}

void livro_exibe(pLivro *biblio, int qtde){
    for(int i = 0; i < qtde; i++){
        printf("Livro %d\n", i+1);
        printf("Nome: %s\n", biblio[i].nome);
        printf("ISBn: %s\n", biblio[i].isbn);
        printf("Preço: R$ %.2f\n", biblio[i].preco);
        printf("Score: %d\n", biblio[i].score);
        printf("Editora: %s\n\n", biblio[i].editora);
    } 

}

void livro_desaloca(pLivro *biblio){
    free(biblio);
}