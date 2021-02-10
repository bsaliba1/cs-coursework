package assignment05;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;

public class NamesResource {
	private static Random ranGen = new Random();

	public static String getRandomLastName() {
		return lastNames[ranGen.nextInt(lastNames.length)];
	}

	public static String getRandomFirstName() {
		String name = "";
		if(Math.random() > 0.5) {
			name = maleFirstNames[ranGen.nextInt(maleFirstNames.length)];
		} else {
			name = femaleFirstNames[ranGen.nextInt(femaleFirstNames.length)];			
		}
		return name;
	}

	public static String getRandomID() {
		String id = "";
		long L;
		L = Math.abs(ranGen.nextLong())%1000000000;
		if (L < 100000000) {
			id = "0" + L;
		} else {
			id = "" + L;
		}
		return id;
	}

	public static String[] getRandomBirthPlace() {
		String[] retVal = new String[2];
		if (Math.random() < 0.1) {
			int i = ranGen.nextInt(capitalsList.size());
			retVal[0] = capitalsList.get(i);
			retVal[1] = capitals.get(retVal[0]);
		} else {
			retVal[0] = townNames[ranGen.nextInt(townNames.length)]+ ", NY";
			retVal[1] = "USA";
		}
		return retVal;
	}

	public static LocalDate getRandomBirthDate(int maxYear) {
		long minDay = LocalDate.of(1970, 1, 1).toEpochDay();
		long maxDay = LocalDate.of(maxYear, 12, 31).toEpochDay();
		long randomDay = ThreadLocalRandom.current().nextLong(minDay, maxDay);
		return LocalDate.ofEpochDay(randomDay);
	}

	/**
	 * Method will generate an array of random Date objects,
	 * given certain parameters. The years parameter
	 * indicate which years to use and the howMany
	 * parameter indicates how many of each year to
	 * put into the output. The intention is that
	 * if N = years.length, then N = howMany.length. 
	 * The number of LocalDates in the output will be:
	 * howMany[0]+howMany[1]+...+howMany[N]. 
	 * If years.length and howMany.length are different
	 * the extra elements will be ignored and the output
	 * will be shorter.
	 * Example: 
	 * int[] y = {1990, 1989, 1987};
	 * int[] num = {2, 2, 3};
	 * LocalDate[] dates = NamesResource.getDateArray(y, num);
	 * This code will make dates and array of length 7
	 * consisting of 2 dates from 1990, 2 dates from
	 * 1989 and 3 dates from 1987.
	 * NOTE: the method throws NullPointerException if either
	 * array parameter is null.
	 * @param years array of years for the random dates
	 * @param howMany array giving number of each year to create  
	 * @return array of random LocalDates with the given 
	 * distribution of years
	 */
	public static LocalDate[] getDateArray(int[] years, int[] howMany) {
		int len = Math.min(years.length, howMany.length);
		int numDates = 0; 
		for(int i = 0; i < len; i++) {
			numDates += howMany[i];
		}
		LocalDate[] retVal = new LocalDate[numDates];
		int index = 0;
		for(int i = 0; i < len; i++) {
			for(int j = 0; j < howMany[i]; j++) {
				long minDay = LocalDate.of(years[i], 1, 1).toEpochDay();
				long maxDay = LocalDate.of(years[i], 12, 31).toEpochDay();
				long randomDay = ThreadLocalRandom.current().nextLong(minDay, maxDay);
				retVal[index++] = LocalDate.ofEpochDay(randomDay);
			}
		}
		return retVal;
	}

	// Thanks to the mongabay website and the links:	
	// http://names.mongabay.com/1000.html
	// http://names.mongabay.com/male_names.htm
	// http://names.mongabay.com/female_names.htm
	// The 1000 most common last names in the USA
	private static String[] lastNames = {"Smith", "Johnson",
			"Williams", "Brown", "Jones", "Miller",
			"Davis", "Garcia", "Rodriguez", "Wilson",
			"Martinez", "Anderson", "Taylor", "Thomas",
			"Hernandez", "Moore", "Martin", "Jackson",
			"Thompson", "White", "Lopez", "Lee", "Gonzalez",
			"Harris", "Clark", "Lewis", "Robinson", "Walker",
			"Perez", "Hall", "Young", "Allen", "Sanchez",
			"Wright", "King", "Scott", "Green", "Baker",
			"Adams", "Nelson", "Hill", "Ramirez", "Campbell",
			"Mitchell", "Roberts", "Carter", "Phillips",
			"Evans", "Turner", "Torres", "Parker", "Collins",
			"Edwards", "Stewart", "Flores", "Morris", "Nguyen",
			"Murphy", "Rivera", "Cook", "Rogers", "Morgan",
			"Peterson", "Cooper", "Reed", "Bailey", "Bell",
			"Gomez", "Kelly", "Howard", "Ward", "Cox", "Diaz",
			"Richardson", "Wood", "Watson", "Brooks", "Bennett",
			"Gray", "James", "Reyes", "Cruz", "Hughes", "Price",
			"Myers", "Long", "Foster", "Sanders", "Ross",
			"Morales", "Powell", "Sullivan", "Russell",
			"Ortiz", "Jenkins", "Gutierrez", "Perry",
			"Butler", "Barnes", "Fisher", "Henderson",
			"Coleman", "Simmons", "Patterson", "Jordan",
			"Reynolds", "Hamilton", "Graham", "Kim", "Gonzales",
			"Alexander", "Ramos", "Wallace", "Griffin", "West",
			"Cole", "Hayes", "Chavez", "Gibson", "Bryant",
			"Ellis", "Stevens", "Murray", "Ford", "Marshall",
			"Owens", "Mcdonald", "Harrison", "Ruiz", "Kennedy",
			"Wells", "Alvarez", "Woods", "Mendoza", "Castillo",
			"Olson", "Webb", "Washington", "Tucker", "Freeman",
			"Burns", "Henry", "Vasquez", "Snyder", "Simpson",
			"Crawford", "Jimenez", "Porter", "Mason", "Shaw",
			"Gordon", "Wagner", "Hunter", "Romero", "Hicks",
			"Dixon", "Hunt", "Palmer", "Robertson", "Black",
			"Holmes", "Stone", "Meyer", "Boyd", "Mills",
			"Warren", "Fox", "Rose", "Rice", "Moreno",
			"Schmidt", "Patel", "Ferguson", "Nichols",
			"Herrera", "Medina", "Ryan", "Fernandez", "Weaver",
			"Daniels", "Stephens", "Gardner", "Payne", "Kelley",
			"Dunn", "Pierce", "Arnold", "Tran", "Spencer",
			"Peters", "Hawkins", "Grant", "Hansen", "Castro",
			"Hoffman", "Hart", "Elliott", "Cunningham",
			"Knight", "Bradley", "Carroll", "Hudson", "Duncan",
			"Armstrong", "Berry", "Andrews", "Johnston", "Ray",
			"Lane", "Riley", "Carpenter", "Perkins", "Aguilar",
			"Silva", "Richards", "Willis", "Matthews",
			"Chapman", "Lawrence", "Garza", "Vargas",
			"Watkins", "Wheeler", "Larson", "Carlson",
			"Harper", "George", "Greene", "Burke", "Guzman",
			"Morrison", "Munoz", "Jacobs", "O'Brien", "Lawson",
			"Franklin", "Lynch", "Bishop", "Carr", "Salazar",
			"Austin", "Mendez", "Gilbert", "Jensen",
			"Williamson", "Montgomery", "Harvey", "Oliver",
			"Howell", "Dean", "Hanson", "Weber", "Garrett",
			"Sims", "Burton", "Fuller", "Soto", "Mccoy",
			"Welch", "Chen", "Schultz", "Walters", "Reid",
			"Fields", "Walsh", "Little", "Fowler", "Bowman",
			"Davidson", "May", "Day", "Schneider", "Newman",
			"Brewer", "Lucas", "Holland", "Wong", "Banks",
			"Santos", "Curtis", "Pearson", "Delgado", "Valdez",
			"Pena", "Rios", "Douglas", "Sandoval", "Barrett",
			"Hopkins", "Keller", "Guerrero", "Stanley", "Bates",
			"Alvarado", "Beck", "Ortega", "Wade", "Estrada",
			"Contreras", "Barnett", "Caldwell", "Santiago",
			"Lambert", "Powers", "Chambers", "Nunez", "Craig",
			"Leonard", "Lowe", "Rhodes", "Byrd", "Gregory",
			"Shelton", "Frazier", "Becker", "Maldonado",
			"Fleming", "Vega", "Sutton", "Cohen", "Jennings",
			"Parks", "Mcdaniel", "Watts", "Barker", "Norris",
			"Vaughn", "Vazquez", "Holt", "Schwartz", "Steele",
			"Benson", "Neal", "Dominguez", "Horton", "Terry",
			"Wolfe", "Hale", "Lyons", "Graves", "Haynes",
			"Miles", "Park", "Warner", "Padilla", "Bush",
			"Thornton", "Mccarthy", "Mann", "Zimmerman",
			"Erickson", "Fletcher", "Mckinney", "Page",
			"Dawson", "Joseph", "Marquez", "Reeves", "Klein",
			"Espinoza", "Baldwin", "Moran", "Love", "Robbins",
			"Higgins", "Ball", "Cortez", "Le", "Griffith",
			"Bowen", "Sharp", "Cummings", "Ramsey", "Hardy",
			"Swanson", "Barber", "Acosta", "Luna", "Chandler",
			"Blair", "Daniel", "Cross", "Simon", "Dennis",
			"O'Connor", "Quinn", "Gross", "Navarro", "Moss",
			"Fitzgerald", "Doyle", "Mclaughlin", "Rojas",
			"Rodgers", "Stevenson", "Singh", "Yang", "Figueroa",
			"Harmon", "Newton", "Paul", "Manning", "Garner",
			"Mcgee", "Reese", "Francis", "Burgess", "Adkins",
			"Goodman", "Curry", "Brady", "Christensen", "Potter",
			"Walton", "Goodwin", "Mullins", "Molina", "Webster",
			"Fischer", "Campos", "Avila", "Sherman", "Todd",
			"Chang", "Blake", "Malone", "Wolf", "Hodges",
			"Juarez", "Gill", "Farmer", "Hines", "Gallagher",
			"Duran", "Hubbard", "Cannon", "Miranda", "Wang",
			"Saunders", "Tate", "Mack", "Hammond", "Carrillo",
			"Townsend", "Wise", "Ingram", "Barton", "Mejia",
			"Ayala", "Schroeder", "Hampton", "Rowe", "Parsons",
			"Frank", "Waters", "Strickland", "Osborne",
			"Maxwell", "Chan", "Deleon", "Norman", "Harrington",
			"Casey", "Patton", "Logan", "Bowers", "Mueller",
			"Glover", "Floyd", "Hartman", "Buchanan", "Cobb",
			"French", "Kramer", "Mccormick", "Clarke", "Tyler",
			"Gibbs", "Moody", "Conner", "Sparks", "Mcguire",
			"Leon", "Bauer", "Norton", "Pope", "Flynn",
			"Hogan", "Robles", "Salinas", "Yates", "Lindsey",
			"Lloyd", "Marsh", "Mcbride", "Owen", "Solis",
			"Pham", "Lang", "Pratt", "Lara", "Brock", "Ballard",
			"Trujillo", "Shaffer", "Drake", "Roman", "Aguirre",
			"Morton", "Stokes", "Lamb", "Pacheco", "Patrick",
			"Cochran", "Shepherd", "Cain", "Burnett", "Hess",
			"Li", "Cervantes", "Olsen", "Briggs", "Ochoa",
			"Cabrera", "Velasquez", "Montoya", "Roth", "Meyers",
			"Cardenas", "Fuentes", "Weiss", "Hoover", "Wilkins",
			"Nicholson", "Underwood", "Short", "Carson",
			"Morrow", "Colon", "Holloway", "Summers", "Bryan",
			"Petersen", "Mckenzie", "Serrano", "Wilcox",
			"Carey", "Clayton", "Poole", "Calderon", "Gallegos",
			"Greer", "Rivas", "Guerra", "Decker", "Collier",
			"Wall", "Whitaker", "Bass", "Flowers", "Davenport",
			"Conley", "Houston", "Huff", "Copeland", "Hood",
			"Monroe", "Massey", "Roberson", "Combs", "Franco",
			"Larsen", "Pittman", "Randall", "Skinner",
			"Wilkinson", "Kirby", "Cameron", "Bridges",
			"Anthony", "Richard", "Kirk", "Bruce", "Singleton",
			"Mathis", "Bradford", "Boone", "Abbott", "Charles",
			"Allison", "Sweeney", "Atkinson", "Horn",
			"Jefferson", "Rosales", "York", "Christian",
			"Phelps", "Farrell", "Castaneda", "Nash",
			"Dickerson", "Bond", "Wyatt", "Foley", "Chase",
			"Gates", "Vincent", "Mathews", "Hodge", "Garrison",
			"Trevino", "Villarreal", "Heath", "Dalton",
			"Valencia", "Callahan", "Hensley", "Atkins",
			"Huffman", "Roy", "Boyer", "Shields", "Lin",
			"Hancock", "Grimes", "Glenn", "Cline", "Delacruz",
			"Camacho", "Dillon", "Parrish", "O'Neill", "Melton",
			"Booth", "Kane", "Berg", "Harrell", "Pitts",
			"Savage", "Wiggins", "Brennan", "Salas", "Marks",
			"Russo", "Sawyer", "Baxter", "Golden", "Hutchinson",
			"Liu", "Walter", "Mcdowell", "Wiley", "Rich",
			"Humphrey", "Johns", "Koch", "Suarez", "Hobbs",
			"Beard", "Gilmore", "Ibarra", "Keith", "Macias",
			"Khan", "Andrade", "Ware", "Stephenson", "Henson",
			"Wilkerson", "Dyer", "Mcclure", "Blackwell",
			"Mercado", "Tanner", "Eaton", "Clay", "Barron",
			"Beasley", "O'Neal", "Preston", "Small", "Wu",
			"Zamora", "Macdonald", "Vance", "Snow", "Mcclain",
			"Stafford", "Orozco", "Barry", "English", "Shannon",
			"Kline", "Jacobson", "Woodard", "Huang", "Kemp",
			"Mosley", "Prince", "Merritt", "Hurst", "Villanueva",
			"Roach", "Nolan", "Lam", "Yoder", "Mccullough",
			"Lester", "Santana", "Valenzuela", "Winters",
			"Barrera", "Leach", "Orr", "Berger", "Mckee",
			"Strong", "Conway", "Stein", "Whitehead", "Bullock",
			"Escobar", "Knox", "Meadows", "Solomon", "Velez",
			"O'Donnell", "Kerr", "Stout", "Blankenship",
			"Browning", "Kent", "Lozano", "Bartlett", "Pruitt",
			"Buck", "Barr", "Gaines", "Durham", "Gentry",
			"Mcintyre", "Sloan", "Melendez", "Rocha", "Herman",
			"Sexton", "Moon", "Hendricks", "Rangel", "Stark",
			"Lowery", "Hardin", "Hull", "Sellers", "Ellison",
			"Calhoun", "Gillespie", "Mora", "Knapp", "Mccall",
			"Morse", "Dorsey", "Weeks", "Nielsen", "Livingston",
			"Leblanc", "Mclean", "Bradshaw", "Glass",
			"Middleton", "Buckley", "Schaefer", "Frost",
			"Howe", "House", "Mcintosh", "Ho", "Pennington",
			"Reilly", "Hebert", "Mcfarland", "Hickman", "Noble",
			"Spears", "Conrad", "Arias", "Galvan", "Velazquez",
			"Huynh", "Frederick", "Randolph", "Cantu",
			"Fitzpatrick", "Mahoney", "Peck", "Villa",
			"Michael", "Donovan", "Mcconnell", "Walls",
			"Boyle", "Mayer", "Zuniga", "Giles", "Pineda",
			"Pace", "Hurley", "Mays", "Mcmillan", "Crosby",
			"Ayers", "Case", "Bentley", "Shepard", "Everett",
			"Pugh", "David", "Mcmahon", "Dunlap", "Bender",
			"Hahn", "Harding", "Acevedo", "Raymond", "Blackburn",
			"Duffy", "Landry", "Dougherty", "Bautista", "Shah",
			"Potts", "Arroyo", "Valentine", "Meza", "Gould",
			"Vaughan", "Fry", "Rush", "Avery", "Herring",
			"Dodson", "Clements", "Sampson", "Tapia", "Bean",
			"Lynn", "Crane", "Farley", "Cisneros", "Benton",
			"Ashley", "Mckay", "Finley", "Best", "Blevins",
			"Friedman", "Moses", "Sosa", "Blanchard", "Huber",
			"Frye", "Krueger", "Bernard", "Rosario", "Rubio",
			"Mullen", "Benjamin", "Haley", "Chung", "Moyer",
			"Choi", "Horne", "Yu", "Woodward", "Ali",
			"Nixon", "Hayden", "Rivers", "Estes", "Mccarty",
			"Richmond", "Stuart", "Maynard", "Brandt",
			"O'Connell", "Hanna", "Sanford", "Sheppard",
			"Church", "Burch", "Levy", "Rasmussen", "Coffey",
			"Ponce", "Faulkner", "Donaldson", "Schmitt",
			"Novak", "Costa", "Montes", "Booker", "Cordova",
			"Waller", "Arellano", "Maddox", "Mata", "Bonilla",
			"Stanton", "Compton", "Kaufman", "Dudley",
			"Mcpherson", "Beltran", "Dickson", "Mccann",
			"Villegas", "Proctor", "Hester", "Cantrell",
			"Daugherty", "Cherry", "Bray", "Davila", "Rowland",
			"Levine", "Madden", "Spence", "Good", "Irwin",
			"Werner", "Krause", "Petty", "Whitney", "Baird",
			"Hooper", "Pollard", "Zavala", "Jarvis", "Holden",
			"Haas", "Hendrix", "Mcgrath", "Bird", "Lucero",
			"Terrell", "Riggs", "Joyce", "Mercer", "Rollins",
			"Galloway", "Duke", "Odom", "Andersen", "Downs",
			"Hatfield", "Benitez", "Archer", "Huerta", "Travis",
			"Mcneil", "Hinton", "Zhang", "Hays", "Mayo",
			"Fritz", "Branch", "Mooney", "Ewing", "Ritter",
			"Esparza", "Frey", "Braun", "Gay", "Riddle",
			"Haney", "Kaiser", "Holder", "Chaney", "Mcknight",
			"Gamble", "Vang", "Cooley", "Carney", "Cowan",
			"Forbes", "Ferrell", "Davies", "Barajas", "Shea",
			"Osborn", "Bright", "Cuevas", "Bolton", "Murillo",
			"Lutz", "Duarte", "Kidd", "Key", "Cooke"};
	private static String[] maleFirstNames = {
			"James", "John", "Robert", "Michael",
			"William", "David", "Richard", "Charles", "Joseph",
			"Thomas", "Christopher", "Daniel", "Paul", "Mark",
			"Donald", "George", "Kenneth", "Steven", "Edward",
			"Brian", "Ronald", "Anthony", "Kevin", "Jason",
			"Matthew", "Gary", "Timothy", "Jose", "Larry", "Jeffrey",
			"Frank", "Scott", "Eric", "Stephen", "Andrew", "Raymond",
			"Gregory", "Joshua", "Jerry", "Dennis", "Walter",
			"Patrick", "Peter", "Harold", "Douglas", "Henry", "Carl",
			"Arthur", "Ryan", "Roger", "Joe", "Juan", "Jack",
			"Albert", "Jonathan", "Justin", "Terry", "Gerald",
			"Keith", "Samuel", "Willie", "Ralph", "Lawrence",
			"Nicholas", "Roy", "Benjamin", "Bruce", "Brandon", "Adam",
			"Harry", "Fred", "Wayne", "Billy", "Steve", "Louis",
			"Jeremy", "Aaron", "Randy", "Howard", "Eugene",	"Carlos",
			"Russell", "Bobby", "Victor", "Martin", "Ernest",
			"Phillip", "Todd", "Jesse", "Craig", "Alan", "Shawn",
			"Clarence", "Sean", "Philip", "Chris", "Johnny", "Earl",
			"Jimmy", "Antonio", "Danny", "Bryan", "Tony", "Luis",
			"Mike", "Stanley", "Leonard", "Nathan", "Dale", "Manuel",
			"Rodney", "Curtis", "Norman", "Allen", "Marvin",
			"Vincent", "Glenn", "Jeffery", "Travis", "Jeff", "Chad",
			"Jacob", "Lee", "Melvin", "Alfred", "Kyle", "Francis",
			"Bradley", "Jesus", "Herbert", "Frederick", "Ray", "Joel",
			"Edwin", "Don", "Eddie", "Ricky", "Troy", "Randall",
			"Barry", "Alexander", "Bernard", "Mario", "Leroy",
			"Francisco", "Marcus", "Micheal", "Theodore", "Clifford",
			"Miguel", "Oscar", "Jay", "Jim", "Tom", "Calvin", "Alex",
			"Jon", "Ronnie", "Bill", "Lloyd", "Tommy", "Leon",
			"Derek", "Warren", "Darrell", "Jerome", "Floyd", "Leo",
			"Alvin", "Tim", "Wesley", "Gordon", "Dean", "Greg",
			"Jorge", "Dustin", "Pedro", "Derrick", "Dan", "Lewis",
			"Zachary", "Corey", "Herman", "Maurice", "Vernon",
			"Roberto", "Clyde", "Glen", "Hector", "Shane", "Ricardo",
			"Sam", "Rick", "Lester", "Brent", "Ramon", "Charlie",
			"Tyler", "Gilbert", "Gene", "Marc", "Reginald", "Ruben",
			"Brett", "Angel", "Nathaniel", "Rafael", "Leslie",
			"Edgar", "Milton", "Raul", "Ben", "Chester", "Cecil",
			"Duane", "Franklin", "Andre", "Elmer", "Brad", "Gabriel",
			"Ron", "Mitchell", "Roland", "Arnold", "Harvey", "Jared",
			"Adrian", "Karl", "Cory", "Claude", "Erik", "Darryl",
			"Jamie", "Neil", "Jessie", "Christian", "Javier",
			"Fernando", "Clinton", "Ted", "Mathew", "Tyrone",
			"Darren", "Lonnie", "Lance", "Cody", "Julio", "Kelly",
			"Kurt", "Allan", "Nelson", "Guy", "Clayton", "Hugh",
			"Max", "Dwayne", "Dwight", "Armando", "Felix", "Jimmie",
			"Everett", "Jordan", "Ian", "Wallace", "Ken", "Bob",
			"Jaime", "Casey", "Alfredo", "Alberto", "Dave", "Ivan",
			"Johnnie", "Sidney", "Byron", "Julian", "Isaac", "Morris",
			"Clifton", "Willard", "Daryl", "Ross", "Virgil", "Andy",
			"Marshall", "Salvador", "Perry", "Kirk", "Sergio",
			"Marion", "Tracy", "Seth", "Kent", "Terrance", "Rene",
			"Eduardo", "Terrence", "Enrique", "Freddie", "Wade"};
	private static String[] femaleFirstNames = {"Mary", "Patricia", "Linda",
			"Barbara", "Elizabeth", "Jennifer", "Maria", "Susan",
			"Margaret", "Dorothy", "Lisa", "Nancy", "Karen",
			"Betty", "Helen", "Sandra", "Donna", "Carol", "Ruth",
			"Sharon", "Michelle", "Laura", "Sarah", "Kimberly",
			"Deborah", "Jessica", "Shirley", "Cynthia", "Angela",
			"Melissa", "Brenda", "Amy", "Anna", "Rebecca",
			"Virginia", "Kathleen", "Pamela", "Martha", "Debra",
			"Amanda", "Stephanie", "Carolyn", "Christine", "Marie",
			"Janet", "Catherine", "Frances", "Ann", "Joyce", "Diane",
			"Alice", "Julie", "Heather", "Teresa", "Doris", "Gloria",
			"Evelyn", "Jean", "Cheryl", "Mildred", "Katherine",
			"Joan", "Ashley", "Judith", "Rose", "Janice", "Kelly",
			"Nicole", "Judy", "Christina", "Kathy", "Theresa",
			"Beverly", "Denise", "Tammy", "Irene", "Jane", "Lori",
			"Rachel", "Marilyn", "Andrea", "Kathryn", "Louise",
			"Sara", "Anne", "Jacqueline", "Wanda", "Bonnie", "Julia",
			"Ruby", "Lois", "Tina", "Phyllis", "Norma", "Paula",
			"Diana", "Annie", "Lillian", "Emily", "Robin", "Peggy",
			"Crystal", "Gladys", "Rita", "Dawn", "Connie", "Florence",
			"Tracy", "Edna", "Tiffany", "Carmen", "Rosa", "Cindy",
			"Grace", "Wendy", "Victoria", "Edith", "Kim", "Sherry",
			"Sylvia", "Josephine", "Thelma", "Shannon", "Sheila",
			"Ethel", "Ellen", "Elaine", "Marjorie", "Carrie",
			"Charlotte", "Monica", "Esther", "Pauline", "Emma",
			"Juanita", "Anita", "Rhonda", "Hazel", "Amber", "Eva",
			"Debbie", "April", "Leslie", "Clara", "Lucille", "Jamie",
			"Joanne", "Eleanor", "Valerie", "Danielle", "Megan",
			"Alicia", "Suzanne", "Michele", "Gail", "Bertha",
			"Darlene", "Veronica", "Jill", "Erin", "Geraldine",
			"Lauren", "Cathy", "Joann", "Lorraine", "Lynn", "Sally",
			"Regina", "Erica", "Beatrice", "Dolores", "Bernice",
			"Audrey", "Yvonne", "Annette", "June", "Samantha",
			"Marion", "Dana", "Stacy", "Ana", "Renee", "Ida",
			"Vivian", "Roberta", "Holly", "Brittany", "Melanie",
			"Loretta", "Yolanda", "Jeanette", "Laurie", "Katie",
			"Kristen", "Vanessa", "Alma", "Sue", "Elsie", "Beth",
			"Jeanne", "Vicki", "Carla", "Tara", "Rosemary", "Eileen",
			"Terri", "Gertrude", "Lucy", "Tonya", "Ella", "Stacey",
			"Wilma", "Gina", "Kristin", "Jessie", "Natalie", "Agnes",
			"Vera", "Willie", "Charlene", "Bessie", "Delores",
			"Melinda", "Pearl", "Arlene", "Maureen", "Colleen",
			"Allison", "Tamara", "Joy", "Georgia", "Constance",
			"Lillie", "Claudia", "Jackie", "Marcia", "Tanya",
			"Nellie", "Minnie", "Marlene", "Heidi", "Glenda",
			"Lydia", "Viola", "Courtney", "Marian", "Stella",
			"Caroline", "Dora", "Jo", "Vickie", "Mattie", "Terry",
			"Maxine", "Irma", "Mabel", "Marsha", "Myrtle", "Lena",
			"Christy", "Deanna", "Patsy", "Hilda", "Gwendolyn",
			"Jennie", "Nora", "Margie", "Nina", "Cassandra", "Leah",
			"Penny", "Kay", "Priscilla", "Naomi", "Carole", "Brandy",
			"Olga", "Billie", "Dianne", "Tracey", "Leona", "Jenny",
			"Felicia", "Sonia", "Miriam", "Velma", "Becky", "Bobbie",
			"Violet", "Kristina", "Toni", "Misty", "Mae", "Shelly",
			"Daisy", "Ramona", "Sherri", "Erika", "Katrina", "Claire",
			"Lindsey", "Lindsay", "Geneva", "Guadalupe", "Belinda",
			"Margarita", "Sheryl", "Cora", "Faye", "Ada", "Natasha",
			"Sabrina", "Isabel", "Marguerite", "Hattie", "Harriet",
			"Molly", "Cecilia", "Kristi", "Brandi", "Blanche",
			"Sandy", "Rosie", "Joanna", "Iris", "Eunice", "Angie",
			"Inez", "Lynda", "Madeline", "Amelia", "Alberta",
			"Genevieve", "Monique", "Jodi", "Janie", "Maggie",
			"Kayla", "Sonya", "Jan", "Lee", "Kristine", "Candace",
			"Fannie", "Maryann", "Opal", "Alison", "Yvette", "Melody",
			"Luz", "Susie", "Olivia", "Flora", "Shelley", "Kristy",
			"Mamie", "Lula", "Lola", "Verna", "Beulah", "Antoinette",
			"Candice", "Juana", "Jeannette", "Pam", "Kelli", "Hannah",
			"Whitney", "Bridget", "Karla", "Celia", "Latoya", "Patty",
			"Shelia", "Gayle", "Della", "Vicky", "Lynne", "Sheri",
			"Marianne", "Kara", "Jacquelyn", "Erma", "Blanca", "Myra",
			"Leticia", "Pat", "Krista", "Roxanne", "Angelica",
			"Johnnie", "Robyn", "Francis", "Adrienne", "Rosalie",
			"Alexandra", "Brooke", "Bethany", "Sadie", "Bernadette",
			"Traci", "Jody", "Kendra", "Jasmine", "Nichole",
			"Rachael", "Chelsea", "Mable", "Ernestine", "Muriel",
			"Marcella", "Elena", "Krystal", "Angelina", "Nadine",
			"Kari", "Estelle", "Dianna", "Paulette", "Lora", "Mona",
			"Doreen", "Rosemarie", "Angel", "Desiree", "Antonia",
			"Hope", "Ginger", "Janis", "Betsy", "Christie", "Freda",
			"Mercedes", "Meredith", "Lynette", "Teri", "Cristina",
			"Eula", "Leigh", "Meghan", "Sophia", "Eloise", "Rochelle",
			"Gretchen", "Cecelia", "Raquel", "Henrietta", "Alyssa",
			"Jana", "Kelley", "Gwen", "Kerry", "Jenna", "Tricia",
			"Laverne", "Olive", "Alexis", "Tasha", "Silvia", "Elvira",
			"Casey", "Delia", "Sophie", "Kate", "Patti", "Lorena",
			"Kellie", "Sonja", "Lila", "Lana", "Darla", "May",
			"Mindy", "Essie", "Mandy", "Lorene", "Elsa", "Josefina",
			"Jeannie", "Miranda", "Dixie", "Lucia", "Marta", "Faith",
			"Lela", "Johanna", "Shari", "Camille", "Tami", "Shawna",
			"Elisa", "Ebony", "Melba", "Ora", "Nettie", "Tabitha",
			"Ollie", "Jaime", "Winifred", "Kristie", "Marina",
			"Alisha", "Aimee", "Rena", "Myrna", "Marla", "Tammie",
			"Latasha", "Bonita", "Patrice", "Ronda", "Sherrie",
			"Addie", "Francine", "Deloris", "Stacie", "Adriana",
			"Cheri", "Shelby", "Abigail", "Celeste", "Jewel", "Cara",
			"Adele", "Rebekah", "Lucinda", "Dorthy", "Chris", "Effie",
			"Trina", "Reba", "Shawn", "Sallie", "Aurora", "Lenora",
			"Etta", "Lottie", "Kerri", "Trisha", "Nikki", "Estella",
			"Francisca", "Josie", "Tracie", "Marissa", "Karin",
			"Brittney", "Janelle", "Lourdes", "Laurel", "Helene",
			"Fern", "Elva", "Corinne", "Kelsey", "Ina", "Bettie",
			"Elisabeth", "Aida", "Caitlin", "Ingrid", "Iva",
			"Eugenia", "Christa", "Goldie", "Cassie", "Maude",
			"Jenifer", "Therese", "Frankie", "Dena", "Lorna",
			"Janette", "Latonya", "Candy", "Morgan", "Consuelo",
			"Tamika", "Rosetta", "Debora", "Cherie", "Polly", "Dina",
			"Jewell", "Fay", "Jillian", "Dorothea", "Nell", "Trudy",
			"Esperanza", "Patrica", "Kimberley", "Shanna", "Helena",
			"Carolina", "Cleo", "Stefanie", "Rosario", "Ola",
			"Janine", "Mollie", "Lupe", "Alisa", "Lou", "Maribel",
			"Susanne", "Bette", "Susana", "Elise", "Cecile",
			"Isabelle", "Lesley", "Jocelyn", "Paige", "Joni",
			"Rachelle", "Leola", "Daphne", "Alta", "Ester", "Petra",
			"Graciela", "Imogene", "Jolene", "Keisha", "Lacey",
			"Glenna", "Gabriela", "Keri", "Ursula", "Lizzie",
			"Kirsten", "Shana", "Adeline", "Mayra", "Jayne",
			"Jaclyn", "Gracie", "Sondra", "Carmela", "Marisa",
			"Rosalind", "Charity", "Tonia", "Beatriz", "Marisol",
			"Clarice", "Jeanine", "Sheena", "Angeline", "Frieda",
			"Lily", "Robbie", "Shauna", "Millie", "Claudette",
			"Cathleen", "Angelia", "Gabrielle", "Autumn", "Katharine",
			"Summer", "Jodie", "Staci", "Lea", "Christi", "Jimmie",
			"Justine", "Elma", "Luella", "Margret", "Dominique",
			"Socorro", "Rene", "Martina", "Margo", "Mavis", "Callie",
			"Bobbi", "Maritza", "Lucile", "Leanne", "Jeannine",
			"Deana", "Aileen", "Lorie", "Ladonna", "Willa", "Manuela",
			"Gale", "Selma", "Dolly", "Sybil", "Abby", "Lara", "Dale",
			"Ivy", "Dee", "Winnie", "Marcy", "Luisa", "Jeri",
			"Magdalena", "Ofelia", "Meagan", "Audra", "Matilda",
			"Leila", "Cornelia", "Bianca", "Simone", "Bettye",
			"Randi", "Virgie", "Latisha", "Barbra", "Georgina",			
			"Eliza", "Leann", "Bridgette", "Rhoda", "Haley", "Adela",
			"Nola", "Bernadine", "Flossie", "Ila", "Greta", "Ruthie",
			"Nelda", "Minerva", "Lilly", "Terrie", "Letha", "Hilary",
			"Estela", "Valarie", "Brianna", "Rosalyn", "Earline",
			"Catalina", "Ava", "Mia", "Clarissa", "Lidia", "Corrine",
			"Alexandria", "Concepcion", "Tia", "Sharron", "Rae",
			"Dona", "Ericka", "Jami", "Elnora", "Chandra", "Lenore",
			"Neva", "Marylou", "Melisa", "Tabatha", "Serena", "Avis",
			"Allie", "Sofia", "Jeanie", "Odessa", "Nannie",
			"Harriett", "Loraine", "Penelope", "Milagros", "Emilia",
			"Benita", "Allyson", "Ashlee", "Tania", "Tommie",
			"Esmeralda", "Karina", "Eve", "Pearlie", "Zelma",
			"Malinda", "Noreen", "Tameka", "Saundra", "Hillary",
			"Amie", "Althea", "Rosalinda", "Jordan", "Lilia",
			"Alana", "Gay", "Clare", "Alejandra", "Elinor", "Michael",
			"Lorrie", "Jerri", "Darcy", "Earnestine", "Carmella",
			"Taylor", "Noemi", "Marcie", "Liza", "Annabelle",
			"Louisa", "Earlene", "Mallory", "Carlene", "Nita",
			"Selena", "Tanisha", "Katy", "Julianne", "John",
			"Lakisha", "Edwina", "Maricela", "Margery", "Kenya",
			"Dollie", "Roxie", "Roslyn", "Kathrine", "Nanette",
			"Charmaine", "Lavonne", "Ilene", "Kris", "Tammi",
			"Suzette", "Corine", "Kaye", "Jerry", "Merle", "Chrystal",
			"Lina", "Deanne", "Lilian", "Juliana", "Aline", "Luann",
			"Kasey", "Maryanne", "Evangeline", "Colette", "Melva",
			"Lawanda", "Yesenia", "Nadia", "Madge", "Kathie", "Eddie",
			"Ophelia", "Valeria", "Nona", "Mitzi", "Mari",
			"Georgette", "Claudine", "Fran", "Alissa", "Roseann",
			"Lakeisha", "Susanna", "Reva", "Deidre", "Chasity",
			"Sheree", "Carly", "James", "Elvia", "Alyce", "Deirdre",
			"Gena", "Briana", "Araceli", "Katelyn", "Rosanne",
			"Wendi", "Tessa", "Berta", "Marva", "Imelda", "Marietta",
			"Marci", "Leonor", "Arline", "Sasha", "Madelyn", "Janna",
			"Juliette", "Deena", "Aurelia", "Josefa", "Augusta",
			"Liliana", "Young", "Christian", "Lessie", "Amalia",
			"Savannah", "Anastasia", "Vilma", "Natalia", "Rosella",
			"Lynnette", "Corina", "Alfreda", "Leanna", "Carey",
			"Amparo", "Coleen", "Tamra", "Aisha", "Wilda", "Karyn",
			"Cherry", "Queen", "Maura", "Mai", "Evangelina",
			"Rosanna", "Hallie", "Erna", "Enid", "Mariana", "Lacy",
			"Juliet", "Jacklyn", "Freida", "Madeleine", "Mara",
			"Hester", "Cathryn", "Lelia", "Casandra", "Bridgett",
			"Angelita", "Jannie", "Dionne", "Annmarie", "Katina",
			"Beryl", "Phoebe", "Millicent", "Katheryn", "Diann",
			"Carissa", "Maryellen", "Liz", "Lauri", "Helga", "Gilda",
			"Adrian", "Rhea", "Marquita", "Hollie", "Tisha", "Tamera",
			"Angelique", "Francesca", "Britney", "Kaitlin", "Lolita",
			"Florine", "Rowena", "Reyna", "Twila", "Fanny", "Janell",
			"Ines", "Concetta", "Bertie", "Alba", "Brigitte",
			"Alyson", "Vonda", "Pansy", "Elba", "Noelle", "Letitia",
			"Kitty", "Deann", "Brandie", "Louella", "Leta", "Felecia",
			"Sharlene", "Lesa", "Beverley", "Robert", "Isabella",
			"Herminia", "Terra", "Celina"};
	// mixture of American and English road names from:
	// http://funky-facts.blogspot.com/2009/03/most-common-street-names-in-uk.html
	// http://everything2.com/title/most+common+street+names+in+the+U.S.
	private static String[] roadNames = {"High Street",
			"Station Road", "Main Street", "Park Road", "Church Road",
			"Church Street", "London Road", "Victoria Road", "Green Lane",
			"Manor Road", "Church Lane", "Park Avenue", "The Avenue",
			"The Crescent", "Queens Road", "New Road", "Grange Road",
			"Kings Road", "Kingsway", "Windsor Road", "Highfield Road",
			"Mill Lane", "Alexander Road", "York Road", "St. John's Road",
			"Main Road", "Broadway", "King Street", "The Green",
			"Springfield Road", "George Street", "Park Lane",
			"Victoria Street", "Albert Road", "Queensway", "New Street",
			"Queen Street", "West Street", "North Street",
			"Manchester Road", "The Grove", "Richmond Road", "Grove Road",
			"South Street", "School Lane", "The Drive", "North Road",
			"Stanley Road", "Chester Road", "Mill Road", "Park Street",
			"Washington Street", "Maple Street", "Oak Street",
			"Lincoln Street", "Walnut Street", "Elm Street",
			"Jefferson Street", "Highland Street", "Madison Street",
			"Pine Street", "Cedar Street", "Sunset Street",
			"Jackson Street", "Franklin Street", "Willow Street",
			"3rd Street", "Wilson Street", "2nd Street", "Laurel Street",
			"5th Street", "Chestnut Street", "4th Street", "Adams Street",
			"Virginia Street", "Linden Street", "Woodland Street",
			"Cherry Street", "Rose Street", "1st Street"};
	// List of town names in New York from
	// http://uscitynameslist.com/BBB New York.htm
	private static String[] townNames = {"Adams", "Afton", "Akron", "Albany",
			"Albertson", "Albion", "Alden", "Alexandria Bay", "Alfred",
			"Allegany", "Altamont", "Amagansett", "Amherst",
			"Amityville", "Amsterdam", "Ancram", "Andes", "Andover",
			"Angelica", "Angola", "Apalachin", "Appleton", "Aquebogue",
			"Arcade", "Ardsley", "Arkport", "Arkville", "Armonk",
			"Ashville", "Astoria", "Atlantic Beach", "Attica",
			"Au Sable Forks", "Auburn", "Averill Park", "Avon",
			"Babylon", "Bainbridge", "Baldwin", "Baldwinsville",
			"Ballston Lake", "Ballston Spa", "Batavia", "Bath",
			"Bay Shore", "Bayport", "Bayside", "Bayville", "Beacon",
			"Bearsville", "Bedford", "Bedford Hills", "Bellerose",
			"Bellmore", "Bellport", "Belmont", "Bemus Point", "Bergen",
			"Berlin", "Bethpage", "Big Flats", "Billings", "Binghamton",
			"Blauvelt", "Bloomfield", "Bloomingburg", "Bloomville",
			"Bohemia", "Bolivar", "Bolton Landing", "Boonville",
			"Boston", "Bowling Green", "Brasher Falls", "Brentwood",
			"Brewerton", "Brewster", "Briarcliff Manor",
			"Bridgehampton", "Brightwaters", "Broadalbin", "Brockport",
			"Brocton", "Bronx", "Bronxville", "Brooklyn", "Buchanan",
			"Buffalo", "Burnt Hills", "Cairo", "Caledonia",
			"Callicoon", "Calverton", "Cambria Heights", "Cambridge",
			"Camden", "Camillus", "Campbell Hall", "Canaan",
			"Canajoharie", "Canal Street", "Canandaigua", "Canastota",
			"Candor", "Canisteo", "Canton", "Carle Place", "Carmel",
			"Caroga Lake", "Carthage", "Castleton On Hudson", "Cato",
			"Catskill", "Cazenovia", "Cedarhurst", "Center Moriches",
			"Centereach", "Centerport", "Central Islip",
			"Central Square", "Central Valley", "Chappaqua", "Chatham",
			"Cheektowaga", "Chenango Bridge", "Cherry Valley",
			"Chester", "Chestertown", "Chittenango", "Churchville",
			"Cicero", "Clarence", "Clarksville", "Claverack",
			"Clayton", "Clifton Park", "Clifton Springs", "Climax",
			"Clinton", "Clinton Corners", "Clyde", "Clymer",
			"Cobleskill", "Coeymans", "Cohoes", "Cold Spring",
			"Cold Spring Harbor", "College Point", "Collins",
			"Commack", "Congers", "Cooperstown", "Copake", "Copiague",
			"Coram", "Corfu", "Corinth", "Corning", "Cornwall",
			"Cornwall On Hudson", "Corona", "Cortland", "Cortlandt",
			"anor", "Coxsackie", "Cross River", "Croton On Hudson",
			"Cuba", "Cutchogue", "Dansville", "Deansboro", "Deer Park",
			"Delanson", "Delevan", "Delhi", "Delmar", "Depew",
			"Deposit", "Derby", "Dexter", "Dix Hills", "Dobbs Ferry",
			"Dolgeville", "Douglaston", "Dover Plains", "Dryden",
			"Duanesburg", "Dundee", "Dunkirk", "Earlville",
			"East Amherst", "East Aurora", "East Bloomfield",
			"East Elmhurst", "East Greenbush", "East Hampton",
			"East Islip", "East Meadow", "East Moriches",
			"East Northport", "East Norwich", "East Quogue",
			"East Rochester", "East Rockaway", "East Setauket",
			"East Syracuse", "East Williston", "Eastchester", "Eden",
			"Edmeston", "Elbridge", "Eldred", "Elizabethtown",
			"Ellenville", "Ellicottville", "Elma", "Elmhurst",
			"Elmira", "Elmont", "Elmsford", "Endicott", "Fair Haven",
			"Fairport", "Falconer", "Far Rockaway", "Farmingdale",
			"Farmington", "Farmingville", "Fayetteville", "Ferndale",
			"Fillmore", "Findley Lake", "Fishers", "Fishkill",
			"Floral", " Park", "Florida", "Flushing", "Fly Creek",
			"Fonda", "Forest Hills", "Fort Covington", "Fort Edward",
			"Fort Plain", "Franklin Square", "Franklinville",
			"Fredonia", "Freeport", "Freeville", "Fresh Meadows",
			"Fulton", "Fultonham", "Fultonville", "Galway",
			"Gansevoort", "Garden City", "Garnerville", "Garrison",
			"Geneseo", "Geneva", "Germantown", "Getzville", "Ghent",
			"Gilbertsville", "Glasco", "Glen Cove", "Glen Falls",
			"Glen Head", "Glen Oaks", "Glendale", "Glenmont",
			"Glens Falls", "Glenville", "Gloversville",
			"Goldens Bridge", "Goshen", "Gouverneur", "Gowanda",
			"Grahamsville", "Grand Island", "Granville", "Great Neck",
			"Greene", "Greenlawn", "Greenport", "Greenvale",
			"Greenville", "Greenwich", "Greenwood", "Greenwood Lake",
			"Groton", "Guilderland", "Hague", "Halesite", "Hamburg",
			"Hamilton", "Hamlin", "Hammondsport", "Hampton Bays",
			"Hancock", "Harriman", "Harrison", "artsdale", "Hastings",
			"Hastings On Hudson", "Hauppauge", "Haverstraw",
			"Hawthorne", "Hempstead", "Henrietta", "Herkimer",
			"Hewlett", "Hicksville", "Highland", "Highland Falls",
			"Highland Mills", "Hillsdale", "Hilton", "Hogansburg",
			"Holbrook", "Holland", "Holland Patent", "Holley", "Hollis",
			"oltsville", "Homer", "Honeoye", "Honeoye Falls",
			"Hoosick Falls", "Hopewell Junction", "Hornell",
			"Horseheads", "Houghton", "Howard Beach", "Howells",
			"Hudson", "Hudson Falls", "Hunter", "Huntington",
			"Huntington Station", "Hurley", "Hyde Park", "Ilion",
			"Inlet", "Interlaken", "Inwood", "Irvington",
			"Island Park", "Islandia", "Islip", "Islip Terrace",
			"Ithaca", "Jackson Heights", "Jamaica", "Jamesport",
			"Jamestown", "Jeffersonville", "Jericho", "Johnson City",
			"Johnstown", "Jordan", "atonah", "Keeseville", "Kenmore",
			"Kew Gardens", "Kinderhook", "King Ferry", "Kings Park",
			"Kingston", "La Fayette", "Lagrangeville", "Lake George",
			"Lake Grove", "Lake Hill", "Lake Luzerne",
			"Lake Peekskill", "Lake Placid", "Lake Pleasant",
			"Lakeville", "Lakewood", "Lancaster", "Larchmont",
			"Latham", "Laurelton", "Lawrence", "Le Roy", "Levittown",
			"Lewiston", "Liberty", "Lima", "Lindenhurst",
			"Little Falls", "Little Neck", "Little Valley",
			"Liverpool", "Livingston Manor", "Livonia", "Lockport",
			"Locust Valley", "Lodi", "Long Beach", "Long Is City",
			"Long Island City", "Lowville", "Lynbrook", "Lyndonville",
			"Lyons", "Macedon", "Mahopac", "Malone", "Malverne",
			"Mamaroneck", "Manhasset", "Manhattan", "Manlius",
			"Marathon", "Marcellus", "Marcy", "Margaretville",
			"Marion", "Marlboro", "Maspeth", "Massapequa",
			"Massapequa Park", "Massena", "Mastic", "Mastic Beach",
			"Mattituck", "Mayville", "Mechanicville", "Medford",
			"Medina", "Melville", "Menands", "Mendon", "Merrick",
			"Mexico", "Middle Granville", "Middle Island",
			"Middle Village", "Middleburgh", "Middleport",
			"Middletown", "Millbrook", "Miller Place", "Millerton",
			"Millwood", "Milton", "Mineola", "Mohegan Lake", "Monroe",
			"Monsey", "Montauk", "Montgomery", "Monticello",
			"Montour Falls", "Montrose", "Moravia", "Morris",
			"Morristown", "Morrisville", "Mount Kisco", "Mount Morris",
			"Mount Sinai", "Mount Vernon", "Nanuet", "Naples",
			"Nassau", "Nesconset", "New Berlin", "New City",
			"New Hampton", "New Hartford", "New Hyde Park",
			"New Paltz", "New Rochelle", "New Windsor", "New York",
			"New York Mills", "Newark", "Newburgh", "Newport",
			"Newyork", "Niagara Falls", "Niskayuna", "North Babylon",
			"North Baldwin", "North Bellmore", "North Chatham",
			"North Chili", "North Collins", "North Greece",
			"North Salem", "North Tonawanda", "Northport",
			"Northville", "Norwich", "Norwood", "Nunda", "Nyack",
			"Oakdale", "Oakfield", "Oakland Gardens", "Oceanside",
			"Odessa", "Ogdensburg", "Old Bethpage", "Old Chatham",
			"Old Forge", "Old Westbury", "Olean", "Oneida", "Oneonta",
			"Ontario", "Orangeburg", "Orchard Park", "Oriskany",
			"Ossining", "Oswego", "Ovid", "Owego", "Oxford",
			"Oyster Bay", "Ozone Park", "Painted Post",
			"Palatine Bridge", "Palisades", "Palmyra", "Parishville",
			"Parksville", "Patchogue", "Patterson", "Pawling",
			"Pearl River", "Peekskill", "Pelham", "Penfield",
			"Penn Yan", "Perry", "Phelps", "Phoenix", "Piermont",
			"Pine Bush", "Pine Island", "Pine Plains", "Pittsford",
			"Plainview", "Plattsburgh", "Pleasant Valley",
			"Pleasantville", "Poestenkill", "Point Lookout", "Pomona",
			"Port Chester", "Port Ewen", "Port Jefferson",
			"Port Jefferson Sta", "Port Jefferson Station",
			"Port Jervis", "Port Washington", "Portville", "Potsdam",
			"Poughkeepsie", "Poughquag", "Pound Ridge", "Prattsburgh",
			"Pulaski", "Purchase", "Putnam Valley", "Queens Village",
			"Queensbury", "Randolph", "Ravena", "Red Creek", "Red Hook",
			"Rego Park", "Remsen", "Remsenburg", "Rensselaer",
			"Rexford", "Rhinebeck", "Richfield Springs",
			"Richmond Hill", "Ridgewood", "Riverhead", "Rochester",
			"Rock Hill", "Rockaway Park", "Rockville Centre",
			"Rocky Point", "Rome", "Ronkonkoma", "Roosevelt",
			"Rosedale", "Roseland", "Rosendale", "Roslyn",
			"Roslyn Heights", "Rouses Point", "Roxbury", "Rush",
			"Rushville", "Rye", "Rye Brook", "S Richmond Hl",
			"Sackets Harbor", "Sag Harbor", "Saint Albans",
			"Saint James", "Saint Johnsville", "Salamanca", "Salem",
			"Sands Point", "Saranac Lake", "Saratoga Springs",
			"Saugerties", "Sayville", "Scarsdale", "Schenectady",
			"Schenevus", "Schoharie", "Schuylerville", "Scottsville",
			"Sea Cliff", "Seafor", "Selden", "Seneca Falls",
			"Setauket", "Shelter Island", "Sherburne", "Sherman",
			"Sherrill", "Shirley", "Shoreham", "Shortsville", "Sidney",
			"Silver Creek", "Silver Springs", "Sinclairville",
			"Skaneateles", "Slate Hill", "Sleepy Hollow",
			"Slingerlands", "Smithtown", "Sodu", "Somers",
			"Sound Beach", "South Fallsburg", "South Glens Falls",
			"South Ozone Park", "South Richmond Hill", "South Salem",
			"South Setauket", "Southampton", "Southold", "Sparkill",
			"Speculator", "Spencer", "Spencerport", "Speonk",
			"Spring Valley", "Springfield Gardens", "Springville",
			"Staatsburg", "Stamford", "Stanfordville", "Stanley",
			"Staten Island", "Stephentown", "Stone Ridge",
			"Stony Brook", "Stony Point", "Suffern", "Sugar Loaf",
			"Sunnyside", "Sylvan Beach", "Syosset", "Syracuse",
			"Tallman", "Tannersville", "Tappan", "Tarrytown",
			"Theresa", "Thiells", "Thompson Ridge", "Thornwood",
			"Ticonderoga", "Tivoli", "Tonawanda", "Trinity", "Troy",
			"Trumansburg", "Tuckahoe", "Tully", "Tupper Lake",
			"Tuxedo Park", "Unadilla", "Uniondale", "Utica", "Valatie",
			"Valhalla", "Valley Cottage", "Valley ", "Stream",
			"Verbank", "Vernon", "Verplanck", "Vestal", "Victor",
			"Voorheesville", "Waccabuc", "Wading River", "Wainscott",
			"Walden", "Wallkill", "Walton", "Walworth", "Wampsville",
			"Wantagh", "Wappingers Falls", "Warsaw", "Warwick",
			"Washingtonville", "Water Mill", "Waterford", "Waterloo",
			"Watertown", "Waterville", "Watervliet", "Watkins Glen",
			"Waverly", "Wayland", "Webster", "Weedsport", "Wellsville",
			"West Babylon", "West Coxsackie", "West Fulton",
			"West Harrison", "West Haverstraw", "West Hempstead",
			"West Henrietta", "West Islip", "West Monroe",
			"West Nyack", "West Sand Lake", "West Sayville",
			"West Seneca", "West Valley", "West Winfield", "Westbury",
			"Westerlo", "Westfield", "Westhampton",
			"Westhampton Beach", "Westport", "White Plains",
			"Whitehall", "Whitesboro", "Whitestone", "Whitney Point",
			"Williamson", "Williamsville", "Williston Park",
			"Wilmington", "Wilson", "Windham", "Windsor", "Wolcott",
			"Woodbourn", "Woodbur", "Woodhaven", "Woodmere",
			"Woodridge", "Woodside", "Woodstock", "Worcester",
			"Wurtsboro", "Wykagyl", "Wynantskill", "Yaphank",
			"Yonkers", "Yorktown Heights", "Yorkville", "Youngstown"};

	private static ArrayList<String> capitalsList = new ArrayList<String>();

	private static Map<String, String> capitals = 
			new HashMap<String,String>();
	static {
		capitals.put("Abu Dhabi", "United Arab Emirates");
		capitals.put("Abuja", "Nigeria");
		capitals.put("Accra", "Ghana");
		capitals.put("Addis Ababa", "Ethiopia");
		capitals.put("Algiers", "Algeria");
		capitals.put("Amman", "Jordan");
		capitals.put("Amsterdam", "Netherlands");
		capitals.put("Andorra la Vella", "Andorra");
		capitals.put("Ankara", "Turkey");
		capitals.put("Antananarivo", "Madagascar");
		capitals.put("Apia", "Samoa");
		capitals.put("Ashgabat", "Turkmenistan");
		capitals.put("Asmara", "Eritrea");
		capitals.put("Astana", "Kazakhstan");
		capitals.put("Asuncion", "Paraguay");
		capitals.put("Athens", "Greece");
		capitals.put("Baghdad", "Iraq");
		capitals.put("Baku", "Azerbaijan");
		capitals.put("Bamako", "Mali");
		capitals.put("Bandar Seri Begawan", "Brunei");
		capitals.put("Bangkok", "Thailand");
		capitals.put("Bangui", "Central African Republic");
		capitals.put("Banjul", "Gambia");
		capitals.put("Basseterre", "Saint Kitts and Nevis");
		capitals.put("Beijing", "People's Republic of China");
		capitals.put("Beirut", "Lebanon");
		capitals.put("Belgrade", "Serbia");
		capitals.put("Belmopan", "Belize");
		capitals.put("Berlin", "Germany");
		capitals.put("Bern", "Switzerland");
		capitals.put("Bishkek", "Kyrgyzstan");
		capitals.put("Bissau", "Guinea-Bissau");
		capitals.put("Bogota", "Colombia");
		capitals.put("Brailia", "Brazil");
		capitals.put("Bratislava", "Slovakia");
		capitals.put("Brazzaville", "Republic of the Congo");
		capitals.put("Bridgetown", "Barbados");
		capitals.put("Brussels", "Belgium");
		capitals.put("Bucharest", "Romania");
		capitals.put("Budapest", "Hungary");
		capitals.put("Buenos Aires", "Argentina");
		capitals.put("Bujumbura", "Burundi");
		capitals.put("Cairo", "Egypt");
		capitals.put("Canberra", "Australia");
		capitals.put("Caracas", "Venezuela");
		capitals.put("Castries", "Saint Lucia");
		capitals.put("Chisinau", "Moldova");
		capitals.put("Conakry", "Guinea");
		capitals.put("Copenhagen", "Denmark");
		capitals.put("Dakar", "Senegal");
		capitals.put("Damascus", "Syria");
		capitals.put("Dhaka", "Bangladesh");
		capitals.put("Dili", "East Timor");
		capitals.put("Djibouti", "Djibouti");
		capitals.put("Dodoma", "Tanzania");
		capitals.put("Doha", "Qatar");
		capitals.put("Dublin", "Ireland");
		capitals.put("Dushanbe", "Tajikistan");
		capitals.put("Freetown", "Sierra Leone");
		capitals.put("Funafuti", "Tuvalu");
		capitals.put("Gaborone", "Botswana");
		capitals.put("Georgetown", "Guyana");
		capitals.put("Guatemala City", "Guatemala");
		capitals.put("Hanoi", "Vietnam");
		capitals.put("Harare", "Zimbabwe");
		capitals.put("Havana", "Cuba");
		capitals.put("Helsinki", "Finland");
		capitals.put("Honiara", "Solomon Islands");
		capitals.put("Islamabad", "Pakistan");
		capitals.put("Jakarta", "Indonesia");
		capitals.put("Jerusalem", "Israel ");
		capitals.put("Kabul", "Afghanistan");
		capitals.put("Kampala", "Uganda");
		capitals.put("Kathmandu", "Nepal");
		capitals.put("Khartoum", "Sudan");
		capitals.put("Kiev", "Ukraine");
		capitals.put("Kigali", "Rwanda");
		capitals.put("Kingston", "Jamaica");
		capitals.put("Kingstown", "Saint Vincent and the Grenadines");
		capitals.put("Kinshasa", "Democratic Republic of the Congo");
		capitals.put("Kuala Lumpur", "Malaysia");
		capitals.put("Kuwait City", "Kuwait");
		capitals.put("La Paz", "Bolivia");
		capitals.put("Libreville", "Gabon");
		capitals.put("Lilongwe", "Malawi");
		capitals.put("Lima", "Peru");
		capitals.put("Lisbon", "Portugal");
		capitals.put("Ljubljana", "Slovenia");
		capitals.put("Lome", "Togo");
		capitals.put("London", "United Kingdom");
		capitals.put("Luanda", "Angola");
		capitals.put("Lusaka", "Zambia");
		capitals.put("Luxembourg City", "Luxembourg");
		capitals.put("Madrid", "Spain");
		capitals.put("Majuro", "Marshall Islands");
		capitals.put("Malabo", "Equatorial Guinea");
		capitals.put("Male", "Maldives");
		capitals.put("Managua", "Nicaragua");
		capitals.put("Manama", "Bahrain");
		capitals.put("Manila", "Philippines");
		capitals.put("Maputo", "Mozambique");
		capitals.put("Maseru", "Lesotho");
		capitals.put("Mbabane", "Swaziland");
		capitals.put("Mexico City", "Mexico");
		capitals.put("Minsk", "Belarus");
		capitals.put("Mogadishu", "Somalia");
		capitals.put("Monaco", "Monaco");
		capitals.put("Monrovia", "Liberia");
		capitals.put("Montevideo", "Uruguay");
		capitals.put("Moroni", "Comoros");
		capitals.put("Moscow", "Russia");
		capitals.put("Muscat", "Oman");
		capitals.put("Nairobi", "Kenya");
		capitals.put("Nassau", "Bahamas");
		capitals.put("Naypyidaw", "Myanmar");
		capitals.put("N\'Djamena", "Chad");
		capitals.put("New Delhi", "India");
		capitals.put("Melekeok", "Palau");
		capitals.put("Niamey", "Niger");
		capitals.put("Nicosia", "Cyprus");
		capitals.put("Nouakchott", "Mauritania");
		capitals.put("Nuku\'alofa", "Tonga");
		capitals.put("Oslo", "Norway");
		capitals.put("Ottawa", "Canada");
		capitals.put("Ouagadougou", "Burkina Faso");
		capitals.put("Palikir", "Federated States of Micronesia");
		capitals.put("Panama City", "Panama");
		capitals.put("Paramaribo", "Suriname");
		capitals.put("Paris", "France");
		capitals.put("Phnom Penh", "Cambodia");
		capitals.put("Podgorica", "Montenegro");
		capitals.put("Port Louis", "Mauritius");
		capitals.put("Port Moresby", "Papua New Guinea");
		capitals.put("Port Vila", "Vanuatu");
		capitals.put("Port-au-Prince", "Haiti");
		capitals.put("Port of Spain", "Trinidad and Tobago");
		capitals.put("Porto-Novo", "Benin");
		capitals.put("Prague", "Czech Republic");
		capitals.put("Praia", "Cape Verde");
		capitals.put("Pretoria", "South Africa");
		capitals.put("Putrajaya", "Malaysia");
		capitals.put("Pyongyang", "North Korea");
		capitals.put("Quito", "Ecuador");
		capitals.put("Rabat", "Morocco");
		capitals.put("Reykjavik", "Iceland");
		capitals.put("Riga", "Latvia");
		capitals.put("Riyadh", "Saudi Arabia");
		capitals.put("Rome", "Italy");
		capitals.put("Roseau", "Dominica");
		capitals.put("San Jose", "Costa Rica");
		capitals.put("San Juan", "Puerto Rico");
		capitals.put("San Marino", "San Marino");
		capitals.put("San Salvador", "El Salvador");
		capitals.put("Sanaa", "Yemen");
		capitals.put("Santiago", "Chile");
		capitals.put("Santo Domingo", "Dominican Republic");
		capitals.put("Sao Tome", "Sao Tome and Príncipe");
		capitals.put("Sarajevo", "Bosnia and Herzegovina");
		capitals.put("Seoul", "South Korea");
		capitals.put("Singapore", "Singapore");
		capitals.put("Skopje", "Macedonia");
		capitals.put("Sofia", "Bulgaria");
		capitals.put("South Tarawa", "Kiribati");
		capitals.put("Sri Jayawardenepura", "Sri Lanka");
		capitals.put("St. George\'s", "Grenada");
		capitals.put("St. John\'s", "Antigua and Barbuda");
		capitals.put("Stockholm", "Sweden");
		capitals.put("Sucre", "Bolivia");
		capitals.put("Suva", "Fiji");
		capitals.put("Taipei", "Republic of China (Taiwan)");
		capitals.put("Tallinn", "Estonia");
		capitals.put("Tashkent", "Uzbekistan");
		capitals.put("Tbilisi", "Georgia");
		capitals.put("Tegucigalpa", "Honduras");
		capitals.put("Tehran", "Iran");
		capitals.put("Thimphu", "Bhutan");
		capitals.put("Tirana", "Albania");
		capitals.put("Tokyo", "Japan");
		capitals.put("Tripoli", "Libya");
		capitals.put("Tunis", "Tunisia");
		capitals.put("Ulaanbaatar", "Mongolia");
		capitals.put("Vaduz", "Liechtenstein");
		capitals.put("Valletta", "Malta");
		capitals.put("Vatican City", "Vatican City");
		capitals.put("Victoria", "Seychelles");
		capitals.put("Vienna", "Austria");
		capitals.put("Vientiane", "Laos");
		capitals.put("Vilnius", "Lithuania");
		capitals.put("Warsaw", "Poland");
		capitals.put("Washington, D.C.", "United States");
		capitals.put("Wellington", "New Zealand");
		capitals.put("Windhoek", "Namibia");
		capitals.put("Yamoussoukro", "Cote d\'Ivoire");
		capitals.put("Yaounde", "Cameroon");
		capitals.put("Yaren", "Nauru");
		capitals.put("Yerevan", "Armenia");
		capitals.put("Zagreb", "Croatia");
		capitalsList.addAll(capitals.keySet());
	}

	public static void main(String[] args) {
		System.out.println(NamesResource.getRandomBirthDate(2017));
		System.out.println("------------------");
		int[] y = {1990, 1989, 1987};
		int[] num = {2, 2, 3};
		LocalDate[] dates = NamesResource.getDateArray(y, num);
		for(LocalDate date : dates) {
			System.out.println(date);
		}	
		System.out.println("------------------");
		for(int i = 0; i < 10; i++) {
			Person p = new Person(getRandomLastName(), getRandomFirstName(), getRandomBirthDate(2017));
			System.out.println(p);
		}
	}
}

