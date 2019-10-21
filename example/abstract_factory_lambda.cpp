#include <iostream>
#include <memory>

#include "abstract_factory_lambda.h"

int main()
{
    // Factory factory_x{
    //     [] { return std::make_unique<ConcreteProductAX>(); },
    //     [] { return std::make_unique<ConcreteProductBX>(); }
    // };
    // auto product_ax{ factory_x.CreateProductA() };
    // auto product_bx{ factory_x.CreateProductB() };

    // Factory factory_y{
    //     [] { return std::make_unique<ConcreteProductAY>(); },
    //     [] { return std::make_unique<ConcreteProductBY>(); }
    // };
    // auto product_ay{ factory_y.CreateProductA() };
    // auto product_by{ factory_y.CreateProductB() };

    InstallFactoryX();
    auto product_ax{ CreateProductA() };
    auto product_bx{ CreateProductB() };

    InstallFactoryY();
    auto product_ay{ CreateProductA() };
    auto product_by{ CreateProductB() };

    std::cout << product_ax->GetName() << std::endl;
    std::cout << product_ay->GetName() << std::endl;
    std::cout << product_bx->GetName() << std::endl;
    std::cout << product_by->GetName() << std::endl;
}