configure_file(index.html.in "${CMAKE_CURRENT_SOURCE_DIR}/index.html")

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/index.html"
        cordova.js
        dashboard-host.css
        dashboard-host.html
        index.css
        DESTINATION
        etc
        )

install(DIRECTORY
        images
        scripts
        skins
        DESTINATION
        etc
        )
