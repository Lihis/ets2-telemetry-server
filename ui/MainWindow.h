#ifndef ETS2_TELEMETRY_SERVER_MAINWINDOW_H
#define ETS2_TELEMETRY_SERVER_MAINWINDOW_H

#include "Base/MainWindow.h"
#include "IApplication.h"
#include "Config.h"
#include <map>

class MainWindow : public Base::MainWindow {
public:
    explicit MainWindow(IApplication *app);

protected:
    void interface_changed(wxCommandEvent &event) final;
    void check_game_status(wxTimerEvent &event) final;

private:

    void update_urls();

    /**
     * Show setup dialog
     *
     * @param event
     */
    void on_setup(wxCommandEvent &event);

    /**
     * Exit application
     *
     * @param event
     */
    void on_exit(wxCommandEvent &event);

    /**
     * Show About dialog
     *
     * @param event
     */
    void on_about(wxCommandEvent &event);

    IApplication *m_app;
};


#endif //ETS2_TELEMETRY_SERVER_MAINWINDOW_H
