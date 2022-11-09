# Act. 4.2 - Grafos: sus representaciones y sus recorridos

## <span style="color: rgb(26, 99, 169);">¿Qué tengo que hacer?</span>

Realiza en forma individual una aplicación en C++ llamada "appGrafo.cpp" que:

<!-- primera tabla -->
<table style="height: 10px; width: 0%; border-collapse: collapse; border-top-style: solid; border-right-style: solid; border-bottom-style: solid; border-left-style: solid;" border="1">
<tbody>
<tr style="height: 24px;">
<td style="width: 30%; height: 10px; background-color: rgb(25, 99, 169);" rowspan="5"><span style="font-size: 18pt; color: rgb(255, 255, 255);">loadGraph</span></td>
<td style="width: 0px; height: 0px; background-color: rgb(0, 139, 247);">Descripción</td>
<td style="width: 0px; height: 0px; background-color: rgb(183, 219, 255);">
Cargue los arcos del grafo y almacene una Matriz de Adjacencia y en una L
ista de Adjacencia.
</td>
</tr>
<tr style="height: 24px;">
<td style="width: 0px; height: 0px; background-color: rgb(0, 139, 247);">Entrada</td>
<td style="width: 0px; height: 0px; background-color: rgb(183, 219, 255);">
El archivo de datos de entrada por referencia. 
</td>
</tr>
<tr style="height: 24px;">
<td style="width: 0px; height: 0px; background-color: rgb(0, 139, 247);">Salida</td>
<td style="width: 0px; height: 0px; background-color: rgb(183, 219, 255);">nada</td>
</tr>
<tr style="height: 24px;">
<td style="width: 0px; height: 0px; background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Precondición</span></td>
<td style="width: 0px; height: 0px; background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);">nada</span></td>
</tr>
<tr style="height: 24px;">
<td style="width: 0px; height: 10px; background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Postcondición</span></td>
<td style="width: 0px; height: 10px; background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);">Nada</span></td>
</tr>
</tbody>
</table>

<!-- segunda tabla -->
<table style="height: 10px; width: 0%; border-collapse: collapse; border-top-style: solid; border-right-style: solid; border-bottom-style: solid; border-left-style: solid;" border="1">
<tbody>
<tr style="height: 24px;">
<td style="width: 30%; height: 10px; background-color: rgb(25, 99, 169);" rowspan="5"><span style="font-size: 18pt; color: rgb(255, 255, 255);">DFS</span></td>
<td style="width: 0px; height: 0px; background-color: rgb(0, 139, 247);">Descripción</td>
<td style="width: 0px; height: 0px; background-color: rgb(183, 219, 255);">
Imprima el recorrido de DFS (Profundidad) a partir del nodo inicial
</td>
</tr>
<tr style="height: 24px;">
<td style="width: 0px; height: 0px; background-color: rgb(0, 139, 247);">Entrada</td>
<td style="width: 0px; height: 0px; background-color: rgb(183, 219, 255);">
Un entero representando el nodo inicial.
</td>
</tr>
<tr style="height: 24px;">
<td style="width: 0px; height: 0px; background-color: rgb(0, 139, 247);">Salida</td>
<td style="width: 0px; height: 0px; background-color: rgb(183, 219, 255);">nada</td>
</tr>
<tr style="height: 24px;">
<td style="width: 0px; height: 0px; background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Precondición</span></td>
<td style="width: 0px; height: 0px; background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);">El nodo inicial debe existir y el grafo debera de
estar correctamente cargado en la matriz de adjacencia.</span></td>
</tr>
<tr style="height: 24px;">
<td style="width: 0px; height: 10px; background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Postcondición</span></td>
<td style="width: 0px; height: 10px; background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);">Nada</span></td>
</tr>
</tbody>
</table>

<!-- tercer tabla -->
<table style="height: 10px; width: 0%; border-collapse: collapse; border-top-style: solid; border-right-style: solid; border-bottom-style: solid; border-left-style: solid;" border="1">
<tbody>
<tr style="height: 24px;">
<td style="width: 30%; height: 10px; background-color: rgb(25, 99, 169);" rowspan="5"><span style="font-size: 18pt; color: rgb(255, 255, 255);">BFS</span></td>
<td style="width: 0px; height: 0px; background-color: rgb(0, 139, 247);">Descripción</td>
<td style="width: 0px; height: 0px; background-color: rgb(183, 219, 255);">
Imprima el recorrido de BFS (anchura) a partir del nodo inicial
</td>
</tr>
<tr style="height: 24px;">
<td style="width: 0px; height: 0px; background-color: rgb(0, 139, 247);">Entrada</td>
<td style="width: 0px; height: 0px; background-color: rgb(183, 219, 255);">
Un entero representando el nodo inicial. </td>
</tr>
<tr style="height: 24px;">
<td style="width: 0px; height: 0px; background-color: rgb(0, 139, 247);">Salida</td>
<td style="width: 0px; height: 0px; background-color: rgb(183, 219, 255);">nada</td>
</tr>
<tr style="height: 24px;">
<td style="width: 0px; height: 0px; background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Precondición</span></td>
<td style="width: 0px; height: 0px; background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);">El nodo inicial debe existir y el grafo debera estar
correctamente cargado en la lista de adjacencia. </span></td>
</tr>
<tr style="height: 24px;">
<td style="width: 0px; height: 10px; background-color: rgb(0, 139, 247);"><span style="color: rgb(0, 0, 0);">Postcondición</span></td>
<td style="width: 0px; height: 10px; background-color: rgb(183, 219, 255);"><span style="color: rgb(0, 0, 0);">Nada</span></td>
</tr>
</tbody>
</table>
