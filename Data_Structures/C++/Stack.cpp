class Stack
{
	//LIFO
	//private variables
	private:
	int size;
	vector<string> data;
	//public variables
	public:
	Stack(int size)
	:size(size)
	{

	}

	int getSize()
	{
		return this->size;
	}

	string push(string a)
	{
		data.push_back(a);
		return a;
	}

	string pop()
	{
		string last = data.back();
		data.pop_back();
		return last;
	}

	string back()
	{
		return data.back();
	}

	bool empty()
	{
		if (data.size() == 0)
		{
			return true;
		}
		return false;
	}




};
