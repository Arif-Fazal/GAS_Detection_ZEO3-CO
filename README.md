# ZEO3-CO Electrochemical Gas Sensor Interface (Analog & UART)

This repository provides code examples for interfacing the **ZEO3-CO Electrochemical Carbon Monoxide (CO) Gas Sensor**, which supports both **analog** and **UART** output modes. The sensor is designed to detect carbon monoxide concentrations in the range of **0–1000 ppm**.

## Overview

The sensor outputs gas concentration data in two formats:
- **Analog Output:** A voltage signal proportional to the gas concentration.
- **UART Output:** Digital serial data representing ppm readings.

This repository includes **separate Arduino `.ino` files** for each output method.

## Features

- Dual output support: Analog and UART
- CO concentration range: 0–1000 ppm
- Linear interpolation for analog output based on the sensor datasheet
- UART data parsing for direct digital readings
- Reference formulas and values from the official datasheet

## Code Description

### Analog Output

The analog voltage signal from the sensor is read using an analog input pin. **Linear interpolation** is applied in the code to estimate CO concentration in ppm, as described in the sensor's datasheet.

### UART Output

The UART example reads serial data transmitted by the sensor and extracts the CO concentration in ppm directly from the received bytes.

## Requirements

- ZEO3-CO Gas Sensor module
- Arduino board (e.g., Uno)
- Jumper wires
- Breadboard (optional)

## Circuit Diagrams

Circuit connection diagrams for both analog and UART setups are provided in the `Circuit_diagrams` folder of this repository.

## Reference

For detailed specifications and formula explanations, refer to the official sensor datasheet:

- [ZEO3-CO Sensor Datasheet ](https://www.winsen-sensor.com/d/files/ze03-electrochemical-module-manualv2_8(1).pdf)

## Notes

- The **analog zero voltage (Vout0)** and **test voltage (Vout1)** are typically provided in the inspection report that comes with the sensor module. These values are used to calculate the gas concentration for the specific target gas based on the sensor type.

- If you are using a different sensor variant, such as **ZEO-SO2**, the following values should be adjusted based on the corresponding datasheet:
  - Zero voltage (Vout0)
  - Test voltage (Vout1)
  - Calibration ppm at Vout1 (ppm1)
  - Maximum detection range (Max PPM)

- For modifications related to **UART output**, please refer to the detailed instructions provided in the sensor's datasheet.

## Let’s Connect

---

Feel free to explore the code, share feedback, or contribute to improvements.

