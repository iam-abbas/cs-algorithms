import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Queue;

import Graph;
import Node;

/**
* Breadth-first search
* @author rafbel
* @since 2019-10-15
*
*/
public class BFS {

	public static List<Node> traverse(Graph graph, int startNodeIndex) {
		List<Node> traversalList = new ArrayList<Node>();
		Queue<Node> queue = new ArrayDeque<Node>();
		Node startNode = graph.getNode(startNodeIndex);
		startNode.setVisited(true);
		queue.add(startNode);
		
		while (!queue.isEmpty()) {
			Node currentNode = queue.remove();
			traversalList.add(currentNode);
			
			List<Node> orderedAdjacentNodes = currentNode.getAdjacencyList();
			orderedAdjacentNodes.sort(Comparator.comparing(Node::getData));
			
			for (Node adjacentNode : orderedAdjacentNodes) {
				if (!adjacentNode.getVisited()) {
					adjacentNode.setVisited(true);
					queue.add(adjacentNode);
				}
			}
		}
		
		return traversalList;
	}
}
