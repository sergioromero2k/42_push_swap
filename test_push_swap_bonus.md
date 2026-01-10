## Pruebas de Funcionamiento Básico (Manuales)
---
Ejecuta el checker y escribe las instrucciones a mano. Para terminar la lectura, presiona Ctrl+D.

### Caso: Lista ya ordenada
```bash
./checker 1 2 3
# Presiona Ctrl+D inmediatamente
# Resultado esperado: OK
```

### Caso: Ordenación correcta con movimientos
```bash
./checker 3 2 1
sa
rra
# Presiona Ctrl+D
# Resultado esperado: OK
```

### Caso: Lista desordenada (KO)
```bash
./checker 1 5 2 4 3
sa
pb
ra
# Presiona Ctrl+D
# Resultado esperado: KO
```

## 2. Pruebas de Errores (Gestión de Basura)
El checker debe ser muy estricto con los inputs.

### Instrucción inexistente
```bash
./checker 1 2 3
hola
# Resultado esperado: Error (en stderr)
```

### Formato incorrecto o duplicados
```bash
./checker 1 2 1
# Resultado esperado: Error (o lo que gestione tu initializate_stack_a)
```

## 3. Pruebas Combinadas (Push_swap + Checker)
Esta es la prueba definitiva. El checker leerá la salida de tu push_swap.

### Con una secuencia pequeña
```bash
ARG="3 5 2 1 4"; ./push_swap $ARG | ./checker $ARG
# Resultado esperado: OK
```

### Con 100 números aleatorios (Linux/Bash)
```bash
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG
# Resultado esperado: OK
```

### Con 500 números aleatorios (Linux/Bash)
```bash
ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG
# Resultado esperado: OK
```

## 4. Pruebas de Memoria (Valgrind)
Es obligatorio que el bonus no tenga fugas de memoria (leaks), especialmente cuando recibe un "Error".

### Prueba de leak en ejecución normal
```bash
ARG="4 2 7"; echo "ra\npb\nsa" | valgrind --leak-check=full ./checker $ARG
```
### Prueba de leak ante un Error (Muy importante)
```bash
ARG="1 2 3"; echo "instruccion_falsa" | valgrind --leak-check=full ./checker $ARG```
```

## 5. Tabla de Verificación de Requisitos
| Prueba            | Entrada                              | Salida Esperada | ¿Por qué?                        |
|-------------------|--------------------------------------|------------------|----------------------------------|
| Vacío             | `./checker`                          | (Nada)           | No hay argumentos.               |
| Ordenado          | `./checker 1 2`                      | OK               | Ya está ordenado.               |
| Desordenado       | `./checker 2 1`                      | KO               | No hemos dado instrucciones.     |
| Error Instrucción | `echo "abc" | ./checker 1 2`        | Error            | `"abc"` no es una regla.        |
| Espacios          | `./checker "  1 2 3  "`              | OK               | El parsing debe limpiar espacios.|
