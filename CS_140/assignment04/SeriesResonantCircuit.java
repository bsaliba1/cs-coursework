package assignment04;

public class SeriesResonantCircuit extends ResonantCircuit{
	private double r;
	private double c;
	private double L;


	public SeriesResonantCircuit(double r,double c,double L){
		super(computeFrequency(c,L), computeBandwidth(r,L), computeGain(r));
		this.r = r;
		this.c = c;
		this.L = L;
	}
	public void display(){
		super.display();
		System.out.println('\n'+"Resonant Circuit Characteristics: ");
		System.out.println('\t'+"frequency: "+ computeFrequency(c,L));
		System.out.println('\t'+"bandwidth: "+ computeBandwidth(r,L));
		System.out.println('\t'+"gain: "+ computeGain(r));
		System.out.println('\t'+"resistance: "+ r);
		System.out.println('\t'+"capacitance: "+ c);
		System.out.println('\t'+"inductance: "+ L);

	}
	static private double computeBandwidth(double r, double L){
		if(L!=0 && r!=0){
			double returnVal = r/L;
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
	static private double computeGain(double r){
		if(r!=0){
			double returnVal = 1/r;
			return returnVal;
		}else{
			throw new IllegalArgumentException("inputs cannot be zero");
		}
	}
}