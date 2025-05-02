#define SENSOR_PIN A5  // Analog input pin for sensor
#define VREF 5.0       // Reference voltage of Arduino (5V for most boards)
#define ADC_RES 1023.0 // ADC resolution for 10-bit ADC (0-1023)

float Vout0 = 0.6;   // Zero point voltage (0 ppm CO)
float Vout1 = 0.9;   // Voltage at 200 ppm CO
float ppm1 = 200.0;  // Calibration ppm at Vout1
float maxPPM = 1000; // Maximum detection range

void setup() {
    Serial.begin(9600);
}

void loop() {
    int rawADC = analogRead(SENSOR_PIN);       // Read analog value (0-1023)
    float Voutx = (rawADC / ADC_RES) * VREF;   // Convert to voltage

    float ppm = (ppm1 / (Vout1 - Vout0)) * (Voutx - Vout0); // Linear interpolation

    // Prevent values from exceeding the max range
    if (ppm < 0) ppm = 0;
    if (ppm > maxPPM) ppm = maxPPM;

    Serial.print("Voltage Output: ");
    Serial.print(Voutx);
    Serial.print(" V, CO Concentration: ");
    Serial.print(ppm);
    Serial.println(" ppm");

    delay(1000); // Read every second
}
