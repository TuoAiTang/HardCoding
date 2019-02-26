import java.util.*;
class testJ{
	
	public static void main(String[] args) {
		double [] f1 = {1500, 2700, 2000, 1800};
		// double f1_sum = getVectorSum(f1);
		// double sum = 0;
		// for(double d : f1){
		// 	double r = d / f1_sum;
		// 	System.out.println("f1:" + r); 
		// 	sum += r * r;
		// }
		// System.out.println("sum:" + sum);
		double f_max = 2700;
		double f_min = 1500;
		for(double d : f1)
			System.out.println("getByDelta:" + getByDelta(d, f_max, f_min, true));


	}

	private static double getByDelta(double x, double f_max, double f_min, boolean flag){
		double delta = f_max - f_min;
		if(flag)
			return (x - f_min) / delta;
		return (f_max - x) / delta;
	}

	private static double getVectorSum(double [] a){
		double sum = 0;
		for(double d : a)
			sum += d * d;
		return Math.sqrt(sum);
	}


	private static void swap(String s1, String s2){
		String tmp = s1;
		s1 = s2;
		s2 = tmp;
	}

	static class Pair{
		int a;
		int b;
		public Pair(int a, int b){
			this.a = a;
			this.b = b;
		}
	}
}


