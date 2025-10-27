"""
Mixin is special class that provides methods to other classes through inheritance
They are not meant to stand on their own
They do not define full-fledged class hierarchy
Designed to combine with other classes to add specific functionality

Benefits: Code Re-use | Seperation of concerns | Flexibility
When to use?
    1. When we have common functionality to share across multiple classes
    2. Shared functionality is not central to primary role of the class
    3. Avoid deep inheritance and promote composition over inheritance.

"""


# Mixin Classes

class FlyMixin:
    def fly(self):
        return "I can Fly"


class SwimMixin:
    def swim(self):
        return "I can Swim"


# Primary Class

class Animal:
    def __init__(self, name):
        self.name = name

    def make_sound(self):
        pass


class Dog(Animal):
    def make_sound(self):
        return "Bark"


class Duck(Animal, FlyMixin, SwimMixin):
    def make_sound(self):
        return "Quack"


if __name__ == '__main__':
    dog = Dog("Rex")
    print(dog.name)  # Output: Rex
    print(dog.make_sound())  # Output: Bark

    duck = Duck("Daffy")
    print(duck.name)  # Output: Daffy
    print(duck.make_sound())  # Output: Quack
    print(duck.fly())  # Output: I can fly!
    print(duck.swim())  # Output: I can swim!
