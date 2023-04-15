#pragma once

#include <vector>
#include <string>


/*
 * Class for task entries.
 * Divided between primary and secondary properties
 * (primary must be defined or otherwise the display functions will not work)
 * (secondary are initialized right away, do not require user input right away)
 *
 *
 */
class myObjective {
    public:
        //primary items
        std::string name;
        std::string date;
        std::string type;
        int id;
        // secondary items
        std::string description = "";
        int score = 0;
        bool done = false;

};
