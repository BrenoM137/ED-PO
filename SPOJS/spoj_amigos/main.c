#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000

typedef struct Fila {
    int* elementos;
    int tamanho;
    int inicio;
    int fim;
} Fila;

Fila* criar_fila(int tamanho) {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->elementos = (int*) malloc(tamanho * sizeof(int));
    fila->tamanho = tamanho;
    fila->inicio = 0;
    fila->fim = 0;
    return fila;
}

void enfileirar(Fila* fila, int elemento) {
    fila->elementos[fila->fim] = elemento;
    fila->fim = (fila->fim + 1) % fila->tamanho;
}

int desenfileirar(Fila* fila) {
    int elemento = fila->elementos[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->tamanho;
    return elemento;
}

int fila_vazia(Fila* fila) {
    return fila->inicio == fila->fim;
}

typedef struct node {
    int vertice;
    struct node* proximo;
} Node;

typedef struct lista_ligada {
    Node* cabeca;
} ListaLigada;

Node* criar_no(int v) {
    Node* novo_no = (Node*) malloc(sizeof(Node));
    novo_no->vertice = v;
    novo_no->proximo = NULL;
    return novo_no;
}

ListaLigada* criar_lista_ligada() {
    ListaLigada* lista = (ListaLigada*) malloc(sizeof(ListaLigada));
    lista->cabeca = NULL;
    return lista;
}

void adicionar_no(ListaLigada* lista, int v) {
    Node* novo_no = criar_no(v);
    novo_no->proximo = lista->cabeca;
    lista->cabeca = novo_no;
}

void remover_no(ListaLigada* lista, int v) {
    Node* atual = lista->cabeca;
    Node* anterior = NULL;

    while (atual != NULL && atual->vertice != v) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) return;

    if (anterior == NULL) {
        lista->cabeca = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
}

typedef struct pilha {
    int topo;
    int* elementos;
} Pilha;

Pilha* criar_pilha(int tamanho) {
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->topo = -1;
    pilha->elementos = (int*) malloc(tamanho * sizeof(int));
    return pilha;
}

int pilha_vazia(Pilha* pilha) {
    return pilha->topo == -1;
}

void empilhar(Pilha* pilha, int elemento) {
    pilha->elementos[++pilha->topo] = elemento;
}

int desempilhar(Pilha* pilha) {
    if (pilha_vazia(pilha)) {
        printf("Erro: pilha vazia\n");
        exit(1);
    }
    return pilha->elementos[pilha->topo--];
}

typedef struct grafo {
    ListaLigada* lista_adjacencia;
    int* tamanho_atributos;
    char*** atributos;
    int* processado;
    int* grau;
    int num_vertices;
} Grafo;

Grafo* criar_grafo(int num_vertices) {
    Grafo* grafo = (Grafo*) malloc(sizeof(Grafo));
    grafo->lista_adjacencia = (ListaLigada*) malloc(num_vertices * sizeof(ListaLigada));
    grafo->tamanho_atributos = (int*) calloc(num_vertices, sizeof(int));
    grafo->atributos = (char***) malloc(num_vertices * sizeof(char**));
    grafo->processado = (int*) calloc(num_vertices, sizeof(int));
    grafo->grau = (int*) calloc(num_vertices, sizeof(int));
    grafo->num_vertices = num_vertices;

    for (int i = 0; i < num_vertices; i++) {
        grafo->lista_adjacencia[i].cabeca = NULL;
        grafo->atributos[i] = (char**) malloc(MAXN * sizeof(char*));
        for (int j = 0; j < MAXN; j++) {
            grafo->atributos[i][j] = (char*) malloc(21 * sizeof(char));
        }
    }

    return grafo;
}

void adicionar_aresta(Grafo* grafo, int origem, int destino) {
    adicionar_no(&grafo->lista_adjacencia[origem], destino);
    grafo->grau[origem]++;
}
void remover_aresta(Grafo* grafo, int origem, int destino) {
    Node* atual = grafo->lista_adjacencia[origem].cabeca;
    Node* anterior = NULL;

    while (atual != NULL && atual->vertice != destino) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) return;

    if (anterior == NULL) {
        grafo->lista_adjacencia[origem].cabeca = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    grafo->grau[origem]--;
}

void imprimir_grafo(Grafo* grafo) {
    for (int i = 1; i < grafo->num_vertices; i++) {
        printf("%d: ", i);
        Node* temp = grafo->lista_adjacencia[i].cabeca;
        while (temp != NULL) {
            printf("%d -> ", temp->vertice);
            temp = temp->proximo;
        }
        printf("NULL\n");
    }
}

void liberar_memoria(Grafo* grafo) {
    for (int i = 0; i < grafo->num_vertices; i++) {
        Node* temp = grafo->lista_adjacencia[i].cabeca;
        while (temp != NULL) {
            Node* next = temp->proximo;
            free(temp);
            temp = next;
        }
        for (int j = 0; j < MAXN; j++) {
            free(grafo->atributos[i][j]);
        }
        free(grafo->atributos[i]);
    }
    free(grafo->lista_adjacencia);
    free(grafo->tamanho_atributos);
    free(grafo->atributos);
    free(grafo->processado);
    free(grafo->grau);
    free(grafo);
}

void dfs(Grafo* grafo, int x, int t1, int t2, char* a1, char* a2, char* a3) {
    grafo->processado[x] = 1;
    grafo->tamanho_atributos[x]--;

    if (grafo->grau[x] < t1)
        strcpy(grafo->atributos[x][grafo->tamanho_atributos[x]++], a1);
    else if (grafo->grau[x] < t2)
        strcpy(grafo->atributos[x][grafo->tamanho_atributos[x]++], a2);
    else
        strcpy(grafo->atributos[x][grafo->tamanho_atributos[x]++], a3);

    Node* temp = grafo->lista_adjacencia[x].cabeca;
    while (temp != NULL) {
        int v = temp->vertice;
        if (grafo->processado[v] == 0) dfs(grafo, v, t1, t2, a1, a2, a3);
        temp = temp->proximo;
    }
}


void bfs(Grafo* grafo, int luis_espalha_lixo, int t1, int t2, char* a1, char* a2, char* a3) {
    Fila* fila = criar_fila(grafo->num_vertices);
    enfileirar(fila, luis_espalha_lixo);

    while (!fila_vazia(fila)) {
        int v = desenfileirar(fila);

        if (grafo->processado[v] == 0) {
            grafo->processado[v] = 1;
            grafo->tamanho_atributos[v]--;
            if (grafo->grau[v] < t1)
                strcpy(grafo->atributos[v][grafo->tamanho_atributos[v]++], a1);
            else if (grafo->grau[v] < t2)
                strcpy(grafo->atributos[v][grafo->tamanho_atributos[v]++], a2);
            else
                strcpy(grafo->atributos[v][grafo->tamanho_atributos[v]++], a3);

            Node* temp = grafo->lista_adjacencia[v].cabeca;
            while (temp != NULL) {
                int u = temp->vertice;
                if (grafo->processado[u] == 0) {
                    enfileirar(fila, u);
                }
                temp = temp->proximo;
            }
        }
    }
}


int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        Grafo* grafo = criar_grafo(n + 1);

        for (int i = 1; i <= n; i++) {
            int j;
            while (scanf("%d", &j) && j != 0) {
                adicionar_aresta(grafo, i, j);
            }
        }

        int inicio_spam = 0;
        while (scanf("%d", &inicio_spam) && inicio_spam != 0 && inicio_spam <= n) {

            int t1, t2;

            char a1[MAXN], a2[MAXN], a3[MAXN];
            memset(a1, 0, sizeof(a1));
            memset(a2, 0, sizeof(a2));
            memset(a3, 0, sizeof(a3));

            scanf("%d %d %s %s %s", &t1, &t2, a1, a2, a3);

            for (int i = 1; i <= n; i++) {
                grafo->processado[i] = 0;
                strcpy(grafo->atributos[i][grafo->tamanho_atributos[i]++], a1);
            }

            dfs(grafo, inicio_spam, t1, t2, a1, a2, a3);


        }

        for (int i = 1; i <= n; i++) {
            char nome[21];
            scanf("%s", nome);

            printf("%s: ", nome);

            for (int j = 0; j < grafo->tamanho_atributos[i]; j++) {
                printf("%s ", grafo->atributos[i][j]);
            }
            printf("\n");
        }
        liberar_memoria(grafo);
    }
    return 0;
}