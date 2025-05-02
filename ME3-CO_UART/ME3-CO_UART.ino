#include <SoftwareSerial.h>

SoftwareSerial SensorSerial(10 , 11); // RX, TX

void setup() {
  pinMode(10, INPUT);
  digitalWrite(10, LOW);  
  Serial.begin(9600);
  SensorSerial.begin(9600);
}

void loop() {
  if (SensorSerial.available() >= 9) { // Full packet is 9 bytes
    uint8_t buffer[9];

    // Read full 9-byte frame
    for (int i = 0; i < 9; i++) {
      buffer[i] = SensorSerial.read();
    }

    // Print the raw sensor data in HEX format
    Serial.print("Raw Data: ");
    for (int i = 0; i < 9; i++) {
      Serial.print("0x");
      if (buffer[i] < 0x10) Serial.print("0"); // Leading zero for single-digit hex values
      Serial.print(buffer[i], HEX);
      Serial.print(" ");
    }
    Serial.println();

    // Validate start byte (must be 0xFF)
    if (buffer[0] != 0xFF) {
      Serial.println("Invalid data frame.");
      return;
    }

    // Extract high and low bytes of gas concentration
    int highByte = buffer[2];
    int lowByte = buffer[3];

    // Extract decimal resolution
    int decimalPlaces = buffer[5];

    // Compute gas concentration
    float concentration = (highByte * 256 + lowByte) * pow(10, -decimalPlaces);

    // Print gas concentration
    Serial.print("Gas Concentration: ");
    Serial.print(concentration, decimalPlaces);
    Serial.println(" ppm");
  }
}
