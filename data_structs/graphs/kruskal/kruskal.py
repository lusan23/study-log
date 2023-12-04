from graphs.mdv import Mdv
earth  = Mdv("Earth")
mart = Mdv("Mart")
jupyter = Mdv("Jupyter")
saturn = Mdv("Saturn") 

def define_connections(pointing_planet, L1, L2, L3):
    """ (Mdv, [Mdv, float], [Mdv, float], [Mdv, float] ) -> NoneType

    """
    # distance between planets
    pointing_planet.point_to(L1[0])
    #updating weight
    p_lone = pointing_planet.get_edge(two=True)
    p_lone.update_weight(L1[1])

    pointing_planet.point_to(L2[0])
    # updating weight in the edge inside self.__edge_set
    p_ltwo = pointing_planet.get_edges()
    l2_key = hex(id(L2[0]))
    p_ltwo = p_ltwo[l2_key]
    p_ltwo.update_weight(L2[1])

    pointing_planet.point_to(L3[0])
    # updating weight in the edge inside self.__edge_set
    p_lthree = pointing_planet.get_edges()
    l3_key = hex(id(L3[0]))
    p_lthree = p_lthree[l3_key]
    p_lthree.update_weight(L3[1])

def get_min_weight_edge(vertex, result_list):
    """ (vertex ) -> [Edges]
    return all the edges from that vertex in a list
    """
    dict_edge = vertex.get_edges()
    dict_edge = list(dict_edge.items())
    dict_edge.append(vertex.get_edge(two=True))
    minimum_weight = 10000.0
    choosen_edge = None

    for edge in dict_edge:
 
        if (isinstance(edge, tuple)):    
            current_weight = edge[1]
        else:
            current_weight = edge

        current_weight = current_weight.get_weight()

        if (not is_repeated_edge(edge, edge_list=result_list)):
        
            if (current_weight < minimum_weight):
                minimum_weight = current_weight
                if (isinstance(edge, tuple)):
                    choosen_edge = edge[1]
                else:
                    choosen_edge = edge
    
    if minimum_weight == 10000.0:
         return None
    
    # return minimum_weight, choosen_edge.
    return minimum_weight, choosen_edge

def is_repeated_edge(edge, edge_list) -> bool:
  """ (Edge, list_edge) -> bool
  verifies if a given edge share the sames vertexes as one of the edges in edge_list
  >>> is_repeated_edge(edge, result)
  True/False 
  """  
  is_repeated = False
  if edge_list == []:
      return False
  if (isinstance(edge, tuple)):
    given_edge_vtxs = {edge[1].get_dest_vertex(), edge[1].get_src_vertex()}
  else:
    given_edge_vtxs = {edge.get_dest_vertex(), edge.get_src_vertex()}

  # get src and dest vertexes of each edge and put in a set
  for item_edge in edge_list:
    if (isinstance(edge, tuple)):
        current_item_edge_vtxs = {item_edge[1].get_dest_vertex(), item_edge[1].get_src_vertex()}
    else:
        current_item_edge_vtxs = {item_edge[1].get_dest_vertex(), item_edge[1].get_src_vertex()}
      # compare this set with the set of the edge
    if current_item_edge_vtxs == given_edge_vtxs:
        is_repeated = True
        return is_repeated

  return is_repeated

  
  
def make_list (vertex_list) -> list:
    """ ([Vertex]) -> ((Vertex, int) ... (Vertex, int))
    
    go through all of the vertex and find the minimun weight

    """
    result = []
    for vertex in vertex_list:
        found_edge = get_min_weight_edge(vertex, result)
        if (found_edge ==  None):
            pass
        else:
            result.append(found_edge) 
    # go to the next vertex

    result = sorted(result, key=lambda x: x[0])

    return result


if __name__ == "__main__":

    # float in Astronomical Units
    define_connections(earth, [mart, 0.52 ], [jupyter, 4.20 ], [saturn, 8.34 ])
    define_connections(mart, [earth, 0.52 ], [jupyter, 3.68 ], [saturn, 7.82 ])
    define_connections(jupyter, [earth, 4.20 ], [mart, 3.68 ], [saturn, 4.14 ])
    define_connections(saturn, [earth, 8.20 ], [mart, 7.82 ], [jupyter, 4.14 ])

    # result = make_list([mart, earth, jupyter, saturn])
    # for edge in result:
    #     print(edge)
    
    ls = make_list([ earth, mart,  jupyter, saturn])
    # for edg in ls:
    #     src, dest = edg[1].get_src_vertex().get_data(), edg[1].get_dest_vertex().get_data()
    #     print(f"weight:{edg[0]} | src:{src} | dest: {dest}")
