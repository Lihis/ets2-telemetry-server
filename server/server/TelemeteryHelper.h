#ifndef ETS2_TELEMETRY_SERVER_TELEMETERYHELPER_H
#define ETS2_TELEMETRY_SERVER_TELEMETERYHELPER_H

#include <string>
#include <ets2-telemetry-common.hpp>

namespace TelemetryHelper {
    template<typename T>
    std::string getBool(const T &value) {
        return value ? "true" : "false";
    }

    bool isGameRunning(std::string &game);

    bool getPaused(const ets2TelemetryMap_t *data);

    uint32_t getTime(const ets2TelemetryMap_t *data);
    uint32_t getTimeAbsolute(const ets2TelemetryMap_t *data);

    float getLocalScale(const ets2TelemetryMap_t *data);
    int32_t getNextRestStop(const ets2TelemetryMap_t *data);
    float getNavigationDistance(const ets2TelemetryMap_t *data);
    float getNavigationTime(const ets2TelemetryMap_t *data);
    float getNavigationSpeedLimit(const ets2TelemetryMap_t *data);

    uint32_t getPluginVersion(const ets2TelemetryMap_t *data);
    uint32_t getETS2VersionMajor(const ets2TelemetryMap_t *data);
    uint32_t getETS2VersionMinor(const ets2TelemetryMap_t *data);

    bool getTrailerAttached(const ets2TelemetryMap_t *data);
    std::string getTrailerId(const ets2TelemetryMap_t *data);
    std::string getTrailerName(const ets2TelemetryMap_t *data);
    float getTrailerMass(const ets2TelemetryMap_t *data);
    float getTrailerWeight(const ets2TelemetryMap_t *data);

    float getSpeed(const ets2TelemetryMap_t *data);
    float getCruiseControlSpeed(const ets2TelemetryMap_t *data);

    float getAccelerationX(const ets2TelemetryMap_t *data);
    float getAccelerationY(const ets2TelemetryMap_t *data);
    float getAccelerationZ(const ets2TelemetryMap_t *data);

    float getCoordinateX(const ets2TelemetryMap_t *data);
    float getCoordinateY(const ets2TelemetryMap_t *data);
    float getCoordinateZ(const ets2TelemetryMap_t *data);

    float getRotationX(const ets2TelemetryMap_t *data);
    float getRotationY(const ets2TelemetryMap_t *data);
    float getRotationZ(const ets2TelemetryMap_t *data);

    float getCabinPositionX(const ets2TelemetryMap_t *data);
    float getCabinPositionY(const ets2TelemetryMap_t *data);
    float getCabinPositionZ(const ets2TelemetryMap_t *data);

    float getHeadPositionX(const ets2TelemetryMap_t *data);
    float getHeadPositionY(const ets2TelemetryMap_t *data);
    float getHeadPositionZ(const ets2TelemetryMap_t *data);

    float getHookPositionX(const ets2TelemetryMap_t *data);
    float getHookPositionY(const ets2TelemetryMap_t *data);
    float getHookPositionZ(const ets2TelemetryMap_t *data);

    float getTrailerCoordinateX(const ets2TelemetryMap_t *data);
    float getTrailerCoordinateY(const ets2TelemetryMap_t *data);
    float getTrailerCoordinateZ(const ets2TelemetryMap_t *data);

    float getTrailerRotationX(const ets2TelemetryMap_t *data);
    float getTrailerRotationY(const ets2TelemetryMap_t *data);
    float getTrailerRotationZ(const ets2TelemetryMap_t *data);

    int32_t getGear(const ets2TelemetryMap_t *data);
    int32_t getDisplayedGear(const ets2TelemetryMap_t *data);
    int32_t getGearsForward(const ets2TelemetryMap_t *data);
    int32_t getGearsReverse(const ets2TelemetryMap_t *data);
    int32_t getGearRanges(const ets2TelemetryMap_t *data);
    int32_t getGearRangeActive(const ets2TelemetryMap_t *data);

    float getEngineRpm(const ets2TelemetryMap_t *data);
    float getEngineRpmMax(const ets2TelemetryMap_t *data);

    float getFuel(const ets2TelemetryMap_t *data);
    float getFuelCapacity(const ets2TelemetryMap_t *data);
    float getFuelRate(const ets2TelemetryMap_t *data);
    float getFuelAvgConsumption(const ets2TelemetryMap_t *data);

    float getUserSteer(const ets2TelemetryMap_t *data);
    float getUserThrottle(const ets2TelemetryMap_t *data);
    float getUserBrake(const ets2TelemetryMap_t *data);
    float getUserClutch(const ets2TelemetryMap_t *data);

    float getGameSteer(const ets2TelemetryMap_t *data);
    float getGameThrottle(const ets2TelemetryMap_t *data);
    float getGameBrake(const ets2TelemetryMap_t *data);
    float getGameClutch(const ets2TelemetryMap_t *data);

    std::string getTruckMake(const ets2TelemetryMap_t *data);
    std::string getTruckMakeId(const ets2TelemetryMap_t *data);
    std::string getTruckModel(const ets2TelemetryMap_t *data);
    float getTruckOdometer(const ets2TelemetryMap_t *data);
    float getTruckWeight(const ets2TelemetryMap_t *data);

    int32_t getJobIncome(const ets2TelemetryMap_t *data);
    int32_t getJobDeadline(const ets2TelemetryMap_t *data);
    std::string getJobCitySource(const ets2TelemetryMap_t *data);
    std::string getJobCompanySource(const ets2TelemetryMap_t *data);
    std::string getJobCityDestination(const ets2TelemetryMap_t *data);
    std::string getJobCompanyDestination(const ets2TelemetryMap_t *data);

    int32_t getRetarderBrake(const ets2TelemetryMap_t *data);
    int32_t getRetarderStepCount(const ets2TelemetryMap_t *data);

    int32_t getShifterSlot(const ets2TelemetryMap_t *data);
    int32_t getShifterToggle(const ets2TelemetryMap_t *data);
    std::string getShifterType(const ets2TelemetryMap_t *data);

    bool getEngineEnabled(const ets2TelemetryMap_t *data);
    bool getElectricEnabled(const ets2TelemetryMap_t *data);
    bool getCruiseControlEnabled(const ets2TelemetryMap_t *data);
    bool getWipersEnabled(const ets2TelemetryMap_t *data);
    bool getParkingBrakeEnabled(const ets2TelemetryMap_t *data);
    bool getMotorBrakeEnabled(const ets2TelemetryMap_t *data);
    bool getBlinkerLeftActive(const ets2TelemetryMap_t *data);
    bool getBlinkerRightActive(const ets2TelemetryMap_t *data);
    bool getBlinkerLeftOn(const ets2TelemetryMap_t *data);
    bool getBlinkerRightOn(const ets2TelemetryMap_t *data);

    bool getLightsParking(const ets2TelemetryMap_t *data);
    bool getLightsBeamLow(const ets2TelemetryMap_t *data);
    bool getLightsBeamHigh(const ets2TelemetryMap_t *data);
    bool getLightsAuxFront(const ets2TelemetryMap_t *data);
    bool getLightsAuxRoof(const ets2TelemetryMap_t *data);
    bool getLightsBeacon(const ets2TelemetryMap_t *data);
    bool getLightsBrake(const ets2TelemetryMap_t *data);
    bool getLightsReverse(const ets2TelemetryMap_t *data);
    float getLightsDashboard(const ets2TelemetryMap_t *data);

    bool getBatteryVoltageWarning(const ets2TelemetryMap_t *data);
    bool getAirPressureWarning(const ets2TelemetryMap_t *data);
    bool getAirPressureEmergency(const ets2TelemetryMap_t *data);
    bool getAdBlueWarning(const ets2TelemetryMap_t *data);
    bool getOilPressureWarning(const ets2TelemetryMap_t *data);
    bool getWaterTemperatureWarning(const ets2TelemetryMap_t *data);
    bool getFuelWarning(const ets2TelemetryMap_t *data);
    float getFuelWarningFactor(const ets2TelemetryMap_t *data);

    float getAirPressure(const ets2TelemetryMap_t *data);
    float getAirPressureWarningValue(const ets2TelemetryMap_t *data);
    float getAirPressureEmergencyValue(const ets2TelemetryMap_t *data);
    float getBrakeTemperature(const ets2TelemetryMap_t *data);
    float getAdBlue(const ets2TelemetryMap_t *data);
    float getAdBlueConsumption(const ets2TelemetryMap_t *data);
    float getAdBlueCapacity(const ets2TelemetryMap_t *data);
    float getOilPressure(const ets2TelemetryMap_t *data);
    float getOilPressureWarningValue(const ets2TelemetryMap_t *data);
    float getOilTemperature(const ets2TelemetryMap_t *data);
    float getWaterTemperature(const ets2TelemetryMap_t *data);
    float getWaterTemperatureWarningValue(const ets2TelemetryMap_t *data);
    float getBatterVoltage(const ets2TelemetryMap_t *data);
    float getBatteryVoltageWarningValue(const ets2TelemetryMap_t *data);
    float getWearEngine(const ets2TelemetryMap_t *data);
    float getWearTransmission(const ets2TelemetryMap_t *data);
    float getWearCabin(const ets2TelemetryMap_t *data);
    float getWearChassis(const ets2TelemetryMap_t *data);
    float getWearWheels(const ets2TelemetryMap_t *data);
    float getWearTrailer(const ets2TelemetryMap_t *data);

    std::string toJson(const bool &game_running, const ets2TelemetryMap_t *data);
//    struct Structure {
//        uint32_t time;
//        uint32_t paused;
//
//        uint32_t ets2_telemetry_plugin_revision;
//        uint32_t ets2_version_major;
//        uint32_t ets2_version_minor;
//
//        // ***** REVISION 1 ****** //
//
//        uint8_t padding1;
//        uint8_t trailer_attached;
//        uint8_t padding2;
//        uint8_t padding3;
//
//        float speed;
//        float accelerationX;
//        float accelerationY;
//        float accelerationZ;
//
//        float coordinateX;
//        float coordinateY;
//        float coordinateZ;
//
//        float rotationX;
//        float rotationY;
//        float rotationZ;
//
//        int32_t gear;
//        int32_t gearsForward;
//        int32_t gearRanges;
//        int32_t gearRangeActive;
//
//        float engineRpm;
//        float engineRpmMax;
//
//        float fuel;
//        float fuelCapacity;
//        float fuelRate;
//        float fuelAvgConsumption;
//
//        float userSteer;
//        float userThrottle;
//        float userBrake;
//        float userClutch;
//
//        float gameSteer;
//        float gameThrottle;
//        float gameBrake;
//        float gameClutch;
//
//        float truckWeight;
//        float trailerWeight;
//
//        int32_t modelOffset;
//        int32_t modelLength;
//
//        int32_t trailerOffset;
//        int32_t trailerLength;
//
//        int32_t timeAbsolute;
//        int32_t gearsReverse;
//
//        float trailerMass;
//
//        //[MarshalAs(UnmanagedType.ByValArray, SizeConst = GeneralStringSize)]
//        uint8_t trailerId[64];
//
//        //[MarshalAs(UnmanagedType.ByValArray, SizeConst = GeneralStringSize)]
//        uint8_t trailerName[64];
//
//        int32_t jobIncome;
//        int32_t jobDeadline;
//
//        //[MarshalAs(UnmanagedType.ByValArray, SizeConst = GeneralStringSize)]
//        uint8_t jobCitySource[64];
//        //[MarshalAs(UnmanagedType.ByValArray, SizeConst = GeneralStringSize)]
//        uint8_t jobCityDestination[64];
//
//        //[MarshalAs(UnmanagedType.ByValArray, SizeConst = GeneralStringSize)]
//        uint8_t jobCompanySource[64];
//        //[MarshalAs(UnmanagedType.ByValArray, SizeConst = GeneralStringSize)]
//        uint8_t jobCompanyDestination[64];
//
//        // ***** REVISION 3 ****** //
//
//        int32_t retarderBrake;
//        int32_t shifterSlot;
//        int32_t shifterToggle;
//        int32_t padding4;
//
//        uint8_t cruiseControl;
//        uint8_t wipers;
//
//        uint8_t parkBrake;
//        uint8_t motorBrake;
//
//        uint8_t electricEnabled;
//        uint8_t engineEnabled;
//
//        uint8_t blinkerLeftActive;
//        uint8_t blinkerRightActive;
//        uint8_t blinkerLeftOn;
//        uint8_t blinkerRightOn;
//
//        uint8_t lightsParking;
//        uint8_t lightsBeamLow;
//        uint8_t lightsBeamHigh;
//        uint32_t lightsAuxFront;
//        uint32_t lightsAuxRoof;
//        uint8_t lightsBeacon;
//        uint8_t lightsBrake;
//        uint8_t lightsReverse;
//
//        uint8_t batteryVoltageWarning;
//        uint8_t airPressureWarning;
//        uint8_t airPressureEmergency;
//        uint8_t adblueWarning;
//        uint8_t oilPressureWarning;
//        uint8_t waterTemperatureWarning;
//
//        float airPressure;
//        float brakeTemperature;
//        int32_t fuelWarning;
//        float adblue;
//        float adblueConsumption;
//        float oilPressure;
//        float oilTemperature;
//        float waterTemperature;
//        float batteryVoltage;
//        float lightsDashboard;
//        float wearEngine;
//        float wearTransmission;
//        float wearCabin;
//        float wearChassis;
//        float wearWheels;
//        float wearTrailer;
//        float truckOdometer;
//        float cruiseControlSpeed;
//
//        //[MarshalAs(UnmanagedType.ByValArray, SizeConst = GeneralStringSize)]
//        uint8_t truckMake[64];
//        //[MarshalAs(UnmanagedType.ByValArray, SizeConst = GeneralStringSize)]
//        uint8_t truckMakeId[64];
//        //[MarshalAs(UnmanagedType.ByValArray, SizeConst = GeneralStringSize)]
//        uint8_t truckModel[64];
//
//        // ***** REVISION 4 ****** //
//
//        float fuelWarningFactor;
//        float adblueCapacity;
//        float airPressureWarningValue;
//        float airPressureEmergencyValue;
//        float oilPressureWarningValue;
//        float waterTemperatureWarningValue;
//        float batteryVoltageWarningValue;
//
//        uint32_t retarderStepCount;
//
//        float cabinPositionX;
//        float cabinPositionY;
//        float cabinPositionZ;
//        float headPositionX;
//        float headPositionY;
//        float headPositionZ;
//        float hookPositionX;
//        float hookPositionY;
//        float hookPositionZ;
//
//        //[MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
//        uint8_t shifterType[16];
//
//        float localScale;
//        int32_t nextRestStop;
//        float trailerCoordinateX;
//        float trailerCoordinateY;
//        float trailerCoordinateZ;
//        float trailerRotationX;
//        float trailerRotationY;
//        float trailerRotationZ;
//
//        int32_t displayedGear;
//        float navigationDistance;
//        float navigationTime;
//        float navigationSpeedLimit;
//
//        /*
//        const int MaxSlotCount = 32; // TODO: need to fix.
//        const int MaxWheelCount = 20;
//        uint32_t wheelCount;
//        [MarshalAs(UnmanagedType.ByValArray, SizeConst = MaxWheelCount)]
//        float[] wheelPositionX;
//        [MarshalAs(UnmanagedType.ByValArray, SizeConst = MaxWheelCount)]
//        float[] wheelPositionY;
//        [MarshalAs(UnmanagedType.ByValArray, SizeConst = MaxWheelCount)]
//        float[] wheelPositionZ;
//        [MarshalAs(UnmanagedType.ByValArray, SizeConst = MaxWheelCount)]
//        uint8_t[] wheelSteerable;
//        [MarshalAs(UnmanagedType.ByValArray, SizeConst = MaxWheelCount)]
//        uint8_t[] wheelSimulated;
//        [MarshalAs(UnmanagedType.ByValArray, SizeConst = MaxWheelCount)]
//        float[] wheelRadius;
//        [MarshalAs(UnmanagedType.ByValArray, SizeConst = MaxWheelCount)]
//        uint8_t[] wheelPowered;
//        [MarshalAs(UnmanagedType.ByValArray, SizeConst = MaxWheelCount)]
//        uint8_t[] wheelLiftable;
//        uint32_t selectorCount;
//        [MarshalAs(UnmanagedType.ByValArray, SizeConst = MaxSlotCount)]
//        int32_t[] slotGear;
//        [MarshalAs(UnmanagedType.ByValArray, SizeConst = MaxSlotCount)]
//        uint32_t[] slotHandlePosition;
//        [MarshalAs(UnmanagedType.ByValArray, SizeConst = MaxSlotCount)]
//        uint32_t[] slotSelectors;
//        */
//    };
} // namespace

#endif //ETS2_TELEMETRY_SERVER_TELEMETERYHELPER_H
