package edu.metrostate.ics340.p4.msr812;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

import com.google.common.graph.Graphs;
import com.google.common.graph.MutableValueGraph;
import com.google.common.graph.ValueGraphBuilder;

/*
 *  Develop a program that will load in cost estimates for various rail segments between cities.
 *  Produce a plan that connects all cities at the minimum construction cost.
 *  RailPlanner is designed to take an input of .CSV, pipe-delimited files.
 *  Then, performs Kruskal's algorithm on the input and return a value graph of minimum construction costs.
 */
public class RailPlanner {

	// We place the input in an arraylist to get access to Collections.sort
	ArrayList<GraphNode> inputNodes = new ArrayList<GraphNode>();

	// undirectedGraph, will store and return MST
	private MutableValueGraph<String, Integer> undirectedGraph = ValueGraphBuilder.undirected().allowsSelfLoops(false)
			.build();

	// Total path cost of MST
	private int totalCost = 0;

	/*
	 * Precondition: file at extimateFilePath must exist and be readable.
	 * 
	 * @param estimateFilePath a file path for the input csv.
	 * 
	 * @returns com.google.common.graph.ValueGraph<String,Integer> undirectedGraph
	 * (MST)
	 */
	public com.google.common.graph.ValueGraph<String, Integer> createPlan(String estimateFilePath) {
		// BufferedReader, opens file, scans line by line, creates GraphNodes and inputs
		// in arraylist.
		try (BufferedReader br = new BufferedReader(new FileReader(estimateFilePath))) {
			String line;
			while ((line = br.readLine()) != null) {
				String[] values = line.split("\\|");
				inputNodes.add(new GraphNode(values[0], values[1], Integer.parseInt(values[2])));
				// Sort arraylist with Collections.sort comparator.
				sortNodes(inputNodes);
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

		/*
		 * Will input from the sorted ararylist to the undriectedGraph, one at a time.
		 * With it, it will also add up the cost that was input. After 1 insertion, it
		 * will perform a check to see if the graph contains a cycle. If it does, it
		 * will undo the insertion and contiune with the next item in the arraylist.
		 */
		for (int i = 0; i < inputNodes.size(); i++) {
			undirectedGraph.putEdgeValue(inputNodes.get(i).getSrc(), inputNodes.get(i).getDest(),
					inputNodes.get(i).getWeight());
			totalCost += inputNodes.get(i).getWeight();
			if (Graphs.hasCycle(undirectedGraph.asGraph())) {
				undirectedGraph.removeEdge(inputNodes.get(i).getSrc(), inputNodes.get(i).getDest());
				totalCost -= inputNodes.get(i).getWeight();
			}
		}
		// Returns the MST
		return undirectedGraph;
	}

	/*
	 * @returns undirectedGraph.edges().size() the amount of edges in the MST
	 */
	public int getAmountOfEdges() {
		return undirectedGraph.edges().size();
	}

	/*
	 * @returns totalCost the total cost of all edges in the MST.
	 */
	public int getTotalPathCost() {
		return totalCost;
	}

	/*
	 * Comparator to sort GraphNodes by weighted value. Sorts in ascending order.
	 */
	private void sortNodes(ArrayList<GraphNode> inputNodes) {
		Collections.sort(inputNodes, new Comparator<GraphNode>() {
			@Override
			public int compare(GraphNode g1, GraphNode g2) {
				return g1.getWeight() - g2.getWeight();
			}
		});
	}

	// Main
	public static void main(String[] args) {
		RailPlanner r1 = new RailPlanner();
		r1.createPlan("p4_scenario0.csv");
		r1.getAmountOfEdges();
		r1.getTotalPathCost();
	}
}
