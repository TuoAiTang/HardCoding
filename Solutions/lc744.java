
/*	
	Case 1: ['a', 'b'] target = 'z'

	l = 0, r = 1
	mid = 0
	letters[mid] < target
	l = 1

	l = 1, r = 1;


	Case 2: ['a', 'c', 'd', 'f', 'g'] target = 'z'

	l = 0, r = 4;
	mid = 2
	letters[mid] < target
	l = 3

	l = 3, r = 4
	mid = 3
	letters[mid] < target
	l = 4

	l = 4, r = 4

	Case 3: ['a', 'c', 'd', 'f', 'g'] target = 'e'

	l = 0, r = 4;
	mid = 2
	letters[mid] < target
	l = 3

	l = 3, r = 4
	mid = 3
	letters[mid] > target
	r = 3

	l = 3, r = 3



*/
class lc744 {
	//binary search
	//Time: O(logn)
	//8ms beats 42.3%
    public char nextGreatestLetter(char[] letters, char target) {
        int l = 0;
        int r = letters.length - 1;
        int mid;

        while(l < r){
        	mid = (l + r) / 2;
        	if(letters[mid] <= target)
        		l = mid + 1;
        	else
        		r = mid;
        }

        return letters[l] > target ? letters[l] : letters[0];	//l == r, so l or r , both valid
    }
}