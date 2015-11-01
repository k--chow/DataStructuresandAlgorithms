
/**
 * HashMap test for set, get, delete, load.
 */
public class HashMapTest
{
    public static void main(String [] args)
    {
        //HashMap test with Integer data type
        HashMapLinearProbe<String, Integer> test = new HashMapLinearProbe<String, Integer>(20);
        //test set
        System.out.println("Set key to value:" + test.set("ab", 5));
        System.out.println("Value: " + test.get("ab"));
        test.set("ac", 6);
        //same key, different value replace test 
        test.set("ab", 7);
        System.out.println("Value after replacement: " + test.get("ab"));
        test.set("ad", 12);
        test.set("ae", 13);
        test.set("af", 14);
        test.set("ag", 15);
        test.set("ah", 16);
        test.set("ai", 17);
        test.set("aj", 17);
        test.set("al", 17);
        test.set("ak", 17);
        test.set("a", 17);  
        test.set("axss", 50);
        test.set("bby", 99);
        test.set("bbys", 20);
        //check if long string key works
        System.out.println("Long key test: " + test.set("aaaaaaaaaaaaaa", 50));
        //check if duplicate returns false;
        System.out.println("Duplicate should return false: " + test.set("a", 17));
        //check that getting nonexistent key returns null
        System.out.println("Nonexistent key returns: " + test.get("xx"));
        //check that deleting nonexistent key returns null
        System.out.println("Deleting nonexistent key returns: " + test.delete("yy"));
        //check if deleting existent returns deleteed
        System.out.println("Deleting existent key returns: " + test.delete("axss"));
        //check if 0.75 causes no more load
        test.set("ackle", 60);
        System.out.println("Load Factor: " + test.load());
        System.out.println("Attempt to add after 0.75 load reached: " + test.set("axe", 5));
        //check load factor
        System.out.println("Load Factor: " + test.load());
        //different data types 
        HashMapLinearProbe<String, Double> test2 = new HashMapLinearProbe<String, Double>(20);
        HashMapLinearProbe<String, String> test3 = new HashMapLinearProbe<String, String>(30);
    }
}
