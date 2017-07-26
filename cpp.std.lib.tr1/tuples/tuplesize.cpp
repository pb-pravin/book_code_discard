#include <tr1/tuple>
#include <iostream>

using std::tr1::tuple;
using std::tr1::tuple_size;
using std::cout;

typedef tuple<> tuple0;
typedef tuple<int> tuple1;
typedef tuple<int &, double &> tuple2;
typedef tuple<int, int, int, int, int> tuple5;

int main()
{
	cout << tuple_size<tuple0>::value << '\n';
	cout << tuple_size<tuple1>::value << '\n';
	cout << tuple_size<tuple2>::value << '\n';
	cout << tuple_size<tuple5>::value << '\n';

	return 0;
}
