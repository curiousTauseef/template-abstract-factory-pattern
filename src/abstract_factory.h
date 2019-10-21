#ifndef ABSTRACT_FACTORY_H_
#define ABSTRACT_FACTORY_H_

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

class AbstractFactory {
public:
    virtual ~AbstractFactory() = default;
    virtual std::unique_ptr<AbstractProductA> CreateProductA() const = 0;
    virtual std::unique_ptr<AbstractProductB> CreateProductB() const = 0;
};

template <typename Derived>
class Factory : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> CreateProductA() const override
    {
        return static_cast<const Derived&>(*this).CreateProductA();
    }

    std::unique_ptr<AbstractProductB> CreateProductB() const override
    {
        return static_cast<const Derived&>(*this).CreateProductB();
    }
};

class ConcreteFactoryX : public Factory<ConcreteFactoryX> {
public:
    std::unique_ptr<AbstractProductA> CreateProductA() const
    {
        return std::make_unique<ConcreteProductAX>();
    }

    std::unique_ptr<AbstractProductB> CreateProductB() const
    {
        return std::make_unique<ConcreteProductBX>();
    }
};

class ConcreteFactoryY : public Factory<ConcreteFactoryY> {
public:
    std::unique_ptr<AbstractProductA> CreateProductA() const
    {
        return std::make_unique<ConcreteProductAY>();
    }

    std::unique_ptr<AbstractProductB> CreateProductB() const
    {
        return std::make_unique<ConcreteProductBY>();
    }
};

#endif // ABSTRACT_FACTORY_H_