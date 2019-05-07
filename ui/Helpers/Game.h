#ifndef ETS2_TELEMETRY_SERVER_GAME_H
#define ETS2_TELEMETRY_SERVER_GAME_H

#include "Platform.h"
#include <wx/string.h>

namespace Game {
    enum Type {
        ETS2 = 0,
        ATS = 1
    };

    /**
     * Determine game platform.
     *
     * On Linux game path is checked is if it is installed natively or via
     * Proton.
     * @param game
     * @param game_path
     * @return
     */
    Platform get_platform(const Type &game, const wxString &game_path);
}

#endif //ETS2_TELEMETRY_SERVER_GAME_H
