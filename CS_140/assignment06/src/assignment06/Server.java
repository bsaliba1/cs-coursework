package assignment06;

public class Server {
	private MComp allMenus;

	public Server (MComp aAllMenus) {
		this.allMenus = aAllMenus;
	}
	public void printMenu() {
		System.out.print(allMenus);
	}
	public void printVegetarianMenu() {
		System.out.println("\n"+ "VEGETARIANMENU"+"\n"+"-----");
		for(MComp comp: allMenus) {
			if(comp instanceof MenuItem) {
				System.out.println(comp);
			}
		}
	}
	public static MenuItem cheapest(MComp menus) {
		MenuItem cheapest = null;
		for(MComp comp: menus) {
			if(comp instanceof MenuItem) {
				if(cheapest == null) {
					cheapest = (MenuItem)comp;
				}else {
					if(cheapest.getPrice()>comp.getPrice()) {
						cheapest = (MenuItem)comp;
					}
				}
			}
		}
		return cheapest;
	}
	public static MenuItem greatest(MComp menus) {
		MenuItem greatest = null;
		for(MComp comp: menus) {
			if(comp instanceof MenuItem) {
				if(greatest == null) {
					greatest = (MenuItem)comp;
				}else {
					if(greatest.getPrice()<comp.getPrice()) {
						greatest = (MenuItem)comp;
					}
				}
			}
		}
		return greatest;
	}
	public static MenuItem longestDescr(Menu menus) {
		MenuItem longDesc = null;//(MenuItem)menus.getChild(0);
		for(MComp comp: menus) {
			if(comp instanceof MenuItem) {
				if(longDesc == null) {
					longDesc = (MenuItem)comp;
				}else {
					if(longDesc.getDescription().length()<comp.getDescription().length()) {
						longDesc = (MenuItem)comp;
					}
				}
			}
		}
		return longDesc;
	}
}