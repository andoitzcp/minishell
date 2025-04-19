# minishell
42 project

## Requerimientos del subject

### En caso de duda utilizar **bash** como referencia!

- [ ] **1.** Mostrar una nueva entrada mientras espera el comando nuevo.
- [x] **2.** Tener una historia funcional.
- [x] **3.** Buscar y ejecutar el ejecutable correcto (basado en la variable PATH o mediante el uso de rutas relativas o absolutas).
- [x] **4.** Evita utilizar más de una variable global para indicar la recepción de una señal. (Prohibido utilizar estructuras tipo norm en global).
- [ ] **5.** No interpretar comillas sin cerrar o caracteres especiales no especificados en el enunciado como `\` (barra invertida) o `;` (punto y coma).
- [x] **6.** Gestionar que la `’` evite que el shell interprete los metacaracteres en la secuencia entrecomillada.
- [x] **7.** Gestionar que la " evite que el shell interprete los metacaracteres en la secuencia entrecomillada exceptuando $ (signo de dólar).
- [ ] **8.** Implementar redirecciones:
- - `<` debe redirigir el input
- - `>` debe redirigir el output 
- - `<<` debe recibir un delimitador, después leer del input de la fuente actual hasta que una línea que contenga solo el delimitador aparezca. Sin embargo, no necesita actualizar el historial.
- - `>>` debe redirigir el output en modo append.
- [x] **9.** Implementar pipes.
- [x] **10.** Gestionar variables de entorno que deberan expandirse a sus valores.
- [x] **11.** Gestionar `$?`, que deberá expandirse al estado de salida del comando más reciente ejecutado en la pipeline.
- [x] **12.** Gestionar `ctrl-C` `ctrl-D` `ctrl-\`, que deberán funcionar como en bash
- [x] **13.** Cuando sea interactivo:
    - `ctrl-C` imprime una nueva entrada en una línea nueva.
    - `ctrl-D` termina la shell.
    - `ctrl-\` no hace nada.
- [x] **14.** Implementar los siguientes built-ins:
    - `echo` con la opcion `-n`.
    - `cd` solo con una ruta relativa o absoluta.
    - `pwd` sin opciones.
    - `export` sin opciones.
    - `unset` sin opciones.
    - `env` sin opciones ni argumentos.
    - `exit` sin opciones.
    

## Funciones autorizadas

|   |   |   |   |   |
|---|---|---|---|---|
| readline | rl_clear_history | rl_on_new_line | rl_replace_line | rl_redisplay | 
| add_history | printf | malloc | free | write | 
| access | open | read | close | fork | 
| wait | waitpid | wait3 | wait4 | signal | 
| sigaction | kill | exit | getcwd | chdir | 
| stat | lstat | fstat | unlink | execve | 
| dup | dup2 | pipe | opendir | readdir | 
| closedir | strerror | perror | isatty | ttyname | 
| ttyslot | ioctl | getenv | tcsetattr | tcgetattr | 
| tgetent | tgetflag | tgetnum | tgetstr | tgoto | 
| tputs | | | | |

## Recursos

### Documentacion
- [readline](https://web.mit.edu/gnu/doc/html/rlman_2.html)
- [getcwd] (https://www.gnu.org/software/libc/manual/html_node/Working-Directory.html)

## Estructura general del programa
### Metadata
Estructura de uso general en distintos puntos del programa
```c
typedef struct s_md
{
    struct s_token **tok;   // Lista de tokens
    struct s_tree **tree;   // Lista de nodos
    struct s_tree *nodeact; // Nodo actual
    int **fd;               // Array de fd-s
    char **env;             // Array de variables globales
    int	status;             // 
    int	exit_code;          // Codigo de retorno del ultimo comando
    char *prompt;           // Prompt de la minishell
} t_md;
``` 

### Main

1. Inicializacion de la estructura principal de datos y reserva de memoria correspondiente `initmetadata()`
2. Distincion entre modo interactivo o modo comando: 
    - Cuando la shell se inicia sin argumentos entra en modo interactivo
    - Sino, interpreta esos argumentos como un comando e intenta ejecutarlo
    ```C
    if (argc == 1)  // Comprobacion del nunmero de argumentos
    {
        // Modo interactivo 
    }
    else 
    {
        // Modo comando
    }
    ```
2.1. Modo interactivo:
    Se inicializa la gestion de señales `sig_init()`\n
    Se actualiza la variable del prompt y se lee el input del usuario\n
    Si no hay input (se ha presionado `Ctrl-d`) se cierra la shell.\n
    Si hay input:\n
        \tSe guarda en el historial\n
        \tSe tokeniza, se parsea y se reorganiza en funcion de las redirecciones\n
        \tFinalmente se ejecuta el comando\n
2.2 - Modo comando:
    \tSe convierte la lista de argumentos en un string unico\n
    \tSe tokeniza, parsea y ejecuta como si se tratase de un comando en modo interactico\n

