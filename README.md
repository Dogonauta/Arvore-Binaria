# Funcionamento do código.

### Parâmetros: A função recebe três parâmetros: 
###  raiz: Um ponteiro para o nó raiz da árvore. 
###  nivel: Um inteiro que representa o nível atual na árvore. 
### largura: Um inteiro que representa a largura atual da árvore. 
### 2. Condição de Parada: A função verifica se o nó atual é nulo. Se for, significa que não há mais nós na árvore, então a função retorna. 
### 3. Recursão para os Nós Filhos: A função chama a si mesma duas vezes, uma para o filho esquerdo e outra para o filho direito do nó atual. Isso permite percorrer todos os nós da árvore. 
### 4. Desenho do Nó Atual: Antes de desenhar o nó atual, a função calcula a posição horizontal do nó com base na largura atual da árvore. Em seguida, imprime espaços em branco para alinhar o nó corretamente na linha de saída. Após isso, imprime o valor do nó atual. 
### 5. Desenho das Conexões entre os Nós: Após desenhar o valor do nó atual, a função verifica se há nós filhos e desenha as conexões entre o nó atual e seus filhos. Isso é feito utilizando caracteres como "/" e "" para representar as conexões da árvore. 
### 6. Chamadas Recursivas para os Nós Filhos: A função chama a si mesma recursivamente para desenhar os nós filhos, passando o filho esquerdo como argumento para a primeira chamada e o filho direito para a segunda chamada. Isso permite percorrer a árvore em profundidade, desenhando todos os nós. 
### 7. Retorno: Após desenhar todos os nós e suas conexões, a função retorna.

## :hammer_and_wrench: Ferramentas utilizadas:

<br>
<img scr="./assents/evidencia.png" width=600> 
<br>

* C++

## Feito por:

### Gabriel França

## Feito por :

|[<img src="./assents/eu.png" width=115><br> Gabriel França </sub>](https://github.com/dogonauta)
| :---: |