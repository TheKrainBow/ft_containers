#include "vector.hpp"
#include <vector>
#define SHOW(tmp) for (int i = 0; i < tmp.size(); i++) {std::cout << tmp[i] << " ";} std::cout << std::endl;
using namespace ft;

int main()
{
	vector<int>::size_type sz;

  vector<int> foo;
  sz = foo.capacity();
  std::cout << "making foo grow:\n";
  for (int i=0; i<100; ++i) {
    foo.push_back(i);
    if (sz!=foo.capacity()) {
      sz = foo.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }

  vector<int> bar;
  sz = bar.capacity();
  bar.reserve(100);   // this is the only difference with foo above
  std::cout << "making bar grow:\n";
  for (int i=0; i<100; ++i) {
    bar.push_back(i);
    if (sz!=bar.capacity()) {
      sz = bar.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }
  std::vector<int> baaar(5, 100);

  std::cout << baaar.capacity() << std::endl;
  baaar.reserve(100);
  std::cout << baaar.capacity() << std::endl;
  for (int i=0; i<101; ++i) {
    baaar.push_back(i);
    if (sz!=baaar.capacity()) {
      sz = baaar.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }
  std::cout << baaar.capacity() << std::endl;
  return 0;
}