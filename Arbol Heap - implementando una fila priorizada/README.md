# Act 3.2 - Arbol Heap: Implementando una fila priorizada

```md
File: main.cpp
File: heap.h
File: heap.cpp
Author: Carlos Salguero
Date: 23/10/2022
```

## ¿Qué tengo que hacer?

Implementa una clase en C++ llamada "heap" que tenga las siguientes operaciones utilizando un heap y simulando una fila priorizada de enteros con prioridad de valor
mayor.

## Funciones a implementar

<table style="border-collapse: collapse; border-top-style: solid; border-right-style: solid; border-bottom-style: solid; border-left-style: solid;" border="1">
<tbody>

<tr style="">
<td style="background-color: rgb(25, 99, 169);" rowspan="5"><span style="font-size: 18pt; color: rgb(255, 255, 255);">push</span></td>
<td style="background-color: rgb(0, 139, 247);">Descripción</td>
<td style="background-color: rgb(183, 219, 255);">
Agregue un dato a la fila priorizada
</td>
</tr>

<tr style="">
<td style="background-color: rgb(0, 139, 247);">Entrada</td>
<td style="background-color: rgb(183, 219, 255);">
Un entero, el cual se desea agregar a la fila priorizada
</td>
</tr>

<tr style="">
<td style="background-color: rgb(0, 139, 247);">Salida</td>
<td style="background-color: rgb(183, 219, 255);">Nada</td>
</tr>

<tr style="">
<td style="background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Precondición</span></td>
<td style="background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);">n es un entero
</span></td>
</tr>

<tr style="">
<td style="background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Postcondición</span></td>
<td style="background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);">La fila priorizada contiene un nuevo dato</span></td>
</tr>

</tbody>
</table>

<table style="border-collapse: collapse; border-top-style: solid; border-right-style: solid; border-bottom-style: solid; border-left-style: solid;" border="1">
<tbody>

<tr style="">
<td style="background-color: rgb(25, 99, 169);" rowspan="5"><span style="font-size: 18pt; color: rgb(255, 255, 255);">pop</span></td>
<td style="background-color: rgb(0, 139, 247);">Descripción</td>
<td style="background-color: rgb(183, 219, 255);">
Saca de la fila priorizada el dato que tiene mayor prioridad.
</td>
</tr>

<tr style="">
<td style="background-color: rgb(0, 139, 247);">Entrada</td>
<td style="background-color: rgb(183, 219, 255);">
Nada
</td>
</tr>

<tr style="">
<td style="background-color: rgb(0, 139, 247);">Salida</td>
<td style="background-color: rgb(183, 219, 255);">Nada</td>
</tr>

<tr style="">
<td style="background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Precondición</span></td>
<td style="background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);"> Que la fila priorizada contenga al menos 1 dato.
</span></td>
</tr>

<tr style="">
<td style="background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Postcondición</span></td>
<td style="background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);">La fila priorizada queda sin el dato con mayor prioridad</span></td>
</tr>

</tbody>
</table>

<table style="border-collapse: collapse; border-top-style: solid; border-right-style: solid; border-bottom-style: solid; border-left-style: solid;" border="1">
<tbody>

<tr style="">
<td style="background-color: rgb(25, 99, 169);" rowspan="5"><span style="font-size: 18pt; color: rgb(255, 255, 255);">top</span></td>
<td style="background-color: rgb(0, 139, 247);">Descripción</td>
<td style="background-color: rgb(183, 219, 255);">
Regresa el valor del dato que esta con mayor prioridad en la fila priorizada.
</td>
</tr>

<tr style="">
<td style="background-color: rgb(0, 139, 247);">Entrada</td>
<td style="background-color: rgb(183, 219, 255);">
Nada
</td>
</tr>

<tr style="">
<td style="background-color: rgb(0, 139, 247);">Salida</td>
<td style="background-color: rgb(183, 219, 255);">El dato que tiene mayor prioridad dentro de la Fila priorizada
</td>
</tr>

<tr style="">
<td style="background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Precondición</span></td>
<td style="background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);"> Que la fila priorizada contenga al menos 1 dato.
</span></td>

</tr>

<tr style="">
<td style="background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Postcondición</span></td>
<td style="background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);">Nada</span></td>
</tr>

</tbody>
</table>

<table style="border-collapse: collapse; border-top-style: solid; border-right-style: solid; border-bottom-style: solid; border-left-style: solid;" border="1">
<tbody>

<tr style="">
<td style="background-color: rgb(25, 99, 169);" rowspan="5"><span style="font-size: 18pt; color: rgb(255, 255, 255);">is_empty</span></td>
<td style="background-color: rgb(0, 139, 247);">Descripción</td>
<td style="background-color: rgb(183, 219, 255);">
Regresa un valor boleando diciendo si la fila priorizada esta vacía o tiene datos.
</td>
</tr>

<tr style="">
<td style="background-color: rgb(0, 139, 247);">Entrada</td>
<td style="background-color: rgb(183, 219, 255);">
Nada
</td>
</tr>

<tr style="">
<td style="background-color: rgb(0, 139, 247);">Salida</td>
<td style="background-color: rgb(183, 219, 255);">Un valor boleano que diga si la fila priorizada esta vacía o tiene datos.
</td>
</tr>

<tr style="">
<td style="background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Precondición</span></td>
<td style="background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);"> Nada
</span></td>
</tr>

<tr style="">
<td style="background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Postcondición</span></td>
<td style="background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);">Nada</span></td>
</tr>

</tbody>
</table>

<table style="border-collapse: collapse; border-top-style: solid; border-right-style: solid; border-bottom-style: solid; border-left-style: solid;" border="1">
<tbody>

<tr style="">
<td style="background-color: rgb(25, 99, 169);" rowspan="5"><span style="font-size: 18pt; color: rgb(255, 255, 255);">size</span></td>
<td style="background-color: rgb(0, 139, 247);">Descripción</td>
<td style="background-color: rgb(183, 219, 255);">
Regresa la cantidad de datos que tiene la fila priorizada
</td>
</tr>

<tr style="">
<td style="background-color: rgb(0, 139, 247);">Entrada</td>
<td style="background-color: rgb(183, 219, 255);">
Nada
</td>
</tr>

<tr style="">
<td style="background-color: rgb(0, 139, 247);">Salida</td>
<td style="background-color: rgb(183, 219, 255);">Un valor entero que represena la cantidad de datos de la fila priorizada
</td>
</tr>

<tr style="">
<td style="background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Precondición</span></td>
<td style="background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);"> Nada
</span></td>
</tr>

<tr style="">
<td style="background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Postcondición</span></td>
<td style="background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);">Nada</span></td>
</tr>

</tbody>
</table>

Todas las funcionalidades deberán de estar correctamente alineadas y documentadas. Como parte de la docuementación deberá incluirse la complejidad de cada una de ellas.

## Compilando & Corriendo el programa

Para el primer tipo de compilador:

```C++
g++ -std=c++20 main.cpp -o app
```

Si tu compilador funciona con std=c++2a

```C++
g++ -std=c++2a main.cpp -o app
```

Este comando compilará tu código y generará el archivo de salida correspondiente.

```c++
./app
```
