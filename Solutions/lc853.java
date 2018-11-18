class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
    	int fleets = 0;
    	int n = position.length;
    	Car [] cars = new Car[n];
        for (int i = 0; i < n; i++)
        	cars[i] = new Car(position[i], speed[i]);
        Arrays.sort(cars);
        double pre = Double.MAX_VALUE;
        for (int i = n - 1; i > 0; i--) {
        	double arrival = (double)(target - cars[i].position) / cars[i].speed;
        	if(arrival < pre) fleets ++;
        	else pre = arrival;
        }
        return fleets + (n == 0 ? 0 : 1);
    }
}

class Car implements Comparable<Car>{
	int position;
	//hypothetical arrive time in case that the car is allowed to overtake another
	int speed; 
	public Car(int position, int speed){
		this.position = position;
		this.speed = speed;
	}

	@Override
	public int compareTo(Car another){
		return this.position < another.position ? -1 : 1;
	}
	
}