#include <iostream>
//#include <vector>
#include "vector.hpp"
#include "Iterator.hpp"
#include "reverse_Iterator.hpp"

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

  //std::vector<int> anothervector (2,400);
  //myvector.insert (it+2,anothervector.begin(),anothervector.end());

  //int myarray [] = { 501,502,503 };
  //myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "***************************\n";

  vector<int> vec(3, 100);
  vector<int>::iterator iterator;

  iterator = vec.begin();
  iterator = vec.insert ( iterator , 200 );

  vec.insert (iterator,2,300);

  // "iterator" no longer valid, get a new one:
  iterator = vec.begin();

  //std::vector<int> vec_second (2,400);
  //vec.insert (iterator+2,vec_second.begin(),vec_second.end());

  //int arr [] = { 501,502,503 };
  //vec.insert (vec.begin(), arr, arr+3);
  std::cout << "vec contains     :";
  for (iterator=vec.begin(); iterator<vec.end(); iterator++)
    std::cout << ' ' << *iterator;
  std::cout << '\n';
}

void ft_equal_operator()
{
  std::vector<int> foo (3,0);
  std::vector<int> bar (foo);

  //bar = foo;
  //foo = std::vector<int>();

  std::cout << "Size of foo: " << int(foo.size()) << '\n';
  std::cout << "Size of bar: " << int(bar.size()) << '\n';

  std::cout << "*************************" << std::endl;


  vector<int> original (3,0);
  vector<int> second (original);

  //second = original;
  //original = vector<int>();

  std::cout << "Size of original: " << int(original.size()) << '\n';
  std::cout << "Size of second: " << int(second.size()) << '\n';
}

void ft_pop_back(){
  std::vector<int> myvector;
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  myvector.pop_back();
  std::cout <<"size     : " <<myvector.size() << std::endl;
  std::cout <<"capacity : " <<myvector.capacity() << std::endl; 
  myvector.pop_back();
  std::cout <<"size     : " <<myvector.size() << std::endl;
  std::cout <<"capacity : " <<myvector.capacity() << std::endl; 
  myvector.pop_back();
  std::cout <<"size     : " <<myvector.size() << std::endl;
  std::cout <<"capacity : " <<myvector.capacity() << std::endl; 
  std::cout << "*************************\n";

  vector<int> vec;
  vec.push_back (100);
  vec.push_back (200);
  vec.push_back (300);

  vec.pop_back();
  std::cout <<"size     : " <<vec.size() << std::endl;
  std::cout <<"capacity : " <<vec.capacity() << std::endl; 
  vec.pop_back();
  std::cout <<"size     : " <<vec.size() << std::endl;
  std::cout <<"capacity : " <<vec.capacity() << std::endl; 
  vec.pop_back();
  std::cout <<"size     : " <<vec.size() << std::endl;
  std::cout <<"capacity : " <<vec.capacity() << std::endl;
}

void ft_reserve()
{
  std::vector<int>::size_type sz;

  std::vector<int> foo;
  sz = foo.capacity();
  std::cout << "making foo grow:\n";
  for (int i=0; i<100; ++i) {
    foo.push_back(i);
    if (sz!=foo.capacity()) {
      sz = foo.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }

  std::vector<int> bar;
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

  std::cout << "***************************" << std::endl;

  std::vector<int>::size_type size;

  vector<int> ok;
  size = ok.capacity();
  std::cout << "making ok grow:\n";
  for (int i=0; i<100; ++i) {
    ok.push_back(i);
    if (size!=ok.capacity()) {
      size = ok.capacity();
      std::cout << "capacity changed: " << size << '\n';
    }
  }

  vector<int> ko;
  size = ko.capacity();
  ko.reserve(100);   // this is the only difference with ok above
  std::cout << "making ko grow:\n";
  for (int i=0; i<100; ++i) {
    //std::cout << "ihoo\n";
    ko.push_back(i);
    if (size!=ko.capacity()) {
      size = ko.capacity();
      std::cout << "capacity changed: " << size << '\n';
      //std::cout << "_size    changed: " << ko.size() << '\n';
    }
  }


}

void ft_swap()
{
  std::vector<int> foo (3,100);   // three ints with a value of 100
  std::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';

  std::cout << "***************************\n";

  vector<int> ok (3,100);   // three ints with a value of 100
  vector<int> ko (5,200);   // five ints with a value of 200

  ok.swap(ko);

  std::cout << "ok contains :";
  for (unsigned i=0; i<ok.size(); i++)
    std::cout << ' ' << ok[i];
  std::cout << '\n';

  std::cout << "ko contains :";
  for (unsigned i=0; i<ko.size(); i++)
    std::cout << ' ' << ko[i];
  std::cout << '\n';


}

void ft_rev_iterator()
{

  std::vector<int> myvector;
  std::vector<int>::reverse_iterator reverse_iterbegin;
  std::vector<int>::reverse_iterator reverse_iterend;

  myvector.push_back(4);
  myvector.push_back(4);
  myvector.push_back(3);
  myvector.push_back(7);
  myvector.push_back(25);

  reverse_iterbegin = myvector.rbegin();
  reverse_iterend   = myvector.rend();

  while (reverse_iterbegin != reverse_iterend)
  {
    std::cout << *reverse_iterbegin << std::endl;
    reverse_iterbegin++;
  }

  std::cout << "**************************\n";

  vector<int> vec;
  typedef vector<int>::iterator it;
  vec.push_back(4);
  vec.push_back(4);
  vec.push_back(3);
  vec.push_back(7);
  vec.push_back(25);
  Reverse_Iterator<it> r_iterbegin(vec.rbegin());
  Reverse_Iterator<it> r_iterend(vec.rend());


  while (r_iterbegin != r_iterend)
  {
    std::cout << *r_iterbegin << std::endl;
    r_iterbegin++;
  }

}

void ft_assign()
{
  std::vector<int> first;
  std::vector<int> second;
  std::vector<int> third;

  first.assign (7,100);   // 7 ints with a value of 100
  std::cout << "size     : "<<first.size()<<std::endl;
  std::cout << "capacity : "<<first.capacity()<<std::endl;
  first.assign (20,100);   // 7 ints with a value of 100
  std::cout << "size     : "<<first.size()<<std::endl;
  std::cout << "capacity : "<<first.capacity()<<std::endl;

  //std::vector<int>::iterator it;
  //it=first.begin()+1;

  //second.assign (it,first.end()-1); // the 5 central values of first

  //int myints[] = {1776,7,4};
  //third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  //std::cout << "Size of second: " << int (second.size()) << '\n';
  //std::cout << "Size of third: " << int (third.size()) << '\n';

  std::cout << "*****************************\n";

  vector<int> lawal;
  vector<int> tani;
  vector<int> talt;

  lawal.assign (7,100);   // 7 ints with a value of 100
  std::cout << "size     : "<<lawal.size()<<std::endl;
  std::cout << "capacity : "<<lawal.capacity()<<std::endl;
  lawal.assign (20,100);   // 7 ints with a value of 100
  std::cout << "size     : "<<lawal.size()<<std::endl;
  std::cout << "capacity : "<<lawal.capacity()<<std::endl;

  //vector<int>::iterator it;
  //it=lawal.begin()+1;

  //tani.assign (it,lawal.end()-1); // the 5 central values of lawal

  //int myints[] = {1776,7,4};
  //talt.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of lawal: " << int (lawal.size()) << '\n';
  //std::cout << "Size of tani: " << int (tani.size()) << '\n';
  //std::cout << "Size of talt: " << int (talt.size()) << '\n';


}

int main ()
{
  //ft_resize();
  //ft_erase();
  //ft_get_allocator();
  //ft_insert(); // methode with template type InputIterator remains
  //ft_equal_operator();
  //ft_pop_back();
  //ft_reserve();
  //ft_swap();
  //ft_rev_iterator();
  ft_assign();
  system("leaks a.out");
  return 0;
}

