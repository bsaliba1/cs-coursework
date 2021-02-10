package assignment04;

public class ResonantCircuit{
	private double frequency;
	private double bandwidth;
	private double gain;

	public ResonantCircuit(double aFrequency, double aBandwidth, double aGain){
		this.frequency = aFrequency;
		this.bandwidth = aBandwidth;
		this.gain = aGain;
	}
	public void display(){
		System.out.println('\n'+"Resonant Circuit Characteristics: ");
		System.out.println('\t'+"frequency: "+frequency);
		System.out.println('\t'+"bandwidth: "+bandwidth);
		System.out.println('\t'+"gain: "+gain);
	}
}