#include <stdio.h>
#include <string.h>

int main() {

    FILE *fp;
    char pollutant[10];
    float value;

    float PM25 = 0, PM10 = 0, NO2 = 0, SO2 = 0, CO = 0, O3 = 0;

    fp = fopen("sensor_data.txt", "r");

    if (fp == NULL) {
        printf("Error opening sensor file\n");
        return 1;
    }

    while (fscanf(fp, "%s %f", pollutant, &value) != EOF) {

        if (strcmp(pollutant, "PM25") == 0)
            PM25 = value;

        else if (strcmp(pollutant, "PM10") == 0)
            PM10 = value;

        else if (strcmp(pollutant, "NO2") == 0)
            NO2 = value;

        else if (strcmp(pollutant, "SO2") == 0)
            SO2 = value;

        else if (strcmp(pollutant, "CO") == 0)
            CO = value;

        else if (strcmp(pollutant, "O3") == 0)
            O3 = value;
    }

    fclose(fp);

    printf("Sensor Data:\n");
    printf("PM2.5 = %.1f\n", PM25);
    printf("PM10 = %.1f\n", PM10);
    printf("NO2 = %.1f\n", NO2);
    printf("SO2 = %.1f\n", SO2);
    printf("CO = %.1f\n", CO);
    printf("O3 = %.1f\n\n", O3);

    printf("AQI Determination:\n");

    if (PM25 <= 50)
        printf("AQI Category: Good\n");

    else if (PM25 <= 100)
        printf("AQI Category: Satisfactory\n");

    else if (PM25 <= 200)
        printf("AQI Category: Moderate\n");

    else if (PM25 <= 300)
        printf("AQI Category: Poor\n");

    else if (PM25 <= 400)
        printf("AQI Category: Very Poor\n");

    else
        printf("AQI Category: Severe\n");

    return 0;
}
