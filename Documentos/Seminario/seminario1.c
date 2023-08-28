#include <stdio.h>
#include <string.h>

struct Dado {
    int id;
    char nome[100];
    int idade;
};

void definir(int *q) {
    printf("Dados a inserir: ");
    scanf("%d", q);
}

void inserir(struct Dado d[], int q) {
    for (int i = 0; i < q; i++) {
        printf("\nID: ");
        scanf("%d", &d[i].id);

        printf("Nome: ");
        scanf("%s", d[i].nome);

        printf("Idade: ");
        scanf("%d", &d[i].idade);

        printf("Cadastro realizado.\n\n"); 
    }
}

void apresentar(struct Dado d[], int q) {
    printf("\nDados:\n");
    for (int i = 0; i < q; i++) {
        printf("ID: %d\nNome: %s\nIdade: %d\n\n", d[i].id, d[i].nome, d[i].idade);
    }
}

void relatorios(struct Dado d[], int q) {
    int id;
    printf("ID: ");
    scanf("%d", &id);
    printf("\nResultados para ID %d:\n", id);
    for (int i = 0; i < q; i++) {
        if (d[i].id == id) {
            printf("Nome: %s\nIdade: %d\n\n", d[i].nome, d[i].idade);
            return;
        }
    }
    printf("Dado não encontrado.\n");
}

void atualizar(struct Dado d[], int q) {
    int id;
    printf("ID a atualizar: ");
    scanf("%d", &id);
    for (int i = 0; i < q; i++) {
        if (d[i].id == id) {
            printf("Nova idade: ");
            scanf("%d", &d[i].idade);
            return;
        }
    }
    printf("Dado não encontrado.\n");
}

void mostrar(int q) {
    printf("Dados armazenados: %d\n", q);
}

int main() {
    int q = 0;
    struct Dado d[100];

    int o;
    do {
        printf("\nMenu:\n1. Definir quantidade de dados\n2. Inserir dados\n3. Apresentar dados\n4. Gerar relatórios\n5. Atualizar dado\n6. Mostrar quantidade de dados\n7. Sair\nEscolha: ");
        scanf("%d", &o);

        switch (o) {
            case 1:
                definir(&q);
                break;
            case 2:
                inserir(d, q);
                break;
            case 3:
                apresentar(d, q);
                break;
            case 4:
                relatorios(d, q);
                break;
            case 5:
                atualizar(d, q);
                break;
            case 6:
                mostrar(q);
                break;
            case 7:
                printf("Saindo.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (o != 7);

    return 0;
}