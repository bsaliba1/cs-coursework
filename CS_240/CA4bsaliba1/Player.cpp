class Player{
	private:
		string name;
		int numWins;
	public:
		string getName(){
			return name;
		}
		int getNumWins(){
			return numWins;
		}
		Player(string n){
			name =n;
			numWins=0;
		}
		void incrementWins(){
			numWins++;
		}
};
