#include "plcspectrummodel.h"

PLCSpectrumModel::PLCSpectrumModel()
{
    this->lowerBandLimit = 0.0;
    this->upperBandLimit = 100000.00;
    this->bandResolution = 1000.00;

    this->mainsFrequency = 50;
    this->samplesPerCycle = 50;
    this->simulationLength = 1.0;
}

PLCSpectrumModel::PLCSpectrumModel(const QVariantMap& map){
    fromVariantMap(map);
}

QVariantMap PLCSpectrumModel::toVariantMap(){
    QVariantMap map;

    map["LowerBandLimit"] = lowerBandLimit;
    map["UpperBandLimit"] = upperBandLimit;
    map["BandResolution"] = bandResolution;

    map["MainsFrequency"] = mainsFrequency;
    map["SamplesPerCycle"] = samplesPerCycle;
    map["SimulationLength"] = simulationLength;

    map["NoiseFloor"] = noiseFloor;

    return map;
}

void PLCSpectrumModel::fromVariantMap(const QVariantMap& map){
    lowerBandLimit = map["LowerBandLimit"].toDouble();
    upperBandLimit = map["UpperBandLimit"].toDouble();
    bandResolution = map["BandResolution"].toDouble();

    samplesPerCycle = map["SamplesPerCycle"].toInt();
    simulationLength = map["SimulationLength"].toInt();
    mainsFrequency = map["MainsFrequency"].toInt();

    noiseFloor = map["NoiseFloor"].toDouble();
}