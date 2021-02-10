#include <typeindex>
#include <map>
#include <iostream>
#include <memory>
#include <typeinfo>

/*
 * Implement a TypeMap that allows different handlers to be registered
 * for different types.  The TypeMap can then be called with a value, and
 * asked to handle it.  This should cause dispatch to the registered
 * handler.
 *
 * Hint:  First create a map to map from type_info objects to handlers.
 * Store the handler in the map when it is registered.  When a value needs
 * to be handled, wrap it in a common Value base class, hiding the value
 * inside a derived class template.  Pass the Value to the handler.
 *
 * A suggested, but not required, definition of the base TypeHandler class is:
 *
 *     class TypeHandler {
 *         public:
 *             virtual void handle(std::shared_ptr<Value> v) = 0;
 *     };
 *
 * You will need to implement int_Handler and A_Handler.  Your implementations
 * will need to confirm that the correct handler was called with the correct
 * value, but can otherwise be very simple.
 *
 * You must be able to add new types without changing any existing code.  For
 * example, I must be able to write a B_handler to handle a class B without
 * changing any of the code that you write.  Failure to follow this requirement
 * will limit your maximum credit to 50%.
 */

struct A {
    double x, y;
};

struct TypeNotRegistered {};

// PUT YOUR CODE HERE.

class Base{
    public:
    ~Base(){};
    virtual void handle()=0;
};

template<typename U>
class Model: public Base{
    public:
    Model(const std::shared_ptr<U> ptr):ptr(ptr){};
    void handle(){
        ptr->handle();
    }
    const std::shared_ptr<U> ptr;
};

class TypeMap{
    public:
    TypeMap(){};
    template<typename T>
    void registr(const std::type_info& ti, std::shared_ptr<T> sp){
        my_map[std::type_index(ti)] = std::make_shared< Model<T> >(sp);
    };
    template<typename T>
    void handle(T var){
        if ( my_map.find(typeid(T)) == my_map.end() ) {
            TypeNotRegistered err;
            throw err;
        }else{
            auto temp = my_map[typeid(T)];
            temp->handle();
        }
    }
    std::map<std::type_index, std::shared_ptr<Base> > my_map;
};

class int_Handler{
    public:
    void handle(){
        std::cout<<"int\n";
    }
    void handle(int a){
        std::cout<<a<<std::endl;
    }
};
class A_Handler{
    public:
    void handle(){
        std::cout<<"A\n";
    }
    void handle(A a){
        std::cout<<a.x<<", "<<a.y<<std::endl;
    }
};

int
main() {

    TypeMap tm;
    // Registers a handler for a type.
    tm.registr(typeid(int), std::make_shared<int_Handler>());
    tm.registr(typeid(A), std::make_shared<A_Handler>());

    // Calls the appropriate type handler with the given value.
    tm.handle(2); // Calls int_Handler.
    A a = {1.1,2.2};
    tm.handle(a); // Calls A_handler.
    try {
        tm.handle(1.1);
    } catch (const TypeNotRegistered &e) {
        std::cerr << "double not registered." << std::endl;
    }
}
