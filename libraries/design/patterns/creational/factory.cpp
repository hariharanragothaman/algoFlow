//
// Created by Hariharan Ragothaman on 8/26/24.
//

/*
 *   Creator
 *      factoryMethod()
 *      furtherMethod()
 *
 *   ConcreteCreator
 *   ConcreteProduct
 *   Product
 *
 *
 *   Creator (PetShop)
 *      Declares the factoryMethod
 *      Call the factoryMethod
 *
 *   ConcreteCreator (cat_shop)
 *      Overwrite the factoryMethod
 *
 *   ConcreteProduct (Cat, Dog Classes)
 *      (is created by Concrete Creator & object of Concrete Creator  is independent of CreatorClass)
 *      Implements the interface
 *
 *   Product (pet)
 *      object of this class is created by factoryMethod()
 *
 *   1. Creator does not instantiate ConcreteProduct
 *
 */

#include <iostream>
using namespace std;


// Now we want to create a new-window based on existing one.
// To implemenmt factory - we need to have a class and an enum

enum class WindowType
{
    DefaultWindow,
    FancyWindow
};

// Product
class Window
{
public:
    virtual ~Window() {};
    virtual WindowType getType() const = 0;
    virtual std::string getName() const = 0;
};

// Concrete Product - (inherits Product)
class DefaultWindow: public Window
{
public:
    WindowType getType() const override
    {
        return WindowType::DefaultWindow;
    }

    std::string getName() const override
    {
        return "DefaultWindow";
    }
};

class FancyWindow: public Window
{
public:
    WindowType getType() const override
    {
        return WindowType::FancyWindow;
    }

    std::string getName() const override
    {
        return "FancyWindow";
    }
};

// Concrete Creator
Window* getNewWindow(Window* window)
{
    switch(window->getType())
    {
        case WindowType::DefaultWindow:
            return new DefaultWindow();
            break;
        case WindowType::FancyWindow:
            return new FancyWindow();
            break;
    }
    return nullptr;
}


int main()
{
    DefaultWindow defaultWindow;
    FancyWindow fancyWindow;

    const Window* defaultWindow1 = getNewWindow(&defaultWindow);
    const Window* fancyWindow1 = getNewWindow(&fancyWindow);

    cout << defaultWindow->getName();
    cout << fancyWindow.getName();

    delete defaultWindow1;
    delete fancyWindow1;

}
