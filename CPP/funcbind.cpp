#include <iostream>
#include <string>
#include <functional>

using std::placeholders::_1;

struct Foo {
   Foo(int num) : num_(num) {}
   void print_add(int i) {
       num_  = num_ + i;
       std::cout << num_ << '\n'; }
   int num_;
};

void print_add(int i)
{ 
    std::cout << i << '\n'; 
}

int main()
{
    Foo foo(8);

    std::function<void()> f_display_1 = std::bind(print_add, 1);
    f_display_1();
   
    std::function<void()> f_display_2 = std::bind(&Foo::print_add, foo, 2);
    f_display_2();
     
    std::function<void(int)> f_add_display_4= std::bind( &Foo::print_add, &foo, _1 );
    f_add_display_4(4);
    
    std::function<void(int)> f_add_display_3= std::bind( &Foo::print_add, foo, _1 );
    f_add_display_3(6);
    
    f_add_display_4(8);
    
    
    return 0;
}
