#include<map>
#include<set>
#include<list>
#include<stack>
#include<queue>
#include<cmath>
#include<vector>
#include<memory>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cstddef>
#include<iomanip>
#include<iterator>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

#define pb push_back
#define sz(x) int((x).size())
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

// When using int loop indexes, use size_as_int(container) instead of
// container.size() in order to document the inherent assumption that 
// the size of the container can be represented by an int. 
// (otherwise unsigned integer conversion error will occur.) 

template <typename ContainerType>
long int size_as_int(const ContainerType &c)
{   const auto size = c.size();  // if no auto, use `typename ContainerType::size_type`
	assert(size <= static_cast<std::size_t>(std::numeric_limits<long int>::max()));
	return static_cast<long int>(size);
}

//I used long int in my code but you can switch to long long int (might become slow) for overflows 
//while dealing with big numbers, especially for larger value primes or reduce them by modular division.

//Note: Other code/functions exist in my header primarily for CP-contests.
