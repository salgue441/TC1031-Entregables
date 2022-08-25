/**
 * @file activity.h
 * @author Carlos Salguero - A00833341
 * @version 0.1
 * @date 2022-08-25
 * @copyright Copyright (c) 2022
 */

#ifndef ACTIVITY_H
#define ACTIVITY_H

/**
 * @brief
 * Calcula la suma de 1 hasta n de forma iterativa.
 * @param n               El limite de la suma
 * @return unsigned int   El resultado de la suma.
 * @complexity            O(n)
 */
unsigned int suma_iterativa(unsigned int n)
{
    int aux{};

    for (auto i{1}; i <= n; ++i)
        aux += i;

    return aux;
}

/**
 * @brief
 * Calcula la suma de 1 hasta n de forma recursiva
 * @param n                El limite de la suma
 * @return unsigned int    El resultado de la suma
 * @complexity             T(0) = 0, T(1) = 1, T(n) = n + T(n - 1)
 */
unsigned int suma_recursiva(unsigned int n)
{
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;

    return n + suma_recursiva(n - 1);
}

/**
 * @brief
 * Calcula la suma de 1 hasta n de forma directa. Utiliza el metodo
 * de gauss para calcular la suma.
 * @param n                  El limite de la suma
 * @return unsigned int      El resultado de la suma
 * @complexity               O(1)
 */
unsigned int suma_directa(unsigned int n)
{
    if (n == 1)
        return 1;

    return (n * (n + 1) / 2);
}

#endif //! ACTIVITY_H