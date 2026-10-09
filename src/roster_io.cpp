#include "roster_io.h"

#include <fstream>
#include <sstream>

// TODO (Checkpoint 1): implement save_roster.
// Remove [[maybe_unused]] from a parameter once you use it.
bool save_roster(const std::vector<Mech>& roster,
                 const std::string& path) {
    std::ofstream roster_file(path);

    if (!roster_file.is_open()) {
        return false;
    }

    // Write mech stats to the file
    for (const Mech& mech : roster) {
        roster_file << mech.name() << ","
                    << mech.hp() << ","
                    << mech.attack() << ","
                    << mech.armor() << "\n";
    }

    roster_file.close();
    return roster_file.good();
}
// TODO (Checkpoints 2 and 3): implement load_roster.
bool load_roster(const std::string& path,
                 std::vector<Mech>& roster,
                 int& skipped_lines) {

    std::ifstream roster_file(path);
    
    // open check
    if (!roster_file.is_open()) {
        return false;

  }
            skipped_lines = 0;
            std::vector<Mech> loaded_roster;
            std::string line;
            // read each line
            while (std::getline(roster_file, line)) {
            std::stringstream row(line);
            std::string name;
            std::getline(row, name, ',');
            std::string hp_text;
            std::getline(row, hp_text, ',');
            std::string attack_text;
            std::getline(row, attack_text, ',');
            std::string armor_text;
            std::getline(row, armor_text, ',');
            //checks for missing data
           if (name.empty()) {   
            skipped_lines++;
            continue;
}
            //checks for missing data
           if (hp_text.empty()) {
            skipped_lines++;
            continue;

            }
            //checks for missing data
            if (attack_text.empty()) {
            skipped_lines++;
            continue;
            
            
            }
            //checks for missing data
            if (armor_text.empty()) {
            skipped_lines++;
            continue;
}
    int hp = std::stoi(hp_text);
    int attack = std::stoi(attack_text);
    int armor = std::stoi(armor_text);
    loaded_roster.emplace_back(name, hp, attack, armor);


}
// Update roster
roster = loaded_roster;

return true;

}

// TODO (Checkpoint 4): implement append_line.
bool append_line([[maybe_unused]] const std::string& path,
                 [[maybe_unused]] const std::string& text) {
    return false;
}
