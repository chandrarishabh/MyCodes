#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class vector{
	int cs;
	int ms;
	T* arr;
	public:
		vector(int d=2)
		{
			cs=0;
			ms=2;
			arr = new T[ms];
		}
		void push_back(T d)
		{
			if(cs==ms)
			{
				T* oldarr = arr;
				ms=ms*2;
				arr = new T[ms];
				for(int i=0;i<cs;i++)
				{
					arr[i]=oldarr[i];
				}
				delete[] oldarr;
			}
			arr[cs]=d;
			cs++;
		}
		T operator[](int i)
		{
			return arr[i];
		}
		void pop_back()
		{
			cs--;
		}
		int size()
		{
			return cs;
		} 
		int max_size()
		{
			return ms;
		}
};

#endif