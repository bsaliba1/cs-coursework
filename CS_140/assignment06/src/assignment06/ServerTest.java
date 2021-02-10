package assignment06;
import static org.junit.jupiter.api.Assertions.*;

import org.junit.Before;
import org.junit.jupiter.api.Test;

class ServerTest {
	static Menu menu = null;
	static MenuItem tacoP;
	static MenuItem burgerB;
	static MenuItem fishT;
	@Before
	public void initialize() {
		tacoP = new MenuItem("Taco Popper","This is the one with the super dooper long description",
										true, 15.00);
		burgerB = new MenuItem("Burger Bites", "Short Description", false, 2.00);
		fishT = new MenuItem("Fish Tacos", "Short",false,1.00);

		menu = new Menu("Menu 1", "This is the menu");
		menu.add(tacoP);
		menu.add(burgerB);
		menu.add(fishT);
	}
	@Test
	void leastTest() {
		MenuItem tacoP = new MenuItem("Taco Popper","This is the one with the super dooper long description",
						true, 15.00);
		MenuItem burgerB = new MenuItem("Burger Bites", "Short Description", false, 2.00);
		MenuItem fishT = new MenuItem("Fish Tacos", "Short",false,1.00);

		menu = new Menu("Menu 1", "This is the menu");
		menu.add(tacoP);
		menu.add(burgerB);
		menu.add(fishT);
		try {
			assertEquals(fishT,Server.cheapest(menu));
		} catch(AssertionError e) {
			System.out.println(Server.cheapest(menu));
			System.out.println("least test failed");
			throw e;
		}
	}
	@Test
	void greatestTest() {
		MenuItem tacoP = new MenuItem("Taco Popper","This is the one with the super dooper long description",
				true, 15.00);
		MenuItem burgerB = new MenuItem("Burger Bites", "Short Description", false, 2.00);
		MenuItem fishT = new MenuItem("Fish Tacos", "Short",false,1.00);

		menu = new Menu("Menu 1", "This is the menu");
		menu.add(tacoP);
		menu.add(burgerB);
		menu.add(fishT);
		try {
			assertEquals(15.00,Server.greatest(menu).getPrice(),1e-5);
		} catch(AssertionError e) {
			System.out.println(Server.greatest(menu));
			System.out.println("greatest test failed");
			throw e;
		}
	}
	@Test
	void longestTest() {
		MenuItem tacoP = new MenuItem("Taco Popper","This is the one with the super dooper long description",
				true, 15.00);
		MenuItem burgerB = new MenuItem("Burger Bites", "Short Description", false, 2.00);
		MenuItem fishT = new MenuItem("Fish Tacos", "Short",false,1.00);

		menu = new Menu("Menu 1", "This is the menu");
		menu.add(tacoP);
		menu.add(burgerB);
		menu.add(fishT);
		try {
			assertEquals("This is the one with the super dooper long description",Server.longestDescr(menu).getDescription());
		} catch(AssertionError e) {
			System.out.println(Server.longestDescr(menu).getDescription());
			System.out.println("longestDesc test failed");
			throw e;
		}
	}
}
