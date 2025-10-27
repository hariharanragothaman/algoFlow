"""
The idea is to abstract the creation of objects depending on
    1. business-logic
    2. Platform
    (or) other parameters

In general - The Abstract Factory Pattern - provides an interface to create objects without specifying the actual class
IN python, the interface - is simply a callable, and in python the class itself is that Callable.

Purpose:
Factory Method, defines an interface to create a single object - but it lets the subclasses decide what object to create

Use-Case
1. A class does not know what kind of objects to create.
2. Sub-classes decide what object to create
3. Class delegate the creation of objects to sub-classes.

Also called as - Virtual Constructor Pattern
"""

from typing import *

class Pet:
    def __init__(self, name: str) -> None:
        self.name = name

    def speak(self) -> None:
        raise NotImplementedError

    def __str__(self) -> str:
        raise NotImplementedError

class Dog(Pet):
    def speak(self) -> None:
        print("BOW BOW")

    def __str__(self) -> str:
        return f"Dog<{self.name}>"

class Cat(Pet):
    def speak(self) -> None:
        print("MEOW MEOW")

    def __str__(self) -> str:
        return f"Cat<{self.name}>"

class PetShop:
    def __init__(self, animal_factory: Type[Pet]):
        """
        self.pet_factory - is the name of the class
        Through this constructor of the respective class is directly called
        :param animal_factory:
        """
        self.pet_factory = animal_factory

    def buy_pet(self, name: str) -> Pet:
        """
        # This is where the sub-class get's called
        pet is the new object
        :param name:
        :return:
        """
        pet = self.pet_factory(name)
        print(f"Here is the {pet}")
        return pet

if __name__ == '__main__':
    cat_shop = PetShop(Cat)
    pet = cat_shop.buy_pet("Elizeabeth")
    pet.speak()
