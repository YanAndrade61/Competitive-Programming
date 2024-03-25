### CONjunto frist e follow

Definição de first: o conjunto first compósto de terminais e possivelmente e é definido da seguinte maneira

1. Se x for um terminal ou vazio, então first(x) = x
2. Se x for um não-terminal, então p/ cada escolha de produção x -> x1, x2, x3... first(x) contem first(x1)-{vazio}. Adicionalmente para i< n se first(x1)...first(xi).
**Obs:** o conjunto de terminais que iniciam cadeis derividas de um não terminal:
COntiver vazio. então first(x) contem first(xi+1)-{vazio}. Se first(x1)... CONTEM VAZIO. ENTÃO FIRST(X) tambem contem vazio.

Exemplo:
Calculo do first p/ agramatica abaixo:
exp -> exp soma termo | termo
soma -> + | -
termo -> termo mult fator | fator
mult -> * | /
fator -> id | (exp) | num

Conjunto first:
first('+') = {'+'}
first(fator) = {first(id), first((exp)), first(num)} = {id, '(', num}
first(termo) = {first(fator)} = {id, '(', num}
first(exp) = {first(termo)} = {id, '(', num}
first(soma) = {first('+'), first('-')}


Linguagem P (first)

First(programa) = {first(funcao)}
First(funcao) = {FUNCTION}
first(funcaoSeg) = {function, vazio}
first(lstParams) = {ID, vazio}
first(vazio) = vazio
first(lstParams2) = {COMMA, vazio}
first(bloco) = {LBRACE}
first(comando) = {ID, IF, WHILE, PRINT, PRINTLN}
first(declaracao) = {let}
first(sequencia) = {LET, ID, IF, WHILE, PRINT, PRINTLN}
first(exp) = first(rel) = first(adicao) = first(termo) = first(fator) = {ID, INT_CONST, FLOAT_CONST, CHAR_LITERAL, LPAREN}

Linguagem P (follow)


$ marcador de fim da entrada
Calculo do follow:
1. Coloque $ em follow(S), onde S é o simbolo inicial.
2. Se A -> alphaBY, então first(Y)-{vazio}, esta no follow B.
3. Se A -> alphaB | alphaBY, e first(Y) contem vazio, então inclua follow(A), no follow B. 
Exemplo:
E -> T E'
E' -> + T E'| vazio
T -> F T'
T -> * F T' | vazio
F -> ID | (E)

PRIMEIRO PASSO CALCULO FIRST:

first(F) = {ID, '('}
first(T') = {*, vazio}
first(T) =  first(F) = {ID, '('}
first(T') = {*, vazio}
first(T') = {*, vazio}

SEGUNDO PASSO CALCULO FOLLOW:
1. Para toda produção busca quando ela aprece do lado direito
follow(E) = {$, ')'}
follow(T) = {+, follow(E)} = {+,$, ')'}
...
 
CONSTRUÇÃO DA TABELA DE ANALISE SINTATICA (TABELA M)

Algoritmo p/ a construção da tabela
Para cada produção A->B da gramatica faça:
1. P/ cada terminal a em first(B), inclua A->B em M[A,a]
2. Se vazio em first(B), então inclua A->B, em M[A,b] p/ todo terminal b em follow(A)
3. Se A -> vazio, então inclua A->vazio em M[A,b] p/ todo terminal b em follow(A)
Linhas da tabela são o conjunto de não terminais 
Colunas são o conjunto de terminais (tokens)

