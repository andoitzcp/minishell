# Objetivos
- [ ] Andoitz, tener unos pipes funcionales con redirecciones.
- [ ] Iker, tenere un AST funcional.

# Tareas

## Andoitz
 - [ ] POSPUESTO, HASTA DECIDIR AST vs LList. hacer un algoritmo que navege el tree y vaya ejecutando cada comando. No hace falta que compruebe errores de momento, unicamente que navegue bien. 
 - [ ] Implementar built-ins.
   - [x] echo y echo -n
   - [x] cd
   - [x] pwd
   - [x] export
   - [x] unset
   - [x] env
   - [ ] exit

 - [ ] ...

## Iker
- [x] Tokenizar la entrada
- [x] crear un algoritmo que te cree nodos del AST
- [ ] Navegar el AST para reordenarlo / ejecutarlo en el orden adecuado

- [ ] Implementar uso de señales
  - [ ] Ctrl-C : imprime una nueva entrada de linea
  - [ ] Ctrl-D : exit
  - [ ] Ctrl-\ : no hace nada

- [ ] Expandi variables de entorno

# Dudas
- [ ] Preguntar si el prompt de la minishell tiene que esperar a que un comando
  termine de ejecutar y mostrar el output. Si se ha introducido un comando
  mientras estaba esperando se debe ejecutar este a continuacion.

# Ejecutar redirecciones izq
Nos hemos dado cuenta que podemos ejecutar esta redirecciones en serie
escribiendo en un archivo temporal el resutado de cat < file. Si lo hacemos una
y otra vez podemos simplificar el algoritmo.

## PASOS
1. crear un fork de padre hijo. El padre catea al hijo y el hijo sobreescribe un
   fichero temporla "tmp.txt".
   
2. Cada vez que se encuentre una redireccion hacia la izquierda, hay que
   ejecuatar primero el comando a la derecha del '<' y seguir ejecutando
   comandos mientras no se encuentre un pipe '|' o NULL
   
# CREAR FUNCION MAIN para ir testeando codigo

1. Incializar minishel y structura 'md'
2. Meterle un comando primero tipo cmd1 | cmd2 | cmd3
3. Imprimir structura
4. [ ] checkear valgrind

# Siguientes pasos
1. crear main
2. acabar redirecciones y pipes
3. senales
