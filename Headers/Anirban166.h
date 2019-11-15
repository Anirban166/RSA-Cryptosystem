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
#include<iterator>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

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

//Other code/functions exist in my header primarily for CP-contests but the above function 
//is enough to replace them static arrays with vector ones (in case you want), as only the
//size while taken as long integer might be a bother due to the unsigned integer conversion rule. Cheers! 
