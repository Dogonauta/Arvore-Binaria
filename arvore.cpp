#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

struct No {
    int valor;
    struct No *esq;
    struct No *dir;
};

struct No *raiz;

void iniciaArvore() {
    cout << "\nArvore Binaria Iniciada!\n";
    raiz = NULL;
}

bool testaArvoreVazia() {
    return (raiz == NULL);
}

void insereArvore(int num) {
    struct No *pt, *b;
    pt = new struct No;
    pt->valor = num;
    pt->esq = NULL;
    pt->dir = NULL;
    if (testaArvoreVazia()) {
        cout << "Inserido na raiz!\n";
        raiz = pt;
    } else {
        b = raiz;
        while (b != NULL) {
            cout << "\nAnalisando no " << b->valor << "...\n";
            if (num < b->valor) {
                if (b->esq == NULL) {
                    cout << "Achei o local de inclusao!";
                    b->esq = pt;
                    b = NULL;
                } else {
                    cout << "Buscando local a esquerda...\n";
                    b = b->esq;
                }
            } else {
                if (b->dir == NULL) {
                    cout << "Achei o local de inclusao!";
                    b->dir = pt;
                    b = NULL;
                } else {
                    cout << "Buscando local a direita...\n";
                    b = b->dir;
                }
            }
        }
    }
    cout << "Elemento " << num << " inserido...\n";
}

void erd(struct No *r) {
    if (r != NULL) {
        erd(r->esq);
        cout << "\n" << r->valor;
        erd(r->dir);
    }
}

void red(struct No *r) {
    if (r != NULL) {
        cout << "\n" << r->valor;
        red(r->esq);
        red(r->dir);
    }
}

void edr(struct No *r) {
    if (r != NULL) {
        edr(r->esq);
        edr(r->dir);
        cout << "\n" << r->valor;
    }
}

// Função para desenhar a árvore
void desenharArvore(struct No* r) {
    if (r == NULL) return;

    queue<struct No*> q;
    q.push(r);

    int nivel = 0;
    vector<vector<string>> niveis;

    while (!q.empty()) {
        int nivelSize = q.size();
        vector<string> nivelAtual;
        while (nivelSize > 0) {
            struct No* n = q.front();
            q.pop();

            if (n != NULL) {
                nivelAtual.push_back(to_string(n->valor));
                q.push(n->esq);
                q.push(n->dir);
            } else {
                nivelAtual.push_back(" ");
                q.push(NULL);
                q.push(NULL);
            }

            nivelSize--;
        }

        bool todosNulos = true;
        for (const string &s : nivelAtual) {
            if (s != " ") {
                todosNulos = false;
                break;
            }
        }

        if (todosNulos) break;

        niveis.push_back(nivelAtual);
        nivel++;
    }

    int largura = 2 << (nivel - 1);

    for (int i = 0; i < niveis.size(); i++) {
        int nosNoNivel = niveis[i].size();
        int espacamento = largura / (1 << i);

        // Exibe os nós
        for (int j = 0; j < nosNoNivel; j++) {
            if (j == 0) cout << setw(espacamento);
            else cout << setw(espacamento * 2);
            cout << niveis[i][j];
        }
        cout << endl;

        // Exibe as conexões
        if (i < niveis.size() - 1) {
            for (int j = 0; j < nosNoNivel; j++) {
                if (j == 0) cout << setw(espacamento - 1);
                else cout << setw(espacamento * 2 - 2);
                if (niveis[i][j] != " ") {
                    if (niveis[i + 1][j * 2] != " ") cout << "/";
                    else cout << " ";
                    cout << " ";
                    if (niveis[i + 1][j * 2 + 1] != " ") cout << "\\";
                    else cout << " ";
                } else {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }
}

int main() {
    int i, temp;
    iniciaArvore();
    for (i = 0; i < 31; i++) {
        cout << "\nInforme um numero: ";
        cin >> temp;
        insereArvore(temp);
    }

    cout << "\n\nPercurso Em Ordem: \n";
    erd(raiz);
    cout << "\n\nPercurso Pre Ordem: \n";
    red(raiz);
    cout << "\n\nPercurso Pos Ordem: \n";
    edr(raiz);

    cout << "\n\nDesenho da Arvore: \n";
    desenharArvore(raiz);

    return 0;
}
