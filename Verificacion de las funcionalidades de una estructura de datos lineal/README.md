![Tec de Monterrey](images/logotecmty.png)
# Act 2.2 - Verificación de las funcionalidades de una estructura de datos lineal

## <span style="color: rgb(26, 99, 169);">¿Qué tengo que hacer?</span>
En este repositorio encontrarás el archivo "list.h" que deberás modificar para el desarrollo de esta actividad. Deberás colocar en la parte superior, en comentarios, tus datos. Por ejemplo:
```
// =========================================================
// File: list.h
// Author: Edward Elric - A00123456
// Date: 01/01/2021
// =========================================================
```
Diseña e implementa, de forma <span style="text-decoration-line: underline;">forma individual</span>, siguiendo la especificación de la interfaz para un ADT que represente una estructura de datos lineal:

Dependiendo del ADT de estructura de datos lineal deberán implementar las operaciones CRUD (Create, Read (buscar), Update, Delete) elementos en la estructura de datos. Algunas operaciones no aplican para ciertas estructura de datos

<table style="border-collapse: collapse; border-top-style: solid; border-right-style: solid; border-bottom-style: solid; border-left-style: solid;" border="1">
<tbody>
<tr style="">
<td style="background-color: rgb(25, 99, 169);" rowspan="5"><span style="font-size: 18pt; color: rgb(255, 255, 255);">before</span></td>
<td style="background-color: rgb(0, 139, 247);">Descripción</td>
<td style="background-color: rgb(183, 219, 255);">
Devuelve el valor que se encuentra en previo a la primera ocurrencia de *val*.
</td>
</tr>
<tr style="">
<td style="background-color: rgb(0, 139, 247);">Entrada</td>
<td style="background-color: rgb(183, 219, 255);">*val*, valor a ser buscado.</td>
</tr>
<tr style="">
<td style="background-color: rgb(0, 139, 247);">Salida</td>
<td style="background-color: rgb(183, 219, 255);">Elemento que se encuentra previo a la primera ocurrencia del elemento buscado. Si elemento *val* no existe, deberá arrojar una excepción.</td>
</tr>
<tr style="">
<td style="background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Precondición</span></td>
<td style="background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);">Una estructura válida.</span></td>
</tr>
<tr style="">
<td style="background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Postcondición</span></td>
<td style="background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);">Nada.</span></td>
</tr>
</tbody>
</table>

<br>

<table style="border-collapse: collapse; border-top-style: solid; border-right-style: solid; border-bottom-style: solid; border-left-style: solid;" border="1">
<tbody>
<tr style="">
<td style="background-color: rgb(25, 99, 169);" rowspan="5"><span style="font-size: 18pt; color: rgb(255, 255, 255);">after</span></td>
<td style="background-color: rgb(0, 139, 247);">Descripción</td>
<td style="background-color: rgb(183, 219, 255);">
Devuelve el valor que se encuentra en después de la primera ocurrencia de *val*.
</td>
</tr>
<tr style="">
<td style="background-color: rgb(0, 139, 247);">Entrada</td>
<td style="background-color: rgb(183, 219, 255);">*val*, valor a ser buscado.</td>
</tr>
<tr style="">
<td style="background-color: rgb(0, 139, 247);">Salida</td>
<td style="background-color: rgb(183, 219, 255);">Elemento que se encuentra después de la primera ocurrencia del elemento buscado. Si elemento *val* no existe, deberá arrojar una excepción.</td>
</tr>
<tr style="">
<td style="background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Precondición</span></td>
<td style="background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);">Una estructura válida.</span></td>
</tr>
<tr style="">
<td style="background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Postcondición</span></td>
<td style="background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);">Nada.</span></td>
</tr>
</tbody>
</table>

<br>

<table style="border-collapse: collapse; border-top-style: solid; border-right-style: solid; border-bottom-style: solid; border-left-style: solid;" border="1">
<tbody>
<tr style="">
<td style="background-color: rgb(25, 99, 169);" rowspan="5"><span style="font-size: 18pt; color: rgb(255, 255, 255);">insert_before</span></td>
<td style="background-color: rgb(0, 139, 247);">Descripción</td>
<td style="background-color: rgb(183, 219, 255);">
Inserta un nuevo valor, *newVal*, antes de la primera ocurrencia de *lookingFor*.
</td>
</tr>
<tr style="">
<td style="background-color: rgb(0, 139, 247);">Entrada</td>
<td style="background-color: rgb(183, 219, 255);">*lookingFor*, valor a ser buscado.  

*newVal*, valor a ser insertado.</td>
</tr>
<tr style="">
<td style="background-color: rgb(0, 139, 247);">Salida</td>
<td style="background-color: rgb(183, 219, 255);">Estructura de datos actualizada con el elemento *newVal* antes de la primera ocurrencia de *lookingFor*. Si elemento *lookingFor* no existe, deberá arrojar una excepción.</td>
</tr>
</tr>
<tr style="">
<td style="background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Precondición</span></td>
<td style="background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);">Estructura de datos válida</span></td>
</tr>
<tr style="">
<td style="background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Postcondición</span></td>
<td style="background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);">Estructura de datos debidamente actualizada</span></td>
</tr>
</tbody>
</table>

<br>

<table style="border-collapse: collapse; border-top-style: solid; border-right-style: solid; border-bottom-style: solid; border-left-style: solid;" border="1">
<tbody>
<tr style="">
<td style="background-color: rgb(25, 99, 169);" rowspan="5"><span style="font-size: 18pt; color: rgb(255, 255, 255);">insert_after</span></td>
<td style="background-color: rgb(0, 139, 247);">Descripción</td>
<td style="background-color: rgb(183, 219, 255);">
Inserta un nuevo valor, *newVal*, después de la primera ocurrencia de *lookingFor*.
</td>
</tr>
<tr style="">
<td style="background-color: rgb(0, 139, 247);">Entrada</td>
<td style="background-color: rgb(183, 219, 255);">*lookingFor*, valor a ser buscado.  

*newVal*, valor a ser insertado.</td>
</tr>
<tr style="">
<td style="background-color: rgb(0, 139, 247);">Salida</td>
<td style="background-color: rgb(183, 219, 255);">Estructura de datos actualizada con el elemento *newVal* despues de la primera ocurrencia de *lookingFor*. Si elemento *lookingFor* no existe, deberá arrojar una excepción.</td>
</tr>
<tr style="">
<td style="background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Precondición</span></td>
<td style="background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);">Estructura de datos válida</span></td>
</tr>
<tr style="">
<td style="background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Postcondición</span></td>
<td style="background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);">Estructura de datos debidamente actualizada</span></td>
</tr>
</tbody>
</table>

<br>Todas las funcionalidades deberán de estar correctamente alineadas y documentadas.&nbsp; Recuerda que todas las funcionalidades deberán pasar exitosamente todas las pruebas. Como parte de la documentación deberá incluirse la complejidad de cada una de ellas.

Para probar tu implementación, ejecuta el comando:
```
make
```
Este comando compilará tu código y generará una serie de archivos de pruebas llamados "runTest#", donde # será un número de prueba. Para ejecutar prueba, solo deberás ejecutar el archivos correcto. Por ejemplo, si quiere revisar si mi código cumple con la prueba número 3, deberías ejecutar:
```
./runTest3
```

## <span style="color: rgb(26, 99, 169);">**¿Bajo qué criterios se evalúa mi evidencia?**</span>

- **80%** - Para cada una de las funcionalidades se evaluará:

    - **Excelente (80%)** - pasa correctamente todos los casos de prueba.
    - **Muy Bien (60%)** - pasa correctamente el 75% de los casos de prueba.
    - **Bien (40%)** - pasa correctamente el 50% de los casos de prueba.
    - **Insuficiente (20%)** - pasa correctamente menos del 50% de los casos de prueba.


- **10%** - El código deberá seguir los lineamientos estipulados en el estándar de codificación: <span class="instructure_file_holder link_holder">[liga_estándar_codificación](estandar.pdf)</span>
- **10%** - Se respetan los nombres de las funciones en la aplicación.

## <span style="color: rgb(26, 99, 169);">**¿Dónde la entrego?**</span>
Cuando hayas pasado todas las pruebas, recuerda publicar el código en tu repositorio (*git push*).
