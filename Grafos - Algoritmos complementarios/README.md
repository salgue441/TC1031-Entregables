![Tec de Monterrey](images/logotecmty.png)
# Act 4.2 - Grafos: Algoritmos complementarios

## <span style="color: rgb(26, 99, 169);">¿Qué tengo que hacer?</span>
En este repositorio encontrarás el archivo "activity.h" que deberás modificar para el desarrollo de esta actividad. Deberás colocar en la parte superior, en comentarios, tus datos. Por ejemplo:
```
// =========================================================
// File: activity.h
// Author: Edward Elric - A00123456
// Date: 01/01/2021
// =========================================================
```

Diseña e implementa en forma <ins>forma individual</ins>, las funciones que resuelvan los problemas que se describen a continuación.

Las funciones que debes implementar son:

 1. ``` template <class Vertex> void dfs2(Vertex v, const UnweightedGraph<Vertex>* graph, std::set<Vertex> &reached, std::stack<Vertex> &TS) ```
 Implementa la búsqueda en profundidad modifica vista en clase. Esta función la usurarás para resolver el siguiente problema.

2. ```template <class Vertex> std::string topologicalSort(const UnweightedGraph<Vertex>* graph)```
Regresa un *string* conteniendo el recorrido topológico (*topological sort*) del grafo *graph*. El *Topological Sort* de un Grafo Direccionado Acíclico (*Directed Acyclic Graph*, *DAG*) es un ordenamiento lineal de los vértices que aparecen en un *DAG* tal que si el vértice *u* aparece antes de *v* es porque existe un arco (*u* -> *v*) en el *DAG*. Cada *DAG* tiene al menos, y posiblemente más,  un *topological sort*.

3. ```template <class Vertex> bool isBipartite(const UnweightedGraph<Vertex>* graph)```
Regresa verdadero si el grafo es bipartita; falso en caso contrario. Un grafo es bipartita si los vértices del grafo pueden ser divididos en dos conjuntos disjuntos R y S tal que cada arco conecta a un vértice en R con un vértice en S.

4. ``` template  <class Vertex> bool isCyclic(Vertex v, const UnweightedGraph<Vertex>* graph,   std::set<Vertex> &reached, Vertex parent) ```
Encuentra la raíz del árbol, que es el vértice sin aristas entrantes. Si no existe ningún nodo, devuelve falso. Si existe más de un nodo, entonces el gráfico no está conectado y también deberíamos devolver falso.

5. ```template <class Vertex> bool isTree(const UnweightedGraph<Vertex>* graph)```
Regresa verdadero si el grafo forma un árbol; falso en caso contrario. Para ello, debemos determinar que el grafo se acíclico, que no existe más que un vértice sin aristas entrantes y que esté conectado.

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
