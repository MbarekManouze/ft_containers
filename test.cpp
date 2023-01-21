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
  myvector.resize(12);
  std::cout << "capacity  "<<myvector.capacity() << std::endl;
  myvector.resize(20,100);
  myvector.resize(11);
  std::cout << "capacity  "<<myvector.capacity() << std::endl;
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
  vec.resize(12);
  std::cout << "capacity : "<<vec.capacity() << std::endl;
  vec.resize(20,100);
  vec.resize(11);
  std::cout << "capacity : "<<vec.capacity() << std::endl;
  //std::cout << vec.size() << std::endl;
  std::cout << "capacity : "<<vec.capacity() << std::endl;
  std::cout << "size : "<<vec.size() << std::endl;

  std::cout << "vec contains     :";
  for (int i=0;i<vec.size();i++)
    std::cout << ' ' << vec[i];
  std::cout << '\n';
}

void ft_erase()
{
  std::vector<int> myvector;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) myvector.push_back(i);

  // erase the 6th element
  std::cout << "capacity : "<< myvector.capacity() << std::endl;
  std::cout << "size     : "<<myvector.size() << std::endl;
  myvector.erase (myvector.begin()+5);
  //myvector.erase (myvector.begin());
  //myvector.erase (myvector.end());
  std::cout << "capacity : "<< myvector.capacity() << std::endl;
  std::cout << "size     : "<<myvector.size() << std::endl;

  // erase the first 3 elements:
  myvector.erase (myvector.begin(),myvector.begin()+3);
  std::cout << "capacity : "<< myvector.capacity() << std::endl;
  std::cout << "size     : "<<myvector.size() << std::endl;

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';


  std::cout << "************************************\n";
  
  vector<int> vec;

  for (int i=1; i<=10; i++) vec.push_back(i);

  std::cout << "capacity : "<< vec.capacity() << std::endl;
  std::cout << "size     : "<<vec.size() << std::endl;
  vec.erase (vec.begin()+5);
  //vec.erase (vec.begin());
  //vec.erase (vec.end());
  std::cout << "capacity : "<< vec.capacity() << std::endl;
  std::cout << "size     : "<<vec.size() << std::endl;

  vec.erase(vec.begin(), vec.begin()+3);
  std::cout << "capacity : "<<vec.capacity()<<std::endl;
  std::cout << "size     : "<<vec.size()<<std::endl;

  std::cout << " vec contains    :";
  for (unsigned i=0; i< vec.size(); ++i)
    std::cout << ' ' <<  vec[i];
  std::cout << '\n';

}

void ft_get_allocator()
{
  std::vector<int> myvector;
  int * p;
  unsigned int i;

  // allocate an array with space for 5 elements using vector's allocator:
  p = myvector.get_allocator().allocate(5);

  // construct values in-place on the array:
  for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

  std::cout << "The allocated array contains:";
  for (i=0; i<5; i++) std::cout << ' ' << p[i];
  std::cout << '\n';

  // destroy and deallocate:
  for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
  myvector.get_allocator().deallocate(p,5);

  std::cout << "***********************" << std::endl;

  vector<int> vec;
  int * pointer;
  unsigned int l;



  pointer = vec.get_allocator().allocate(5);


  for(l = 0; l < 5; l++)
    vec.get_allocator().construct(&pointer[l], l);

  std::cout << "The allocated array contains:";
  for (l=0; l<5; l++)
    std::cout << ' ' << pointer[l];
  std::cout << '\n';

  for (l=0; l<5; l++)
    vec.get_allocator().destroy(&pointer[l]);
  vec.get_allocator().deallocate(pointer,5);


}

void ft_insert()
{
  std::vector<int> myvector (3,100);
  std::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  std::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "***************************\n";

  vector<int> vec (3,100);
  vector<int>::iterator it;

  it = vec.begin();
  it = vec.insert ( it , 200 );

  vec.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = vec.begin();

  std::vector<int> anothervector (2,400);
  vec.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  vec.insert (vec.begin(), myarray, myarray+3);

  std::cout << "vec contains     :";
  for (it=vec.begin(); it<vec.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

int main ()
{
  //ft_resize();
  //ft_erase();
  //ft_get_allocator();
  ft_insert();
  //system("leaks a.out");
  return 0;
}

