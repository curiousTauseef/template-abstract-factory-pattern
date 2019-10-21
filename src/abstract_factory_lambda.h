#ifndef ABSTRACT_FACTORY_LAMBDA_H_
#define ABSTRACT_FACTORY_LAMBDA_H_

#include <functional>
#include <memory>
#include <string>

class AbstractProductA {
public:
    virtual ~AbstractProductA() = default;
    virtual std::string GetName() const = 0;
};

template <typename Derived>
class ProductA : public AbstractProductA {
public:
    std::string GetName() const override
    {
        return static_cast<const Derived&>(*this).GetName();
    }
};

class ConcreteProductAX : public ProductA<ConcreteProductAX> {
public:
    std::string GetName() const
    {
        return "Type: Product AX";
    }
};

class ConcreteProductAY : public ProductA<ConcreteProductAY> {
public:
    std::string GetName() const
    {
        return "Type: Product AY";
    }
};

class AbstractProductB {
public:
    virtual ~AbstractProductB() = default;
    virtual std::string GetName() const = 0;
};

template <typename Derived>
class ProductB : public AbstractProductB {
public:
    std::string GetName() const override
    {
        return static_cast<const Derived&>(*this).GetName();
    }
};

class ConcreteProductBX : public ProductB<ConcreteProductBX> {
public:
    std::string GetName() const
    {
        return "Type: Product BX";
    }
};

class ConcreteProductBY : public ProductB<ConcreteProductBY> {
public:
    std::string GetName() const
    {
        return "Type: Product BY";
    }
};

class Factory {
public:
    using FunctionA = std::function<auto()->std::unique_ptr<AbstractProductA>>;
    using FunctionB = std::function<auto()->std::unique_ptr<AbstractProductB>>;

    Factory(FunctionA func_a, FunctionB func_b)
        : func_a_{ std::move(func_a) }
        , func_b_{ std::move(func_b) }
    {
    }

    auto CreateProductA() const
    {
        return func_a_();
    }

    auto CreateProductB() const
    {
        return func_b_();
    }

private:
    FunctionA func_a_;
    FunctionB func_b_;
};

std::function<auto()->std::unique_ptr<AbstractProductA>> CreateProductA;
std::function<auto()->std::unique_ptr<AbstractProductB>> CreateProductB;

void InstallFactoryX()
{
    CreateProductA = [] { return std::make_unique<ConcreteProductAX>(); };
    CreateProductB = [] { return std::make_unique<ConcreteProductBX>(); };
}

void InstallFactoryY()
{
    CreateProductA = [] { return std::make_unique<ConcreteProductAY>(); };
    CreateProductB = [] { return std::make_unique<ConcreteProductBY>(); };
}

#endif // ABSTRACT_FACTORY_LAMBDA_H_