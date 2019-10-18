import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

import Graph;
import Node;

/**
* Depth-first search
* @author rafbel
* @since 2019-10-15
*
*/
public class DFS {

	public static List<Node> traverse(Graph graph, int startNodeIndex) {
		List<Node> traversalList = new ArrayList<Node>();
		recurseTraverse(graph.getNode(startNodeIndex), traversalList);
		return traversalList;
	}
	
	private static void recurseTraverse(Node currentNode, List<Node> traversalList) {
		traversalList.add(currentNode);
		currentNode.setVisited(true);
		
		List<Node> orderedAdjacentNodes = currentNode.getAdjacencyList();
		orderedAdjacentNodes.sort(Comparator.comparing(Node::getData));
		
		for (Node adjacentNode : orderedAdjacentNodes) {
			if (!adjacentNode.getVisited()) {
				recurseTraverse(adjacentNode, traversalList);
			}
		}
		
	}
}
