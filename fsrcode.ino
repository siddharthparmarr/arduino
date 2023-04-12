// Define FSR pin:
#define fsrpin A0

// Define LED pin:
#define ledpin 9

// Define the output frequency range in Hz:
#define freq_min 20
#define freq_max 20000

// Define the output voltage range in volts:
#define voltage_min 0
#define voltage_max 5

// Define variable to store sensor readings:
int fsrreading; //Variable to store FSR value

void setup() {
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);
  // Set the LED pin as output:
  pinMode(ledpin, OUTPUT);
}

void loop() {
  // Read the FSR pin and store the output as fsrreading:
  fsrreading = analogRead(fsrpin);

  // Convert the FSR reading to a frequency value:
  float freq = map(fsrreading, 0, 1023, freq_min, freq_max);

  // Convert the frequency value to a period value in microseconds:
  float period_us = 1000000.0 / freq;

  // Convert the FSR reading to a voltage value:
  float voltage = map(fsrreading, 0, 1023, voltage_min, voltage_max);

  // Turn on the LED for half of the period:
  digitalWrite(ledpin, HIGH);
  delayMicroseconds(period_us / 2);
  // Turn off the LED for the other half of the period:
  digitalWrite(ledpin, LOW);
  delayMicroseconds(period_us / 2);

  // Print the frequency and voltage values in the serial monitor:
  Serial.print("Frequency (Hz): ");
  Serial.print(freq);
  Serial.print(", Voltage (V): ");
  Serial.println(voltage);


  // Plot the frequency and voltage values in the serial plotter:

  Serial.print(freq);
  Serial.print(",");
  Serial.println(voltage);


  delay(100); //Delay 100 ms.
}

