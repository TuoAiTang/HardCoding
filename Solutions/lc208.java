class lc208{
    public static void main(String[] args) {
        Trie t = new Trie();
        t.insert("apple"); 
        System.out.println(t.startsWith("aplk"));
    }
}

class Trie {

    //Space: O(26 * n * l)
    private TrieNode root;

    /** Initialize your data structure here. */
    public Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    //Time: O(l)
    public void insert(String word) {
        TrieNode p = root;
        for(int i = 0; i < word.length(); i++){
            int index = word.charAt(i) - 'a';
            if(p.children[index] == null)
                p.children[index] = new TrieNode();
            p = p.children[index];
        }
        p.is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    //Time: O(l)
    public boolean search(String word) {
        TrieNode p = find(word);
        return p != null && p.is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    //Time: O(l)
    public boolean startsWith(String prefix) {
        TrieNode p = find(prefix);
        return p != null;
    }

    private TrieNode find(String prefix){
        TrieNode p = root;
        for(int i = 0; i < prefix.length(); i++){
            int index = prefix.charAt(i) - 'a';
            if(p.children[index] == null) return null;
            p = p.children[index];
        }
        return p;
    }

    /*specific operations for some problems (e.g. 720)*/
    public boolean hasAllPrefixes(String word){
        TrieNode p = root;
        for(int i = 0; i < word.length(); i++){
            int index = word.charAt(i) - 'a';
            if(p.children[index] == null) return false;
            p = p.children[index];
            if(!p.is_word) return false;
        }
        return true;
    }

    public class TrieNode{
        public boolean is_word;
        public TrieNode [] children;
        TrieNode(){is_word = false; children = new TrieNode[26];}
    }
        
}