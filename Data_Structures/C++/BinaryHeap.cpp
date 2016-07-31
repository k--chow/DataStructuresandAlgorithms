class binaryHeap
{
	private: 
		int size;
		long long arr[5000];

	public: 
		binaryHeap(int N)
		{
			size = N;
			memset(arr, 0, sizeof(arr));
		}

		void insert(long long N)
		{
			size++;
			int index = size;
			arr[index] = N;
			//set index to parent
			int parent = index/2;
			//while parent is smaller
			while (arr[parent] < N && parent != 0)
			{
				long long temp = arr[parent];
				//swap
				arr[parent] = N;
				arr[index] = temp;
				cout << temp << " swapped for " << N << endl;
				//forgot to set parent
				index = parent;
				parent = parent/2;
			}
			

		}
		//I struggled to implement this function conceptually at first.
		//I should have thought about it more, and really tested my understanding
		//of the tree; it's quite intuitive. 
		long long removeMin()
		{
			size--;
			int index = 1;
			long long ans = arr[index];
			arr[index] = arr[size+2];
			long long smallest = arr[index];
			//while a child is larger, swap (make sure it's largest child)
			long long child = max(arr[index*2], arr[(index*2) + 1]);
			while (child > arr[index])
			{
				//swap with larger
				if (arr[index*2] > arr[index*2+1])
				{
					index = index*2;
				}
				else
				{
					index = (index*2)+1;
				}
				long long temp = arr[index];//child
				arr[index] = smallest; 
				arr[index/2] = temp; //back up to parent

				//if index = size break
				if (index == size) break;

				//set child
				child = max(arr[index*2], arr[index*2 +1]);
			}

			return ans;
		}

		void print()
		{
			for(int i=1; i<=size; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
		}


};