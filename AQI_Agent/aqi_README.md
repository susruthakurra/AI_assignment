# AQI Simple Reflex Agent

Objective :
Design and develop a Simple Reflex Agent that reads environmental parameters from sensors (provided as a file) and determines the Air Quality Index (AQI) category of a region.
The agent reads pollutant concentration values from a sensor data file and applies rule-based conditions to determine the AQI category.

Environmental Parameters (Sensors) :
The following pollutants are used as sensor inputs:
* PM2.5
* PM10
* NO2
* SO2
* CO
* O3

These pollutants are commonly used for calculating AQI.

The sensor data is stored in a file called sensor_data.txt.

Example input:
PM25 85 PM10 150 NO2 40 SO2 20 CO 1 O3 60

Agent Design :
This system follows the structure of a Simple Reflex Agent, which selects an action based only on the current percept (sensor input).

Architecture:
Sensors (sensor_data.txt) -> Agent Program (aqi_agent.c) -> Condition Rules -> AQI Category Output

The agent reads pollutant values and immediately applies predefined rules to determine the AQI category.

Decision Rules :
The AQI category is determined based on PM2.5 concentration levels.
PM2.5 ≤ 50 → Good
PM2.5 ≤ 100 → Satisfactory
PM2.5 ≤ 200 → Moderate
PM2.5 ≤ 300 → Poor
PM2.5 ≤ 400 → Very Poor
PM2.5 > 400 → Severe

Working :
1. The program opens the sensor data file.
2. It reads pollutant values from the file.
3. The agent extracts the PM2.5 concentration.
4. The agent applies rule-based conditions.
5. Based on the condition satisfied, the AQI category is displayed.

Output Example :
Sensor Data:
PM2.5 = 85
PM10 = 150
NO2 = 40
SO2 = 20
CO = 1
O3 = 60

AQI Determination:
AQI Category: Satisfactory

The agent is implemented using the C programming language.

## PEAS Description

**Performance Measure:**
Correctly determining the AQI category based on pollutant concentration levels.

**Environment:**
Air quality conditions of a region containing pollutants such as PM2.5, PM10, NO2, SO2, CO, and O3.

**Actuators:**
Displays the AQI category as output on the console.

**Sensors:**
Pollutant data read from the sensor file **sensor_data.txt**.

