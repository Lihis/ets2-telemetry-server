#include "Game.h"
#ifdef __linux__
#include <wx/stdpaths.h>
#endif

namespace Game {
    Platform get_platform(const Type &game, const wxString &game_path) {
        Platform platform;

#ifdef __linux__
        platform = Linux;

        switch (game) {
            case ATS:
                if (wxDirExists(game_path + "/bin/win_x64")) {
                    platform = Wine;
                }
            case ETS2:
                if (wxDirExists(game_path + "/bin/win_x64")) {
                    platform = Wine;
                }
            default:
                break;
        }
#elif _WIN32
        (void)game;
        (void)game_path;
        platform = Windows;
#else
#error "Platform not supported."
        (void)game;
        (void)game_path;
        platform = macOS;
#endif

        return platform;
    }
} // namespace Game
