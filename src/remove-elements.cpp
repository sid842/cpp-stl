#include <algorithm>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <string>

namespace sid {
	namespace detail {

		//Example of template metaprogramming
		struct vectorlike_tag { };
		struct listlike_tag { };
		struct associative_tag { };

		template <typename C> struct container_traits;

		template <typename T, typename A> struct container_traits<std::vector<T, A>> {
			typedef vectorlike_tag category;
		};

		template <typename T, typename A> struct container_traits<std::deque<T, A>> {
			typedef vectorlike_tag category;
		};

		template <typename T, typename A> struct container_traits<std::list<T, A>> {
			typedef listlike_tag category;
		};

		template <typename T, typename A> struct container_traits<std::forward_list<T, A>> {
			typedef listlike_tag category;
		};

		template <typename T, typename C, typename A> struct container_traits<std::set<T, C, A>> {
			typedef associative_tag category;
		};

		template <typename T, typename C, typename A> struct container_traits<std::multiset<T, C, A>> {
			typedef associative_tag category;
		};

		template <typename T, typename C, typename A> struct container_traits<std::unordered_set<T, C, A>> {
			typedef associative_tag category;
		};

		template <typename K, typename V, typename C, typename A> struct container_traits<std::map<K, V, C, A>> {
			typedef associative_tag category;
		};

		template <typename K, typename V, typename C, typename A> struct container_traits<std::multimap<K, V, C, A>> {
			typedef associative_tag category;
		};

		template <typename K, typename V, typename C, typename A> struct container_traits<std::unordered_map<K, V, C, A>> {
			typedef associative_tag category;
		};

		template <typename Container, typename X> void erase_helper(Container& c, const X& x, vectorlike_tag) {	//vectorlike_tag since we don't use the parameter no need to define it
			c.erase(std::remove(c.begin(), c.end(), x), c.end());
		}

		template <typename Container, typename Pred> void erase_if_helper(Container& c, Pred p, vectorlike_tag) {
			c.erase(std::remove_if(c.begin, c.end(), p), c.end());
		}

		template <typename Container, typename X> void erase_helper(Container& c, const X& x, listlike_tag) {
			c.remove(x);	
		}


		template <typename Container, typename Pred> void erase_if_helper(Container& c, Pred p, listlike_tag) {
			c.remove_if(p);
		}

		template <typename Container, typename X> void erase_helper(Container& c, const X& x, associative_tag) {
			c.erase(x);	
		}
		template <typename Container, typename Pred> void erase_if_helper(Container& c, Pred p, associative_tag) {
			for(auto itr = c.begin(); itr != c.end(); ) {
				if(p(*itr)) {
					c.erase(itr++);
				} else {
					++itr;
				}
			}
		}
	}
	//outside the detail namespace 

	//users use the below methods

	template <typename Container, typename X> void erase(Container& c, const X& x) {
		detail::erase_helper(c, x, typename detail::container_traits<Container>::category());	// category provides a type and we need an object of that type
	}

	template <typename Container, typename Pred> void erase_if(Container& c, Pred p) {
		detail::erase_if_helper(c, p, typename detail::container_traits<Container>::category());
	}
} 

int main() {
	std::vector<int> v = {2,1,3,1,4,1};
	
	for(int x: v)
		std::cout << x << " " ;

	std::cout << std::endl;

	sid::erase(v, 1);

	for(int x: v)
		std::cout << x << " " ;

	std::cout << std::endl;

	std::map<int, std::string> m;
	m[1] = "one";
	m[2] = "two";
	m[3] = "three";
	m[4] = "four";

	for (auto itr = m.cbegin(); itr != m.cend(); ++itr) { 
		std::cout <<  "(" << itr->first << ", " << itr->second << ")" << std::endl;
	}

	std::cout << std::endl;

	sid::erase_if(m, [](std::pair<const int, std::string> p) {
		return p.first%2 == 1;
	});

	std::cout << "After deletion:" << std::endl;

	for (auto itr = m.cbegin(); itr != m.cend(); ++itr) { 
		std::cout <<  "(" << itr->first << ", " << itr->second << ")" << std::endl;
	}

	std::cout << std::endl;

	return 0;
}






