# COSC111B Final Project - Arduino Laboratory Activities

A comprehensive collection of Arduino-based laboratory activities demonstrating embedded systems programming, sensor integration, serial communication, and Python interfacing.

---

## Table of Contents

- [Project Overview](#project-overview)
- [Laboratory Activities](#laboratory-activities)
  - [Laboratory 1 - LED Sequential Control](#laboratory-1---led-sequential-control)
  - [Laboratory 2 - PWM Brightness Control](#laboratory-2---pwm-brightness-control)
  - [Laboratory 3 - Fire Detection System](#laboratory-3---fire-detection-system)
  - [Laboratory 4 - Light Threshold Alert System](#laboratory-4---light-threshold-alert-system)
  - [Laboratory 5 - Serial LED Controller](#laboratory-5---serial-led-controller)
  - [Laboratory 6 - Bi-directional Serial Communication](#laboratory-6---bi-directional-serial-communication)
  - [Laboratory 7 - FastAPI Web-Controlled LEDs](#laboratory-7---fastapi-web-controlled-leds)
- [Lab Examinations](#lab-examinations)
  - [Midterm Exam - Adaptive Light Sensor System](#midterm-exam---adaptive-light-sensor-system)
  - [Final Exam - API Button Integration](#final-exam---api-button-integration)

---

## Project Overview

This repository contains all laboratory activities and examinations for **COSC111B** course. Each laboratory demonstrates progressively advanced concepts in:

- **Arduino Programming** (C/C++)
- **Sensor Integration** (Temperature, Light sensors)
- **Serial Communication** (Arduino ↔ Python)
- **Web APIs** (FastAPI integration)
- **Embedded Systems Design**

---

### Hardware Requirements
- Arduino Uno/Nano or compatible board
- LEDs (Red, Green, Blue)
- Resistors (220Ω for LEDs, 10kΩ for sensors)
- Thermistor (NTC)
- Photoresistor (LDR)
- Push buttons
- Breadboard and jumper wires
- USB cable for Arduino

---

## Laboratory Activities

---

### Laboratory 1 - LED Sequential Control
**Folder:** `Laboratory_1/`

#### Description
Introduction to basic Arduino programming with sequential LED control using arrays and loops.

#### Concepts Covered
- Array initialization for pin management
- `pinMode()` and `digitalWrite()` functions
- Sequential execution with `for` loops
- Delay-based timing

#### Files
| File | Description |
|------|-------------|
| `Laboratory_1.ino` | Arduino sketch for sequential LED blinking |
| `Laboratory#1.png` | Circuit diagram/screenshot |

#### How It Works
1. Initializes 5 LEDs connected to pins 8-12
2. Turns on each LED sequentially (1-second delay)
3. Turns off each LED sequentially (1-second delay)
4. Loops continuously

#### Circuit Connections
| Component | Arduino Pin |
|-----------|-------------|
| LED 1 | Pin 8 |
| LED 2 | Pin 9 |
| LED 3 | Pin 10 |
| LED 4 | Pin 11 |
| LED 5 | Pin 12 |

---

### Laboratory 2 - PWM Brightness Control
**Folder:** `Laboratory_2/`

#### Description
Advanced LED control using Pulse Width Modulation (PWM) for smooth brightness transitions on compatible pins.

#### Concepts Covered
- PWM (Pulse Width Modulation) using `analogWrite()`
- Conditional logic to differentiate PWM and non-PWM pins
- `while` loop iteration
- Gradual brightness fade-in and fade-out effects

#### Files
| File | Description |
|------|-------------|
| `Laboratory_2.ino` | Arduino sketch with PWM brightness control |
| `Laboratory#2.png` | Circuit diagram/screenshot |

#### How It Works
1. Checks if the current pin supports PWM (pins 9, 10, 11)
2. **Non-PWM pins:** Simple HIGH/LOW switching with 1-second delay
3. **PWM pins:** Smooth brightness transition (0→255 for ON, 255→0 for OFF)
4. Alternates between turning all LEDs on and off

#### Key Code Logic
```cpp
if (ledPins[counts]!=9 && ledPins[counts]!=10 && ledPins[counts]!=11) {
  digitalWrite(ledPins[counts], HIGH);  // Non-PWM
} else {
  analogWrite(ledPins[counts], brightness);  // PWM fade
}
```

---

### Laboratory 3 - Fire Detection System
**Folder:** `Laboratory_3/`

#### Description
A multi-sensor fire detection system using temperature and light sensors to detect potential fire conditions.

#### Concepts Covered
- Analog sensor reading with `analogRead()`
- Thermistor temperature calculation (Steinhart-Hart equation)
- Photoresistor brightness measurement
- Multi-condition logic (AND operation)
- Custom functions for modular code

#### Files
| File | Description |
|------|-------------|
| `LabAct_3_CODE.ino` | Fire detection system sketch |
| `Laboratory#3.png` | Circuit diagram/screenshot |

#### Sensor Configuration
| Sensor | Arduino Pin | Threshold |
|--------|-------------|-----------|
| Thermistor (NTC) | A0 | 40°C |
| Photoresistor | A2 | 220 (brightness units) |
| Alert LED/Buzzer | Pin 12 | - |

#### Detection Logic
```
IF (Temperature >= 40°C) AND (Brightness >= 220) THEN
    → FIRE DETECTED → Alert LED blinks
ELSE
    → Safe conditions → Alert OFF
```

#### Temperature Calculation
Uses the Steinhart-Hart equation to convert thermistor resistance to Celsius:
```cpp
float temperature = 1 / (log(resistance / 10000.0) / 3950 + 1 / 298.15) - 273.15;
```

---

### Laboratory 4 - Light Threshold Alert System
**Folder:** `Laboratory_4/`

#### Description
A light-based alert system with Serial command control to stop the blinking alert.

#### Concepts Covered
- Serial communication (`Serial.begin()`, `Serial.available()`)
- String parsing with `readStringUntil()`
- Boolean state management
- Real-time Serial monitoring
- User input command handling

#### Files
| File | Description |
|------|-------------|
| `Laboratory_4.ino` | Light threshold alert system |
| `Laboratory_4.png` | Circuit diagram/screenshot |

#### Functionality
1. Continuously monitors light brightness
2. When brightness exceeds threshold (220), alert starts blinking
3. User can type `stop` in Serial Monitor to disable the alert
4. Alert reactivates if brightness exceeds threshold again

#### Serial Commands
| Command | Action |
|---------|--------|
| `stop` | Stops the blinking alert |

---

### Laboratory 5 - Serial LED Controller
**Folder:** `Laboratory_5/`

#### Description
Interactive LED control through both Arduino Serial Monitor and a Python-based terminal interface.

#### Concepts Covered
- Header file creation (`.h`) for reusable functions
- Character-based command parsing
- Python-Arduino serial communication
- Menu-driven Python interface
- Cross-platform serial library (`pyserial`)

#### Files
| File | Description |
|------|-------------|
| `Laboratory_5.ino` | Arduino LED controller sketch |
| `Laboratory_5.py` | Python menu-driven controller |
| `ledheader.h` | Custom header with LED functions |
| `Laboratory_5.png` | Circuit diagram/screenshot |

#### Available Commands
| Command | Action |
|---------|--------|
| `R` | Toggle Red LED |
| `G` | Toggle Green LED |
| `B` | Toggle Blue LED |
| `A` | Turn All LEDs ON |
| `O` | Turn All LEDs OFF |
| `V` | Toggle Violet (Red + Blue) |
| `X` | Exit Python application |

#### Pin Configuration (ledheader.h)
| LED Color | Arduino Pin |
|-----------|-------------|
| Red | Pin 8 |
| Green | Pin 9 |
| Blue | Pin 10 |

#### Running the Python Controller
```bash
cd Laboratory_5
python Laboratory_5.py
```
> **Note:** Update `COM6` in the Python script to match your Arduino port.

---

### Laboratory 6 - Bi-directional Serial Communication
**Folder:** `Laboratory_6/`

#### Description
Full-duplex communication between Arduino and Python - physical buttons on Arduino control LEDs via Python, and Python commands control LEDs on Arduino.

#### Concepts Covered
- Bi-directional serial communication
- Physical button input with edge detection
- Input pullup resistors
- Button debouncing logic
- Python serial listener

#### Files
| File | Description |
|------|-------------|
| `Laboratory_6.ino` | Arduino bi-directional controller |
| `Laboratory_6.py` | Python serial listener and responder |
| `ledheader.h` | LED utility functions |
| `Laboratory_6.png` | Circuit diagram/screenshot |

#### Communication Flow
```
┌─────────────────┐          ┌─────────────────┐
│     ARDUINO     │          │     PYTHON      │
│                 │   'R'    │                 │
│  Button Press ──┼─────────►│  Receives 'R'   │
│                 │   '1'    │                 │
│  LED Toggles   ◄┼──────────┤  Sends '1'      │
└─────────────────┘          └─────────────────┘
```

#### Hardware Configuration
| Component | Arduino Pin |
|-----------|-------------|
| Red LED   |       Pin 7 |
| Green LED |       Pin 6 |
| Blue LED  |       Pin 5 |
| Button (Red) |    Pin 12|
| Button (Green) |  Pin 11|
| Button (Blue) |   Pin 10|

---

### Laboratory 7 - FastAPI Web-Controlled LEDs
**Folder:** `Laboratory_7/`

#### Description
Web-based LED control using FastAPI to create RESTful endpoints that communicate with Arduino via serial.

#### Concepts Covered
- RESTful API design with FastAPI
- HTTP GET endpoints
- Arduino serial integration in web apps
- Event-driven startup/shutdown handlers
- Error handling with HTTP exceptions

#### Files
| File | Description |
|------|-------------|
| `Laboratory_7.ino` | Arduino serial command handler |
| `Laboratory_7.py` | FastAPI web server |
| `ledheader.h` | LED utility functions |
| `Laboratory_7.png` | Circuit diagram/screenshot |

#### API Endpoints
| Endpoint | Method | Description |
|----------|--------|-------------|
| `/` | GET | API status check |
| `/led/on` | GET | Turn all LEDs ON |
| `/led/off` | GET | Turn all LEDs OFF |
| `/led/red` | GET | Toggle Red LED |
| `/led/green` | GET | Toggle Green LED |
| `/led/blue` | GET | Toggle Blue LED |

#### Running the API Server
```bash
cd Laboratory_7
fastapi dev Laboratory_7.py
```

#### Example API Calls
```bash
# Check API status
curl http://localhost:8000/

# Turn all LEDs on
curl http://localhost:8000/led/on

# Toggle red LED
curl http://localhost:8000/led/red
```

---

## Lab Examinations

---

### Midterm Exam - Adaptive Light Sensor System
**Folder:** `LabExam_Midterms/`

#### Description
An advanced light monitoring system with dual modes (Automatic/Manual) and adjustable thresholds via Serial commands.

#### Files
| File | Description |
|------|-------------|
| `LabExam_Midterms.ino` | Complete midterm exam solution |

#### Features
- **Dual Operating Modes:**
  - **Automatic Mode:** Uses default thresholds with environment detection
  - **Manual Mode:** User-adjustable thresholds via Serial commands
- **LED Indicators:**
  - Green: Low light (≤ LOW_THRESHOLD)
  - Yellow: Medium light (between thresholds)
  - Red: High light (≥ HIGH_THRESHOLD)
- **Environment Detection (Auto mode):**
  - ≤40%: "Cloudy"
  - >40%: "Clear"

#### Serial Commands
| Command | Description |
|---------|-------------|
| `MODE AUTO` | Switch to Automatic mode (resets thresholds to default) |
| `MODE MANUAL` | Switch to Manual mode |
| `SET LOW <value>` | Set low threshold (0-99, must be < HIGH) |
| `SET HIGH <value>` | Set high threshold (1-100, must be > LOW) |

#### Hardware Configuration
| Component | Arduino Pin |
|-----------|-------------|
| Photoresistor | A0 |
| Green LED | Pin 11 |
| Yellow LED | Pin 12 |
| Red LED | Pin 13 |

---

### Final Exam - API Button Integration
**Folder:** `LabExam_Finals/`

#### Description
Integration project connecting physical Arduino buttons to external API endpoints for remote LED control.

#### Files
| File | Description |
|------|-------------|
| `LabExam_Finals.ino` | Arduino button press detector |
| `LabExam_Finals.py` | Python API caller |

#### System Architecture
```
┌──────────────┐      Serial      ┌──────────────┐      HTTP       ┌──────────────┐
│    BUTTON    │ ────────────────►│    PYTHON    │ ───────────────►│   REMOTE     │
│   (Arduino)  │  "Button 1..."   │   (Listener) │   GET /led/... │     API      │
└──────────────┘                  └──────────────┘                 └──────────────┘
```

#### How It Works
1. User presses physical button on Arduino
2. Arduino sends "Button 1 Pressed" via Serial
3. Python listens for this message
4. Python calls remote API endpoint: `/led/group/1/toggle`
5. Remote LED (connected to API server) toggles

#### Configuration
Update these values in `LabExam_Finals.py`:
```python
SERIAL_PORT = "COM5"              # Your Arduino COM port
API_BASE_URL = "BASE_API"         # Your API server URL
GROUP_NUMBER = "1"                # Button-to-group mapping
```

---