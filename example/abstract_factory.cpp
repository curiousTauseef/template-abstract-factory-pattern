#include <iostream>
#include <memory>

#include "abstract_factory.h"

int main()
{
    std::unique_ptr<AbstractFactory> factory_x{ std::make_unique<ConcreteFactoryX>() };
    auto product_ax{ factory_x->CreateProductA() };
    auto product_bx{ factory_x->CreateProductB() };

    std::unique_ptr<AbstractFactory> factory_y{ std::make_unique<ConcreteFactoryY>() };
    auto product_ay{ factory_y->CreateProductA() };
    auto product_by{ factory_y->CreateProductB() };

    std::cout << product_ax->GetName() << std::endl;
    std::cout << product_ay->GetName() << std::endl;
    std::cout << product_bx->GetName() << std::endl;
    std::cout << product_by->GetName() << std::endl;
}