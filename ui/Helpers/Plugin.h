#ifndef ETS2_TELEMETRY_SERVER_PLUGIN_H
#define ETS2_TELEMETRY_SERVER_PLUGIN_H

#include "Game.h"
#include <wx/string.h>

namespace Plugin {
    /**
     * Install plugin for game @p game in path @p path.
     *
     * @param game
     * @param arch
     * @param path
     * @param error
     * @return
     */
    bool install(const Game::Type &game, const wxString &path, wxString &error);
};

#endif //ETS2_TELEMETRY_SERVER_PLUGIN_H
