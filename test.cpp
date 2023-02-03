#include <iostream>
//#include <vector>
#include "./Vector/vector.hpp"
#include"./iterators/reverse_Iterator.hpp"
#include"./iterators/Iterator.hpp"

#include <vector>

void ft_resize()
{
  std::vector<int> myvector;

  for (int i=1;i<10;i++) 
    myvector.push_back(i);  
  std::cout << "capacity : "<<myvector.capacity() << std::endl;
  myvector.resize(5);
  std::cout << "capacity  "<<myvector.capacity() << std::endl;
  myvector.resize(20,100);
  std::cout << "capacity  "<<myvector.capacity() << std::endl;
  myvector.resize(11);
  std::cout << "capacity  "<<myvector.capacity() << std::endl;
  std::cout << "size  "<<myvector.size() << std::endl;

  std::cout << "myvector contains:";
  for (int i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  std::cout << "************************\n";


  ft::vector<int> vec;

  for(int i=1; i<10;i++)
    vec.push_back(i);
  std::cout << "capacity : "<<vec.capacity() << std::endl;
  vec.resize(5);
  std::cout << "capacity : "<<vec.capacity() << std::endl;
  vec.resize(20,100);
  std::cout << "capacity : "<<vec.capacity() << std::endl;
  vec.resize(11);
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
  
  ft::vector<int> vec;

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

  ft::vector<int> vec;
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

  ft::vector<int> vec(3, 100);
  ft::vector<int>::iterator iterator;

  iterator = vec.begin();
  iterator = vec.insert ( iterator , 200 );

  vec.insert (iterator,2,300);

  // "iterator" no longer valid, get a new one:
  iterator = vec.begin();

  ft::vector<int> vec_second (2,400);
  vec.insert (iterator+2,vec_second.begin(),vec_second.end());

  int arr [] = { 501,502,503 };
  vec.insert (vec.begin(), arr, arr+3);
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


  ft::vector<int> original (3,0);
  ft::vector<int> second (original);

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

  ft::vector<int> vec;
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

  ft::vector<int> ok;
  size = ok.capacity();
  std::cout << "making ok grow:\n";
  for (int i=0; i<100; ++i) {
    ok.push_back(i);
    if (size!=ok.capacity()) {
      size = ok.capacity();
      std::cout << "capacity changed: " << size << '\n';
    }
  }

  ft::vector<int> ko;
  size = ko.capacity();
  ko.reserve(100);   // this is the only difference with ok above
  std::cout << "making ko grow:\n";
  for (int i=0; i<100; ++i) {
    ko.push_back(i);
    if (size!=ko.capacity()) {
      size = ko.capacity();
      std::cout << "capacity changed: " << size << '\n';
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

  ft::vector<int> ok (3,100);   // three ints with a value of 100
  ft::vector<int> ko (5,200);   // five ints with a value of 200

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

  ft::vector<int> vec;
  typedef ft::vector<int>::iterator it;
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

template <typename Iter>
void print_range(Iter first, Iter last)
{
    for (Iter it = first; it != last; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
void ft_()
{
  ft::vector<double> v;
  for (int i = 0; i < 26; ++i) {
            v.push_back(45.0123);
    if (!(v.capacity() >= v.size())) {
          std::cout << "msg";
            std::cout<<"Capacity is smaller than size"<<std::endl;
        } else {
            std::cout<<"Capacity Ok"<<std::endl;;
        }  
        std::cout << "\nVector content:\n";
         print_range(v.begin(), v.end());
  }
  v.push_back(6);
  std::cout << "size: " << v.size() << '\n';
  std::cout << "capacity: " << v.capacity() << '\n';
  v.push_back(-4356.8933);
  std::cout << "size: " << v.size() << '\n';
  std::cout << "capacity: " << v.capacity() << '\n';
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

  std::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';

  std::cout << "*****************************\n";

  ft::vector<int> lawal;
  ft::vector<int> tani;
  ft::vector<int> talt;

  lawal.assign (7,100);   // 7 ints with a value of 100
  std::cout << "size     : "<<lawal.size()<<std::endl;
  std::cout << "capacity : "<<lawal.capacity()<<std::endl;
  lawal.assign (20,100);   // 7 ints with a value of 100
  std::cout << "size     : "<<lawal.size()<<std::endl;
  std::cout << "capacity : "<<lawal.capacity()<<std::endl;

  ft::vector<int>::iterator iter;
  iter = lawal.begin()+1;

  tani.assign (iter,lawal.end()-1); // the 5 central values of lawal

  int mine[] = {1776,7,4};
  talt.assign (mine,mine+3);   // assigning from array.

  std::cout << "Size of lawal: " << int (lawal.size()) << '\n';
  std::cout << "Size of tani: " << int (tani.size()) << '\n';
  std::cout << "Size of talt: " << int (talt.size()) << '\n';
}

void ft_assign_tester()
{
    {
      std::vector<char> v;

      v.assign(0, 'c');
      std::cout << "capacity : "<< v.capacity()<<std::endl;
      std::cout << "size : "<< v.size()<<std::endl;
      v.assign(64, 'A');
      std::cout << "capacity : "<< v.capacity()<<std::endl;
      std::cout << "size : "<< v.size()<<std::endl;

      v.assign(32, '5');
      std::cout << "capacity : "<< v.capacity()<<std::endl;
      std::cout << "size : "<< v.size()<<std::endl;

      v.assign(49, '8');
      std::cout << "capacity : "<< v.capacity()<<std::endl;
      std::cout << "size : "<< v.size()<<std::endl;

      v.assign(77, '2');
      std::cout << "capacity : "<< v.capacity()<<std::endl;
      std::cout << "size : "<< v.size()<<std::endl;

    }
    std::cout<<"***********************\n";
    { 
      ft::vector<char> v;

      v.assign(0, 'c');
      std::cout << "capacity : "<< v.capacity()<<std::endl;
      std::cout << "size : "<< v.size()<<std::endl;

      v.assign(64, 'A');
      std::cout << "capacity : "<< v.capacity()<<std::endl;
      std::cout << "size : "<< v.size()<<std::endl;

      v.assign(32, '5');
      std::cout << "capacity : "<< v.capacity()<<std::endl;
      std::cout << "size : "<< v.size()<<std::endl;

      v.assign(49, '8');
      std::cout << "capacity : "<< v.capacity()<<std::endl;
      std::cout << "size : "<< v.size()<<std::endl;

      v.assign(77, '2');
      std::cout << "capacity : "<< v.capacity()<<std::endl;
      std::cout << "size : "<< v.size()<<std::endl;

    }
    std::cout<<"***********************\n";
    {
      std::vector<std::string> v;
      size_t i = 0;
      v.assign(0, "");
      //std::cout << "capacity : "<< v.capacity()<<std::endl;
      //std::cout << "size : "<< v.size()<<std::endl;
      std::vector<std::string>::iterator it = v.begin();
      while (it != v.end())
      {
        std::cout << *it << std::endl;
        it++;
      }
      v.assign(64, "vector-string");
      //std::cout << "capacity : "<< v.capacity()<<std::endl;
      //std::cout << "size : "<< v.size()<<std::endl;
      it = v.begin();
      while (it != v.end())
      {
        std::cout << *it << std::endl;
        it++;
        i++;
      }
      std::cout << i << std::endl;
    }
    std::cout<<"***********************\n";
    {
      ft::vector<std::string> v;
      size_t i = 0;

      v.assign(0, "");
      ft::vector<std::string>::iterator it;
      it = v.begin();
      while (it != v.end())
      {
        std::cout << *it << std::endl;
        it++;
      }
      //std::cout << "capacity : "<< v.capacity()<<std::endl;
      //std::cout << "size : "<< v.size()<<std::endl;
      v.assign(64, "vector-string");
      it = v.begin();
      while (it != v.end())
      {
        std::cout << *it << std::endl;
        it++;
        i++;
      }
      std::cout << i << std::endl;
      //std::cout << "capacity : "<< v.capacity()<<std::endl;
      //std::cout << "size : "<< v.size()<<std::endl;    
    }
}

void ft_back()
{
  {  
    const std::vector<long> v(1, 9);

    std::cout << "Back: "<<v.back()<<std::endl;

    std::vector<long>::const_reference b = v.back();
    if (&b != &v[0])
      std::cout << "wrong Reference:\nb : "<<&b<<"v : "<<&v[0]<<std::endl;
  }

  std::cout <<"***********************************\n";

  {  
    const ft::vector<long> v(1, 9);

    std::cout << "Back: "<<v.back()<<std::endl;

    ft::vector<long>::const_reference b = v.back();
    if (&b != &v[0])
      std::cout << "wrong Reference:\nb : "<<&b<<"v : "<<&v[0]<<std::endl;
  }
}

int main ()
{
  //std::cout << "\\/////////////////// RESIZE : ////////////////////\n\n";
  //ft_resize();
  std::cout << "\n\\////////////////// ERASE : ////////////////////\\\n\n";
  ft_erase();
  //std::cout << "\n\\////////////////// GET_ALLOCATER : ////////////////////\\\n\n";
  //ft_get_allocator();
  //std::cout << "\n\\////////////////// INSERT : ////////////////////\\\n\n";
  //ft_insert(); // methode with template type InputIterator remains
  //std::cout << "\n\\////////////////// EQUAL_OPERATOR : ////////////////////\\\n\n";
  //ft_equal_operator();
  //std::cout << "\n\\////////////////// POP_BACK : ////////////////////\\\n\n";
  //ft_pop_back();
  //std::cout << "\n\\////////////////// RESERVE : ////////////////////\\\n\n";
  //ft_reserve();
  //std::cout << "\n\\////////////////// SWAP : ////////////////////\\\n\n";
  //ft_swap();
  //std::cout << "\n\\////////////////// REV_ITERATOR : ////////////////////\\\n\n";
  //ft_rev_iterator();
  //std::cout << "\n\\////////////////// ASSIGN : ////////////////////\\\n\n";
  //ft_assign();
  //ft_assign_tester();
  //std::cout << "\n\\////////////////// BACK : ////////////////////\\\n\n";
  //ft_back();
  //std::vector<int> vec(37, -5);
  //vec.erase(vec.begin() + 1, vec.begin() + 2);
  //std::cout << "size : "<<vec.size()<<std::endl; 
  //system("leaks a.out");
  return 0;
}

