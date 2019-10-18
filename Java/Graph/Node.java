import java.util.ArrayList;
import java.util.List;

/**
* Graph node data structure
* @author rafbel
* @since 2019-10-15
*
*/
public class Node {

	private Character data;
	private List<Node> adjacencyList;
	private Boolean visited;
	
	public Node(Character data) {
		adjacencyList = new ArrayList<Node>();
		this.data = data;
		this.visited = false;
	}
	
	public void addEdge(Node node) {
		adjacencyList.add(node);
	}
	
	public List<Node> getAdjacencyList() {
		return adjacencyList;
	}

	public Character getData() {
		return this.data;
	}

	public Boolean getVisited() {
		return visited;
	}

	public void setVisited(Boolean visited) {
		this.visited = visited;
	}
}
