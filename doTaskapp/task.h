#include <string>

class Objective {
    public:
        Objective(std::string name,std::string type, std::string date);
    private:
        std::string name;
        std::string type;
        std::string date;

        std::string description = "";
        bool completed = false;
        int score = 0;
        std::string deadline = "";
};
