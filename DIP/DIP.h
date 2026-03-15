#ifndef DIP_H
#define DIP_H

#include <iostream>
#include <vector>
#include <string>

// Low-level component implementation detail
struct Person {
    std::string name;
    Person* father = nullptr;
    Person* mother = nullptr;
    std::vector<Person*> spouses; 
    std::vector<Person*> direct_children;
    Person(const std::string& n) : name(n) {}
};


// This interface defines the simple behavior required by the high-level policy layer
class IRelationshipBrowser {
public:
    virtual std::vector<Person*> find_children(Person* p) = 0;
    virtual ~IRelationshipBrowser() = default;
};


// The detail (PersonGraph) DEPENDS on the abstraction (IRelationshipBrowser).
class PersonGraphDIP : public IRelationshipBrowser {
public:
    std::vector<Person*> find_children(Person* p) override {

        std::cout << "Accessing PersonGraph to retrieve children of " << p->name << std::endl;
        
        if (p->direct_children.empty()) {
            std::cout << "Graph search found no direct children." << std::endl;
        } else {
            std::cout << "Returning " << p->direct_children.size() << " children based on direct links." << std::endl;
        }
        return p->direct_children; 
    }
};


// Policy-setting component
class HighLevelResearchModuleDIP {
private:
    IRelationshipBrowser& _browser;

public:
    HighLevelResearchModuleDIP(IRelationshipBrowser& browser) : _browser(browser) {}

    void analyze_family_tree(Person* target) {
        // High-level module calls the abstract interface method
        std::vector<Person*> children = _browser.find_children(target);
        
        if (!children.empty()) {
            std::cout << "High-Level Policy: Found " << children.size() 
                      << " children for " << target->name << std::endl;
        } else {
            std::cout << "High-Level Policy: No children found." << std::endl;
        }
    }
};

#endif