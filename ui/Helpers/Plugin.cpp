#include "Plugin.h"
#include <wx/filename.h>
#include <wx/stdpaths.h>
#include <vector>

namespace Plugin {
    wxString get_plugin_src_prefix(const Platform &platform) {
#ifdef __linux__
        return (platform == Linux ? "linux_" : "wine_");
#elif _WIN32
        return "win_";
#else
#error "Unsupported platform"
#endif
    }

    wxString get_plugin_dst_prefix(const Platform &platform) {
#ifdef __linux__
        return (platform == Linux ? "linux_" : "win_");
#elif _WIN32
        (void)platform;
        return "win_";
#else
#error "Unsupported platform"
#endif
    }

    wxString get_plugin_extension(const Platform &platform) {
#ifdef __linux__
        return (platform == Linux ? ".so" : ".dll");
#elif _WIN32
        (void)platform;
        return ".dll";
#else
#error "Unsupported platform"
#endif
    }

    bool install(const Game::Type &game, const wxString &path, wxString &error) {
        bool ret = true;
        std::vector<wxString> architectures = { "x86", "x64" };
        Platform platform = Game::get_platform(game, path);
        wxString src_platform_prefix = get_plugin_src_prefix(platform);
        wxString dst_platform_prefix = get_plugin_dst_prefix(platform);
        wxString plugin_extension = get_plugin_extension(platform);

        for (auto &arch : architectures) {
            wxString pluginFile;
            wxString dst_bin;
            wxString dst_plugin;

            pluginFile = wxPathOnly(wxStandardPaths::Get().GetExecutablePath()) +
                         wxFileName::GetPathSeparator() + "Ets2Plugins" +
                         wxFileName::GetPathSeparator() + src_platform_prefix + arch +
                         wxFileName::GetPathSeparator() + "ets2-telemetry-server" +
                         plugin_extension;

            dst_bin = path + wxFileName::GetPathSeparator() + "bin" +
                      wxFileName::GetPathSeparator() + dst_platform_prefix + arch;

            dst_plugin = dst_bin + wxFileName::GetPathSeparator() + "plugins" +
                         wxFileName::GetPathSeparator() + "ets2-telemetry-server" +
                         plugin_extension;

            if (!wxDirExists(dst_bin)) {
                ret = false;
                error = "Path does not seem to be correct, please recheck.";
                break;
            }

            if (!wxDirExists(wxPathOnly(dst_plugin))) {
                if (!wxMkdir(wxPathOnly(dst_plugin))) {
                    ret = false;
                    error = "Failed to create plugin directory.";
                    break;
                }
            }

            if (!wxFileExists(pluginFile)) {
                ret = false;
                error = "Plugin can't be installed as it's missing from your installation.";
                break;
            } else {
                if (!wxCopyFile(pluginFile, dst_plugin)) {
                    ret = false;
                    error = "Failed to copy plugin.";
                    break;
                }
            }
        }

        return ret;
    }
} // namespace Plugin
