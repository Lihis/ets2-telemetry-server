#include "TelemeteryHelper.h"
#include "Version.h"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <ets2-telemetry-common.hpp>
#ifdef _WIN32
#include <windows.h>
#include <tlhelp32.h>
#endif

std::string absoluteTimeToDate(time_t seconds) {
    std::stringstream time;
    struct tm *t;

    seconds *= 60;
    t = gmtime(&seconds);

    time << std::setw(4) << std::setfill('0') << t->tm_year << '-'
         << std::setw(2) << std::setfill('0') << t->tm_mon << '-'
         << std::setw(2) << std::setfill('0') << t->tm_mday << 'T'
         << std::setw(2) << std::setfill('0') << t->tm_hour << ':'
         << std::setw(2) << std::setfill('0') << t->tm_min << ':'
         << std::setw(2) << std::setfill('0') << t->tm_sec << 'Z';

    return time.str();
}

std::string getGameVersion(uint32_t major, uint32_t minor) {
    return std::to_string(major) + "." + std::to_string(minor);
}

template<typename T>
std::string toString(const T *const value) {
    char tmp[64];

    sprintf(tmp, "%s", value);

    return tmp;
}

bool TelemetryHelper::isGameRunning(std::string &game) {
    bool running;

#ifdef _WIN32
    HANDLE hProcessSnap;
    HANDLE hProcess;
    PROCESSENTRY32 pe32;

    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if(hProcessSnap == INVALID_HANDLE_VALUE) {
        running = false;
    } else {
        pe32.dwSize = sizeof(PROCESSENTRY32);

        if (!Process32First(hProcessSnap, &pe32)) {
            running = false;
        } else {
            running = false;
            do {
                if (strcmp(pe32.szExeFile, "eurotrucks2.exe") == 0 ||
                    strcmp(pe32.szExeFile, "amtrucks.exe") == 0)
                {
                    game = (strcmp(pe32.szExeFile, "eurotrucks2.exe") == 0 ? "ETS2" : "ATS");
                    running = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, 0, pe32.th32ProcessID);
                    break;
                }
            } while(Process32Next(hProcessSnap, &pe32));
        }
    }
#else
    running = true;

    if (system(R"(pgrep [e]urotrucks2 &>/dev/null)") == 0) {
        game = "ETS2";
    } else if (system(R"(pgrep [a]mtrucks &>/dev/null)") == 0) {
        game = "ATS";
    } else {
        running = false;
    }
#endif

    return running;
}

bool TelemetryHelper::getPaused(const ets2TelemetryMap_t *data) {
    return data->paused;
}

uint32_t TelemetryHelper::getTime(const ets2TelemetryMap_t *data) {
    return data->tel_rev2.time_abs;
}

uint32_t TelemetryHelper::getTimeAbsolute(const ets2TelemetryMap_t *data) {
    return data->tel_rev2.time_abs;
}

float TelemetryHelper::getLocalScale(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.localScale;
}

int32_t TelemetryHelper::getNextRestStop(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.nextRestStop;
}

float TelemetryHelper::getNavigationDistance(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.navigationDistance;
}

float TelemetryHelper::getNavigationTime(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.navigationTime;
}

float TelemetryHelper::getNavigationSpeedLimit(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.navigationSpeedLimit;
}

uint32_t TelemetryHelper::getPluginVersion(const ets2TelemetryMap_t *data) {
    return data->tel_revId.ets2_telemetry_plugin_revision;
}

uint32_t TelemetryHelper::getETS2VersionMajor(const ets2TelemetryMap_t *data) {
    return data->tel_revId.ets2_version_major;
}

uint32_t TelemetryHelper::getETS2VersionMinor(const ets2TelemetryMap_t *data) {
    return data->tel_revId.ets2_version_minor;
}

bool TelemetryHelper::getTrailerAttached(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.trailer_attached;
}

std::string TelemetryHelper::getTrailerId(const ets2TelemetryMap_t *data) {
    return toString(data->tel_rev2.trailerId);
}

std::string TelemetryHelper::getTrailerName(const ets2TelemetryMap_t *data) {
    return toString(data->tel_rev2.trailerName);
}

float TelemetryHelper::getTrailerMass(const ets2TelemetryMap_t *data) {
    return data->tel_rev2.trailerMass;
}

float TelemetryHelper::getSpeed(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.speed;
}

float TelemetryHelper::getCruiseControlSpeed(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.cruiseControlSpeed;
}

float TelemetryHelper::getAccelerationX(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.accelerationX;
}

float TelemetryHelper::getAccelerationY(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.accelerationY;
}

float TelemetryHelper::getAccelerationZ(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.accelerationZ;
}

float TelemetryHelper::getCoordinateX(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.coordinateX;
}

float TelemetryHelper::getCoordinateY(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.coordinateY;
}

float TelemetryHelper::getCoordinateZ(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.coordinateZ;
}

float TelemetryHelper::getRotationX(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.rotationX;
}

float TelemetryHelper::getRotationY(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.rotationY;
}

float TelemetryHelper::getRotationZ(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.rotationZ;
}

float TelemetryHelper::getCabinPositionX(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.cabinPositionX;
}

float TelemetryHelper::getCabinPositionY(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.cabinPositionY;
}

float TelemetryHelper::getCabinPositionZ(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.cabinPositionZ;
}

float TelemetryHelper::getHeadPositionX(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.headPositionX;
}

float TelemetryHelper::getHeadPositionY(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.headPositionY;
}

float TelemetryHelper::getHeadPositionZ(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.headPositionZ;
}

float TelemetryHelper::getHookPositionX(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.hookPositionX;
}

float TelemetryHelper::getHookPositionY(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.hookPositionY;
}

float TelemetryHelper::getHookPositionZ(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.hookPositionZ;
}

float TelemetryHelper::getTrailerCoordinateX(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.trailerCoordinateX;
}

float TelemetryHelper::getTrailerCoordinateY(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.trailerCoordinateY;
}

float TelemetryHelper::getTrailerCoordinateZ(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.trailerCoordinateZ;
}

float TelemetryHelper::getTrailerRotationX(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.trailerRotationX;
}

float TelemetryHelper::getTrailerRotationY(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.trailerRotationY;
}

float TelemetryHelper::getTrailerRotationZ(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.trailerRotationZ;
}

int32_t TelemetryHelper::getGear(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.gear;
}

int32_t TelemetryHelper::getDisplayedGear(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.displayedGear;
}

int32_t TelemetryHelper::getGearsForward(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.gears;
}

int32_t TelemetryHelper::getGearsReverse(const ets2TelemetryMap_t *data) {
    return data->tel_rev2.gears_reverse;
}

int32_t TelemetryHelper::getGearRanges(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.gearRanges;
}

int32_t TelemetryHelper::getGearRangeActive(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.gearRangeActive;
}

float TelemetryHelper::getEngineRpm(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.engineRpm;
}

float TelemetryHelper::getEngineRpmMax(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.engineRpmMax;
}

float TelemetryHelper::getFuel(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.fuel;
}

float TelemetryHelper::getFuelCapacity(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.fuelCapacity;
}

float TelemetryHelper::getFuelRate(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.fuelRate;
}

float TelemetryHelper::getFuelAvgConsumption(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.fuelAvgConsumption;
}

float TelemetryHelper::getUserSteer(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.userSteer;
}

float TelemetryHelper::getUserThrottle(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.userThrottle;
}

float TelemetryHelper::getUserBrake(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.userBrake;
}

float TelemetryHelper::getUserClutch(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.userClutch;
}

float TelemetryHelper::getGameSteer(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.gameSteer;
}

float TelemetryHelper::getGameThrottle(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.gameThrottle;
}

float TelemetryHelper::getGameBrake(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.gameBrake;
}

float TelemetryHelper::getGameClutch(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.gameClutch;
}

std::string TelemetryHelper::getTruckMake(const ets2TelemetryMap_t *data) {
    return toString(data->tel_rev3.truckMake);
}

std::string TelemetryHelper::getTruckMakeId(const ets2TelemetryMap_t *data) {
    return toString(data->tel_rev3.truckMakeId);
}

std::string TelemetryHelper::getTruckModel(const ets2TelemetryMap_t *data) {
    return toString(data->tel_rev3.truckModel);
}

float TelemetryHelper::getTruckOdometer(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.truckOdometer;
}

float TelemetryHelper::getTruckWeight(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.truckWeight;
}

int32_t TelemetryHelper::getJobIncome(const ets2TelemetryMap_t *data) {
    return data->tel_rev2.jobIncome;
}

int32_t TelemetryHelper::getJobDeadline(const ets2TelemetryMap_t *data) {
    return data->tel_rev2.time_abs_delivery;
}

std::string TelemetryHelper::getJobCitySource(const ets2TelemetryMap_t *data) {
    return toString(data->tel_rev2.citySrc);
}

std::string TelemetryHelper::getJobCompanySource(const ets2TelemetryMap_t *data) {
    return toString(data->tel_rev2.compSrc);
}

std::string TelemetryHelper::getJobCityDestination(const ets2TelemetryMap_t *data) {
    return toString(data->tel_rev2.cityDst);
}

std::string TelemetryHelper::getJobCompanyDestination(const ets2TelemetryMap_t *data) {
    return toString(data->tel_rev2.compDst);
}

int32_t TelemetryHelper::getRetarderBrake(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.retarderBrake;
}

int32_t TelemetryHelper::getRetarderStepCount(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.retarderStepCount;
}

int32_t TelemetryHelper::getShifterSlot(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.shifterSlot;
}

int32_t TelemetryHelper::getShifterToggle(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.shifterToggle;
}

std::string TelemetryHelper::getShifterType(const ets2TelemetryMap_t *data) {
    return toString(data->tel_rev4.shifterType);
}

bool TelemetryHelper::getEngineEnabled(const ets2TelemetryMap_t *data) {
    return data->tel_rev1.engine_enabled;
}

bool TelemetryHelper::getElectricEnabled(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.electricEnabled;
}

bool TelemetryHelper::getCruiseControlEnabled(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.cruiseControl;
}

bool TelemetryHelper::getWipersEnabled(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.wipers;
}

bool TelemetryHelper::getParkingBrakeEnabled(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.parkBrake;
}

bool TelemetryHelper::getMotorBrakeEnabled(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.motorBrake;
}

bool TelemetryHelper::getBlinkerLeftActive(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.blinkerLeftActive;
}

bool TelemetryHelper::getBlinkerRightActive(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.blinkerRightActive;
}

bool TelemetryHelper::getBlinkerLeftOn(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.blinkerLeftOn;
}

bool TelemetryHelper::getBlinkerRightOn(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.blinkerRightOn;
}

bool TelemetryHelper::getLightsParking(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.lightsParking;
}

bool TelemetryHelper::getLightsBeamLow(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.lightsBeamLow;
}

bool TelemetryHelper::getLightsBeamHigh(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.lightsBeamHigh;
}

bool TelemetryHelper::getLightsAuxFront(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.lightsAuxFront;
}

bool TelemetryHelper::getLightsAuxRoof(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.lightsAuxRoof;
}

bool TelemetryHelper::getLightsBeacon(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.lightsBeacon;
}

bool TelemetryHelper::getLightsBrake(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.lightsBrake;
}

bool TelemetryHelper::getLightsReverse(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.lightsReverse;
}

float TelemetryHelper::getLightsDashboard(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.lightsDashboard;
}

bool TelemetryHelper::getBatteryVoltageWarning(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.batteryVoltageWarning;
}

bool TelemetryHelper::getAirPressureWarning(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.airPressureWarning;
}

bool TelemetryHelper::getAirPressureEmergency(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.airPressureEmergency;
}

bool TelemetryHelper::getAdBlueWarning(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.adblueWarning;
}

bool TelemetryHelper::getOilPressureWarning(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.oilPressureWarning;
}

bool TelemetryHelper::getWaterTemperatureWarning(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.waterTemperatureWarning;
}

bool TelemetryHelper::getFuelWarning(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.fuelWarning;
}

float TelemetryHelper::getFuelWarningFactor(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.fuelWarningFactor;
}

float TelemetryHelper::getAirPressure(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.airPressure;
}

float TelemetryHelper::getAirPressureWarningValue(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.airPressureWarningValue;
}

float TelemetryHelper::getAirPressureEmergencyValue(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.airPressureEmergencyValue;
}

float TelemetryHelper::getBrakeTemperature(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.brakeTemperature;
}

float TelemetryHelper::getAdBlue(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.adblue;
}

float TelemetryHelper::getAdBlueConsumption(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.adblueConsumption;
}

float TelemetryHelper::getAdBlueCapacity(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.adblueConsumption;
}

float TelemetryHelper::getOilPressure(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.oilPressure;
}

float TelemetryHelper::getOilPressureWarningValue(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.oilPressureWarningValue;
}

float TelemetryHelper::getOilTemperature(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.oilTemperature;
}

float TelemetryHelper::getWaterTemperature(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.waterTemperature;
}

float TelemetryHelper::getWaterTemperatureWarningValue(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.waterTemperatureWarningValue;
}

float TelemetryHelper::getBatterVoltage(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.batteryVoltage;
}

float TelemetryHelper::getBatteryVoltageWarningValue(const ets2TelemetryMap_t *data) {
    return data->tel_rev4.batteryVoltageWarningValue;
}

float TelemetryHelper::getWearEngine(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.wearEngine;
}

float TelemetryHelper::getWearTransmission(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.wearTransmission;
}

float TelemetryHelper::getWearCabin(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.wearCabin;
}

float TelemetryHelper::getWearChassis(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.wearChassis;
}

float TelemetryHelper::getWearWheels(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.wearWheels;
}

float TelemetryHelper::getWearTrailer(const ets2TelemetryMap_t *data) {
    return data->tel_rev3.wearTrailer;
}

std::string TelemetryHelper::toJson(const bool &game_running, const ets2TelemetryMap_t *const data) {
    return "{\n"
           "   \"game\":{\n"
           "      \"connected\":" + getBool(game_running) + ",\n"
           "      \"paused\":" + getBool(getPaused(data)) + ",\n"
           "      \"time\":\"" + absoluteTimeToDate(getTime(data)) +"\",\n"
           "      \"timeScale\":" + std::to_string(getLocalScale(data)) + ",\n"
           "      \"nextRestStopTime\":\"" + absoluteTimeToDate(getNextRestStop(data)) + "\",\n"
           "      \"version\":\"" + getGameVersion(getETS2VersionMajor(data), getETS2VersionMinor(data)) + "\",\n"
           "      \"telemetryPluginVersion\":\"" + std::to_string(getPluginVersion(data)) + "\",\n"
           "      \"telemetryServerVersion\":\"" ETS2_SERVER_VERSION "\"\n"
           "   },\n"
           "   \"truck\":{\n"
           "      \"id\":\"" + getTruckMakeId(data) + "\",\n"
           "      \"make\":\"" + getTruckMake(data) + "\",\n"
           "      \"model\":\"" + getTruckModel(data) + "\",\n"
           "      \"speed\":" + std::to_string(getSpeed(data) * 3.6f) + ",\n"
           "      \"cruiseControlSpeed\":" + std::to_string(getCruiseControlSpeed(data) * 3.6f) + ",\n"
           "      \"cruiseControlOn\":" + getBool(getCruiseControlEnabled(data)) + ",\n"
           "      \"odometer\":" + std::to_string(getTruckOdometer(data)) + ",\n"
           "      \"gear\":" + std::to_string(getGear(data)) + ",\n"
           "      \"displayedGear\":" + std::to_string(getDisplayedGear(data)) + ",\n"
           "      \"forwardGears\":" + std::to_string(getGearsForward(data)) + ",\n"
           "      \"reverseGears\":" + std::to_string(getGearsReverse(data)) + ",\n"
           "      \"shifterType\":\"" + getShifterType(data) + "\",\n"
           "      \"engineRpm\":" + std::to_string(getEngineRpm(data)) + ",\n"
           "      \"engineRpmMax\":" + std::to_string(getEngineRpmMax(data)) + ",\n"
           "      \"fuel\":" + std::to_string(getFuel(data)) + ",\n"
           "      \"fuelCapacity\":" + std::to_string(getFuelCapacity(data)) + ",\n"
           "      \"fuelAverageConsumption\":" + std::to_string(getFuelAvgConsumption(data)) + ",\n"
           "      \"fuelWarningFactor\":" + std::to_string(getFuelWarningFactor(data)) + ",\n"
           "      \"fuelWarningOn\":" + getBool(getFuelWarning(data)) + ",\n"
           "      \"wearEngine\":" + std::to_string(getWearEngine(data)) + ",\n"
           "      \"wearTransmission\":" + std::to_string(getWearTransmission(data)) + ",\n"
           "      \"wearCabin\":" + std::to_string(getWearCabin(data)) + ",\n"
           "      \"wearChassis\":" + std::to_string(getWearChassis(data)) + ",\n"
           "      \"wearWheels\":" + std::to_string(getWearWheels(data)) + ",\n"
           "      \"userSteer\":" + std::to_string(getUserSteer(data)) + ",\n"
           "      \"userThrottle\":" + std::to_string(getUserThrottle(data)) + ",\n"
           "      \"userBrake\":" + std::to_string(getUserBrake(data)) + ",\n"
           "      \"userClutch\":" + std::to_string(getUserClutch(data)) + ",\n"
           "      \"gameSteer\":" + std::to_string(getGameSteer(data)) + ",\n"
           "      \"gameThrottle\":" + std::to_string(getGameThrottle(data)) + ",\n"
           "      \"gameBrake\":" + std::to_string(getGameBrake(data)) + ",\n"
           "      \"gameClutch\":" + std::to_string(getGameClutch(data)) + ",\n"
           "      \"shifterSlot\":" + std::to_string(getShifterSlot(data)) + ",\n"
           "      \"engineOn\": " + getBool(getEngineEnabled(data)) + ",\n"
           "      \"electricOn\":" + getBool(getElectricEnabled(data)) + ",\n"
           "      \"wipersOn\":" + getBool(getWipersEnabled(data)) + ",\n"
           "      \"retarderBrake\":" + getBool(getRetarderBrake(data)) + ",\n"
           "      \"retarderStepCount\":" + std::to_string(getRetarderStepCount(data)) + ",\n"
           "      \"parkBrakeOn\":" + getBool(getParkingBrakeEnabled(data)) + ",\n"
           "      \"motorBrakeOn\":" + getBool(getMotorBrakeEnabled(data)) + ",\n"
           "      \"brakeTemperature\":" + std::to_string(getBrakeTemperature(data)) + ",\n"
           "      \"adblue\":" + std::to_string(getAdBlue(data)) + ",\n"
           "      \"adblueCapacity\":" + std::to_string(getAdBlueCapacity(data)) + ",\n"
           "      \"adblueAverageConsumpton\":" + std::to_string(getAdBlueConsumption(data)) + ",\n"
           "      \"adblueWarningOn\":" + getBool(getAdBlueWarning(data)) + ",\n"
           "      \"airPressure\":" + std::to_string(getAirPressure(data)) + ",\n"
           "      \"airPressureWarningOn\":" + getBool(getAirPressureWarning(data)) + ",\n"
           "      \"airPressureWarningValue\":" + std::to_string(getAirPressureWarningValue(data)) + ",\n"
           "      \"airPressureEmergencyOn\":" + getBool(getAirPressureEmergency(data)) + ",\n"
           "      \"airPressureEmergencyValue\":" + std::to_string(getAirPressureEmergencyValue(data)) + ",\n"
           "      \"oilTemperature\":" + std::to_string(getOilTemperature(data)) + ",\n"
           "      \"oilPressure\":" + std::to_string(getOilPressure(data)) + ",\n"
           "      \"oilPressureWarningOn\":" + getBool(getOilPressureWarning(data)) + ",\n"
           "      \"oilPressureWarningValue\":" + std::to_string(getOilPressureWarningValue(data)) + ",\n"
           "      \"waterTemperature\":" + std::to_string(getWaterTemperature(data)) + ",\n"
           "      \"waterTemperatureWarningOn\":" + getBool(getWaterTemperatureWarning(data)) + ",\n"
           "      \"waterTemperatureWarningValue\":" + std::to_string(getWaterTemperatureWarningValue(data)) + ",\n"
           "      \"batteryVoltage\":" + std::to_string(getBatterVoltage(data)) + ",\n"
           "      \"batteryVoltageWarningOn\":" + getBool(getBatteryVoltageWarning(data)) + ",\n"
           "      \"batteryVoltageWarningValue\":" + std::to_string(getBatteryVoltageWarningValue(data)) + ",\n"
           "      \"lightsDashboardValue\":" + std::to_string(getLightsDashboard(data)) + ",\n"
           "      \"lightsDashboardOn\":" + getBool(getLightsDashboard(data)) + ",\n"
           "      \"blinkerLeftActive\":" + getBool(getBlinkerLeftActive(data)) + ",\n"
           "      \"blinkerRightActive\":" + getBool(getBlinkerRightActive(data)) + ",\n"
           "      \"blinkerLeftOn\":" + getBool(getBlinkerLeftOn(data)) + ",\n"
           "      \"blinkerRightOn\":" + getBool(getBlinkerRightOn(data)) + ",\n"
           "      \"lightsParkingOn\":" + getBool(getLightsParking(data)) + ",\n"
           "      \"lightsBeamLowOn\":" + getBool(getLightsBeamLow(data)) + ",\n"
           "      \"lightsBeamHighOn\":" + getBool(getLightsBeamHigh(data)) + ",\n"
           "      \"lightsAuxFrontOn\":" + getBool(getLightsAuxFront(data)) + ",\n"
           "      \"lightsAuxRoofOn\":" + getBool(getLightsAuxRoof(data)) + ",\n"
           "      \"lightsBeaconOn\":" + getBool(getLightsBeacon(data)) + ",\n"
           "      \"lightsBrakeOn\":" + getBool(getLightsBrake(data)) + ",\n"
           "      \"lightsReverseOn\":" + getBool(getLightsReverse(data)) + ",\n"
           "      \"placement\":{\n"
           "         \"x\":" + std::to_string(getCoordinateX(data)) + ",\n"
           "         \"y\":" + std::to_string(getCoordinateY(data)) + ",\n"
           "         \"z\":" + std::to_string(getCoordinateZ(data)) + ",\n"
           "         \"heading\":" + std::to_string(getRotationX(data)) + ",\n"
           "         \"pitch\":" + std::to_string(getRotationY(data)) + ",\n"
           "         \"roll\":" + std::to_string(getRotationZ(data)) + "\n"
           "      },\n"
           "      \"acceleration\":{\n"
           "         \"x\":" + std::to_string(getAccelerationX(data)) + ",\n"
           "         \"y\":" + std::to_string(getAccelerationY(data)) + ",\n"
           "         \"z\":" + std::to_string(getAccelerationZ(data)) + "\n"
           "      },\n"
           "      \"head\":{\n"
           "         \"x\":" + std::to_string(getHeadPositionX(data)) + ",\n"
           "         \"y\":" + std::to_string(getHeadPositionY(data)) + ",\n"
           "         \"z\":" + std::to_string(getHeadPositionZ(data)) + "\n"
           "      },\n"
           "      \"cabin\":{\n"
           "         \"x\":" + std::to_string(getCabinPositionX(data)) + ",\n"
           "         \"y\":" + std::to_string(getCabinPositionY(data)) + ",\n"
           "         \"z\":" + std::to_string(getCabinPositionZ(data)) + "\n"
           "      },\n"
           "      \"hook\":{\n"
           "         \"x\":" + std::to_string(getHookPositionX(data)) + ",\n"
           "         \"y\":" + std::to_string(getHookPositionY(data)) + ",\n"
           "         \"z\":" + std::to_string(getHookPositionZ(data)) + "\n"
           "      }\n"
           "   },\n"
           "   \"trailer\":{\n"
           "      \"attached\":" + getBool(getTrailerAttached(data)) + ",\n"
           "      \"id\":\"" + getTrailerId(data) + "\",\n"
           "      \"name\":\"" + getTrailerName(data) + "\",\n"
           "      \"mass\":" + std::to_string(getTrailerMass(data)) + ",\n"
           "      \"wear\":" + std::to_string(getWearTrailer(data)) + ",\n"
           "      \"placement\":{\n"
           "         \"x\":" + std::to_string(getTrailerCoordinateX(data)) + ",\n"
           "         \"y\":" + std::to_string(getTrailerCoordinateY(data)) + ",\n"
           "         \"z\":" + std::to_string(getTrailerCoordinateZ(data)) + ",\n"
           "         \"heading\":" + std::to_string(getTrailerRotationX(data)) + ",\n"
           "         \"pitch\":" + std::to_string(getTrailerRotationY(data)) + ",\n"
           "         \"roll\":" + std::to_string(getTrailerRotationZ(data)) + "\n"
           "      }\n"
           "   },\n"
           "   \"job\":{\n"
           "      \"income\":" + std::to_string(getJobIncome(data)) + ",\n"
           "      \"deadlineTime\":\"" + absoluteTimeToDate(getJobDeadline(data)) + "\",\n"
           "      \"remainingTime\":\"" + absoluteTimeToDate(getJobDeadline(data) - getTimeAbsolute(data)) + "\",\n"
           "      \"sourceCity\":\"" + getJobCitySource(data) + "\",\n"
           "      \"sourceCompany\":\"" + getJobCompanySource(data) + "\",\n"
           "      \"destinationCity\":\"" + getJobCityDestination(data) + "\",\n"
           "      \"destinationCompany\":\"" + getJobCompanyDestination(data) + "\"\n"
           "   },\n"
           "   \"navigation\":{\n"
           "      \"estimatedTime\": \"" + absoluteTimeToDate(static_cast<time_t>(getNavigationTime(data))) + "\",\n"
           "      \"estimatedDistance\": " + std::to_string(getNavigationDistance(data)) + ",\n"
           "      \"speedLimit\": " + std::to_string(static_cast<int>(getNavigationSpeedLimit(data) * 3.6f)) + "\n"
           "   }\n"
           "}";
}
