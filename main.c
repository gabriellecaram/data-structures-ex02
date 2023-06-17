#include <stdio.h>
#include <stdlib.h>

typedef int T;

#define MAX 1000

typedef struct node{
  struct node *left, *right;
  struct node *parent;
  T data;
}node;

node* createNode(int i){
  node* newNode = (node*)malloc(sizeof(node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = newNode;
    newNode->data = i;
    return newNode;
}

node* lca(node* a, node* b){
  if (a==b) {
    return a;
  }

  if(a->parent==a && b->parent==a){
    return a;
  }else if(a->parent==b && b->parent==b){
    return b;
  }else{
    return lca(a->parent, b->parent);
  }
}


void link(node* child, node* parent){
    child->parent = parent;
    if (parent->left == NULL) { //se o pai nao tiver filho na esquerda
        parent->left = child;
        //printf("parent now has a child on the left\n");
    } else { //se o pai nao tiver filho na direita
        parent->right = child;
        //printf("parent now has a child on the right\n");
    }
}

void cut(node* cutNode){

    if (cutNode->parent == cutNode){ //se o nó for descendente de si msm
        return;
    }else if(cutNode->parent->left == cutNode){ //se o nó for filho da esquerda
        cutNode->parent->left = NULL;
    }else if (cutNode->parent->right == cutNode){//se o nó for filho da direita
      cutNode->parent->right = NULL;
    }

    cutNode->parent = cutNode; //nó se torna seu próprio pai

}


int main(){
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    
    node* nodes[n+1]; //Vetor para armazenar os nós "soltos"
    for (int i=1; i<=n; i++) { //cria todos os nós necessários
        nodes[i] = createNode(i);
    }

  //recebimento dos comandos
  while(m){
    char operacao[4];
    int a, b;

    scanf("%s", operacao); //recebe a palavra chave
    
    if(operacao[0]=='c'){ //CUT
      scanf("%d", &a);
      cut(nodes[a]);
    }
    else if(operacao[1]=='i'){ //LINK
      scanf("%d %d", &a, &b);
      link(nodes[a], nodes[b]);
    }
    else if (operacao[0] == 'l') { //LCA
      scanf("%d %d", &a, &b);
      node* lcaNode = lca(nodes[a], nodes[b]);
      printf("%d\n", lcaNode->data);
    }
    m--;
  }
  
  return 0;
}