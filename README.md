Este proyecto ha sido creado como parte del plan de estudios 42 por serromer.

#  Guía Completa para el Proyecto Push_swap

El proyecto **Push_swap** es un desafío algorítmico fundamental en el plan de estudios de 42, centrado en la clasificación de datos con restricciones. Es una excelente oportunidad para sumergirte en algoritmos de clasificación y el concepto de complejidad.

---

## 1.  Resumen del Proyecto y Objetivo

### Objetivo Principal
Escribir un programa en C llamado `push_swap` que calcule y muestre la **secuencia más corta de instrucciones** necesarias para ordenar una lista de enteros en la **pila a** en orden ascendente, con el número más pequeño en la parte superior.

### El Entorno
Dispones de **dos pilas** (stacks):

- **Pila a:** Inicialmente contiene una lista aleatoria de números enteros únicos (positivos y/o negativos).
- **Pila b:** Inicialmente vacía.

### El Desafío
Encontrar un **algoritmo de clasificación** que utilice el **número más bajo posible de operaciones**.

---

## 2.  Las Instrucciones Clave

Solo puedes usar **11 instrucciones** para manipular las pilas:

### Operaciones de Intercambio (Swap)
Intercambian los **dos primeros elementos** en la parte superior de la pila.

- `sa` (swap a): Intercambia los 2 primeros elementos en la parte superior de la pila `a`.
- `sb` (swap b): Intercambia los 2 primeros elementos en la parte superior de la pila `b`.
- `ss`: Ejecuta `sa` y `sb` simultáneamente.

### Operaciones de Empuje (Push)
Estas instrucciones mueven el elemento superior de una pila a la parte superior de la otra.
- `pa` (push a): Toma el primer elemento de la parte superior de `b` y lo pone en la parte superior de `a`.
- `pb` (push b): Toma el primer elemento de la parte superior de `a` y lo pone en la parte superior de `b`.

### Operaciones de Rotación (Rotate)
Estas instrucciones mueven todos los elementos de la pila hacia arriba y el primer elemento se convierte en el último (una rotación hacia arriba).
- `ra` (rotate a) : Desplaza hacia arriba todos los elementos de la pila `a` en 1. El primer elemento se convierte en el último.
- `rb` (rotate b) : Desplaza hacia arriba todos los elementos de la pila `b` en 1. El primer elemento se convierte en el último.
- `rr`: ejecuta `ra` y `rb` simultáneamente.

### Operaciones de Rotación Inversa (Reverse Rotate)
Estas instrucciones mueven todos los elementos de la pila hacia abajo, y el último elemento se convierte en el primero (una rotación hacia abajo).
- `rra` (reverse rotate a): Desplaza hacia abajo todos los elementos de la pila `a` en 1. El último elemento se convierte en el primero.
- `rrb` (reverse rotate b): Desplaza hacia abajo todos los elementos de la pila `b` en 1. El último elemento se convierte en el primero.
- `rrr`: ejecuta `rra` y `rrb` simultáneamente.

> **Tip:** Para visualizar estas operaciones, consulta la sección de ejemplo del subject de Push_swap.

---

## 3.  Primeros Pasos: La Parte Obligatoria

### Paso 1: Configuración del Entorno y Manejo de Errores
- **1. Estructura de Datos:** Primero, decide cómo representarás las pilas `a` y `b`. Un listado doblemente enlazado (`doubly linked list`) es ideal, ya que permite la inserción\eliminación eficiente en la parte superior (para `pa`/`pb`) y el movimiento fácil de los nodos para las rotaciones (`ra`/`rra`, etc.).
- **2. Análisis de Argumentos:** Tu programa `push_swap` recibirá los números como argumentos de línea de comandos (ej: `./push_swap 2 1 3 6 5 8`). El primer argumento es el elemento superior de la pila `a`.
- **Manejo de Errores:** Es crucial manejar los errores correctamente y mostrar "`Error\n`" en el standard error. 
Debes comprobar:
  - Si los argumentos son **enteros válidos** (dentro de los límites de un `int`).
  - Si hay **duplicados** en la lista de números.

### Paso 2: Implementación de las Instrucciones
Implementa las 11 funciones de instrucción (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`). Asegúrate de que cada función manipule correctamente tu estructura de datos de pila.

### Paso 3: Clasificación para Casos Pequeños (Warm-up)
Antes de pasar a un algoritmo complejo, practica con casos pequeños:
* **3 Números:** Desarrolla un algoritmo que clasifique 3 números en la pila `a` en el menor número de movimientos posible (máximo 3 movimientos). Este es un ejercicio de lógica pura.
* **5 Números:** Extiende la lógica para clasificar 5 números. Una estrategia común es mover 2 o 3 de los números más pequeños a la pila `b`, clasificar los 2 o 3 restantes en `a`, y luego volver a empujar los de `b` a `a` en el orden correcto.

### Paso 4: Algoritmo para Grandes Cantidades (La clave del proyecto)
Para clasificar 100 y 500 números con la máxima eficiencia (menos de 700 y 5500 operaciones respectivamente), el algoritmo de Radix Sort no es suficiente. En su lugar, implementamos el **Turk Algorithm**, una estrategia basada en el análisis de coste de movimientos.

#### 1. Pre-procesamiento: Indexación con Quick Sort
Antes de manipular los stacks, utilizamos un Quick Sort tradicional sobre un array auxiliar.
* **Propósito**: Convertir los valores de entrada (que pueden ser muy grandes o negativos) en índices de 0 a N-1.
* **Ventaja**: Esto nos permite conocer la posición final de cada número y simplifica el cálculo de "distancias" entre elementos del stack.

#### 2. Fase de Pre-clasificación (A -> B)
En lugar de pasar números al azar, movemos elementos del Stack A al Stack B siguiendo una lógica de "chunks" o medianas basadas en el índice:
* Enviamos casi todos los números a B, dejando solo 3 elementos en A.
* Intentamos que B quede "parcialmente organizado" para reducir el coste de la siguiente fase.

#### 3. El Algoritmo Turco (B -> A): Análisis de Coste
Esta es la fase crítica para cumplir los benchmarks. Devolvemos los números de B a A seleccionando siempre el movimiento más eficiente:
* **Cálculo de Target**: Para cada nodo en B, identificamos su posición ideal en A (donde encajaría en orden ascendente).
* **Análisis de Coste**: Calculamos cuántas operaciones (ra, rb, rra, rrb) cuesta poner el nodo de B en el tope y preparar su hueco en A.
* **Optimización de Movimientos**: Aprovechamos las operaciones dobles (rr, rrr) si ambos stacks deben rotar en la misma dirección.
* **Ejecución**: Seleccionamos y movemos el nodo que requiera el menor número total de instrucciones.

#### 4. Ajuste Final
Una vez que todos los elementos están de vuelta en el Stack A, realizamos una rotación final para que el número más pequeño (índice 0) quede en el tope, dejando la lista perfectamente ordenada.

##### Tabla de Rendimiento del Algoritmo Turk Algorithm

| Cantidad de Números | Límite 42 (100%) | Rendimiento Turk |
|---------------------|------------------|------------------|
| 100 números         | < 700 ops        | ~600 ops         |
| 500 números         | < 5500 ops       | ~5000 ops        |

## 4.  Benchmarks de Rendimiento
El éxito del proyecto se mide por la eficiencia de tu algoritmo. Tu programa será evaluado según el número de operaciones que utilice.
Para obtener la **máxima validación (100%)** y ser elegible para la bonificación, debes cumplir estos límites:

Número de elementos | Límite máximo de operaciones
--- | ---
100 | < 700 operaciones
500 | ≤ 5500 operaciones

---

## 5.  Parte de Bonificación: Programa `checker`
La parte de bonificación consiste en crear un programa llamado `checker`.
### Función
- Leer la pila inicial `a` desde argumentos.
- Leer instrucciones (`sa`, `pb`, etc.) de **stdin**, separadas por `\n`.
- Ejecutarlas en las pilas.

### Salida
- Si `a` ordenada y `b` vacía → imprime `OK\n`.
- Cualquier otro caso → imprime `KO\n`.
- Error en argumentos o instrucción → imprime `Error\n` en `stderr`.

---

## 6.  Consejos Clave para el Éxito

- **Rigor en C:** Manejo de memoria y cumplimiento de la norma (Norm).
- **Pensar en Índices:** Más fácil que trabajar con valores originales grandes o negativos.
- **Optimización Constante:** Usar `rr` y `rrr` para rotaciones simultáneas ahorra operaciones.
- **Pruebas a Conciencia:** Crear tests propios y usar `checker` para validar resultados exhaustivamente.

###  Additional sections (Tree)
```markdown
push_swap/
├── Makefile                  # Compila push_swap y el checker (bonus)
├── include/
│   └── push_swap.h           # Prototipos, estructuras de las pilas y macros
├── src/
│   ├── main.c                # Punto de entrada principal para push_swap
│   ├── operations/           # Lógica base de manipulación de nodos
│   │   ├── stack_ops_1.c     # Lógica fundamental para push y swap
│   │   └── stack_ops_2.c     # Lógica fundamental para rotate y reverse rotate
│   ├── rules/                # Las 11 instrucciones obligatorias (llaman a operations)
│   │   ├── pa.c  ├── pb.c    # Movimientos entre pilas
│   │   ├── ra.c  ├── rb.c  ├── rr.c    # Rotaciones simples y dobles
│   │   ├── rra.c ├── rrb.c ├── rrr.c   # Rotaciones inversas simples y dobles
│   │   └── sa.c  ├── sb.c  └── ss.c    # Intercambios simples y dobles
│   ├── sorting/              # Lógica de ordenación (Algoritmo Turk)
│   │   ├── sort_large.c      # Orquestador para listas grandes (> 5 números)
│   │   ├── sort_small.c      # Algoritmo optimizado para 3 y 5 números
│   │   ├── turk_engine.c     # El "cerebro": cálculo de costes y selección de movimientos
│   │   └── utils_sort.c      # Funciones de apoyo (indexación, buscar el menor, etc.)
│   └── utils/                # Funciones auxiliares generales
│       ├── arg_parsing.c     # Validación de argumentos y conversión (ft_atol)
│       ├── error_handling.c  # Gestión de errores (imprime "Error\n" y libera memoria)
│       └── stack_utils.c     # Gestión de la memoria de la pila (crear/liberar nodos)
├── src_bonus/                # Implementación del programa Checker
│   ├── checker_main.c        # Main del checker: lee instrucciones y verifica el orden
│   └── gnl.c                 # get_next_line para leer la entrada estándar (stdin)
└── libft/                    # Tu librería de funciones genéricas
    ├── Makefile              # Compila la libft.a
    ├── include/
    │   └── libft.h           # Cabecera con los prototipos de la libft
    └── src/                  # Archivos fuente de la libft
        ├── ft_atol.c         # Conversión de string a long (esencial para overflow)
        ├── ft_split.c        # Para gestionar argumentos entre comillas
        └── ...               # Resto de funciones (ft_strlen, ft_calloc, etc.)
```