import static org.junit.jupiter.api.Assertions.assertArrayEquals;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

import org.junit.jupiter.api.Test;

import DroneRouter;

class DroneRouterTest {

	@Test
	void test() {
		Router router = new DroneRouter();
		router.loadRoutes("routes0.txt", "A");
		assertArrayEquals(new String[] { "A", "B", "G" }, router.getRoute("G"));
		assertEquals(17, router.getPathCost("G"));
		assertThrows(IllegalArgumentException.class, () -> router.getRoute("Z"));
		assertArrayEquals(new String[] {}, router.getRoute("M"));
		assertEquals(Router.NO_ROUTE, router.getPathCost("M"));
	}

	@Test
	void test2() {
		Router router = new DroneRouter();
		router.loadRoutes("routes1.txt", "CHI");
		assertArrayEquals(new String[] { "CHI", "MSP", "DEN", "LAS" }, router.getRoute("LAS"));
		assertEquals(2600, router.getPathCost("DEN"));
		assertThrows(IllegalArgumentException.class, () -> router.getRoute("Z"));
		assertArrayEquals(new String[] {}, router.getRoute("STP"));
		assertEquals(Router.NO_ROUTE, router.getPathCost("STP"));
	}
}
