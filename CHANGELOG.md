## Changelog

### 3.2.5

- Another improvement for job information reset code (plugin DLL update).

### 3.2.4

- Added support for SVG, GIF, TTF and WOFF content types.

### 3.2.3

- Added support for up to 9 levels of sub directories for skins to use (previous version allowed only 5).
- Minor code refactoring.

### 3.2.2

- Fixed occasional bug in latest job information reset code (new job info might have been reset).

### 3.2.1

- Updated telemetry plugin DLL and fixed job information reset when job is done (trailer detached).
- Added support for sending UserId/Password for telemetry broadcaster to allow user identification.
- Fixed typo in property name: adblueAverageConsumption (was adblueAverageConsumpton).

### 3.2.0

- Added support for American Truck Simulator
- Added two new skins: MAN TGX (MPH) and Peterbilt 579 by NightstalkerPL, Lisek Chytrusek (by WEBX.PL)
- Added application menu to ease uninstallation and extending for future updates
- Added new GameName property to the telemetry (proposed by mkoch227)
- Fixed CPU overhead issue for some users (when CPU goes above 1%)
- Updated all project files for Visual Studio 2015 and C# 6.0

### 3.0.7

- Fixed 'Dynamic' skin size display issue.

### 3.0.6

- Fixed minor bug in the telemetry plugin with wrong hshifter.selector usage.
- Added new 'Dynamic' skin size type, cursor fixes and other refactorings (thanks to denilsonsa & Phil0499!).

### 3.0.5

- Removed small visual padding around skins. Now skins takes full canvas space (thanks to James).
- Fixed rounding problem with speed limit value, sometimes it was displayed as 79 instead of 80, etc (thanks to R0adrunner).

### 3.0.4

- Restored truck.engineOn property (separated from truck.electricOn).

### 3.0.3

- Removed truck.engineOn property which was a duplicate for truck.electricOn property causing it not to work properly inside the telemetry plugin (thanks to ivanrichwalski).

### 3.0.2

- Fixed bug with parsing date-min/max HTML attributes.
- Changed property name format inside date-min/max HTML attributes, object separation character was changed from '-' to '.', for example: **date-max="truck-fuelCapacity"** must be changed to: **date-max="truck.fuelCapacity"**. 

### 3.0.1

- Fixed iOS Safari window reload bug (window gets reloaded several times in a row).
- Added new skin "rd-info" created by van_argiano. Thank you very much!

### 3.0.0

- Changed telemetry JSON object structure by introducing complex nested types. If you develop or use 3rd party custom skin please note that it will not work as is with the new server version! You will have to update your skin files first. I have created a handy tool that will do 99% (or usually even 100%) work for you. You may [download the tool here](http://funbit.info/ets2/Telemetry-Dashboard-3.0.0-Skin-Upgrader.zip). Just drop your skin files to the  SkinFileUpgrader.exe and you will get the updated version of it (you need to upgrade dashboard.html, css and js files). The source code is included in the ZIP files as well, just in case.
- New telemetry JSON structure. All properties are now structurized in several categories: game, truck, trailer, job and navigation. To understand the new system better please refer to the [updated skin tutorial](https://raw.githubusercontent.com/Funbit/ets2-telemetry-server/master/Dashboard%20Skin%20Tutorial.pdf) and [complete telemetry property reference](Telemetry.md). 
- Removed hasJob property. You should use *trailer.attached* property instead (or add a custom *data.hasJob = data.trailer.attached;* to your dashboard.js).
- Added support for new telemetry properties: game.nextRestStopTime, game.timeScale, truck.forwardGears, truck.reverseGears, navigation.estimatedTime, navigation.estimatedDistance, navigation.speedLimit.
- Added [complete telemetry property reference](Telemetry.md). 
- Fixed aux light indicators (roof and front indicators didn't work)
- [Forked ETS2 telemetry plugin](https://github.com/Funbit/ets2-sdk-plugin) to make it a custom part of the server.
- Some bug fixes and improvements.

### 2.2.6

- Fixed trailerAttached property so it is properly changed when trailer is attached/detached. 
- Changed hasJob property, now it equals to the trailerAttached value.
- Fixed odometer for default MPH skin (was showing kilometers) *(thanks to kevindwood)* 

### 2.2.5

- Fixed truck speed rounding to avoid jumps between 0 and 1 km/h 
- Created new MPH version of the default skin
- Fixed minor bug with cruise control speed displayed as NaN sometimes (default skin)

### 2.2.4

- Fixed speedometer for Scania and Volvo skins (made the needle movement smoother) 
- Fixed floating point rendering (truck speed sometimes might have been displayed as XX.YYYY) *(big thanks to Jorji_costava and sketch)*

### 2.2.3

- Fixed speedometer for all built-in skins (DAF, MAN, Mercedes, Volvo)
- Implemented automatic window reloading on resize (for PC) *(greetings to denilsonsa)*
- Added skin ability to control user clicks (back to menu link moved to dashboard.js) *(greetings to mkoch227)*
- Changed speed rounding algorithm to match game's speed *(greetings to 
maysaraahmad)*
- Minor comment and typo fixes

### 2.2.2

- Fixed bug in Android APK (no IP address prompt)
- Fixed Scania skin (invalid speed limit)

### 2.2.1

- Completely revamped dashboard core, including rendering and connection layers. The mobile dashboard now reflects game changes almost instantly (within 5-10ms)!
- Removed refreshRate option (now it is adjusted automatically)
- Fixed fuelWarning telemetry property (updated telemetry plugin DLL)
- Fixed NaN trailer mass when dashboard is disconnected (default skin only)
- Added some utility functions to dashboard.js (see Skin Tutorial for more info)
- Added new server status: "Connected to Ets2TestTelemetry.json"

### 2.2.0

- Added Dashboard Skin Tutorial!
- Fixed support for Cruise Control indicator and added Cruise Control Speed
- Fixed deadline time bug
- Made speed value always positive (even when reversing)
- Significantly improved skin loading speed
- Added ability to skip certain setup steps to support 3rd-party firewalls
- Added ability to manually select ETS2 game path using standard UI when it is not detected automatically
- Added wear indicators to the default skin
- Added additional status message to check if server is connected to the telemetry plugin
- Added 5 new photo realistic skins made by Klauzzy (DAF-XF, MAN-TGX, Mercedes-Atego, Scania, Volvo-FH)
- Added simple template skin
- Changed telemetry plugin DLL name from ets2-telemetry.dll to ets2-telemetry-server.dll (previous version is not compatible anymore)
- Various refactoring and improvements

### 2.1.0

- Moved to WebSockets for low-latency data updates
- Optimized UI animation (now it is SUPER SMOOTH, especially in Desktop and Mobile Safari browsers)  
- Minor fixes

### 2.0.0

- Completely rewritten client side application. All code is now written in Typescript. 
- Full support for custom skins
- Automated server installer
- Telemetry broadcasting to external URLs (see Ets2Telemetry.exe.config)
- Updated default dashboard skin
- Administrator rights are now required only for installation. Server starts under user privileges.

### 1.0.4

- Added server IP to the server window
- Minor logging improvements
- Fixed IE behavior with ajax requests (should fix Windows Phone issues)

### 1.0.3

- Fixed bug with invalid day of the week
- Improved connection stability
- Completely decoupled gauge design and gauge update engine (coded in Typescript)
- Added some scripts to simplify the installation

### 1.0.2
- Refactored gauge screen fitting algorithm, the app should work in any modern browser now 
- Added logging
- Added support for binding on a particular network interface
- Added Cordova mobile application (compiled Android APK is included in the bundle)
- Various fixes and improvements
- Made HTML5 application URL shorter

### 1.0.1
- Fixed bug with multiple network interfaces (thanks to thorerik)
- Made application run under Administrator by default (thanks to thorerik)
- Updated application icon and added it to the HTML app
- Minor refactoring and bug fixes 