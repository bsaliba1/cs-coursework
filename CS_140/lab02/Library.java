package lab02;
public class Library{
	
	public static void main(String[] args){
		//create array
		Book[] library = new Book[3];
		//create 3 book objects and add to array		
		library[0] = new Book("Bible",650);
		library[1] = new Book("Kite Runner", 450);
		library[2] = new Book("Lightning Thief", 350);
		//print titles
		for (Book currentElement: library){
			System.out.println(currentElement.getTitle());
		}
		for (Book currentElement: library){
			System.out.println(currentElement.getNumPages());
		}
		//Print out expected vs actual
		System.out.println("Expected # pages is 1450");
		System.out.println(numPagesInLibrary(library));
		//Test mostPages() method
		System.out.println("Expected # is 650");
		System.out.println(mostPages(library));	
	}
	public static int numPagesInLibrary(Book[] books){ 
		int pages= 0;		
		for (Book currentElement : books){
			pages = pages + currentElement.getNumPages();
		}		
		return pages;	
	}
	public static int mostPages(Book[] books){
		int pages = 0;
		for (Book currentElement : books){
			if (pages<currentElement.getNumPages()){
				pages = currentElement.getNumPages();
			}
		}
		return pages;
	}
}
