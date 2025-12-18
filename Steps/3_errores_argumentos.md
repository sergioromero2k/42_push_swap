# 3 Errores de argumentos
---
### 1. Argumentos que no son Enteros Válidos
Esto incluye cualquier argumento que no pueda interpretarse como un entero dentro de los límites del tipo int estándar (generalmente `-2,147,483,648` a `2,147,483,647`).

| **Caso**                | **Comando de Ejemplo**           | **Razón del Error**                                                  |
|-------------------------|----------------------------------|---------------------------------------------------------------------|
| No-Numérico             | `./push_swap 10 a 20`            | El argumento `a` no es un número.                                   |
| Flotante/Decimal        | `./push_swap 5 1.5 8`            | El argumento `1.5` no es un entero.                                 |
| Caracteres extra        | `./push_swap 10 2k 30`           | El argumento `2k` contiene una letra.                               |
| Sobrecarga (Overflow)   | `./push_swap 1 2147483648 3`     | El número `2,147,483,648` excede el valor máximo de un `int`.      |
| Subcarga (Underflow)    | `./push_swap -5 -2147483649 5`   | El número `-2,147,483,649` es menor que el valor mínimo de un `int`.|
| Signo Mal Colocado      | `./push_swap 1 2 +3`             | El signo `+` no está al inicio (o el programa solo acepta `-` al inicio). |
| Solo Signo              | `./push_swap 1 - 2`              | El argumento `-` por sí solo no es un número.                      |

* **Salida Esperada para cualquiera de estos:** `Error\n` (al standard error).

### 2. Argumentos Duplicados
La lista de números inicial debe ser un conjunto de valores únicos. Si hay dos o más números idénticos, es un error.
| **Caso**                | **Comando de Ejemplo**           | **Razón del Error**                                               |
|-------------------------|----------------------------------|------------------------------------------------------------------|
| Duplicado Simple        | `./push_swap 10 5 8 10`          | El número `10` aparece dos veces.                                |
| Duplicado Cerca         | `./push_swap 1 2 2 3 4`          | El número `2` aparece dos veces consecutivas.                   |
| Duplicado en Negativo    | `./push_swap -5 0 5 -5`          | El número `-5` aparece dos veces.                                |
| Múltiples Duplicados    | `./push_swap 1 5 1 5 8`          | Los números `1` y `5` están duplicados.                         |

* **Salida Esperada para cualquiera de estos:** `Error\n` (al standard error).

### 3. Argumentos Válidos (No Error)

| **Caso**                | **Comando de Ejemplo**           | **Razón del Éxito**                                               |
|-------------------------|----------------------------------|------------------------------------------------------------------|
| Positivos               | `./push_swap 2 1 3 6 5 8`        | Todos son enteros válidos y únicos.                             |
| Positivos y Negativos   | `./push_swap -5 0 10 -15 2`      | Todos son enteros válidos y únicos.                             |
| Valores Límite          | `./push_swap 2147483647 -2147483648 0` | Los valores son los límites del `int` y son únicos.            |


#### Resumen del Flujo de Verificación:
Cuando tu programa se ejecuta, el primer paso lógico sería:
1. **Iterar** sobre cada argumento.
2. Para cada argumento, verificar que **todos los caracteres** son dígitos, opcionalmente precedidos por un único signo (+ o -). Si no, -> **ERROR (No Válido)**.
3. Convertir el argumento a un número y verificar que el valor resultante no excede los límites de int. Si lo hace, -> **ERROR (Overflow/Underflow)**.
4. **Almacenar** los números válidos (ej. en tu lista enlazada).
5. Una vez procesados todos los argumentos, verificar que no hay números repetidos en la estructura de datos. Si los hay, -> **ERROR (Duplicados)**.
6. Si todas las verificaciones pasan, el programa continúa con la lógica de ordenamiento.
