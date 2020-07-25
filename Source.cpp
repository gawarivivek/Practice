class Integer
{
	int* ptr = nullptr;
public:
	Integer()
	{
		ptr = new int;
		*ptr = 5;
	}
	Integer(int* x)
	{
		ptr = new int;
		*ptr = *x;
	}
	
	//Destructor
	~Integer()
	{
		delete ptr;
	}
	Integer(const Integer& obj)
	{
		if(!this->ptr)
			ptr = new int;
		*ptr = *(obj.ptr);
	}
	Integer& operator=(const Integer& obj)
	{
		*ptr = *(obj.ptr);
		return *this;
	}
	
	Integer operator+(const Integer& obj1)
	{
		Integer temp;
		*(temp.ptr) = *ptr + *(obj1.ptr);
		return temp;
	}

};

int main()
{
	Integer o1(new int(4));
	Integer o2;
	o2 = o1;
	Integer o3(o1);
	Integer o4;
	//o4 = o4;
	o4.operator=(o4);
	o4 = o3 = o2;
	Integer o5;
	o5 = o1 + o2;
	o5 = o1.operator+(o2);
}