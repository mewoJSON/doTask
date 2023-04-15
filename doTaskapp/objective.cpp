#pragma once

#include <vector>
#include <string>

class myObjective {
    public:
        //primary items
        std::string name;
        std::string date;
        std::string type;

        // secondary items
        std::string description = "";
        int score = 0;
        bool done = false;

};
