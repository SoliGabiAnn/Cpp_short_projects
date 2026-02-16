#ifndef TRADITIONAL_H
#define TRADITIONAL_H

#include <iostream>
#include <vector>
#include <string>
#include "DIP.h"

// Low-level Module 
class PersonGraph {
    
public:
    std::vector<Person*> get_children_via_graph_search(Person* p) {

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
class HighLevelResearchModule {
private:
    PersonGraph _graph;
public:
    void analyze_family_tree(Person* target) {
        // Policy setting components knows about low-level module details
        std::vector<Person*> children = _graph.get_children_via_graph_search(target);
        
        if (!children.empty()) {
            std::cout << "High-Level Policy: Found " << children.size() 
                      << " children for " << target->name << std::endl;
        } else {
            std::cout << "High-Level Policy: No children found." << std::endl;
        }
    }
};

#endif