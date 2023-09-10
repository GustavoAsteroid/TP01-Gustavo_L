#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> 

#define MAX_LINE_LENGTH 100

struct Aluno {
    char nome[MAX_LINE_LENGTH];
    char telefone[MAX_LINE_LENGTH];
    char curso[MAX_LINE_LENGTH];
    double nota1, nota2;
    double media;
    char situacao[MAX_LINE_LENGTH];
};

int main() {
    setlocale(LC_ALL, "");

    FILE *entrada;
    FILE *saida;

    entrada = fopen("DadosEntrada.csv", "r");
    saida = fopen("SituacaoFinal.csv", "w");

    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    char linha[MAX_LINE_LENGTH];
    struct Aluno aluno;

    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        char *token = strtok(linha, ",");
        strcpy(aluno.nome, token);
        
        token = strtok(NULL, ",");
        strcpy(aluno.telefone, token);
        
        token = strtok(NULL, ",");
        strcpy(aluno.curso, token);

        token = strtok(NULL, ",");
        aluno.nota1 = atof(token);

        token = strtok(NULL, ",");
        aluno.nota2 = atof(token);

        aluno.media = (aluno.nota1 + aluno.nota2) / 2.0;

        if (aluno.media >= 7.0) {
            strcpy(aluno.situacao, "APROVADO");
        } else {
            strcpy(aluno.situacao, "REPROVADO");
        }

        fprintf(saida, "%s, %.2lf, %s\n", aluno.nome, aluno.media, aluno.situacao);
    }

    fclose(entrada);
    fclose(saida);

    printf("Processamento concluído. Resultados salvos em SituacaoFinal.csv.\n");

    return 0;
}

