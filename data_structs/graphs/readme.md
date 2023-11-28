This Graph data structure consists of three Python files: `edges.py`, `vertices.py`, and `graph_set.py`, each contributing to the implementation of a versatile graph data structure. Additionally, there is a `mdv.py` (muti degreed vertex) file extending the capabilities of the graph to handle vertices with multiple edge
## `edges.py`

The `edges.py` file contains the implementation of the `Edge` class. This class represents edges in a graph, storing two pointers to vertex objects and a weight attribute. Key functionalities include creating an edge, accessing and updating the weight, source, and destination vertices, and pointing the edge to a specific vertex.

### Usage

```python
from graphs.edges import Edge

edge_ab = Edge(vertex_a, vertex_b, 1.0)
weight = edge_ab.get_weight()
src_vertex = edge_ab.get_src_vertex()
dest_vertex = edge_ab.get_dest_vertex()
edge_ab.update_weight(4.7)
edge_ab.update_edge(new_source, new_destiny)
```

For more details, refer to the docstrings provided in the code.

## `vertices.py`

The `vertices.py` file defines the `Vertex` class, representing vertices in a graph. Each vertex stores data and edges pointing to other vertices. Functionalities include creating a vertex, accessing and updating data and edges, pointing an edge to another vertex, updating the edge of the pointed vertex, and generating a list of connected vertices.

### Usage

```python
from graphs.vertices import Vertex

vertex_a = Vertex(10000)
data = vertex_a.get_data()
edge_one = vertex_a.get_edge()
vertex_a.update_data(20)
vertex_a.__update_edge(src, dest, two=True)
vertex_a.replace_edge(new_edge)
vertex_a.point_to(vertex_h, direct=False)
vertex_a.unpoint()
path_list = vertex_a.vertex_path()
```

Refer to the docstrings for detailed information.

## `graph_set.py`

The `graph_set.py` file defines the `GraphSet` class, managing a set of vertices and their connections. Functionalities include creating a set of vertices with optional enumeration, linking all vertices in the set in the order they were created, retrieving the set of graphs, and generating an adjacency list representing vertex connections.

### Usage

```python
from graphs.graph_set import GraphSet

graphs_a = GraphSet()
graphs_a.set_vertexes(3)
graphs_a.link_all()
graph_dict = graphs_a.get_graphs()
adjacency_list = graphs_a.adjascent_list()
```

See the code comments and docstrings for detailed information.

## `multi_degree_vertex.py`

The `multi_degree_vertex.py` file introduces the `Mdv` class, extending the `Vertex` class to handle vertices with multiple edges. This class includes methods to add edges, get the set of edges, and point to other vertices, creating new edges when necessary.

### Usage

```python
from graphs.multi_degree_vertex import Mdv

mdv_a = Mdv(10)
mdv_b = Mdv(20)

mdv_a.add_edge('ab')
mdv_a.add_edge('ac')

edge_set = mdv_a.get_edges()

mdv_a.point_to(mdv_b)
mdv_a.point_to(mdv_c, direct=True)
```

Explore the code comments and docstrings for comprehensive information.

Feel free to integrate these classes into your graph-related projects, and if you encounter any issues or have suggestions for improvement, please let us know!