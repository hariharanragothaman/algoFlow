//
// Created by Hariharan Ragothaman on 8/26/24.
//

#include <iostream>
using namespace std;


// Product
class Window
{
public:
    virtual Window* create() = 0;
    virtual  Window* clone() = 0;
    virtual ~Window() {};
};

// Concrete Products
class DefaultWindow: public Window
{
    DefaultWindow* create() override
    {
        cout << "Creating Default Window" << endl;
        return new DefaultWindow;
    }

    DefaultWindow* clone() override
    {
        cout << "Cloning Default Window" << endl;
        return new DefaultWindow(*this);
    }
};
class FancyWindow: public Window
{
    FancyWindow* create() override
    {
        cout << "Creating Fancy Window" << endl;
        return new FancyWindow;
    }

    FancyWindow* clone() override
    {
        cout << "Cloning Default Window" << endl;
        return new FancyWindow(*this);
    }
};

Window* createWindow(Window& oldWindow)
{
    return oldWindow.create();
}

// Constructor takes this pointer in membor function - and copy-constructed Window
Window* cloneWindow(Window& oldWindow)
{
    return oldWindow.clone();
}

int main()
{
    DefaultWindow defaultWindow;
    FancyWindow fancyWindow;

    const Window* defaultWindow1 = createWindow(defaultWindow);
    const Window* fancyWindow1 = createWindow(fancyWindow);

    delete defaultWindow1;
    delete fancyWindow1;
}
