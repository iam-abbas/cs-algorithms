import java.util.ArrayList;
import java.util.List;

/**
* Graph data structure
* @author rafbel
* @since 2019-10-15
*
*/
public class Graph {

	private List<Node> nodes;
	
	public Graph() {
		nodes = new ArrayList<Node>();
	}
	
	public void addNode(Node node) {
		nodes.add(node);
	}
	
	public Node getNode(int i) {
		return nodes.get(i);
	}
	
	public List<Node> getNodes() {
		return nodes;
	}
}
