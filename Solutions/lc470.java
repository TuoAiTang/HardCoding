//5ms beats 100%
class Solution extends SolBase {
    public int rand10() {
        int index;
        do{
           index = (rand7() - 1) * 7 + (rand7() - 1); 
        } while(index > 39);        
        return index % 10 + 1;
    }
}