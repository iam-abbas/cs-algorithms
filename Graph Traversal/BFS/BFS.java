import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class BFS{
  public static void main(String[] args){
    Graph G = new Graph();
    G.addEdge(1,2);
    G.addEdge(1,3);
    G.addEdge(1,4);
    G.addEdge(4,5);
    G.addEdge(4,6);
    G.addEdge(2,7);

    List<Node> BFSresult = G.breadthFirstSearch(1); //1 is the root from where we start BFS

    //printing the result
    for(Node nodes : BFSresult){
      System.out.println(nodes.getName());
    }
  }
}

class Graph {
  private Map<Integer, Node> nodes = new HashMap<Integer, Node>();

  public Graph() {}

  public void addEdge(Integer nodeName1, Integer nodeName2) {
    Node node1 = nodes.get(nodeName1);
    if (node1 == null) {
      node1 = new Node(nodeName1);
    }

    Node node2 = nodes.get(nodeName2);
    if (node2 == null) {
      node2 = new Node(nodeName2);
    }

    node1.addNeighbor(node2);
    node2.addNeighbor(node1);

    nodes.put(nodeName1, node1);
    nodes.put(nodeName2, node2);
  }

  public List<Node> breadthFirstSearch(int rootName) {
    List<Node> result = new ArrayList<Node>();
    List<Node> temp = new ArrayList<Node>();
    Set<Integer> visited = new HashSet<Integer>();

    Node root = nodes.get(rootName);
    temp.add(root);
    visited.add(rootName);

    while (temp.size() > 0) {
      Node currentNode = temp.get(0);
      List<Node> neighbors = currentNode.getNeighbors();

      for (int i = 0; i < neighbors.size(); i++) {
        Node neighbor = neighbors.get(i);
        // a node can only be visited once if it has more than one parents
        if (visited.contains(neighbor.getName())) {
          continue;
        } else {
          temp.add(neighbor);
          visited.add(neighbor.getName());
        }
      }

      temp.remove(0);
      result.add(currentNode);
    }

    return result;
  }
}

class Node {
  Integer name;
  List<Node> neighbors = new ArrayList<Node>();

  public Node(Integer name) {
    this.name = name;
  }

  public Integer getName() {
    return this.name;
  }

  public void addNeighbor(Node neighbor) {
    neighbors.add(neighbor);
  }

  public List<Node> getNeighbors() {
    return neighbors;
  }
}