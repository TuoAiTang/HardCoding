import java.util.*;

class lc126test{
	public static void main(String[] args) {
		String beginWord = "a";
		String endWord = "c";
		String [] wordList = {"a", "b", "c"};
		lc126_Bidirection_BFS helper = new lc126_Bidirection_BFS();


		List<List<String>> res = helper.findLadders(beginWord, endWord, Arrays.asList(wordList));
		System.out.println(res);
	}
}