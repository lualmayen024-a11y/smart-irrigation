/*
 * SMART IRRIGATION SYSTEM - COMPLETE & LOGICAL
 * 100% Tinkercad Compatible
 * 
 * SENSOR LOGIC EXPLAINED:
 * - LOW number (200-400) = WET soil = NO watering needed
 * - HIGH number (700-1023) = DRY soil = WATERING needed  
 * - MID number (400-700) = MOIST soil = Monitor
 * 
 * This matches how soil moisture sensors actually work!
 */

// ===== PIN DEFINITIONS =====
const int PUMP_PIN = 9;           // Controls water pump via transistor
const int MOISTURE_SENSOR_PIN = A0; // Reads soil moisture level
const int STATUS_LED_PIN = 13;     // Visual indicator LED

// ===== MOISTURE THRESHOLDS =====
const int DRY_THRESHOLD = 700;     // ABOVE this = DRY soil = WATER NEEDED
const int WET_THRESHOLD = 400;     // BELOW this = WET soil = NO WATER NEEDED

// ===== TIMING CONSTANTS =====
const int CYCLE_DELAY = 3000;      // 3 seconds between checks
const int WATERING_TIME = 2000;    // 2 seconds watering duration
const int BLINK_FAST = 200;        // Fast blink speed
const int BLINK_SLOW = 500;        // Slow blink speed

// ===== VARIABLES =====
int moistureLevel = 0;             // Stores soil moisture reading

void setup() {
  // Initialize all pins
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(STATUS_LED_PIN, OUTPUT);
  
  // Start serial communication
  Serial.begin(9600);
  
  // Ensure everything starts OFF
  digitalWrite(PUMP_PIN, LOW);
  digitalWrite(STATUS_LED_PIN, LOW);
  
  // Display system information
  Serial.println("==================================================");
  Serial.println("        SMART IRRIGATION SYSTEM - ACTIVE");
  Serial.println("==================================================");
  Serial.println("SENSOR LOGIC:");
  Serial.println("  • 200-400  = WET SOIL    = NO WATERING");
  Serial.println("  • 400-700  = MOIST SOIL  = MONITOR");  
  Serial.println("  • 700-1023 = DRY SOIL    = WATER NOW");
  Serial.println("--------------------------------------------------");
  
  // Initial sensor test
  moistureLevel = analogRead(MOISTURE_SENSOR_PIN);
  Serial.print("Initial Sensor Reading: ");
  Serial.println(moistureLevel);
  
  if (moistureLevel == 0) {
    Serial.println("⚠  Check sensor wiring: VCC→5V, GND→GND, SIG→A0");
  }
  
  Serial.println("System ready! Starting monitoring...");
  Serial.println();
  delay(2000);
}

void loop() {
  // === STEP 1: READ SOIL MOISTURE ===
  moistureLevel = analogRead(MOISTURE_SENSOR_PIN);
  
  // Display current reading
  Serial.println("--------------- Soil Check ---------------");
  Serial.print("Moisture Reading: ");
  Serial.println(moistureLevel);
  
  // === STEP 2: MAKE WATERING DECISION ===
  if (moistureLevel > DRY_THRESHOLD) {
    // DRY SOIL DETECTED - WATER NEEDED
    Serial.println("🚨 STATUS: SOIL IS DRY");
    Serial.println("💧 ACTION: STARTING WATERING");
    startWateringCycle();
    
  } else if (moistureLevel < WET_THRESHOLD) {
    // WET SOIL DETECTED - NO WATER NEEDED
    Serial.println("✅ STATUS: SOIL IS WET");
    Serial.println("🌱 ACTION: No watering needed");
    indicateGoodCondition();
    
  } else {
    // MOIST SOIL - MONITORING
    Serial.println("🔍 STATUS: SOIL IS MOIST");
    Serial.println("📊 ACTION: Continuing monitoring");
    indicateMonitoring();
  }
  
  Serial.println("------------------------------------------");
  delay(CYCLE_DELAY);
}

void startWateringCycle() {
  /*
   * ACTIVATES WHEN SOIL IS DRY
   * Turns on pump and solid LED for watering duration
   */
  Serial.println("💧 PUMP: ACTIVATED");
  
  // Turn on pump and LED
  digitalWrite(PUMP_PIN, HIGH);
  digitalWrite(STATUS_LED_PIN, HIGH);
  
  // Show watering in progress
  Serial.println("Watering for 2 seconds...");
  delay(WATERING_TIME);
  
  // Turn off pump and LED
  digitalWrite(PUMP_PIN, LOW);
  digitalWrite(STATUS_LED_PIN, LOW);
  Serial.println("💧 PUMP: DEACTIVATED");
  Serial.println("✅ Watering complete!");
}

void indicateGoodCondition() {
  /*
   * INDICATES WET SOIL - NO WATERING NEEDED
   * Double blink pattern = "All good!"
   */
  Serial.println("💡 LED: Double blink (Soil wet - Happy!)");
  for(int i = 0; i < 2; i++) {
    digitalWrite(STATUS_LED_PIN, HIGH);
    delay(BLINK_SLOW);
    digitalWrite(STATUS_LED_PIN, LOW);
    delay(BLINK_SLOW);
  }
}

void indicateMonitoring() {
  /*
   * INDICATES MOIST SOIL - MONITORING MODE
   * Single blink pattern = "Keeping watch"
   */
  Serial.println("💡 LED: Single blink (Monitoring moisture)");
  digitalWrite(STATUS_LED_PIN, HIGH);
  delay(BLINK_FAST);
  digitalWrite(STATUS_LED_PIN, LOW);
}

/*
 * ============================================================
 * TINKERCAD DEMONSTRATION GUIDE:
 * ============================================================
 * 
 * 1. CIRCUIT SETUP:
 *    Moisture Sensor:
 *      - VCC  → 5V
 *      - GND  → GND  
 *      - SIG  → A0
 *    
 *    Pump Circuit:
 *      - Pump+ → Transistor Collector
 *      - Pump- → GND
 *      - Transistor Base → 1kΩ resistor → Pin 9
 *      - Transistor Emitter → GND
 *      - Diode across pump (striped end to pump+)
 *    
 *    LED Indicator:
 *      - LED+ → 220Ω resistor → Pin 13
 *      - LED- → GND
 *
 * 2. TESTING PROCEDURE:
 *    a) Open Serial Monitor
 *    b) Click moisture sensor component
 *    c) Move slider to test all conditions:
 *        
 *        SLIDER POSITION | EXPECTED BEHAVIOR
 *        ----------------|-------------------
 *        BOTTOM (Wet)    | "SOIL IS WET" + Double blink
 *        MIDDLE (Moist)  | "SOIL IS MOIST" + Single blink  
 *        TOP (Dry)       | "SOIL IS DRY" + Pump runs 2 sec
 *
 * 3. EXPECTED OUTPUT EXAMPLES:
 *    
 *    EXAMPLE 1 - DRY SOIL:
 *    --------------- Soil Check ---------------
 *    Moisture Reading: 850
 *    🚨 STATUS: SOIL IS DRY
 *    💧 ACTION: STARTING WATERING
 *    💧 PUMP: ACTIVATED
 *    Watering for 2 seconds...
 *    💧 PUMP: DEACTIVATED
 *    ✅ Watering complete!
 *    
 *    EXAMPLE 2 - WET SOIL:
 *    --------------- Soil Check ---------------
 *    Moisture Reading: 350  
 *    ✅ STATUS: SOIL IS WET
 *    🌱 ACTION: No watering needed
 *    💡 LED: Double blink (Soil wet - Happy!)
 *    
 * 4. TROUBLESHOOTING:
 *    - If readings stay at 0: Check sensor power wires
 *    - If pump doesn't run: Check transistor connections
 *    - If LED doesn't blink: Check LED direction
 * ============================================================
 */
