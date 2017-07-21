# **Relajación de matrices**

#### Descripción de los archivos
* **relax.c:** Código secuencial
* **omp_r.c:** Código paralelizado con omp_r

#### Compilación de los archivos:
* Secuencial: ``gcc relax.c -o [nombre archivo de salida]``, por ejemplo, ``gcc relax.c -o out``
* Paralelo: ``gcc -fopenmp omp_out.c -o [nombre archivo de salida]``

#### Ejecución de los archivos:
Se deben ejecutar con los siguientes argumentos:
1. Número de ecuaciones lineales
2. Tolerancia de error
3. Parámetro de relajación

Se ejecutaría así: ``./out 100 0.001 1.2``
