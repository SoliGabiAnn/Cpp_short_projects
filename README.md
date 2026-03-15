# Cpp short projects
In this repository multiple programming paradigms and patterns were tested using short projects as examples.

## Rule of 3, 5, 0
### What does this rule entail?
The **Rule of 3, 5, 0** is a C++ guideline for managing class resource lifecycle:
- **Rule of 3**: If a class defines a destructor, copy constructor, or copy assignment operator, it must define all three.
- **Rule of 5**: With modern C++, also define move constructor and move assignment operator for efficiency.
- **Rule of 0**: If your class doesn't manage raw resources, define none of these—let the compiler generate defaults.

### How was this implemented?
The [biblioteka](Rule_of_3_5_0/library.cpp) class manages a dynamic array of book titles. It implements:
- **Destructor**: Deallocates dynamically allocated book strings and the array.
- **Copy constructor/assignment**: Creates deep copies of book data to avoid shared ownership issues.
- **Move constructor/assignment**: Efficiently transfers ownership using `std::move` and leaves the source object in a valid state.

Example: `biblioteka` can be safely copied (full data duplication) or moved (ownership transfer) without memory leaks.

## Decorator Programming Pattern
### Characteristics
The **Decorator Pattern** attaches additional responsibilities to an object dynamically, providing a flexible alternative to subclassing. It wraps an object with a decorator that has the same interface but adds behavior or state.
- Decorators can be stacked to combine multiple enhancements.
- Each decorator delegates to the wrapped object and adds its own functionality.
- More flexible than inheritance for combining features.

### Implementation
The [Decorator/Main.cpp](Decorator/Main.cpp) implements a coffee shop example:
- **Base class** [Napoj.h](Decorator/Napoj.h): Defines the interface with `getOpis()` (description) and `getCena()` (price).
- **Concrete beverages**: `Esspresso`, `Herbata`, `Americano` are base drinks.
- **Decorators** [Dodatki.h](Decorator/Dodatki.h): `Mleko` (milk), `BitaSmietana` (whipped cream), `SyropKarmelowy` (caramel syrup) wrap a drink and enhance its description and price.

Example: Creating `Esspresso` → adding `Mleko` → adding `BitaSmietana` results in a stacked beverage with combined properties without creating separate classes for every combination.

## Strategy Programming Pattern
### Characteristics
The **Strategy Pattern** defines a family of algorithms, encapsulates each one, and makes them interchangeable. High-level logic depends on abstractions, not concrete implementations, allowing runtime algorithm selection.

### Implementation
The [Strategy/](Strategy/) system demonstrates user management with pluggable components:
- **Abstractions** [UserRepository.h](Strategy/UserRepository.h), [EmailService.h](Strategy/EmailService.h), [Logger.h](Strategy/Logger.h): Define interfaces for persistence, notification, and logging strategies.
- **Concrete implementations**: `DatabaseUserRepository` (JSON storage), `SmtpEmailService` (email sending), `FileLogger` (file logging).
- **Manager** [UserManager.h](Strategy/UserManager.h): Accepts strategy implementations via dependency injection and uses them without knowing concrete details.

Result: Different storage backends, email providers, or logging strategies can be swapped at runtime without changing `UserManager`.

## Dependency Inversion Principle
### Characteristics
The **Dependency Inversion Principle** (DIP) states:
- High-level modules should not depend on low-level modules; both should depend on abstractions.
- Abstractions should not depend on details; details should depend on abstractions.

This decouples components and improves flexibility and testability.

### Implementation
The [DIP/](DIP/) folder contrasts two approaches:

**Traditional (Violates DIP)** [Traditional.h](DIP/Traditional.h):
- `HighLevelResearchModule` directly depends on `PersonGraph` (low-level detail).
- Tightly coupled; changes to `PersonGraph` require changes to the high-level module.

**DIP Approach** [DIP.h](DIP/DIP.h):
- Both `HighLevelResearchModuleDIP` (high-level) and `PersonGraphDIP` (low-level) depend on `IRelationshipBrowser` (abstraction).
- `IRelationshipBrowser` defines the contract; implementations follow it.
- Decoupled; high-level logic is independent of storage implementation details.

Result: The high-level analysis logic remains unchanged even if relationship data storage changes from graph search to database queries.
