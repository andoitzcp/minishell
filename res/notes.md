# Parseo:

## Fuentes:
 - [Explicacion minishell](https://m4nnb3ll.medium.com/minishell-building-a-mini-bash-a-42-project-b55a10598218)
 - [Algoritmo de agrupacion - Precedence climbing](https://eli.thegreenplace.net/2012/08/02/parsing-expressions-by-precedence-climbing)
 - [Formatos de ordenacion de arboles binarios](https://www.geeksforgeeks.org/introduction-to-binary-tree/)

## Prioridad de las operaciones:

1. Parentesis (?? Hay que contemplarlos)
2. Pipes
3. Here-doc (<<)
4. Redir IN (<)
5. Redir OUT (>) y Redir APPEND (>>)

## Algoritmo : Precedence Climbing
Busca agrupar operaciones en funcion de su orden de prioridad, determinando asi los niveles de cada operacion y el orden en el que deben ejecutarse.

a + b * c - d / e -> a + (b * c) - (d / e)

Debe tener en cuenta las propiedades asociativas.

### Funcionamiento
Los nodos son operaciones o argumentos. Cualquier operacion consta de al menos dos argumentos. 

El algoritmo se basa en una funcion recursiva que profundiza a medida que encuentra operaciones de mayor prioridad que el nivel en el que se encuentra. Si estamos intentando resolver una suma (operacion de nivel 1) y nos encontramos una multiplicacion (operacion de nivel 2) profundizara un nivel mas llamandose a si misma con los argumentos que acompañan a la multiplicacion. De esta forma se van resolviendo las operaciones mas prioritarias antes de seguir con las de menor nivel.

## Opciones de resultado de parseo:

1. Resolver las operaciones a medida que se navega el arbol.
2. Navegar el arbol y reordenarlo en forma de linked list.

