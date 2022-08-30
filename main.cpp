#include <list>
#include <map>
#include "map/map.hpp"

int		main(void)
{
	std::map<int, std::string> map;
  map.insert(std::pair<int, std::string>(1, "lel"));
  std::cout << map[1] << std::endl;
	// lst.clear();
	// is_empty(mp);
	// printSize(mp);

	// is_empty(mp2);
	// mp2 = mp;
	// is_empty(mp2);

	// it = mp.begin();
	// for (unsigned long int i = 3; i < mp.size(); ++i)
	// 	it++->second = i * 7;

	// printSize(mp);
	// printSize(mp2);

	// mp2.clear();
	// is_empty(mp2);
	// printSize(mp2);
	return (0);
}