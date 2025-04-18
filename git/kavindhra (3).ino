// Pins for each zone
const int zone1Pin = A0;
const int zone2Pin = A1;
const int zone3Pin = A2;

// Threshold for fault detection (adjust based on testing)
const int threshold = 100; // Analog value, tweak this if needed

void setup() {
  Serial.begin(9600);

  pinMode(zone1Pin, INPUT);
  pinMode(zone2Pin, INPUT);
  pinMode(zone3Pin, INPUT);
}

void loop() {
  int zone1 = analogRead(zone1Pin);
  int zone2 = analogRead(zone2Pin);
  int zone3 = analogRead(zone3Pin);

  Serial.println("----- Monitoring Zones -----");
  Serial.print("Zone 1 Voltage: "); Serial.println(zone1);
  Serial.print("Zone 2 Voltage: "); Serial.println(zone2);
  Serial.print("Zone 3 Voltage: "); Serial.println(zone3);

  if (zone1 < threshold) {
    Serial.println("⚠ Fault detected in Zone 1");
  } else if (zone2 < threshold) {
    Serial.println("⚠ Fault detected in Zone 2");
  } else if (zone3 < threshold) {
    Serial.println("⚠ Fault detected in Zone 3");
  } else {
    Serial.println("✅ All zones normal");
  }

  delay(1000); // Delay for 1 second before next reading
}