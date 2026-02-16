#include <iostream>
#include "Traditional.h"
#include "DIP.h"

// Example Usage (Client/Main function):
int main() {
    Person alice{"Alice"};
    alice.direct_children.push_back(new Person{"Bob"});
    alice.direct_children.push_back(new Person{"Charlie"});
    
    std::cout << "--- TRADITIONAL APPROACH (VIOLATES DIP) ---" << std::endl;
    HighLevelResearchModule traditionalModule;
    traditionalModule.analyze_family_tree(&alice);
    std::cout << "\n";
    
    std::cout << "--- DIP APPROACH (DEPENDENCY INVERTED) ---" << std::endl;
    PersonGraphDIP concreteGraph;
    HighLevelResearchModuleDIP dipModule(concreteGraph); 
    dipModule.analyze_family_tree(&alice);
    
    return 0;
}