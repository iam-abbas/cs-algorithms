package edu.metrostate.ics340.p4.msr812;

public class GraphNode {

	private String src;
	private String dest;
	private int weight;

	GraphNode(String src, String dest, int weight) {
		this.src = src;
		this.dest = dest;
		this.weight = weight;
	}

	public String getSrc() {
		return src;
	}

	public String getDest() {
		return dest;
	}

	public int getWeight() {
		return weight;
	}

	@Override
	public String toString() {
		return this.src + " " + this.dest + " " + this.weight;
	}
}
