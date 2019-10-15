/**
 * @author Ralph A Foy
 *
 */
public interface Router {

	/**
	 * Value indicating there is no path from the source to the specified
	 * destination
	 */
	int NO_ROUTE = -1;

	/**
	 * Loads the file containing waypoints pairs and the cost to travel between
	 * them.
	 * 
	 * @param routesFilePath path to the routes file
	 * @param source         the waypoint that is the source location, that is, the
	 *                       starting point of all routs
	 * @throws IllegalArgumentException if the file is not accessible or the source
	 *                                  location does not exist
	 */
	void loadRoutes(String routesFilePath, String source);

	/**
	 * Returns the route from the designated source waypoint to the specified
	 * destination
	 * 
	 * @param destination endpoint of route
	 * @return array of waypoints representing the least expensive route from the
	 *         source to the destination (inclusive). The array is empty if no path
	 *         exists.
	 * @throws IllegalArgumentException if destination does not exist in the route
	 *                                  file
	 */
	String[] getRoute(String destination);

	/**
	 * Returns the cost of the shortest route from the designated source waypoint to
	 * the specified destination
	 * 
	 * @param destination endpoint of route from the source waypoint
	 * @return the cost in units, or {@link NO_ROUTE} if no route exists from the
	 *         source to the specified destination
	 * @throws IllegalArgumentException if destination does not exist in the route
	 *                                  file
	 * @throws NullPointerException     if destination is {@code null}
	 */
	int getPathCost(String destination);

}
