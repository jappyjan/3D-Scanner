#include <Arduino.h>
#include "config.hpp"
#include "DRV8825.h"
#include <CliTerminal.h>

#define METHOD_PCS 1

Cli_Terminal terminal(50);

DRV8825 stepper(
    STEPPER_ROTATE_STEPS_PER_REVOLUTION,
    STEPPER_ROTATE_PIN_DIR,
    STEPPER_ROTATE_PIN_STEP,
    STEPPER_ROTATE_PIN_ENABLE);

void takePicture()
{
  digitalWrite(SHUTTER_PIN, LOW);
  delay(1000);
  digitalWrite(SHUTTER_PIN, HIGH);
  delay(SHUTTER_DELAY_MS);
}

void runScan()
{
  Serial.print("Running scan with ");

  int totalRotationSteps = 360 / ROTATION_DEGREES_PER_PICTURE;

  Serial.print(totalRotationSteps);
  Serial.println(" pictures.");

  for (int rotationStep = 0; rotationStep < totalRotationSteps; rotationStep++)
  {
    Serial.print(rotationStep);
    Serial.print(" ... ");
    stepper.rotate(ROTATION_DEGREES_PER_PICTURE);
    delay(1000);
    takePicture();
  }
  Serial.println();

  Serial.println("Scan complete");
}

void setup()
{
  Serial.begin(9600);
  pinMode(SHUTTER_PIN, OUTPUT);
  digitalWrite(SHUTTER_PIN, HIGH);
  stepper.begin(STEPPER_ROTATE_RPM, STEPPER_ROTATE_USE_MICROSTEPS);
  stepper.setEnableActiveState(LOW);
  stepper.enable();

  terminal.commands[0] = Command("scan", [](String str) -> void
                                 { runScan(); });

  Serial.println("Welcome to the greatest 3D scanner of all time!");
  Serial.println("Type 'scan' (plus ENTER) to start the scan");
  Serial.print(">");
}

void loop()
{
  terminal.cli_cal();
}
