This project has been created as part of the 42 curriculum by serromer

# 🌀 Guía Completa para el Proyecto Push_swap

El proyecto **Push_swap** es un desafío algorítmico fundamental en el plan de estudios de 42, centrado en la clasificación de datos con restricciones. Es una excelente oportunidad para sumergirte en algoritmos de clasificación y el concepto de complejidad.

---

## 1. 📚 Resumen del Proyecto y Objetivo

### Objetivo Principal
Escribir un programa en C llamado `push_swap` que calcule y muestre la **secuencia más corta de instrucciones** necesarias para ordenar una lista de enteros en la **pila a** en orden ascendente, con el número más pequeño en la parte superior.

### El Entorno
Dispones de **dos pilas** (stacks):

- **Pila a:** Inicialmente contiene una lista aleatoria de números enteros únicos (positivos y/o negativos).
- **Pila b:** Inicialmente vacía.

### El Desafío
Encontrar un **algoritmo de clasificación** que utilice el **número más bajo posible de operaciones**.

---

## 2. ⚙️ Las Instrucciones Clave

Solo puedes usar **11 instrucciones** para manipular las pilas:

### Operaciones de Intercambio (Swap)
Intercambian los **dos primeros elementos** en la parte superior de la pila.

- `sa` (swap a): intercambia los 2 primeros elementos de `a`.
- `sb` (swap b): intercambia los 2 primeros elementos de `b`.
- `ss`: ejecuta `sa` y `sb` simultáneamente.

### Operaciones de Empuje (Push)
Mueven el **elemento superior** de una pila a la otra.

- `pa` (push a): mueve el top de `b` a `a`.
- `pb` (push b): mueve el top de `a` a `b`.

### Operaciones de Rotación (Rotate)
Desplazan **todos los elementos hacia arriba**; el primer elemento pasa a ser el último.

- `ra` (rotate a)
- `rb` (rotate b)
- `rr`: ejecuta `ra` y `rb` simultáneamente.

### Operaciones de Rotación Inversa (Reverse Rotate)
Desplazan **todos los elementos hacia abajo**; el último elemento pasa a ser el primero.

- `rra` (reverse rotate a)
- `rrb` (reverse rotate b)
- `rrr`: ejecuta `rra` y `rrb` simultáneamente.

> **Tip:** Para visualizar estas operaciones, consulta la sección de ejemplo del subject de Push_swap.

---

## 3. 🏁 Primeros Pasos: La Parte Obligatoria

### Paso 1: Configuración del Entorno y Manejo de Errores
- **Estructura de Datos:** Lista doblemente enlazada recomendada (eficiente para `pa/pb` y rotaciones).
- **Análisis de Argumentos:** Recibirás los números desde la línea de comandos (ej: `./push_swap 2 1 3 6 5 8`).
- **Manejo de Errores:** Debes comprobar:
  - Que los argumentos sean enteros válidos.
  - Que no haya duplicados.
  - Mostrar `Error\n` en `stderr` si hay problemas.

### Paso 2: Implementación de las Instrucciones
Implementa correctamente las **11 instrucciones** asegurando manipulación adecuada de tu estructura de pila.

### Paso 3: Clasificación para Casos Pequeños
- **3 Números:** Ordena con **máximo 3 movimientos**.
- **5 Números:** Estrategia común:
  - Mover 2-3 números pequeños a `b`.
  - Ordenar los restantes en `a`.
  - Reinsertar de `b` a `a` en orden correcto.

### Paso 4: Algoritmo para Grandes Cantidades
Para 100 o 500 números, necesitarás un algoritmo eficiente.

#### Sugerencia: Radix Sort
1. Transformar los números en **índices del 0 al N−1**.
2. Ordenar por bits usando `pb` y `pa`.
3. Empezar por el bit menos significativo.
> Esta técnica es rápida y cumple con los límites de operaciones.

---

## 4. 📈 Benchmarks de Rendimiento

Número de elementos | Límite máximo de operaciones
--- | ---
100 | < 700 operaciones
500 | ≤ 5500 operaciones

---

## 5. ➕ Parte de Bonificación: Programa `checker`

### Función
- Leer la pila inicial `a` desde argumentos.
- Leer instrucciones (`sa`, `pb`, etc.) de **stdin**, separadas por `\n`.
- Ejecutarlas en las pilas.

### Salida
- Si `a` ordenada y `b` vacía → imprime `OK\n`.
- Cualquier otro caso → imprime `KO\n`.
- Error en argumentos o instrucción → imprime `Error\n` en `stderr`.

---

## 6. ✅ Consejos Clave para el Éxito

- **Rigor en C:** Manejo de memoria y cumplimiento de la norma (Norm).
- **Pensar en Índices:** Más fácil que trabajar con valores originales grandes o negativos.
- **Optimización Constante:** Usar `rr` y `rrr` para rotaciones simultáneas ahorra operaciones.
- **Pruebas a Conciencia:** Crear tests propios y usar `checker` para validar resultados exhaustivamente.

###  Additional sections (Tree)
```markdown
push_swap_project/
├── Makefile                  # Builds push_swap (and checker if implemented)
├── README.md                 # Project explanation, instructions, examples
├── push_swap.c               # Main entry point
├── src/
│   ├── main.c                # Actual main function of the program
│   ├── rules/                # Implementation of each stack operation
│   │   ├── sa.c
│   │   ├── sb.c
│   │   ├── ss.c
│   │   ├── pa.c
│   │   ├── pb.c
│   │   ├── ra.c
│   │   ├── rb.c
│   │   ├── rr.c
│   │   ├── rra.c
│   │   ├── rrb.c
│   │   └── rrr.c
│   ├── sorting/              # Sorting algorithms
│   │   ├── sort_small.c      # Sorts 2-5 elements
│   │   ├── sort_large.c      # Algorithm for >5 elements (e.g., Radix Sort)
│   │   └── utils_sort.c      # Helper functions for sorting
│   └── utils/                # General helper functions
│       ├── error_handling.c
│       ├── stack_utils.c
│       └── arg_parsing.c
├── include/
│   ├── push_swap.h           # Main prototypes and structs
│   └── checker_bonus.h       # Prototypes specific to checker/bonus
└── libft/                    # Your Libft library
    ├── src/                  # Libft .c files
    ├── include/              # Libft header
    │   └── libft.h
    └── Makefile               # Makefile to build libft
```