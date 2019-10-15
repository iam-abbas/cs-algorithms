/*
 * @author Samy Rezzag
 */
package package;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.NavigableSet;
import java.util.Scanner;
import java.util.TreeSet;

import package.Router;

/*
 * This DroneRouter class implements the Router interface. This class is 
 * responsible for interfacing between user command input and with the Dijsktra 
 * Algorithm. This class has inner classes of Graph, Edge, and Vertex.
 */
public class DroneRouter implements Router {

	// Saves the Drone starting point.
	private String startingPoint;
	// Graph array which holds all the paths/edges
	private Graph.Edge[] GRAPH = null;

	// Constructor for DroneRouter
	public DroneRouter() {
	}

	/*
	 * Finds absolute file path, use buffered reader to count lines to instantiate
	 * the Graph.Edge GRAPH array's length.
	 * 
	 * Uses scanner to scan each line and create a edges into Graph.Edge GRAPH
	 * 
	 * @param routesFilePath path to routing file
	 * 
	 * @param startingPoint the initial starting point of the drone
	 */
	@Override
	public void loadRoutes(String routesFilePath, String startingPoint) {
		this.startingPoint = startingPoint;
		String sentence = "";
		File file = new File(routesFilePath).getAbsoluteFile();

		BufferedReader reader = null;
		try {
			reader = new BufferedReader(new FileReader(file));
			int lines = 0;
			while (reader.readLine() != null)
				lines++;
			reader.close();
			GRAPH = new Graph.Edge[lines];
		} catch (IOException e1) {
			throw new IllegalArgumentException("Illegal Argument Exception, File Not Found: " + routesFilePath);
		}

		try {
			int counter = 0;
			Scanner input = new Scanner(file);
			while (input.hasNextLine()) {
				sentence = input.nextLine();
				String[] values = sentence.split("\\s+");
				GRAPH[counter] = new Graph.Edge(values[0], values[1], Integer.parseInt(values[2]));
				counter++;
			}
			input.close();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	/*
	 * Finds route. Creates an instance of Graph with the provided Graph.Edge GRAPH
	 * made by routing file. Runes the dijkstra algorithm in respect to the starting
	 * point given iniitally.
	 * 
	 * @param destination to find path to.
	 */
	@Override
	public String[] getRoute(String destination) {
		Graph g = new Graph(GRAPH);
		g.dijkstra(startingPoint);

		return g.printPath(destination);
	}

	/*
	 * Finds cost. Creates an instance of Graph with the provided Graph.Edge GRAPH
	 * made by routing file. Runes the dijkstra algorithm in respect to the starting
	 * point given iniitally.
	 * 
	 * @param destination to find path to.
	 */
	@Override
	public int getPathCost(String destination) {
		Graph g = new Graph(GRAPH);
		g.dijkstra(startingPoint);

		return g.printCost(destination);
	}
}

class Graph {
	// mapping of vertex names to Vertex objects, built from a set of Edges
	private final Map<String, Vertex> graph;
	private static ArrayList<String> temp = new ArrayList<String>();
	private static int cost = 0;

	/**
	 * One edge of the graph (only used by Graph constructor)
	 */
	public static class Edge {
		public final String source, destination;
		public final int weight;

		public Edge(String source, String destination, int weight) {
			this.source = source;
			this.destination = destination;
			this.weight = weight;
		}
	}

	/**
	 * One vertex of the graph, with mappings of neighboring vertexes
	 */
	public static class Vertex implements Comparable<Vertex> {
		public final String name;
		// MAX_VALUE assumed to be infinity
		public int weight = Integer.MAX_VALUE;
		public Vertex previous = null;
		public final Map<Vertex, Integer> neighbours = new HashMap<>();

		public Vertex(String name) {
			this.name = name;
		}

		/*
		 * Will traverse and calculate which paths are taken to get from source to
		 * destination. Will add the node/edge to a temp arraylist. Arraylist is
		 * converted to array and returned.
		 * 
		 * Will return an empty array if null edge.
		 */
		private String[] printPath() {

			if (this == this.previous) {
				temp.add(this.name);
			} else if (this.previous == null) {
				String[] emptyArray = new String[0];
				return emptyArray;
			} else {
				this.previous.printPath();
				temp.add(this.name);
			}
			String[] path = new String[temp.size()];
			path = temp.toArray(path);
			return path;
		}

		/*
		 * Will traverse and calculate which costs are taken to get from source to
		 * destination. Will add the node/edge to a running tally.
		 * 
		 * Will return -1 if null.
		 */
		private int printCost() {
			if (this == this.previous) {
				cost += this.weight;
			} else if (this.previous == null) {
				return Router.NO_ROUTE;
			} else {
				this.previous.printPath();
				cost += this.weight;
			}
			return cost;
		}

		public int compareTo(Vertex other) {
			if (weight == other.weight)
				return name.compareTo(other.name);

			return Integer.compare(weight, other.weight);
		}
	}

	/**
	 * Builds a graph from a set of edges
	 */
	public Graph(Edge[] edges) {
		graph = new HashMap<>(edges.length);

		// one pass to find all vertices
		for (Edge e : edges) {
			if (!graph.containsKey(e.source))
				graph.put(e.source, new Vertex(e.source));
			if (!graph.containsKey(e.destination))
				graph.put(e.destination, new Vertex(e.destination));
		}

		// another pass to set neighbouring vertices
		for (Edge e : edges) {
			graph.get(e.source).neighbours.put(graph.get(e.destination), e.weight);
			// graph.get(e.destination).neighbours.put(graph.get(e.source), e.weight); //
			// also do this for
			// an undirected graph
		}
	}

	/**
	 * Runs dijkstras algorithm with the startPoint specified earlier.
	 * 
	 * @param startingPoint the vertex to start on.
	 */
	public void dijkstra(String startingPoint) {
		if (!graph.containsKey(startingPoint)) {
			throw new IllegalArgumentException("Illegal Argument Exception on value: " + startingPoint);
		}
		final Vertex source = graph.get(startingPoint);
		NavigableSet<Vertex> q = new TreeSet<>();

		// set-up vertices
		for (Vertex v : graph.values()) {
			v.previous = v == source ? source : null;
			v.weight = v == source ? 0 : Integer.MAX_VALUE;
			q.add(v);
		}
		dijkstra(q);
	}

	/**
	 * Implementation of dijkstra's algorithm using a binary heap.
	 */
	private void dijkstra(final NavigableSet<Vertex> q) {
		Vertex u, v;
		while (!q.isEmpty()) {
			// vertex with shortest weightance (first iteration will return source)
			u = q.pollFirst();
			if (u.weight == Integer.MAX_VALUE)
				break; // we can ignore u (and any other remaining vertices) since they are unreachable

			// look at weightances to each neighbour
			for (Map.Entry<Vertex, Integer> a : u.neighbours.entrySet()) {
				v = a.getKey(); // the neighbour in this iteration

				final int alternateDist = u.weight + a.getValue();
				if (alternateDist < v.weight) { // shorter path to neighbour found
					q.remove(v);
					v.weight = alternateDist;
					v.previous = u;
					q.add(v);
				}
			}
		}
	}

	/**
	 * Helper method to get the path of the vertices taken from stratingPoint to
	 * destination
	 * 
	 * @param destination
	 * @return array
	 */
	public String[] printPath(String destination) {
		if (!graph.containsKey(destination)) {
			throw new IllegalArgumentException("Invalid Destination, " + destination);
		} else {
			Graph.temp = new ArrayList<String>();
			return graph.get(destination).printPath();
		}
	}

	/**
	 * Helper method to get the cost of the vertices taken from stratingPoint to
	 * destination
	 * 
	 * @param destination
	 * @return cost
	 */
	public int printCost(String destination) {
		if (!graph.containsKey(destination)) {
			throw new IllegalArgumentException("Invalid Destination, " + destination);
		} else {
			Graph.cost = 0;
			return graph.get(destination).printCost();
		}
	}
}
