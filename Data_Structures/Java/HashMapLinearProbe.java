
/**
 * Custom Linear Probing HashMap created by Kevin Chow.
 */
public class HashMapLinearProbe<String, Value>
{
    private int pairs = 0; //keeps track of key-value pairs
    private int size; //size of array
    private Value[] values;
    private String[] keys;
    //keys array?
    
    public HashMapLinearProbe(int size)
    {
        this.size = size;
        values = (Value[])new Object[size];
        keys = (String[])new Object[size];
        
    }
    
    public boolean set(String key, Value value)
    {
        //if load isn't too high
        if (load() < 0.75)//too full is not good!
        {
            //get key hash index
            int index = hash(key);
            //val is null, delete key
            if (value == null) 
            {
                delete(key);
                return true;
                
            }
            //if index is taken
            while (keys[index] != null)
            {
                if (keys[index].equals(key))
                {
                    if (values[index] == value)
                    {
                        return false; //duplicate
                    }
                    //else, set index to value
                    values[index] = value;
                    return true;
                }
                index = (index + 1) % size;
            }
            //index is free
            keys[index] = key;
            values[index] = value;
            pairs++;
            return true;
        }

        return false;
    }
    
    public Value get(String key)
    {
        //return value 
        int index = hash(key);
        //index may not be right
        while (keys[index] != key)
        {
            if (index == size -1)//not found
            {
                return null;
            }
            index = (index + 1) % size;
        }
        return values[index];
    }
    
    public Value delete(String key)
    {
        //find right index
        int index = hash(key);
        while (keys[index] != key)
        {
            if (index == size-1)//key not found
            {
                return null;
                
            }
            index = (index + 1) % size;
        }
        
        //what if key doesn't existt?
        //return value
        keys[index] = null;
        Value rtn = values[index];
        values[index] = null;
        pairs--;
        return rtn;
    }
    
    public float load()
    {
        //return load factor
        return ((float)this.pairs/(float)this.size);
    }
    //set to absolute value for greater than max INT
    public int hash(String key)
    {
        return Math.abs(key.hashCode() % size);
    }

}
