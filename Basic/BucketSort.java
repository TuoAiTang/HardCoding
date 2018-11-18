import java.util.*;

class BucketSort{

	//fixed-length sort
	static void countingRadixSort(String [] arr, int stringLen){

		int BUCKECTS = 26;
		int size = arr.length;

		String [] buffer = new String[size];

		String [] in = arr;
		String [] out = buffer;
		for (int pos = stringLen - 1; pos >= 0; --pos)
		{
			int [] count = new int[BUCKECTS + 1];

			for (int i = 0; i < size; ++i)
				count[in[i].charAt(pos) - 'a' + 1]++;

			for (int b = 1; b < BUCKECTS; b++)
				count[b] += count[b - 1];

			for(int i = 0; i < size; i++)
				out[count[in[i].charAt(pos) - 'a'] ++] = in[i];

			String [] tmp = in;
			in = out;
			out = tmp;
		}

		if(stringLen % 2 == 1)
			for(int i = 0; i < arr.length; i++)
				out[i] = in[i];
	}

	//O(maxLen * (n + BUCKETS))
	static void radixSort(String [] arr, int maxLen){
		final int BUCKETS = 256;
		List<List<String>> wordsByLength = new ArrayList<>();
		List<List<String>> buckets = new ArrayList<>();

		//init length Bucket ArrayList with size maxLen + 1
		for(int i = 0; i < maxLen + 1; i++)
			wordsByLength.add(new ArrayList<>());

		//init character Bucket ArrayList with size BUCKETS
		for(int i = 0; i < BUCKETS; i++)
			buckets.add(new ArrayList<>());

		//sort the arr by length, O(n + maxLen)
		for(String s : arr)
			wordsByLength.get(s.length()).add(s);
		int idx = 0;
		for(List<String> wordList : wordsByLength)
			for(String s : wordList)
				arr[idx++] = s;

		int startingIdx = arr.length;
		//O(maxLen * (n + BUCKETS))
		for(int pos = maxLen - 1; pos >= 0; pos--)
		{
			//ensure the string charAt(pos) valid
			startingIdx -= wordsByLength.get(pos + 1).size();

			//O(n)
			for(int i = startingIdx; i < arr.length; i++)
				buckets.get(arr[i].charAt(pos)).add(arr[i]);

			//O(n + BUCKET)
			idx = startingIdx;
			for(List<String> thisBucket : buckets){
				for(String s : thisBucket)
					arr[idx++] = s;
				thisBucket.clear();
			} 

		}
	}

	/*@param d the max length of number*/
	//Least Significant Digit First - LSD
	static void radixSort(int [] arr, int d){
		int RADIX = 10;
		int [] buffer = new int[arr.length];
		int [] count = new int[RADIX + 1];

		for(int i = 0, rate = 1; i < d; i++, rate *= RADIX){
			Arrays.fill(count, 0);

			for(int j = 0; j < arr.length; j++){
				int key = arr[j] / rate % RADIX;
				++count[key + 1];
			}

			for(int j = 1; j < RADIX; j++)
				count[j] += count[j - 1];

			for(int j = 0; j < arr.length; j++){
				int key = arr[j] / rate % RADIX;
				buffer[count[key] ++] = arr[j];
			}

			for(int j = 0; j < arr.length; j++)
				arr[j] = buffer[j];
		}	
	}

	

	public static void main(String[] args) {
		// String [] arr = {"abac", "aacd", "baadf", "cab", "ca"};

		// System.out.println("Original:");		
		// for(String str : arr)
		// 	System.out.printf(str + "\t");

		// // countingRadixSort(arr, 2);
		// radixSort(arr, 5);
		// System.out.println("\nSorted:");

		// for(String str : arr)
		// 	System.out.printf(str + "\t");

		int [] a = {22, 11, 345, 56, 6, 981};

		System.out.println("Int radix sort:");

		radixSort(a, 3);

		for(int j = 0; j < a.length; j++)
			System.out.print(a[j] + "\t");

	}
}

