#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//// for 7.1.1
// struct A
// {
//     float data;
// };
// struct B
// {
//     A a;
// };
// struct C
// {
//     B* b;
//     // B b;
// };
// struct D
// {
//     C c;
// };

//// for 7.1.2
struct B
{
    float d, e;
};
struct A
{
    float a, b, c;
    B* ptr;
    B mem;
};


//// for 7.1.3
struct point
{
    float x, y;
};
void bar(point p3)
{
    p3.x *= .5f;
    p3.y *= .5f;
}
void foo(point& p1, point p2)
{
    point p3;
    p3.x = p1.x + p2.x; 
    p3.y = p1.y + p2.y; 
    bar(p3);
    p1.x -= p3.x;
    p1.y -= p3.y;
}


int main(){

    // pointer vs refrences
    // memory allocation
    // pass by value vs pass by refrence
    
    // std::cout << "Task 7.1.1" << std::endl;
    
    // D d;
    // B b;
    // b.a.data = 42.0f;
    // d.c.b = &b;
    
    // float data = d.c.b->a.data;
    // std::cout << "data: " << data << std::endl;

    // D* ptr_d = &d;
    // std::cout << "data: " << ptr_d->c.b->a.data << std::endl;

    //// Answer: ptr_d->c.b->a.data


    // std::cout << "\n\nTask 7.1.2" << std::endl;
    A stack;
    A* stack_ptr = nullptr;
    std::cout << "stack_ptr: " << stack_ptr << std::endl;
    std::cout << "&stack_ptr->a: " << &stack_ptr->a << "\t&stack_ptr->b: " << &stack_ptr->b << "\t&stack_ptr->c: " << &stack_ptr->c << std::endl;

    // stack_ptr->ptr->d = 1.1f;
    std::cout << "&stack_ptr->ptr: " << &stack_ptr->ptr << "\t&stack_ptr->ptr->d: " << &stack_ptr->ptr << std::endl;
    std::cout << "&stack_ptr->mem.d: " << &stack_ptr->mem.d << "\t&stack_ptr->mem.e: " << &stack_ptr->mem.e << std::endl;
    


    std::cout << "\n\n&stack: " << &stack << std::endl;
    std::cout << "&stack.a: " << &stack.a << "\t&stack.b: " << &stack.b << "\t&stack.c: " << &stack.c << std::endl;
    std::cout << "&stack.ptr->d: " << &stack.ptr->d << "\t&stack.ptr->e: " << &stack.ptr->e << std::endl;
    std::cout << "&stack.mem.d: " << &stack.mem.d << "\t&stack.mem.e: " << &stack.mem.e << std::endl;
    
    //// Answer: 
    // A+0x0        stack, stack.a
    // A+0x4        stack.b
    // A+0x8        stack.c
    // A+0xC        ????
    // A+0x10       stack->ptr, stack->ptr->d
    // A+0x14       stack->ptr->e
    // A+0x18       stack.mem.d
    // A+0x1c       stack.mem.e

    // std::cout << "\n\nTask 7.1.3" << std::endl;
    
    // point a, b;
    // a.x = b.y = 1;
    // a.y = b.x = 0;

    // std::cout << "a.x: " << a.x << "\ta.y: " << a.y << "\tb.x: " << b.x << "\tb.y: " << b.y << "\n";
    // foo(a, b);
    // std::cout << "a.x: " << a.x << "\ta.y: " << a.y << "\tb.x: " << b.x << "\tb.y: " << b.y << "\n";
    
    //// Answer: 
    // Before: a.x: 1  a.y: 0  b.x: 0  b.y: 1
    // After:  a.x: 0  a.y: -1 b.x: 0  b.y: 1
}