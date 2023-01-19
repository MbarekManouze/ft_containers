#include <iostream>
//#include <vector>
#include "vector.hpp"
#include "Iterator.hpp"


//class MyIterator {
//public:
//    // constructor
//    MyIterator(int* data) : data_(data) {}

//    // overload the dereference operator
//    int operator*() const { return *data_; }

//    // overload the pre-increment operator
//    MyIterator& operator++() {
//        ++data_;
//        return *this;
//    }

//    // overload the equality operator
//    bool operator==(const MyIterator& other) const { return data_ == other.data_; }

//    // overload the inequality operator
//    bool operator!=(const MyIterator& other) const { return !(*this == other); }

//private:
//    int* data_;
//};


//int main()
//{
//    vector <int> vec(5);
//    vec.push_back(8);
//    vec.push_back(55);
//    vec.push_back(2002);
//    vec.push_back(1999);
//    vec.push_back(12);
//    vec.push_back(300);
//    vector<int>::iterator it_begin;
//    vector<int>::iterator it_end;
//    it_begin = vec.begin();
//    it_end = vec.end();
//    while (it_begin != it_end)
//    {
//        std::cout << *it_begin << std::endl;
//        it_begin++;
//    }
//	//int data[] = { 1, 2, 3, 4, 5 };
//	//MyIterator begin(data);
//	//MyIterator end(data + 5);

//	//for (MyIterator it = begin; it != end; ++it) {
//	//std::cout << *it << " ";
//	//}
//    //std::vector<int> v;
//    //v.push_back(1);
//    //v.push_back(2);
//    //v.push_back(3);
//    //v.push_back(4);
//    //v.push_back(5);
//    //std::vector<int>::iterator it1 = v.begin();
//    //std::vector<int>::iterator it2 = v.end();
//    //std::ptrdiff_t diff = it2 - it1; // diff is 5
//    //std::cout << diff << std::endl;
//}

#include <vector>

void ft_resize()
{
  std::vector<int> myvector;

  for (int i=1;i<10;i++) 
    myvector.push_back(i);  
  std::cout << "capacity : "<<myvector.capacity() << std::endl;
  myvector.resize(30);
  //std::cout << "capacity  "<<myvector.capacity() << std::endl;
  myvector.resize(40,100);
  //std::cout << myvector.size() << std::endl;
  myvector.resize(12);
  std::cout << "size  "<<myvector.size() << std::endl;
  myvector.resize(10,30);
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
  vec.resize(30);
  //std::cout << "capacity : "<<vec.capacity() << std::endl;
  vec.resize(40,100);
  //std::cout << vec.size() << std::endl;
  vec.resize(12);
  std::cout << "size : "<<vec.size() << std::endl;
  vec.resize(10,30);
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

