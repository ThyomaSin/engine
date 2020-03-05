#include <iostream>
#include <vector>
#include "DataStorage.hpp"

class TestComponent: public Component
{
    public:


};

main()
{
    DataStorage data;
    GameObject obj1;
    obj1.name = "obj1";
    GameObject obj2;
    obj2.name = "obj2";

    if(data.addObject(obj1))
        std::cout << "Added" << '\n';
    if(data.addObject(obj1))
        std::cout << "Added" << '\n'; // Must write, that this element is already aexist in data

    TestComponent comp1;
    comp1.name = typeid(TestComponent).name();

    if(obj1.addComponent(comp1))
        std::cout << "Added" << '\n';
    if(obj1.addComponent(comp1))
        std::cout << "Added" << '\n'; // Must write, that this element is already aexist in data

    if(typeid(TestComponent).name() == comp1.name)
        std::cout << "equal" << '\n';

    std::cout << typeid(TestComponent).name() << '\n';
    std::cout << comp1.name << '\n';

    TestComponent* comp2 = obj1.getComponent<TestComponent>(comp1); // I cho suvat' v functiyu????????????????????????
    std::cout << std::endl;
    std::cout << comp2 -> name;
}
