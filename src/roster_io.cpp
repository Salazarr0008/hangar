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
bool load_roster([[maybe_unused]] const std::string& path,
                 [[maybe_unused]] std::vector<Mech>& roster,
                 [[maybe_unused]] int& skipped_lines) {
    return false;
}

// TODO (Checkpoint 4): implement append_line.
bool append_line([[maybe_unused]] const std::string& path,
                 [[maybe_unused]] const std::string& text) {
    return false;
}
