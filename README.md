# Polynomial investigate project
## General
- I made this project as a part of my B.Sc degree in Computer Science, in OOP course.
- I made this project with C++, please view comments to understand it better.
- The project's idea was based on a linked-list (Polynomial) of Monomials.

## Classes and possibilites
### Monomial:
1. There are 3 kinds of constructors:
- Build Monomial by 2 numbers (Coefficient will be double, and degree will be int)
- Build Monomial by other Monomial (Copy constructor)
- Build Monomial from a string - that will parse your string and make it a new Monomial
    String allowed templates:
    1. 'Coefficient'x^'Degree' i.e: 3x^3
    2. x^'Degree' i.e: x^3
    3. 'Coefficient'x i.e.: 1x
    4. x
    5 'Coefficient' i.e: 3
2. Setters:
  - setCofficient
  - setDegree
  - setNext (for next monom, will be used in Polynomial)
3. Getters:
  - getCofficient
  - getDegree
  - getNext
4. getNumberOfMonomials - That will return the currently number of Monomials
5. print - That will print the Monomial.
6. add - A bool function that will return True or False (depends if you can add between 2 monomials)

### Polynomial:
1. There are 2 kinds of constructors:
  - Default constructor
  - Copy constructor
2. print - That will print the whole Polynomial.
3. add - That should get a Monomial and it will add the Monomial to the currently Polynomial.
4. RemoveNodes - That will clear the whole Polynomial from nodes.

### License:
Feel free to use, change and do whatever you want with this code.
