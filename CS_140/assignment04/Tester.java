package assignment04;

public class Tester{
	public static void main(String[] args){
		ResonantCircuit r1 = new ResonantCircuit(10,3,70);
		r1.display();

		ResonantCircuit circ1 = new ParallelResonantCircuit(70.0, 0.05, 0.07);
		circ1.display();

		ResonantCircuit circ2 = new SeriesResonantCircuit(70.0, 0.05, 0.07);
		circ2.display();

		try{
			ResonantCircuit errcir1 = new ParallelResonantCircuit(0.0, 0.0, 0.0);
			ResonantCircuit errcir2 = new SeriesResonantCircuit(0.0, 0.0, 0.0);
		}catch(IllegalArgumentException e){
			System.out.println('\n'+"EXCEPTIONS CAUGHT"+'\n');
		}
	}
}