#include <iostream>
#include <vector>
#include <algorithm>

class A
{
    private:
        int val;

    public:
        //ctr
        A(int v) : val(v){}

        // overloaded operator<
        bool operator<(A* p) const { return val < p->val; }

        // getter
        int getVal() { return val; }
};


int main()
{
    const int sz = 5;
	std::vector<A*> v;

	for (int i = 0; i < sz ; i++)
	{
		int val;
		std::cin >> val;

		A* p = new A(val);
		v.push_back( p );
	}

	std::sort(v.begin(), v.end() ); // sort vector by 'val'

	//print
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << "Value: " << v[i]->getVal() << std::endl;
	}

	// delete memory associated with each pointer
	for(int i = 0; i < v.size(); i++) delete v[i];

	return 0;
}
