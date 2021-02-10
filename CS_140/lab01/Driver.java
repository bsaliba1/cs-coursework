package lab01;

/**
 * Tester program for BodyOfWater and River
 * Data from http://www.enchantedlearning.com/usa/rivers/  
 * References Encyclopedia Britannica and Kammerer, J.C., May, 1990, 
 * Largest Rivers in the United States, US Geological Survey Fact Sheet, 
 * Open File Report 87-242. 
 * @author CS140
 */
public class Driver {

	public static void main(String[] args) {
		BodyOfWater gulfOfMexico = new BodyOfWater("Gulf of 			Mexico");
		BodyOfWater beringSea = new BodyOfWater("Bering Sea");
		BodyOfWater gulfOfStLawrence = new BodyOfWater("Gulf 			of St. Lawrence ");
		BodyOfWater gulfOfCalifornia = new BodyOfWater("Gulf 			of California");
		BodyOfWater pacificOcean = new BodyOfWater("Pacific 			Ocean");
		BodyOfWater matagordoBay = new BodyOfWater("Matagordo 			Bay");
		River mississippi = new River("Mississippi River", 			gulfOfMexico, 2340);
		River missouri = new River("Missouri River", 			mississippi, 2540);
		River yukon = new River("Yukon River", beringSea, 			1980);
		River rioGrande = new River("Rio Grande River", 		gulfOfMexico, 1900);
		River stLawrence = new River("St. Lawrence River", 			gulfOfStLawrence, 1900);
		River arkansas = new River("Arkansas River", 			mississippi, 1460);
		River colorado = new River("Colorado River", 			gulfOfCalifornia, 1450);
		River red = new River("Red River of the South", 			mississippi, 1290);
		River brazos = new River("Brazos River", gulfOfMexico, 			1280);
		River columbia = new River("Columbia River", 			pacificOcean, 1240);
		River snake = new River("Snake River", columbia, 1040);
		River platte = new River("Platte River", missouri, 			990);
		River ohio = new River("Ohio River", mississippi, 981);
		River pecos = new River("Pecos River", gulfOfMexico, 			926);
		River canadian = new River("Canadian River", arkansas, 			906);
		River tennessee = new River("Tennessee River", ohio, 			886);
		River coloradoTexas = new River("Colorado River, 			Texas", matagordoBay, 862);
		River northCanadian = new River("North Canadian 		River", canadian, 800);
		River mobile = new River("Mobile River", gulfOfMexico, 			774);
		River kansas = new River("Kansas River", missouri, 			743);
		River kuskokwim = new River("Kuskokwim River", 			beringSea, 724);
		River green = new River("Green River", colorado, 730);
		River james = new River("James River", missouri, 710);
		River yellowstone = new River("Yellowstone River", 			missouri, 692);
		River tanana = new River("Tanana River", yukon, 659);
		River gila = new River("Gila River River", colorado, 			630);
		River milk = new River("Milk River", missouri, 625);
		River quachita = new River("Quachita River", red, 605);

		System.out.print("Water in the Arkansas River flows down to the ");
		System.out.println(arkansas.flowsOutTo());
		System.out.println("Expected: the Gulf of Mexico");
		
	}

}

