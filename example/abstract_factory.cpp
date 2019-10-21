#include <iostream>
#include <memory>

#include "abstract_factory.h"

int main()
{
    std::unique_ptr<AbstractFactory> factory_x{ std::make_unique<ConcreteFactoryX>() };
    std::unique_ptr<AbstractFactory> factory_y{ std::make_unique<ConcreteFactoryY>() };

    std::unique_ptr<AbstractProductA> product_ax{ factory_x->CreateProductA() };
    std::cout << product_ax->GetName() << std::endl;

    std::unique_ptr<AbstractProductA> product_ay{ factory_y->CreateProductA() };
    std::cout << product_ay->GetName() << std::endl;

    std::unique_ptr<AbstractProductB> product_bx{ factory_x->CreateProductB() };
    std::cout << product_bx->GetName() << std::endl;

    std::unique_ptr<AbstractProductB> product_by{ factory_y->CreateProductB() };
    std::cout << product_by->GetName() << std::endl;
}