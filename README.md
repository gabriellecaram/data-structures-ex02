"# data-structures-ex02" 

PROBLEMA:

Menor Ancestral Comum

O Menor Ancestral Comum (LCA em inglês) de dois vétices A e B em uma árvore T é o menor nó de T (em profundidade) que possui os nós A e B como seus descendentes. Define-se que o nó A é descendente dele próprio. (então, caso A seja filho de B em T, B é o LCA de A e B) [Fonte: Wikipedia]

Inicialmente a floresta consiste de N árvores enraizadas com exatamente um nó (cada um rotulado de 1 a N).
Considere as seguintes operações:

link A B: adicione uma aresta do nó B para o A, fazendo com que A seja filho de B na árorve de B, inicialmente A é um nó raiz, e A e B estão em diferentes árvores.
cut A: remove a aresta que liga o nó pai de A com A, inicialmente A não é um nó raiz.
lca A B: imprima o Menor Ancestral Comum de A e B, A e B estão na mesma árvore.
Veja a figura abaixo:

	    1
	   / 
	  2
	 / 
	3  
       / \
      4   5
O resultado da operação lca 4 5 é 3.

Problema:
Neste problema, você deve calcular o Menor Ancestral Comum entre dois nós A e B. Considere que A e B sempre fazem parte da mesma árvore. (i.e. existe um Ancestral Comum entre eles)

Especificação de entrada e saída
Entrada
A primeira linha da entrada contém dois inteiros, N e M. N é o número de árvores da floresta inicial.
Em seguida tem-se M linhas cada uma com uma operação. (1 ≤ N, M ≤ 1000)

Saída
Para cada operação lca A B, você deve imprimir o Menor Ancestral Comum entre os nós A e B.

Exemplo de entrada
5 9
lca 1 1
link 1 2
link 3 2
link 4 3
lca 1 4
lca 3 4
cut 4
link 5 3
lca 1 5
Exemplo de saída
1
2
3
2