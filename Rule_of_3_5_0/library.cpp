// Temat: Zasada zero, zasada trzech, zasada pięciu
// Napisz klasę o nazwie biblioteka, która przechowuje nazwy książek. 
// Zaimplementuj kod zgodnie z zasadą trzech, pięciu i zera
// Zasada zera jest spełniona bo klasa jest przeznaczona do zarządzania zasobami biblioteki.
#include <iostream>
#include <string>

class biblioteka {
    std::string** books;
    size_t libraryCount=0;
    public:
        explicit biblioteka(std::string* bookTitles, size_t bookCount) {
            books = new std::string*[bookCount];
            libraryCount = bookCount;
            for (size_t i = 0; i < bookCount; ++i) {
                books[i] = new std::string (bookTitles[i]);
            }
        }
        ~biblioteka() {
            for (size_t i = 0; i < libraryCount; ++i) {
                delete books[i];
            }
            delete[] books;
        }
        biblioteka(const biblioteka& other) 
            : books(new std::string*[other.libraryCount]), libraryCount(other.libraryCount) {
            for (size_t i = 0; i < libraryCount; ++i) {
                books[i] = new std::string (*other.books[i]);
            }
        }
        biblioteka(biblioteka&& other) noexcept 
            : books(other.books), libraryCount(other.libraryCount) {
            other.books = nullptr;
            other.libraryCount = 0;
        }
        biblioteka& operator=(const biblioteka& other) {
            biblioteka temp(other);
            std::swap(books, temp.books);
            std::swap(libraryCount, temp.libraryCount);
            return *this;
        }
        biblioteka& operator=(biblioteka&& other) noexcept {
            std::swap(books, other.books);
            std::swap(libraryCount, other.libraryCount);
            return *this;
        }
        void printBooks() const {
            for (size_t i = 0; i < libraryCount; ++i) {
                std::cout << *books[i] << " ";
            }
            std::cout << std::endl;
        }
        void printLibraryCount() const {
            std::cout << "Library count: " << libraryCount << std::endl; 
        }
    };



int main() {
    std::string titles[] = {"Dickson","Jeffrey","Anna"};
    biblioteka myLibrary(titles, 3);
    myLibrary.printBooks();
    
    // Copy constructor
    biblioteka anotherLibrary(myLibrary);
    anotherLibrary.printBooks();
    anotherLibrary.printLibraryCount();
    myLibrary.printLibraryCount();
    
    // Move constructor - transfers ownership
    biblioteka movedLibrary(std::move(anotherLibrary));
    std::cout << "After move:" << std::endl;
    movedLibrary.printLibraryCount();
    anotherLibrary.printLibraryCount(); 
    
    // Move assignment
    biblioteka assignedLibrary = std::move(myLibrary);
    std::cout << "After move assignment:" << std::endl;
    assignedLibrary.printLibraryCount();
    myLibrary.printLibraryCount(); 
};