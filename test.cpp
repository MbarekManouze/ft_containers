#include <iostream>
//#include <vector>
#include "vector.hpp"
#include "Iterator.hpp"

#include <vector>

void ft_resize()
{
  std::vector<int> myvector;

  for (int i=1;i<10;i++) 
    myvector.push_back(i);  
  std::cout << "capacity : "<<myvector.capacity() << std::endl;
  myvector.resize(8,100);
  std::cout << "capacity  "<<myvector.capacity() << std::endl;
  myvector.resize(5);
  std::cout << "capacity  "<<myvector.capacity() << std::endl;
  myvector.resize(12);
  std::cout << "capacity  "<<myvector.capacity() << std::endl;
  std::cout << "size  "<<myvector.size() << std::endl;

  std::cout << "myvector contains:";
  for (int i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  std::cout << "************************\n";


  vector<int> vec;

  for(int i=1; i<10;i++)
    vec.push_back(i);
  std::cout << "capacity : "<<vec.capacity() << std::endl;
  vec.resize(8,100);
  std::cout << "capacity : "<<vec.capacity() << std::endl;
  vec.resize(5);
  std::cout << "capacity : "<<vec.capacity() << std::endl;
  vec.resize(12);
  std::cout << "capacity : "<<vec.capacity() << std::endl;
  std::cout << "size : "<<vec.size() << std::endl;

  std::cout << "vec contains     :";
  for (int i=0;i<vec.size();i++)
    std::cout << ' ' << vec[i];
  std::cout << '\n';

}

int main ()
{
  ft_resize();
  //system("leaks a.out");
  return 0;
}

