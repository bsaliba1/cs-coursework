package assignment04;

public class ParallelResonantCircuit extends ResonantCircuit{
	private double r;
	private double c;
	private double L;

	public ParallelResonantCircuit(double r,double c,double L){
		super(computeFrequency(c,L), computeBandwidth(r,c),r);
		this.r = r;
		this.c = c;
		this.L = L;
	}
	public void display(){
		super.display();
		System.out.println('\n'+"Resonant Circuit Characteristics: ");
		System.out.println('\t'+"frequency: "+ computeFrequency(c,L));
		System.out.println('\t'+"bandwidth: "+ computeBandwidth(r,c));
		System.out.println('\t'+"gain: "+ r);
		System.out.println('\t'+"resistance: "+ r);
		System.out.println('\t'+"capacitance: "+ c);
		System.out.println('\t'+"inductance: "+ L);

	}
	static private double computeBandwidth(double r, double c){
		if(c!=0 && r!=0){
			double returnVal = 1/(r*c);
			return returnVal;
		}else{
			throw new IllegalArgumentException("inputs cannot be zero");
		}
	}
	static private double computeFrequency(double c, double L){
		if(c!=0 && L!=0){
			double returnVal = Math.sqrt(1/(c*L));
			return returnVal;
		}else{
			throw new IllegalArgumentException("inputs cannot be zero");
		}
	}
}