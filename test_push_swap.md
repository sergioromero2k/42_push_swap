#  Push_swap Tester - Hoja de pruebas

## 1. Pruebas de Gestión de Errores
El programa debe imprimir `Error\n` por stderr (canal 2).

| Caso de Prueba          | Comando                           | Resultado Esperado | ¿Pasó? |
|-------------------------|-----------------------------------|---------------------|--------|
| No numérico             | `./push_swap 1 2 a 4`             | `Error`             | [ ]    |
| Duplicados              | `./push_swap 1 2 3 2`             | `Error`             | [ ]    |
| Fuera de rango (+)      | `./push_swap 2147483648`          | `Error`             | [ ]    |
| Fuera de rango (-)      | `./push_swap -2147483649`         | `Error`             | [ ]    |
| Parámetro vacío         | `./push_swap ""`                  | `Nada o Error`      | [ ]    |
| Solo un número          | `./push_swap 42`                  | `Nada (éxito)`      | [ ]    |

## 2. Pruebas de Casos Pequeños
El objetivo es la precisión extrema en pocos movimientos.

| Cantidad                | Comando                           | Límite |
|-------------------------|-----------------------------------|--------|
| Ya ordenado             | `./push_swap 1 2 3`               | 0      |
| 3 números               | `./push_swap 3 1 2`               | ≤ 3    |
| 5 números               | `./push_swap 5 2 4 1 3`           | ≤ 12   |

## 3. Pruebas de Rendimiento (Turk Algorithm)
Utiliza estos comandos para generar números aleatorios y contar las líneas de salida.

###  100 Números (Benchmark)
Límite para 100%: < 700 movimientos.

Comando:
```bash
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l
```

### 500 Números (Benchmark)
Límite para 100%: < 700 movimientos.

Comando:
```bash
ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l
```
## 4. Estabilidad y Memoria
Verificación técnica final.

### Valgrind (Leaks):
```bash
valgrind --leak-check=full ./push_swap $(seq 1 100 | shuf)
```
Resultado esperado: "All heap blocks were freed -- no leaks are possible"

### Verificación con Checker:
```bash
ARG=$(seq 1 100 | shuf); ./push_swap $ARG | ./checker_linux $ARG
```